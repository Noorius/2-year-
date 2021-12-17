import java.io.*;
import java.util.*;


public class arrlist{
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);

        List<List<Integer>> arr = new ArrayList<>();
        
        int n = in.nextInt();
        for (int i = 0; i < n; i++){
            int siz = in.nextInt();
            List<Integer> temp = new ArrayList<>();
            for(int j=0; j<siz; j++){
                temp.add(in.nextInt());
            }
            arr.add(temp);
        }
        
        n = in.nextInt();
        for (int i = 0; i < n; i++){
            int mas = in.nextInt();
            int index = in.nextInt();
            try{
                System.out.println(arr.get(mas-1).get(index-1));
            }catch(Exception e){
                System.out.println("ERROR!");
            }
        }
    }
}