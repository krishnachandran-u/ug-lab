import java.io.FileReader;
import java.io.BufferedReader;

class DisplayCount {
    public static void main(String args[]) {
        String input = "input.txt";    
        int totalCharacters = 0, lines = 0, totalWords = 0;

        try {
            BufferedReader br = new BufferedReader(new FileReader(input));
            String line;
            while((line = br.readLine()) != null) {
                int characters = 0; 
                int spaces = 0;
                for(int i = 0; i < line.length();) {
                    if(line.charAt(i) != ' ') {
                        characters++;
                        i++;
                    }
                    else {
                        while(line.charAt(i) == ' ' && i < line.length()) {
                            i++;
                        }
                        spaces++;
                    }
                }
                totalCharacters += characters;
                totalWords += spaces + 1;
                lines++;
            }
            br.close();
            System.out.println("Total characters: " + totalCharacters);
            System.out.println("Total words: " + totalWords);
            System.out.println("Total lines: " + lines);
            return;
        }
        catch(Exception e) {
            System.out.println(e);
        }
        return;
    }
}
