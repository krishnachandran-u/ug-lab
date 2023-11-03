import java.io.FileWriter;
import java.io.FileReader;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.IOException;
import java.lang.Math;
import java.util.Scanner;

class cycle3q3{
    public static void main(String args[]){
        String inputfile = "input.txt";

        try{
            FileReader fileReader = new FileReader(inputfile);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
        
            String line;
            int chars = 0, words = 0, lines = 0;
            while((line = bufferedReader.readLine()) != null){
                lines++;
                chars += line.length();
                int spaces = 0;
                for(int i = 0; i < line.length(); i++){
                    if(line.charAt(i) == ' ') spaces++;
                }
                words += spaces + 1;
            }
            System.out.println("chars: " + chars);     
            System.out.println("words: " + words);
            System.out.println("lines: " + lines);

            return;
        }
        catch(IOException e){
             System.err.println("Error: " + e.getMessage());
        }
    }
}
