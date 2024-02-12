import java.util.Scanner;

class Example extends Thread {
    int x; 
    static Object lock = new Object(); 
    Example(int x) { this.x = x; }
    public void run() {
        synchronized(lock) {
            for(int i = 0; i < 100; i++) {
                System.out.println(x);
            }
        }
    }
}

class Synchro {
    public static void main(String args[]) {
        Example e = new Example(0);
        Example f = new Example(1);   

        e.start();
        f.start();
    }
}
