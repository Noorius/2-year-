package Sea;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Helper {
    public String getInput(String s){
        String inputLine = null;
        try{
            BufferedReader is = new BufferedReader(new InputStreamReader(System.in));
            inputLine = is.readLine();
            if(inputLine.length() == 0) return null;
        }catch(IOException eo){
            System.out.println(eo);
        }
        return inputLine;
    }
}
