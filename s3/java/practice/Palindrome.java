import java.util.Scanner;

class Palindrome {
    public static void main(String args[]) {
        Scanner sc =  new Scanner(System.in);
        System.out.print("Enter a string: ");
        String s = sc.next();
        int n = s.length();
        for(int i = 0; i < n/2; i++) {
            if(s.charAt(i) != s.charAt(n - i - 1)) {
                System.out.println("Not a palindrome");
                return;
            }
        }
        System.out.println("Yes a palindrome");
        return;
    }
}
