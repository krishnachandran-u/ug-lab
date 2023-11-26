/*
    author: krishnachandran-u
    github: https://github.com/krishnachandran-u
    text-editor: NVIM v0.9.1
*/
import java.util.Scanner;

class cycle6q4{
    static int[] a = new int[100];

    public static void swap(int i, int j){
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        return;
    }

    public static void heapify(int n, int i){
        int mx = i; 

        int l = 2*i + 1;
        int r = 2*i + 1;
    
        if(l < n && a[l] > a[mx]){
            mx = l;
        }

        if(r < n && a[r] > a[mx]){
            mx = r;
        }
        
        if(mx != i){
            swap(i, mx);
            heapify(n, mx);
        }
        return;
    }

    public static void sort(int n){
        for(int i = n/2 - 1; i >= 0; i--){            
            heapify(n, i);  
        }

        for(int i = n - 1; i > 0; i--){
            swap(i, 0);
            heapify(i, 0);
        }
        return;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int n; System.out.print("n: ");
        n = sc.nextInt();

        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }

        sort(n);

        for(int i = 0 ; i < n; i++){
            System.out.print(a[i] + " ");
        }
        
        System.out.println();
        return;
    }
}

