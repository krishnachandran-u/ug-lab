interface Water {
    void swim();
}

interface Land {
    void walk();
}

class Amphibian implements Water, Land {
    public void swim() {
        System.out.println("Amphibian Swims");
    }
    public void walk() {
        System.out.println("Ampbhibian Walks");
    }
}

class Interfaces {
    public static void main(String args[]) {
        Amphibian amphibian = new Amphibian();

        amphibian.swim();
        amphibian.walk();

        return;
    }
}
