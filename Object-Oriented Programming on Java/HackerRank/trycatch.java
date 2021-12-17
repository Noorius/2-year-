import java.util.*;

public class trycatch{

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        try{
            int x = in.nextInt();
            int y = in.nextInt();
            System.out.println((int)(x/y));
        }catch(InputMismatchException e){
            System.out.println("java.util.InputMismatchException");
        }catch(Exception e){
            System.out.println(e.toString());
        }
    }
}
