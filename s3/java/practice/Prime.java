import java.util.Scanner;
import java.lang.Math;

class Prime {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ener the number: ");
        int x = sc.nextInt();
        for(int i = 2; i <= Math.sqrt(x); i++) {
            if(x % i == 0) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
        return;
    }
}
