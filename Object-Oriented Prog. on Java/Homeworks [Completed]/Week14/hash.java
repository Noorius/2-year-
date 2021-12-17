import java.util.*;

public class hash {
	public static void main(String[] args) {
        Map<String, Integer> m = new HashMap<String, Integer>();
        for(int i=65; i<=100; i++){
            String c = ""+(char)i;
            m.put(c, i);
        }

        while(true){
            Scanner in = new Scanner(System.in);
            String input = in.next();
            if(m.containsKey(input)){
                System.out.println("Your key contains mapping: ");
                System.out.println(input+" "+m.get(input));
                System.out.println("-----------------------------");
            }else{
                System.out.println("This key is not in the map. Try another key");
            }
        }

    }
}
/*
Write a Java program to test if a map contains a mapping for the specified key
*/