package Week8;

abstract class Shape {
    protected double area;
    public Shape(){
        area = 0;
    }

    abstract void Calculate_Area(); // pure virtual method

    void Print_Area(){ 
        System.out.println(this.getArea());
    }

    public void Display_Area(){ // simple method (must not be private or final since we will override it later)
        System.out.println(this.getArea());
    } 

    double getArea(){
        return area;
    }

}
