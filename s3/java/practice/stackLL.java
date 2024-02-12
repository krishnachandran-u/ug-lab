class Node {
    int x;
    Node next;

    Node() { this.next = null; }

    Node(int x) {
        this.x = x;
        this.next = null;
    }
}

class Stack {
    Node head;

    Stack() {
        head = new Node(Integer.MIN_VALUE);
        head.next = null;
    }

    void push(int x) {
        Node newNode = new Node(x);
        Node rover = head;
        while(rover.next != null) {
            rover = rover.next;    
        }
        rover.next = newNode;
        return;
    }

    void pop() {
        Node rover = head;
        Node parent = null;  
        while(rover.next != null) {
            parent = rover;
            rover = rover.next;
        }
        if(rover == head) {
            System.out.println("Stack underflow");
        }
        else {
            rover = null;
            parent.next = null;
        }
        return;
    }

    void display() {
        Node rover = head;
        while(rover.next != null) {
            rover = rover.next;
            System.out.print(rover.x);
        }
        System.out.println();
        return;
    }

    int top() {
        Node rover = head;
        while(rover.next != null) {
            rover = rover.next;
        }
        if(rover == head) {
            System.out.println("Stack underflow");
            return Integer.MIN_VALUE;
        }
        else {
            return rover.x;
        }
    }
}

class stackLL {
    public static void main(String args[]) {
        Stack stack = new Stack();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.display();
        stack.pop();
        stack.display();
        System.out.println(stack.top());
        stack.pop();
        stack.pop();
        stack.pop();
        stack.top();
        stack.display();
        return;
    }
}
