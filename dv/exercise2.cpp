`timescale 1ns / 1ps


module exercise2_tb;
    reg clk;
    reg reset;
    reg [15:0] init;
    wire [15:0] out;
    
     exercise2 ex_inst(
        .clk(clk),
        .reset(reset),
        .init(init),
        .out(out)
    );
    
always begin
        #10 clk = ~clk; 
end 

reg [8:0] i; 
reg [15:0] correct;
initial begin
clk = 0;
reset = 1;
 
init = 16'hAAAA; 
        
#20
reset = 0;
        
        
correct = ~init;
        
        
 if (out != correct) begin
$display("Reset fail.");
$finish;
 end

for (i=0; i<20; i=i+1) begin
#20
    correct = {correct[14:0], correct[10] ^ correct[8] ^ correct[3] ^ correct[1]};
    if (correct != out) begin
        $display("Mismatch: i=%0d, out_10=%0d, out_8=%0d, out_3=%0d, out_1=%0d", i, out[10], out[8], out[3], out[1]);
        $finish;
    end
end
$display("All tests passed successfully.");
$finish;
end

endmodule