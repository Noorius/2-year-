package Week8;

public class Square extends Shape{
    double length;

    public Square(){
        this.length = 1;
        this.Calculate_Area();
    }
    public Square(double l){
        this.length = l;
        this.Calculate_Area();
    }

    @Override
    public void Display_Area(){
        System.out.println("Displaying: Square area is "+this.getArea());
    }
    @Override
    void Print_Area(){ //virtual method (not final or private)
        System.out.println("Printing: Square area is "+this.getArea());
    } 

    void Calculate_Area(){
        this.area = Math.round(this.length * this.length*100.0)/100.0; 
    }

    public static void main(String [] args){
    }
}
