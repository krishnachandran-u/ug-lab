import java.util.Scanner;
import java.lang.Math;

abstract class Shape{
    abstract void numberOfSides();
}

class Rectangle extends Shape{
    public void numberOfSides(){
        System.out.println("4");
    }
}

class Triangle extends Shape{
    public void numberOfSides(){
        System.out.println("3");
    }
}

class Hexagon extends Shape{
    public void numberOfSides(){
        System.out.println("6");
    }
}

class cycle2q4{
    public static void main(String args[]){
        Shape rectangle = new Rectangle();
        Shape triangle = new Triangle();
        Shape hexagon = new Hexagon();

        rectangle.numberOfSides();
        triangle.numberOfSides();
        hexagon.numberOfSides();
        return;
    }
}

