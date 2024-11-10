`timescale 1ns / 1ps

module exercise3(
    input clk,
    input reset,
    input [3:0] a,         
    input [15:0] b,        
    input [15:0] c,         
    output reg [15:0] out   
);

reg [7:0] a_in, b_in;
reg [2:0] state;           


always @(*) begin
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
end


always @(negedge clk or posedge reset) begin
    if (reset) begin
        out <= {b_in, a_in};  
        state <= 0;
    end else begin
        case (state)
            0: out <= {a_in, 8'b0};
            1: out <= {out[15:8], b_in};
            2: out <= {out[7:0], out[15:8]};
            3: out <= {out[3:0], out[7:4], out[11:8], out[15:12]};
            4: out <= {15'b0, ^out};
        endcase
        state <= (state + 1) % 5;  
    end
end

endmodule