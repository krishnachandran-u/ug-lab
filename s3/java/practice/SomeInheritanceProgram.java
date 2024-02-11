class Employee {
    protected String name, address;
    protected int age, phoneNumber, salary;

    Employee(String name, int age, int phoneNumber, String address, int salary) {
        this.name = name;
        this.age = age;
        this.phoneNumber = phoneNumber;
        this.address = address;
        this.salary = salary;
    }

    public void printSalary() {
        System.out.println("Salary of the Employee: " + this.salary);
    }

    public void printAll() {
        System.out.println("Name: " + this.name);
        System.out.println("Age: " + this.age);
        System.out.println("Phone Number: " + this.phoneNumber);
        System.out.println("Address: " + this.address);
        System.out.println("Salary: " + this.salary);        
    }
}

class Officer extends Employee {
    String specialization;

    Officer(String name, int age, int phoneNumber, String address, int salary, String specialization) {
        super(name, age, phoneNumber, address, salary);
        this.specialization = specialization;
    }

    public void printAll() {
        super.printAll();
        System.out.println("Specialization: " + this.specialization);
    }
}

class Manager extends Employee {
    String department;

    Manager(String name, int age, int phoneNumber, String address, int salary, String department) {
        super(name, age, phoneNumber, address, salary);
        this.department = department;
    }

    public void printAll() {
        super.printAll();
        System.out.println("Department: " + this.department);
    }
}

class SomeInheritanceProgram {
    public static void main(String args[]) {
        Employee e = new Employee("John", 25, 1234567890, "New York", 10000);
        Officer o = new Officer("Jane", 30, 1234567890, "New York", 20000, "Computer Science");
        Manager m = new Manager("Jack", 35, 1234567890, "New York", 30000, "Computer Science");

        e.printAll();
        o.printAll();
        m.printAll();
    }
}
