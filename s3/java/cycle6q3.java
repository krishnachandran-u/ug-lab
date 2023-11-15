/*
    author: krishnachandran-u
    github: https://github.com/krishnachandran-u
    text-editor: NVIM v0.9.1
*/

import java.util.Scanner;



class cycle6q3.java{
    String[] a = new String[100];

    public int split(int begin, int end){
        int pvt = a[begin];
        int cnt = 0;
        for(int i = begin + 1; i <= end; i++){

        }
    }

    
    public void quicksort(int begin, int end){
        if(begin >= end) return;

        int p = split(begin, end);
        quicksort(begin, p - 1);
        quicksort(p + 1, end);
    }

    public
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("n: ");
        int n = sc.nextInt();   
        System.out.println("enter element: ");
        for(int i = 0; i < n; i++){
            this.a[i] = sc.next();
        }
        quicksort(0, n - 1);
        for(int i = 0; i < n; i++){
            System.out.print(this.a[i] + " ");
        }
        System.out.println();
        return;
    }
}
