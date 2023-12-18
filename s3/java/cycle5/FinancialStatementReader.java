import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class FinancialStatementReader {
    public static void main(String[] args) {
        String csvFile = "Financial Statements.csv";
        String line = "";
        String csvSplitBy = ",";
        int lineCount = 0;

        try (BufferedReader br = new BufferedReader(new FileReader(csvFile))) {
            while ((line = br.readLine()) != null && lineCount < 50) {
                String[] data = line.split(csvSplitBy);
                for (String record : data) {
                    System.out.print(record + " ");
                }
                System.out.println();
                lineCount++;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
