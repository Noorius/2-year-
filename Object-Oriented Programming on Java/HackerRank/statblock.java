import java.util.*;

public class  statblock{

static int B, H;
static boolean flag = true;

static {
    Scanner in = new Scanner(System.in);
    B = in.nextInt();
    H = in.nextInt();
    if(B<=0 || H<=0){
        System.out.println("java.lang.Exception: Breadth and height must be positive");
        flag = false;
    }
    in.close();
}

public static void main(String[] args){
		if(flag){
			int area=B*H;
			System.out.print(area);
		}
		
	}//end of main

}//end of class
