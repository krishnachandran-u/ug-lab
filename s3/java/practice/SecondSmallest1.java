import java.util.Scanner;
import java.util.ArrayList;

class SecondSmallest1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();

        if(n <= 1) System.out.println("Error: no sufficient elements");

        ArrayList<Integer> arrayList = new ArrayList<Integer>();

        for(int i = 0; i < n; i++) {
            int x = sc.nextInt();
            arrayList.add(x);
        }

        int smallest = Integer.MAX_VALUE;
        int secondSmallest = Integer.MAX_VALUE;

        for(int x: arrayList) {
            if(x < smallest) {
                secondSmallest = smallest;
                smallest = x;
            }
            else if(x < secondSmallest && x > smallest) {
                secondSmallest = x;
            }
        }

        int count = 0;
        for(int x: arrayList)
            if(x == smallest) count++;

        if(count == n) {
            System.out.println("No second smallest element found");
        }
        else if(count > 1) {
            System.out.println("Second smallest element: " + smallest);
        }
        else {
            System.out.println("Second smallest element: " + secondSmallest);
        }
    }
}
