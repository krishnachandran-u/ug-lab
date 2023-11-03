import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class cycle3q5{
    public static void main(String[] args) {
        try {
            // Read a line of integers from the user
            System.out.println("Enter a line of integers separated by spaces:");
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            String inputLine = reader.readLine();

            // Use StringTokenizer to tokenize the input line
            StringTokenizer tokenizer = new StringTokenizer(inputLine);

            // Variables to store the sum
            int sum = 0;

            // Display each integer and calculate the sum
            System.out.println("Individual integers:");
            while (tokenizer.hasMoreTokens()) {
                String token = tokenizer.nextToken();
                int number = Integer.parseInt(token);
                System.out.println(number);

                // Add the number to the sum
                sum += number;
            }

            // Display the sum of all integers
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

