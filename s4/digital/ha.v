module ha(a,b,s,c);
input a, b;
output s, c;
assign s = a ^ b;
assign c = a & b;
endmodule

module tb;
reg a, b;
wire s, c;
ha gate(a, b, s, c);
initial begin
    $dumpfile("ha.vcd");
    $dumpvars(0, tb);
end
initial begin
    $monitor("a=%b,b=%b,s=%b,c=%b", a, b, s, c);
    a=0; b=0;
    #10;
    a=0; b=1;
    #10;
    a=1; b=0;
    #10;
    a=1; b=1;
    #10;
    $finish();
end
endmodule
