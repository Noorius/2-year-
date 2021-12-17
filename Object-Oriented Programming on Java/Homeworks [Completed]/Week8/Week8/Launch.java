package Week8;

import Week8.Shape;

public class Launch {
    public static void main(String [] args){
        Shape circle = new Circle(10);
        circle.Print_Area();  // Printing: Circle area is 314.16

        Shape sq = new Square(5);
        sq.Display_Area(); // Displaying: Square area is 25.0

        Rectangle rec = new Rectangle(10,5);
        rec.Print_Area(); // Printting: Rectangle area is 50.0
    }
}
/* Instructions
Define a class Shape having an attribute Area and a pure virtual function Calculate_Area. Also
include following in this class.
? A constructor that initializes Area to zero.
? A method Display_Area() that display value of member variable ?Area?.
? A virtual method Print_Area() that display value of member variable ?Area?.
Now derive two classes from Shape; Circle having attribute radius, Square having attribute Length
and Rectangle having attributes Length and Breadth. Include following in each class.
? A constructor that takes values of member variables as argument.
? A method Display_Area() that overrides Display_Area() method of Shape class.
? A method Print_Area() that overrides Print_Area() method of Shape class.
? A method Calculate_Area() that calculates the area as follows:
Area of Circle= PI* Radius^2
Area of Square=Length^2
Area of Rectangle=Length*Breadth */
