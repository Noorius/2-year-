package OOP.Project;

import java.util.*;
import java.io.*;

class Position{
    private int r, c;

    public Position(int x, int y) {
        this.r = y;
        this.c = x;
    }
    public void setX(int x){
        this.c = x;
    }
    public void setY(int y){
        this.r = y;
    }
    public int getX(){
        return this.c;
    }
    public int getY(){
        return this.r;
    }
    public boolean equals(Position pos){
        return this.c == pos.getX() && this.r == pos.getY();
    }
    public String toString(){
        return "("+this.c+","+this.r+")";
    }
}

interface Player{
    public void setMap(Map map);
    public void moveRight();
    public void moveLeft();
    public void moveUp();
    public void moveDown();
    public Position getPosition();
}

class MyPlayer implements Player{
    Position position;
    Map map;

    public void setMap(Map map){
        this.map = map;
        this.position = new Position(map.pl_pos.getX(), map.pl_pos.getY());
    }
    public void moveRight(){
        if(position.getX()+1<map.getSize() && !map.getValueAt(position.getY(), position.getX()+1).equals("1"))
            position.setX(position.getX() + 1);
    }
    public void moveLeft(){
        if(position.getX()-1>=0 && !map.getValueAt(position.getY(), position.getX()-1).equals("1"))
            position.setX(position.getX() - 1);
    }
    public void moveUp(){
        if(position.getY()-1>=0 && !map.getValueAt(position.getY()-1, position.getX()).equals("1"))
            position.setY(position.getY() - 1);
    }
    public void moveDown(){
        if(position.getY()+1<map.getSize() && !map.getValueAt(position.getY()+1, position.getX()).equals("1"))
            position.setY(position.getY() + 1);
    }
    public Position getPosition(){
        return position;
    }
}

class Map{
    private String[][] a;
    private int n;
    public Position pl_pos;
    public Map(Scanner in) throws InvalidMapException{
        n = in.nextInt();
        if(n == 0){throw new InvalidMapException("Map size can not be zero");}
        a = new String[n][n];
        try{
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    a[i][j] = in.next();
                    if(a[i][j].equals("P")){
                        this.pl_pos = new Position(j,i);
                    }
                }
            }
        }catch (Exception e){
            throw new InvalidMapException("Not enough map elements");
        }
    }
    public int getSize(){
        return this.n;
    }
    public String getValueAt(int x, int y){
        return this.a[x][y];
    }
    public void print(){
        for(int i = 0; i < this.n; i++){
            for(int j = 0; j < this.n; j++){
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        }
    }

}

class InvalidMapException extends Exception{
    public InvalidMapException(String m){
        super(m);
        //System.out.println("")
    }
}

class Game{
    Map map;
    Player player;
    public Game(Map map){
        this.map = map;
    }
    public void setMap(Map m){
        this.map = m;
        this.player.setMap(this.map);
    }
    public void addPlayer(Player p){
        this.player = p;
        this.player.setMap(this.map);
    }
}


public class Solution{
    public static void main(String[] args) throws FileNotFoundException, InvalidMapException{
        Scanner input = new Scanner(System.in);
        String className = input.nextLine();
        
        // Checking the implementation of the Position class
        if(className.equals("Position")){
            Position p1 = new Position(input.nextInt(), input.nextInt());
            System.out.println(p1);
            p1.setX(5);
            System.out.println(p1.getX());
            
            Position p2 = new Position(5, 10);
            System.out.println(p1.equals(p2));            
        }
        
        // Checking the implementation of the Map class
        else if(className.equals("Map")){
            try{
                Map map = new Map(input);
                map.print();
                int size = map.getSize();
                System.out.println(size);		
                System.out.println(map.getValueAt(size/2, size/2)); 
            }
            catch(Exception e){}
        }
        
        // Checking the Player interface and the MyPlayer class
        else if(className.equals("Player")){
            Player player = new MyPlayer();
            System.out.println(Player.class.isInterface());  
            System.out.println(player instanceof Player);
            System.out.println(player instanceof MyPlayer);
        }
        
        // Checking the InvalidMapException class
        else if(className.equals("Exception")){
            try{
                throw new InvalidMapException("Some message");
            }
            catch(InvalidMapException e){
                System.out.println(e.getMessage());
            }
        }
        
        // Checking the Game class and all of its components
        else if(className.equals("Game")){
            
            // Initialize player, map, and the game
            Player player = new MyPlayer();
            Game game = null;

            try{
                game = new Game(new Map(input));
            }
            catch(InvalidMapException e){ // custom exception
                System.out.println(e.getMessage());
                System.exit(0);
            }

            game.addPlayer(player);

            // Make the player move based on the commands given in the input
            String moves = input.next();
            char move;
            for(int i=0; i<moves.length(); i++){
                move = moves.charAt(i);
                switch(move){
                    case 'R':
                        player.moveRight();
                        break;
                    case 'L':
                        player.moveLeft();
                        break;
                    case 'U':
                        player.moveUp();
                        break;
                    case 'D':
                        player.moveDown();
                        break;
                }
            }

            // Determine the final position of the player after completing all the moves above
            Position playerPosition = player.getPosition();
            System.out.println("Player final position");
            System.out.println("Row: " + playerPosition.getY());
            System.out.println("Col: " + playerPosition.getX());
    }  
}

}