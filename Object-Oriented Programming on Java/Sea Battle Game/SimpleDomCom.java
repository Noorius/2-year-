package Sea;
import java.util.Scanner;
import java.util.ArrayList;

public class SimpleDomCom {
    private ArrayList<String> locationCells;

    String checkYouself(String guess){
        int ind = locationCells.indexOf(guess);
        String result = "Miss";
        if(ind >= 0){
            locationCells.remove(ind);
            if(locationCells.isEmpty())
                result = "Destroyed";
            else    
                result = "Hit";
        } 
        return result;
    }

    void setLocationCells(ArrayList<String> loc){
        locationCells = loc;
    }

    public static void main(String[] args){
        SimpleDomCom dot = new SimpleDomCom();

        int randomnum = (int) (Math.random(1) * 10);

        int[] ships = {randomnum,randomnum+1,randomnum+2};
        dot.setLocationCells(ships);
        
        Scanner input = new Scanner(System.in);
        
        String res = "";
        while(res!="Destroyed"){
            String guess = input.next();
            res = dot.checkYouself(guess);
            System.out.println(res);
        }

    }
}
