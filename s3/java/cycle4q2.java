import java.util.Scanner;

class cycle4q2{
	public static void check(int age){
		if(age < 18){
			throw new ArithmeticException(age + ": not eligible to vote");
		}
		else{
			System.out.println(age + ": eligible to vote");
		}
	}

	public static void main(String args[]){
		check(20);
		check(15);
		return;	
	}
}
