package Week8;

public class Rectangle extends Shape{
    double length, breadth;

    public Rectangle(){
        this.length = 1;
        this.breadth = 1;
        this.Calculate_Area();
    }
    public Rectangle(double l,double b){
        this.length = l;
        this.breadth = b;
        this.Calculate_Area();
    }

    @Override
    public void Display_Area(){
        System.out.println("Printting: Rectangle area is "+this.getArea());
    }
    @Override
    void Print_Area(){
        System.out.println("Printting: Rectangle area is "+this.getArea());
    }

    void Calculate_Area(){ //virtual method (not final or private)
        this.area = Math.round(this.length * this.breadth * 100.0)/100.0; 
    } 

    public static void main(String [] args){
    }
}
