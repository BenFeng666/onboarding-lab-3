`timescale 1ns / 1ps



module exercise2(
    input clk,
    input reset,
    input [15:0] init,
    output reg [15:0] out
);
  always @(posedge clk)
  begin
    if (reset) begin out <= ~init;end
    else begin out <= {out[14:0], out[10] ^ out[8] ^ out[3] ^ out[1]};end


end 
endmodule
