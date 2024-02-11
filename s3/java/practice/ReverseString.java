import java.util.Scanner; 

class ReverseString {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String s = sc.next(); 
        String r = "";
        for(int i = s.length() - 1; i >= 0; i--) {
            r += s.charAt(i);
        }
        System.out.println("Reverse " + s + ": " + r);
        return;
    }
}
