import java.util.Scanner;
import java.util.Random;

class RandInt extends Thread{
	public void run(){
		Random seed = new Random();
		for(int i = 0; i < 20; i++){
			try{
				int x = seed.nextInt(100);
				System.out.println(x);
				if(x % 2 == 0){
					Square square = new Square(x);
					square.start();
				}
				else{
					Cube cube = new Cube(x);	
					cube.start();
				}
				this.sleep(1000);
			}
			catch(Exception e){
				System.out.println(e);
			}
		}
		return;
	}
}

class Square extends Thread{
	int x;
	Square(int x){
		this.x = x;
	}
	public void run(){
		try{
			System.out.println("square: " + x*x);			
		}
		catch(ArithmeticException e){
			System.out.println(e);
		}
		return;
	}
}

class Cube extends Thread{
	int x;
	Cube(int x){
		this.x = x;
	}
	public void run(){
		try{
			System.out.println("cube: " + x*x*x);	
		}
		catch(ArithmeticException e){
			System.out.println(e);
		}
		return;
	}
}

class cycle4q3{
	public static void main(String args[]){
		RandInt randint = new RandInt();					
		randint.start();
		return;
	}
}

