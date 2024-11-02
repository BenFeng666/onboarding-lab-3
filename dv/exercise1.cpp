`timescale 1ns / 1ps



module exercise1_tb;
    // Inputs to the DUT (Device Under Test)
    reg [1:0] op;
    reg [7:0] a;
    reg [7:0] b;
    wire [7:0] out;

   
    exercise1 dut (
        .op(op),
        .a(a),
        .b(b),
        .out(out)
    );

  
    reg [7:0] expected_result;

  
    reg [7:0] i;
    reg [7:0] j;
    reg [7:0] k;

initial begin
        $display("Simulation started...");
        for (i = 0; i < 4; i = i + 1) begin
            op = i;
            
            for (j = 0; j < 64; j = j + 1) begin
                a = j;
                
                for (k = 0; k < 64; k = k + 1) begin
                    b = k;
                    #1; 

                   
                    case (op)
                        2'b00: expected_result = a ^ b;
                        2'b01: expected_result = (b < 8) ? (a << b) : 0;
                        2'b10: expected_result = (b == 0) ? 0 : (a % b);
                        2'b11: expected_result = ~(a & b);
                        default: expected_result = 8'b0;
                    endcase

                    
                    if (out !== expected_result) begin
                        $display("Mismatch: op=%0d, a=%0d, b=%0d, expected=%0d, got=%0d", op, a, b, expected_result, out);
                        $finish; 
                    end
                end
            end
        end
        #500000; // Delay to allow all test cases to finish
        $display("All tests passed successfully.");
        $finish; // End simulation after all tests are complete
    end
endmodule





}
