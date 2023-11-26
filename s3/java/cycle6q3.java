/*
    author: krishnachandran-u
    github: https://github.com/krishnachandran-u
    text-editor: NVIM v0.9.1
*/
import java.util.Scanner;

class cycle6q3{
    static String[] a = new String[100];

    public static void swap(int i, int j){
        String tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        return;
    }
    
    public static int split(int b, int e){
        String pvt = a[b];
        int cnt = 0;
        for(int i = b + 1; i <= e; i++){
            if(pvt.compareTo(a[i]) >= 0){
                cnt++; 
            }
        }
        int p = b + cnt;
        swap(b, p);
        for(int i = b, j = e; i < p && p < j;){
            while(i < p && a[i].compareTo(a[p]) <= 0) i++;
            while(j > p && a[j].compareTo(a[p]) > 0) j--;
            if(i < p && j < p){
                swap(i++, j--);
            }
        }
        return p;
    }

    public static void sort(int b, int e){
        if(b >= e) return;

        int p = split(b, e);

        sort(b, p - 1);
        sort(p + 1, e);
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int n; System.out.print("n: ");
        n = sc.nextInt();

        System.out.println("enter elements: ");
        for(int i = 0; i < n; i++){
            a[i] = sc.next();
        }

        sort(0, n - 1);

        for(int i = 0; i < n; i++){
            System.out.print(a[i] + "   ");
        }
        System.out.println();
        return;
    }
}

