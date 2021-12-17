import java.util.*;

public class subarrays{

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] a = new int[n];
        int val;
        for (int i = 0; i < n; i++) {
            val = scan.nextInt();
            a[i] = val;
        }
        
        val = 0;
        for (int i = 0; i < n; i++) {
            int sum = a[i];
            if(a[i]<0) val+=1;
            for (int j = i+1; j < n; j++) {
                sum += a[j];
                if(sum<0) val+=1;
            }
        }
        System.out.println(val);
        scan.close();
    }
}
