class ExceptionHandling {
    public static void main(String args[]) {
    System.out.println("Inside try block perform 2 / 0");
        try {
            System.out.println("Try block");
            System.out.println(2/0);
        }
        catch(ArithmeticException e) {
            System.out.println("Catch block");
            System.out.println(e);
        }
        finally {
            System.out.println("Finally block has been executed");
        }
        return;
    }
}
