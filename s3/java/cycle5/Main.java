import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Student {
    private int rollNo;
    private String name;
    private double cgpa;

    public Student(int rollNo, String name, double cgpa) {
        this.rollNo = rollNo;
        this.name = name;
        this.cgpa = cgpa;
    }

    public double getCgpa() {
        return cgpa;
    }

    @Override
    public String toString() {
        return "Roll No: " + rollNo + ", Name: " + name + ", CGPA: " + cgpa;
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("Fetching database...");

        Scanner scanner = new Scanner(System.in);
        List<Student> students = new ArrayList<>();

        System.out.print("Enter the number of students: ");
        int n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.println("Enter details for student " + (i + 1) + ":");
            System.out.print("Roll No: ");
            int rollNo = scanner.nextInt();
            System.out.print("Name: ");
            String name = scanner.next();
            System.out.print("CGPA: ");
            double cgpa = scanner.nextDouble();

            System.out.println("Storing data for student " + (i + 1) + "...");
            students.add(new Student(rollNo, name, cgpa));
        }

        System.out.println("Closing database connections...");

        System.out.println("Students with CGPA greater than 7:");
        for (Student student : students) {
            if (student.getCgpa() > 7) {
                System.out.println(student);
            }
        }
    }
}
