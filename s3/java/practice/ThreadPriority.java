class Example extends Thread {
    public void print() {
        System.out.println("here");
    }
}

class ThreadPriority {
    public static void main(String args[]) {
        Example p = new Example();
        Example q = new Example();
        Example r = new Example();

        System.out.println("Priority of the main thread: " + Thread.currentThread().getPriority());

        p.setPriority(1);
        q.setPriority(2);
        r.setPriority(3);

        System.out.println("Priority of the thread p: " + p.getPriority());
        System.out.println("Priority of the thread q: " + q.getPriority());
        System.out.println("Priority of the thread r: " + r.getPriority());

        return;
    }
}
