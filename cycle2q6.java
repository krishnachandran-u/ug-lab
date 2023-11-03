import java.util.Scanner;
import java.lang.Math;

class Gb{
    private String name;
    Gb(String name){
        this.name = name;
        System.out.println(name + " initialized");
    }
}

class cycle2q6{
    public static void main(String args[]){
        Gb ob = new Gb("steve");
        ob = null;
        System.gc();
        System.out.println("--end--");
        return;
    }
}
