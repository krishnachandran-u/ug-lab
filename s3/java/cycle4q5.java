class Odd extends Thread{
	public void run(){
		try{
			for(int i = 1; i <= 100; i+=2){
				System.out.print(i);
                System.out.print(" ");
			}
		}
		catch(Exception e){
			System.out.println(e);
		}
		return;
	}
}

class Even extends Thread{
	public void run(){
		try{
			for(int i = 2; i <= 100; i+=2){
				System.out.print(i);
                System.out.print(" ");
			}
		}
		catch(Exception e){
			System.out.println(e);
		}
	}
}

class cycle4q5{	
	public static void main(String args[]){
		Odd odd = new Odd();
		Even even = new Even();
		odd.start();
		even.start();
		return;
	}
}
