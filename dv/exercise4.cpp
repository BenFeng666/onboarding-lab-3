`timescale 1ns / 1ps



module exercise4_tb;

    reg [1:0] sel;
    reg cs;
    reg [7:0] alpha;
    reg [7:0] beta;
    reg [7:0] gamma;
    wire [7:0] out;

    
    Exercise4 ex_int(
        .sel(sel),
        .cs(cs),
        .alpha(alpha),
        .beta(beta),
        .gamma(gamma),
        .out(out)
    );

    
    initial begin
        
        alpha = 8'b00000001; // Example value
        beta = 8'b00000010;  // Example value
        gamma = 8'b00000100; // Example value

        
        cs = 0;
        #10;
        if (out == 8'b00000000)
            $display("Correct for cs=0, sel=x, out=%b", out);
        else
            $display("Wrong for cs=0, sel=x, out=%b", out);

        
        cs = 1;
        sel = 2'b00;
        #10;
        if (out == alpha)
            $display("Correct for cs=1, sel=00, out=%b", out);
        else
            $display("Wrong for cs=1, sel=00, out=%b", out);

        
        sel = 2'b01;
        #10;
        if (out == beta)
            $display("Correct for cs=1, sel=01, out=%b", out);
        else
            $display("Wrong for cs=1, sel=01, out=%b", out);

        
        sel = 2'b10;
        #10;
        if (out == gamma)
            $display("Correct for cs=1, sel=10, out=%b", out);
        else
            $display("Wrong for cs=1, sel=10, out=%b", out);

        
        sel = 2'b11;
        #10;
        if (out == 8'b00000000)
            $display("Correct for cs=1, sel=11, out=%b", out);
        else
            $display("Wrong for cs=1, sel=11, out=%b", out);

        $finish; // End simulation
    end

endmodule
