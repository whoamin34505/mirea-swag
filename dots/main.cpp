#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Rectangle.h"
#include "Parallelepiped.h"
#include "Product.h"
#include "List.h"

int main() {
    List<Point> p1;
    p1.add(Point(-1000,0,1)); // нет ошибки
    p1.print();

    Point p(1500, 0, 0); 

    Point p2(1, 2, 3);
    p2.setX(-2000);
    return 0;
}