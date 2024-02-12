import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;

class ReaderWriter {
    public static void main(String args[]) {
        String inputFile = "input.txt";
        String outputFile = "output.txt";

        try {
            BufferedReader br = new BufferedReader(new FileReader(inputFile));
            BufferedWriter bw = new BufferedWriter(new FileWriter(outputFile));

            String line;

            while((line = br.readLine()) != null) {
                bw.write(line);
                bw.newLine();
            }

            bw.close();
            br.close();
            return;
        }
        catch(Exception e) {
            System.out.println(e);
        }
        return;
    }
}
