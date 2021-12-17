package OOP.Collections;

import java.io.*;
import java.util.*;


public class Week13{
    
    public static void main(String[] args) throws FileNotFoundException{
        // English to Russian Dictionary
        Map<String,Integer> dic = new HashMap<String,Integer>();
        List<String> words = new ArrayList<>(Arrays.asList("Monday","Cat","Sky","Truck","Flag"));


        for(String w : words){ //Transfers to Dictionary with frequency 0
            dic.put(w, 0);
        }
        
        FileReader myfile = new FileReader("input.txt"); //Reads input
        
        Scanner in = new Scanner(myfile);

        while(in.hasNextLine()) {
            String word = in.nextLine();
            if(!words.contains(word)){ //Compares with ArrayList
                System.out.println("Sorry the word \""+word+"\" is not in the dictionary");
                continue;
            }
            int cnt = dic.get(word);
            dic.put(word, cnt+1);
        }   

        for(String key : dic.keySet()){
            System.out.println(key+" "+dic.get(key));
        }
        
//      Output:

//      Sorry the word "Hi" is not in the dictionary
//      Sorry the word "Water" is not in the dictionary
//      Sky 0
//      Monday 2
//      Cat 3
//      Truck 0
//      Flag 0
        
       in.close(); 
    }
    
}

/* Task:
Write a program that calculates the frequency of an input word 
by comparing that word with a list of strings. 
As a string list, you can select any words. */