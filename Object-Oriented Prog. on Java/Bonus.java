package OOP;

import java.util.*;

public class Bonus {
    public static void main(String[] args) {
        Map<String, String> m = new HashMap<String, String>();

        System.out.println("Zhetessov Nur M.");
        m.put("light","light"); // 1
        m.put("cat","cat");     // 2
        m.put("pitbull","dog");
        m.put("kitten","cat");
        m.put("dog","puppy");
        m.put("red","red");     //3

        int cnt = 0;
        for(String key : m.keySet()){
            if(m.get(key) == key){
                System.out.println(m.get(key)+" "+key);
                cnt++;
            }
                
        }
        System.out.println("Equal elements are "+cnt);


    }
}
