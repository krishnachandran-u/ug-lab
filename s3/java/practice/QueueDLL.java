class Node {
    public int x;
    public Node next;
    public Node prev;
    public Node() {
        this.next = null;
        this.prev = null;
    }
    public Node(int x) {
        this.x = x;
        this.next = null;
        this.prev = null;
    }
}

class Q {
    public Node head;
    public Q() {
        head = new Node(Integer.MIN_VALUE); 
    }

    public void push(int x) {
        Node newNode = new Node(x);
        Node rover = head;
        while(rover.next != null) rover = rover.next;
        rover.next = newNode;
        newNode.prev = rover;
        return;
    }

    public void pop() {
        if(head.next != null) {
            Node delNode = head.next;
            head.next = head.next.next;
            delNode = null;
        }
        if(head.next != null) head.next.prev = head;
        return;
    }

    public void display() {
        Node rover = head;
        while(rover.next != null) {
            rover = rover.next;
            System.out.print(rover.x + " ");
        }
        System.out.println();
        return;
    }

    public int top() {
        Node rover = head;
        while(rover.next != null) {
            rover = rover.next;
        }
        if(rover != head) {
            return rover.x;
        }
        else {
            return Integer.MIN_VALUE;
        }
    }
}

class QueueDLL {
    public static void main(String args[]) {
        Q q = new Q();
        q.push(1);
        q.push(2);
        q.push(3);
        System.out.println(q.top());
        q.push(4);
        q.push(5); 
        q.display();
        q.pop();
        q.display();
        q.pop();
        q.display();
        q.pop();
        q.display();
        q.pop();
        q.display();
        q.pop();
        q.display();
        q.pop();
        q.display();
        q.push(1);
        q.push(2);
        q.push(2);
        q.push(3);
        System.out.println(q.top());
        q.display();
        q.pop();
        q.display();
        return;
    }
}
