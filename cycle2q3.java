import java.util.Scanner;
import java.lang.Math;

class Employee{
    public void display(){
        System.out.println("Name of class is Employee");
    }
    public void calcSalary(){
        System.out.println("Salary of employee is 10000"); 
    }
}

class Engineer extends Employee{
    public void calcSalary(){
        System.out.println("Salary of employee is 20000");
    }
}

class cycle2q3{
    public static void main(String args[]){
        Employee employee = new Engineer();
        employee.display();
        employee.calcSalary();
    }
}

