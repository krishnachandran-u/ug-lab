import java.util.Scanner;
import java.lang.Math;

class Employee{
    public String name, age, phone_number, address, salary;
    Employee(String name, String age, String phone_number, String address, String salary){
        this.name = name;
        this.age = age;
        this.phone_number = phone_number;
        this.address = address;
        this.salary = salary;
    }
}

class Officer extends Employee{
    public String specialization;
    Officer(String name, String age, String phone_number, String address, String salary, String specialization){
        super(name, age, phone_number, address, salary);
        this.specialization = specialization;
    }
}

class Manager extends Employee{
    public String department;
    Manager(String name, String age, String phone_number, String address, String salary, String department){
        super(name, age, phone_number, address, salary);
        this.department = department;
    }
}

class cycle2q2{
    public static void main(String args[]){ 
        Officer officer = new Officer("John", "40", "1234567890", "London", "300000", "Heart");
        Manager manager = new Manager("Steve", "35", "1234567890", "America", "400000", "Maths");

        System.out.println("officer.name: " + officer.name);
        System.out.println("officer.age: " + officer.age);
        System.out.println("officer.phone_number: " + officer.phone_number);
        System.out.println("officer.address: " + officer.address);
        System.out.println("officer.salary: " + officer.salary);
        System.out.println("officer.specialization: " + officer.specialization);
        System.out.println("manager.name: " + manager.name);
        System.out.println("manager.age: " + manager.age);
        System.out.println("manager.phone_number: " + manager.phone_number);
        System.out.println("manager.address: " + officer.address);
        System.out.println("manager.salary: " + manager.salary);
        System.out.println("manager.department : " + manager.department);

        return;
    }
}
