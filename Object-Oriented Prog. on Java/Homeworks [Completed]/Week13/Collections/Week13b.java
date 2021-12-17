package OOP.Collections;

import java.io.*;
import java.util.*;


public class Week13b{
    
    public static void main(String[] args) throws FileNotFoundException{
        // English to Russian Dictionary
        
        List<Integer> numbers = new ArrayList<>();
        
        FileReader myfile = new FileReader("input2.txt"); //Reads input
        
        Scanner in = new Scanner(myfile);

        while(in.hasNextInt()) {
            int num = in.nextInt();
            if(num == 0) {break;}
            numbers.add(num);
        }   

        int check = in.nextInt();
        if(numbers.contains(check)) {
            System.out.println("It is one of the numbers that was read in.");
        }else{
            System.out.println("It is NOT the numbers that was read in.");
        }
//      Input:  100       
//      Output: It is NOT the numbers that was read in.

//      Input:  1
//      Output: It is one of the numbers that was read in.
        
       in.close();
    }
    
}

/* Task:
Write a program that reads in a series of numbers from the user until they enter “0”
and stores the numbers in aListofIntegers. 
Then ask the user for a number and report whether it is one of the numbers that was read in. */