import java.util.Scanner;

class AgeException extends Exception {
    AgeException(String s) {
        super(s);
    }
}

class UserDefinedException {
    public static void main(String args[]) throws AgeException {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter age for voter card: ");  
        int age = sc.nextInt();

        if(age < 18) {
            throw new AgeException("Requires atleast 18 years of age");
        }
        else {
            System.out.println("Successful");
        }

        return;
    }
}
