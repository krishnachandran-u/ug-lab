module fa(a, b, cin, s, cout);
input a, b, cin;
output s, cout;
assign s = a ^ b ^ cin;
assign cout = (a & b) | (b & cin) | (a & cin);
endmodule

module tb;
reg a, b, cin;
wire s, cout;
fa gate(a, b, cin, s, cout); 
initial begin
    $dumpfile("fa.vcd");
    $dumpvars(0, tb);
end
initial begin
    $monitor("a=%b,b=%b,cin=%b,s=%b,cout=%b", a, b, cin, s, cout); 
    a=0; b=0; cin=0;
    #10;
    a=0; b=0; cin=1;
    #10;
    a=0; b=1; cin=0;
    #10;
    a=0; b=1; cin=1;
    #10;
    a=1; b=0; cin=0;  
    #10;
    a=1; b=0; cin=1;
    #10;
    a=1; b=1; cin=0;
    #10;
    a=1; b=1; cin=1;
    #10;
    $finish();
end
endmodule
     


