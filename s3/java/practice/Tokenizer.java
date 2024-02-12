import java.util.StringTokenizer;
import java.util.Scanner;

class Tokenizer {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        StringTokenizer tz = new StringTokenizer(line, " ");

        int sum = 0;
        while(tz.hasMoreTokens()) {
            String token = tz.nextToken();
            int x = Integer.parseInt(token);
            System.out.println(x);
            sum += x;
        }

        System.out.println("Sum: " + sum);
        return;
    }
}
