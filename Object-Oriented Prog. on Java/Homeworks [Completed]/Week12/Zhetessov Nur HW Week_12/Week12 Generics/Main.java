import java.util.*;

public class Main {
    public static class FavoriteClasses<Type1, Type2, Type3> {
        private Type1 favorite1;
        private Type2 favorite2;
        private Type3 favorite3;

        FavoriteClasses(Type1 fav1, Type2 fav2, Type3 fav3) {
            this.favorite1 = fav1;
            this.favorite2 = fav2;
            this.favorite3 = fav3;
        }

        public Type1 getFav1() {
            return this.favorite1;
        }

        public Type2 getFav2() {
            return this.favorite2;
        }

        public Type3 getFav3() {
            return this.favorite3;
        }

    }

    public static void main(String[] args) {
        List<Double> r = new ArrayList<Double>();

        r.add(6.3);
        r.add(5.9);

        FavoriteClasses<String, Integer, Double> a = new FavoriteClasses<>("Hello", 67, r.get(0));

        System.out.println("My favorites are " + a.getFav1() + ", " + a.getFav2() + ", and " + a.getFav3() + ".");
    }
    // javac Main.java
    // java Main
}

/*
 * Fix the FavoriteClasses class to use generics for it's three variables,
 * favorite1, favorite2, and favorite3, it's constructor, and it's three
 * functions to return each variable, as well as fixing r in the main section.
 * 
 * Then define a variable of the FavoriteClasses class and use "Hello", 67, 6.3
 * as the arguments for the constructor, and when you define it use your
 * favorite classes/types that go with the three arguments.
 */