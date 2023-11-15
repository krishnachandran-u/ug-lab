/*
    author: krishnachandran-u
    github: https://github.com/krishnachandran-u
    text-editor: NVIM v0.9.1
*/

import java.util.Scanner;

class Node{
    Node prev;
    int a;
    Node next;

    Node(){};
    Node(int x){
        this.a = x;
    }
}

class DLL{
    Node head;
    Node tail;
    
    DLL(){
        this.head = null;
        this.tail = null;
    }

    public void insert(int x){
        Node newnode = new Node(x);
        if(this.head == null) head = newnode;
        else{
            this.tail.next = newnode;
            newnode.prev = this.tail;
        }
        this.tail = newnode;
        this.tail.next = null;
        return;
    }

    public void delete(int x){
        Node tempnode = this.head; 
        while(tempnode != null && tempnode.a != x){ 
            tempnode = tempnode.next; 
        }
        if(tempnode == null){
            System.out.println("not found");
        }
        else{
            if(tempnode.prev != null) tempnode.prev.next = tempnode.next;
            if(tempnode.next != null) tempnode.next.prev = tempnode.prev;

            if(tempnode == this.head){
                this.head = tempnode.next;
            }
        }
        return;
    }

    public void display(){
        Node tempnode = this.head;
        while(tempnode != null){
            System.out.print(tempnode.a + "   ");
            tempnode = tempnode.next;
        }
        System.out.println();
        return;
    } 
}

class cycle6q1{
    public static void main(String args[]){
        DLL dll = new DLL();
        dll.insert(1);
        dll.insert(2);
        dll.insert(3);
        dll.insert(5);
        dll.insert(6);
        dll.display();
        dll.delete(5);
        dll.display();
        dll.insert(7);
        dll.display();
        dll.insert(8);
        dll.display();
        dll.delete(8);
        dll.display();
        dll.delete(2);
        dll.delete(1);
        dll.display();
        dll.delete(3);
        dll.delete(8);
        dll.display();
        dll.delete(6);
        dll.delete(7);
        dll.display();
        dll.insert(1);
        dll.display();
        return;
    }
}

/*
1   2   3   5   6   
1   2   3   6   
1   2   3   6   7   
1   2   3   6   7   8   
1   2   3   6   7   
3   6   7   
not found
6   7   

1  
*/





