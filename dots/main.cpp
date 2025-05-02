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
    line.add(Line(1,1,1,0,0,0));
    line.saveToFile("file.txt");
    line.loadFromFile("file.txt");
    return 0;
}