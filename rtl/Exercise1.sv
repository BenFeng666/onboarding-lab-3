`timescale 1ns / 1ps


module exercise1(

    input [1:0] op,
    input [7:0] a,
    input [7:0] b,
    output reg [7:0] out
);
always @*begin
    case (op)
      0: out = a ^ b;
      1: out = a << b;
      2: if (b==0) begin out=0; end else begin out=a%b; end
      3: out = ~(a & b);
    endcase
 end
endmodule
