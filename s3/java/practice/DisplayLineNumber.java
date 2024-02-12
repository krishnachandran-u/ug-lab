import java.io.BufferedReader;
import java.io.FileReader;

class DisplayLineNumber {
    public static void main(String args[]) {
        String input = "input.txt";
        String output = "output.txt";

        try {
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));
            int count = 1;
            String line;
            while((line = br.readLine()) != null) {
                System.out.println(count++ + ". " + line);
            }
            br.close();
        }
        catch(Exception e) {
            System.out.println(e);
        }
        return;
    }
}
