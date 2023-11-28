class DemoThread extends Thread{
	public void run(){	
		System.out.println("inside run");
	}
}

class cycle4q6{
	public static void main(String args[]){
		DemoThread t_1 = new DemoThread();
		DemoThread t_2 = new DemoThread();
		DemoThread t_3 = new DemoThread();

		System.out.println("t_1: " + t_1.getPriority());
		System.out.println("t_2: " + t_2.getPriority());
		System.out.println("t_3: " + t_3.getPriority());
	
		t_1.setPriority(10);
		t_2.setPriority(5);
		t_3.setPriority(7);

		System.out.println("t_1: " + t_1.getPriority());
		System.out.println("t_2: " + t_2.getPriority());
		System.out.println("t_3: " + t_3.getPriority());
	
		return;
	}
}

