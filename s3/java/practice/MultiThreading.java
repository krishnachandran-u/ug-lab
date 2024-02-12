import java.util.Random;
import java.lang.Math;

class Generator extends Thread {
    public void run() {
        Random rand = new Random();
        for(int i = 0; i < 20; i++) {
            int x = Math.abs(rand.nextInt()) % 100 + 1;
            if(x % 2 == 0) {
                Even even = new Even(x);
                even.start();

                try { even.join(); }
                catch(Exception e) { System.out.println(e); }
            }
            else {
                Odd odd = new Odd(x);
                odd.start();

                try { odd.join(); }
                catch(Exception e) { System.out.println(e); }
            }
        }
        return;
    }
}

class Even extends Thread {
    int x;
    Even(int x) { this.x = x; }
    public void run() {
        System.out.println(x + " is Even => Square: " + x*x);
        return;
    }
}

class Odd extends Thread {
    int x;
    Odd(int x) { this.x = x; }
    public void run() {
        System.out.println(x + " is Odd => Cube: " + x*x*x);
        return;
    }
}

class MultiThreading {
    public static void main(String args[]) {
        Generator gen = new Generator();
        gen.start();

        try { gen.join(); }
        catch(Exception e) { System.out.println(e); }
        return;
    }
}
