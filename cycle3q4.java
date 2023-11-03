import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

class cycle3q4{
    public static void main(String args[]){
        String inputfile = "input.txt";
        String outputfile = "output.txt";
        try{
            FileReader fileReader = new FileReader(inputfile);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            FileWriter fileWriter = new FileWriter(outputfile);
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

            String line;

            while((line = bufferedReader.readLine()) != null){
                bufferedWriter.write(line);
                bufferedWriter.newLine();
            }

            bufferedReader.close();
            bufferedWriter.close();
        }

        catch(IOException e){
            System.err.println("Error: " + e.getMessage());
        }
    }
}
