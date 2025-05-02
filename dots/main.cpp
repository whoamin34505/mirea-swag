#include <iostream>
#include "List_point.h"
#include "List_line.h"
#include "List_rectangle.h"
#include "List_parall.h"
#include "List.h"

int main() {
    // List<Point> p1;
    // p1.add(Point(-1000,0,1)); // нет ошибки
    // p1.print();

    // Point p(1500, 0, 0); 

    // Point p2(1, 2, 3);
    // p2.setX(-2000);

    List<Line> line;
    try{
        line.add(Line(0,0,0,0,0,0));
        line.saveToFile("file.txt");
        line.loadFromFile("file.txt");
    }
    catch(const std::exception &e) {
        std::cout << e.what() << '\n';
    }
    
    try{
        Point p(1500, 0, 0); 
    }
    catch(const std::exception &e){
        std::cout << e.what() << '\n';
    }

    List<Point> p1;
    try{
        p1.add(Point(-1000,0,1));
        p1.print();
    }
    catch(const std::exception &e){
        std::cout<<e.what()<<'\n';
    }

    try{
        Point p2(1, 2, 3);
        p2.setX(-2000);
    }
    catch(const std::exception &e){
        std::cout<<e.what()<<'\n';
    }

    List<Product> product;
    try{
        product.add(Product(0,"",-999.0,plug1));
        product.print();
    }
    catch(const std::exception &e){
        std::cout<<e.what()<<'\n';
    }

    List<Rectangle> rec;
    try {
        rec.add(Rectangle(0,1,0,2,3,4,1,4,5,6,1,6));
        rec.print();
    }
    catch(const std::exception &e){
        std::cout<<e.what()<<'\n';
    }
    return 0;
}