/*
    author: krishnachandran-u
    github: https://github.com/krishnachandran-u
    text-editor: NVIM v0.9.1
*/

import java.util.Scanner;

class cycle6q2{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int[] a = new int[100];
        System.out.print("n: "); int n = sc.nextInt();
        System.out.println("enter elements: ");
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt(); 
        }
        System.out.print("x: ");
        int x = sc.nextInt();
        int l = -1, r = n;
        while(r - l > 1){
            int m = l + (r - l)/2;
            if(a[m] <= x) l = m;
            else r = m;
        }
        if(l > -1 && a[l] == x){
            System.out.println("found at " + l);
        }
        else{
            System.out.println("not found\n");
        }
        return;
    }
}
