class Synchronizer{
	synchronized void print(int x){
		try{
			for(int i = 0; i < 5; i++){
				System.out.println(x);
			}
		}
		catch(Exception e){
			System.out.println(e);	
		}
	}
}

class Demo extends Thread{		
	Synchronizer sync;
	int x;

	Demo(Synchronizer sync, int x){
		this.sync = sync;
		this.x = x;
	}
	
	public void run(){
		this.sync.print(x);
	}
}

class cycle4q4{
	public static void main(String args[]){
		Synchronizer newsync = new Synchronizer();
		Demo t_1 = new Demo(newsync, 10);
		Demo t_2 = new Demo(newsync, 20);
		t_1.start();
		t_2.start();
		return;
	}
}
