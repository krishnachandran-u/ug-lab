import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.IOException;

class cycle3q2{
    public static void main(String args[]){
        String inputfile = "input.txt";
        try{
            FileReader fileReader = new FileReader(inputfile);
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            String line;
            int cnt = 0;
            while((line = bufferedReader.readLine()) != null){
                System.out.print(++cnt + ". ");
                System.out.println(line); 
            }
            return;
        }
        catch(IOException e){
             System.err.println("Error: " + e.getMessage());
        }
        return;
    }
}
