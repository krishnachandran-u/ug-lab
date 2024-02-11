import java.util.Scanner;
import java.util.ArrayList;

class MatrixProduct {

    static ArrayList<ArrayList<Integer>> Product(ArrayList<ArrayList<Integer>> a, ArrayList<ArrayList<Integer>> b) {
        int row1 = a.size();
        int col1 = a.get(0).size();
        int row2 = b.size();
        int col2 = b.get(0).size();

        if(col1 != row2) {
            System.out.println("Inconsistent order");
            return null;
        }

        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();

        for(int i = 0; i < row1; i++) {
            ArrayList<Integer> row = new ArrayList<Integer>();
            for(int j = 0; j < col2; j++) {
                int x = 0;
                for(int k = 0; k < row2; k++) {
                    x += a.get(i).get(k)*b.get(k).get(j);
                }
                row.add(x);
            }
            res.add(row);
        }

        return res;
    }

    static ArrayList<ArrayList<Integer>> init(int row, int col) {
        Scanner sc = new Scanner(System.in);
        ArrayList<ArrayList<Integer>> matrix = new ArrayList<ArrayList<Integer>>();

        for(int i = 0; i < row; i++) {
            ArrayList<Integer> matrixRow = new ArrayList<Integer>();
            for(int j = 0; j < col; j++) {
                int x = sc.nextInt();
                matrixRow.add(x);
            }
            matrix.add(matrixRow);
        }

        return matrix;
    }

    static void display(ArrayList<ArrayList<Integer>> matrix) {
        for(ArrayList<Integer> row: matrix) {
            for(int x: row) {
                System.out.print(x + "  ");
            }
            System.out.println();
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int row, col;

        System.out.print("Enter the rows and columns of the matrix 1: ");
        row = sc.nextInt();
        col = sc.nextInt();

        System.out.println("Enter the elements: ");

        ArrayList<ArrayList<Integer>> matrix_a = init(row, col);

        System.out.print("Enter the rows and columns of the matrix 2: ");
        row = sc.nextInt();
        col = sc.nextInt();

        System.out.println("Enter the elements: ");
        
        ArrayList<ArrayList<Integer>> matrix_b = init(row, col);

        ArrayList<ArrayList<Integer>> product = Product(matrix_a, matrix_b);

        System.out.println("matrix_a"); display(matrix_a);
        System.out.println("matrix_b"); display(matrix_b);

        if(product != null) {
            System.out.println("product: "); display(product);
        }
        else {
            System.out.println("cannot find product");
        }

        return;
    }
}
