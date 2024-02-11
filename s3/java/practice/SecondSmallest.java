import java.util.Scanner;
import java.util.ArrayList;

class SecondSmallest {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> arrayList = new ArrayList<Integer>();

        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();

        if(n <= 1) {
            System.out.println("Error: n must be greater than 1");
            return;
        }

        System.out.println("Enter the elements: ");
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++) {
            int x = sc.nextInt(); 
            arrayList.add(x); 
            if(arrayList.get(i) < min) min = arrayList.get(i);
        }


        int count = 0;
        for(int i = 0; i < n; i++) {
            if(arrayList.get(i) == min) count++;
        }

        

        if(count > 1) {
            System.out.println("Second smallest element: " + min);
            return;
        }

        int secondMin = Integer.MAX_VALUE;

        for(int i = 0; i < n; i++) {
            if(arrayList.get(i) > min && arrayList.get(i) < secondMin) secondMin = arrayList.get(i);
        }

        if(secondMin == Integer.MAX_VALUE) {
            System.out.println("Second smallest element not found");
        }
        else {
            System.out.println("Second smallest element: " + secondMin);
        }

        return;
    }
}
