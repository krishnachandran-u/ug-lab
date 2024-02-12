class TestClass {
    public int x; 
}

class GarbageCollector {
    public static void main(String args[]) {
        System.out.println("Allocated memory to reference");
        TestClass object = new TestClass();
        System.out.println("Make the reference point to null");
        object = null;
        System.out.println("Set the reference = null");
        System.out.println("Call garbage collector");
        System.gc();
        System.out.println("Garbage might have been collected");
        return;
    }
}
