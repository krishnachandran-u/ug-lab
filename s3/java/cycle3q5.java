import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class cycle3q5 {
    public static void main(String[] args) {
        try {
            System.out.println("Enter a line of integers separated by spaces:");
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            String inputLine = reader.readLine();

            StringTokenizer tokenizer = new StringTokenizer(inputLine);

            int sum = 0;

            System.out.println("Individual integers:");
            while (tokenizer.hasMoreTokens()) {
                String token = tokenizer.nextToken();
                int number = Integer.parseInt(token);
                System.out.println(number);

                sum += number;
            }

            System.out.println("Sum of all integers: " + sum);
        } catch (IOException e) {
            System.out.println("An error occurred while reading input.");
            e.printStackTrace();
        } catch (NumberFormatException e) {
            System.out.println("Invalid input. Please enter valid integers.");
            e.printStackTrace();
        }
    }
}
