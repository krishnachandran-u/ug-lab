class Employee {
    public void display() { System.out.println("Name of the class is Employee"); }
    public void calcSalary() { System.out.println("Salary of the employee is 10000"); }
}

class Engineer extends Employee {
    public void display() { System.out.println("Name of the class is Engineer"); }
    public void calcSalary() { 
        super.calcSalary();
        System.out.println("Salary of the employee is 20000"); 
    }
}

class SingleObjectInstantiation {
    public static void main(String args[]) {
        Employee engineer = new Engineer();
        engineer.calcSalary();
        return;
    }
}
