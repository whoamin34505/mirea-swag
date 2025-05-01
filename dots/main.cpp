#include <iostream>
#include "List_point.h"
#include "List_line.h"
#include "List_rectangle.h"
#include "List_parall.h"
#include "Parallelepiped.h"
#include "GeometryException.h"
#include "ProductException.h"

int main() {
    List<Point> p1;
    p1.add(Point(-1000,0,1)); // нет ошибки
    p1.print();

    Point p2(2000,0,1);
    p2.printData(); // есть ошибка
    return 0;
}