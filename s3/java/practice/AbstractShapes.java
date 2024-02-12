abstract class Shape {
    abstract void numberOfSides(); 
}

class Rectangle extends Shape {
    void numberOfSides() { System.out.println("Number of sides: 4"); }
}

class Triangle extends Shape {
    void numberOfSides() { System.out.println("Number of sides: 3"); }
}

class Hexagon extends Shape {
    void numberOfSides() { System.out.println("Number of sides: 6"); }
}

class AbstractShapes {
    public static void main(String args[]) {
        Shape rectangle = new Rectangle();
        Shape triangle = new Triangle();
        Shape hexagon = new Hexagon();
        rectangle.numberOfSides();
        triangle.numberOfSides();
        hexagon.numberOfSides();
        return; 
    }
}
