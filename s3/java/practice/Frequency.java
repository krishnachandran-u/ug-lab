import java.util.Scanner;

class Frequency {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String s = sc.next();
        System.out.print("Enter the character: ");
        char c = sc.next().charAt(0);
        int count = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == c) count++;
        }
        System.out.println("Count of " + c + " in " + s + " = " + count);
        return;
    }
}
