import java.lang.Math;

class AreaOverloading {
    static double area(double radius) {
        return Math.PI*radius*radius;
    }

    static double area(double length, double breadth) {
        return length*breadth;
    }

    static double area(double a, double b, double c) {
        double s = (a + b + c)/2;
        return Math.sqrt(s*(s - a)*(s - b)*(s - c));
    }

    public static void main(String args[]) {
        System.out.println("Area of circle of radius 5: " + area(5));
        System.out.println("Area of rectangle of length 4 breadth 5: " + area(4, 5));
        System.out.println("Area of triangle of sides 3, 4, 5: " + area(3, 4, 5));
        return;
    }
}
