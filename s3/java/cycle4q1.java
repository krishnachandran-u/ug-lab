import java.util.Scanner;

class cycle4q1{
	public static void main(String args[]){
		int y = 0, x = 10;
		try{
            if(y == -1) throw new ArithmeticException("y == -1");
			int w = x/y;
			System.out.println(w);
		}
		catch(ArithmeticException ae){
			System.out.println("Error: " + ae);
		}
		finally{
			System.out.println("finally block is executed and exception has been handled");
		}
		return;
	}
}

