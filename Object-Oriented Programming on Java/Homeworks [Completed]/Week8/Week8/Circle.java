package Week8;

public class Circle extends Shape{
    private double radius;

    public Circle(){
        this.radius = 1;
        this.Calculate_Area();
    }
    public Circle(double r){
        this.radius = r;
        this.Calculate_Area();
    }
    @Override 
    public void Display_Area(){
        
        System.out.println("Displaying: Circle area is "+this.getArea());
    }
    @Override
    void Print_Area(){ //virtual method (not final or private)
        System.out.println("Printing: Circle area is "+this.getArea());
    }

    void Calculate_Area(){
        this.area = Math.round(Math.PI*this.radius*this.radius*100.0)/100.0; 
    }

    public static void main(String [] args){
    }
}
