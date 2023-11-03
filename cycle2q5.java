import java.lang.Math;
import java.util.Scanner;

interface Walkable{
    void walk();
}

interface Swimmable{
    void swim();
}

class Amphibian implements Walkable, Swimmable{
    public void walk(){
        System.out.println("Walking on land");
    }
    public void swim(){
        System.out.println("Swimming in Water");
    }
}

public class cycle2q5{
    public static void main(String args[]){
        Amphibian frog = new Amphibian();
        frog.walk();
        frog.swim();
        return;
    }
}
