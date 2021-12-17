

class Rectangle{

    int width;
    int length;
    string color;

    Rectangle(int w = 1,int l= 2,string c = "WHITE"){
        width = w;
        length = l;
        color = c;
    }

    int getPerimeter(){
        return 2 * (width + length);
    }
    int getArea(){
        return width * length;
    }

}

