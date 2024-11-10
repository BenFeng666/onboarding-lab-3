/**
`timescale 1ns / 1ps
module Exercise4 (
    input [1:0] sel,
    input cs,

    input [7:0] alpha,
    input [7:0] beta,
    input [7:0] gamma,

    output reg [7:0] out
);
  always@(*)begin 
    if (!cs) out = 0;
    else
      case (sel)
        0: out = alpha;
        1: out = beta;
        2: out = gamma;
        default: out = alpha & (beta | gamma);
      endcase
  end
endmodule
