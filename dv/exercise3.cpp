`timescale 1ns / 1ps


module exercise_3_tb;

    reg clk;
    reg reset;
    reg [3:0] a;
    reg [15:0] b;
    reg [15:0] c;
    wire [15:0] out;
    reg [15:0] expected;  
    integer i, j, k;      


    exercise3 dut (
        .clk(clk),
        .reset(reset),
        .a(a),
        .b(b),
        .c(c),
        .out(out)
    );
integer state;
reg [7:0] a_in, b_in;
 
    initial begin
        clk = 0;
        forever #5 clk = ~clk; 
    end

    
    task calculate_expected;
        input [2:0] state;
        input [7:0] a_in;
        input [7:0] b_in;
        inout [15:0] exp_out;
        begin
            case (state)
                0: exp_out = {a_in, 8'b0};
                1: exp_out = {exp_out[15:8], b_in};
                2: exp_out = {exp_out[7:0], exp_out[15:8]};
                3: exp_out = {exp_out[3:0], exp_out[7:4], exp_out[11:8], exp_out[15:12]};
                4: exp_out = {15'b0, ^exp_out};
            endcase
        end
    endtask

   
    initial begin
       
        reset = 1;
        a = 4'b0000;
        b = 16'b0000000000000000;
        c = 16'b0000000000000000;
        expected = 16'b0000000000000000; 
        #10 reset = 0; 
        
    
        for (i = 0; i < 16; i = i + 1) begin
            for (j = 0; j < 256; j = j + 1) begin
                for (k = 0; k < 256; k = k + 1) begin
                    a = i[3:0];
                    b = {8'b00000000, j[7:0]};
                    c = {8'b00000000, k[7:0]};
                    expected = {b[15:8], c[7:0]}; 
                    reset = 1;
                    #10 reset = 0;
                    case (a[1:0])
                      2'b00: a_in = {2'b00, b[2:0], c[2:0]};
                      2'b01: a_in = {2'b01, c[2:0], b[2:0]};
                      2'b10: a_in = b[7:0];
                      2'b11: a_in = c[7:0];
                     endcase

                     case (a[3:2])
                       2'b00: b_in = {2'b00, b[10:8], c[10:8]};
                       2'b01: b_in = {2'b01, c[10:8], b[10:8]};
                       2'b10: b_in = b[15:8];
                       2'b11: b_in = c[15:8];
                     endcase
               
                    for (state = 0; state < 5; state = state + 1) begin
                        #10; 
                        calculate_expected(state, a_in[7:0], b_in[7:0], expected);
                        if (out === expected)
                            $display("Correct:  State %0d - a: %b, b: %d, c: %d, out: %d, expected: %d", state, a, b, c, out, expected);
                        else
                            $display("Incorrect: State %0d - a: %b, b: %d, c: %d, out: %d, expected: %d", state, a, b, c, out, expected);
                    end
                end
            end
        end

        #50;
        $finish;
    end

endmodule