import java.util.*;

class loop2{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            int p = 1;
            for(int j=0; j<n; j++){
                a+=p*b;
                System.out.printf("%d ",(a));
                p*=2;
            }
            System.out.println("");
        }
        in.close();
    }
}
