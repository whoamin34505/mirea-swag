#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Rectangle.h"
#include "Parallelepiped.h"
#include "Product.h"
#include "List.h"

void testAll() {
    std::cout << "===== STARTING COMPREHENSIVE TESTS =====" << std::endl;

    // 1. Точка
    std::cout << "\n=== TESTING POINT ===" << std::endl;
    try {
        Point p1(10, 20, 30);
        std::cout << "Point created: ";
        p1.printData();
        
        p1.setX(100);
        p1.setY(200);
        p1.setZ(300);
        std::cout << "Modified point: ";
        p1.printData();
        
        try {
            Point p2(1500, 0, 0);
            std::cout << "ERROR: Invalid point created!" << std::endl;
        } catch (const InvalidPointException& e) {
            std::cout << "Correctly caught: " << e.what() << std::endl;
        }
    } catch (...) {
        std::cout << "Unexpected error in Point tests!" << std::endl;
    }

    // 2. Линия
    std::cout << "\n=== TESTING LINE ===" << std::endl;
    try {
        Line l1(0, 0, 0, 1, 1, 1);
        std::cout << "Line created. Length: " << l1.getLength() << std::endl;
        
        l1.setpX(2);
        l1.setpY(2);
        l1.setpZ(2);
        std::cout << "Modified line. New length: " << l1.getLength() << std::endl;
        
        try {
            Line l2(1, 1, 1, 1, 1, 1);
            std::cout << "ERROR: Zero-length line created!" << std::endl;
        } catch (const InvalidLineException& e) {
            std::cout << "Correctly caught: " << e.what() << std::endl;
        }
    } catch (...) {
        std::cout << "Unexpected error in Line tests!" << std::endl;
    }

    // 3. Прямоугольник
    std::cout << "\n=== TESTING RECTANGLE ===" << std::endl;
    try {
        Rectangle r1(0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0);
        std::cout << "Rectangle created. Area: " << r1.getArea() << std::endl;
        
        try {
            Rectangle r2(0,0,0, 1,1,0, 2,2,0, 3,3,0);
            std::cout << "ERROR: Invalid rectangle created!" << std::endl;
        } catch (const InvalidRectangleException& e) {
            std::cout << "Correctly caught: " << e.what() << std::endl;
        }
    } catch (...) {
        std::cout << "Unexpected error in Rectangle tests!" << std::endl;
    }

    // 4. Параллелепипед
    std::cout << "\n=== TESTING PARALLELEPIPED ===" << std::endl;
    try {
        Parallelepiped pp1(0,0,0, 1,0,0, 1,1,0, 0,1,0,
                          0,0,1, 1,0,1, 1,1,1, 0,1,1);
        std::cout << "Parallelepiped created. Volume: " << pp1.getVolume() << std::endl;
        
        try {
            Parallelepiped pp2(0,0,0, 1,0,0, 1,1,0, 0,1,0,
                             0,0,1, 2,0,1, 1,1,1, 0,1,1);
            std::cout << "ERROR: Invalid parallelepiped created!" << std::endl;
        } catch (const InvalidParallelepipedException& e) {
            std::cout << "Correctly caught: " << e.what() << std::endl;
        }
    } catch (...) {
        std::cout << "Unexpected error in Parallelepiped tests!" << std::endl;
    }

    // 5. Продукт
    std::cout << "\n=== TESTING PRODUCT ===" << std::endl;
    try {
        Product prod1(1, "Laptop", 999.99, plug1);
        std::cout << "Product created: ";
        prod1.printData();
        
        try {
            Product prod2(-1, "", -100, static_cast<plugs>(5));
            std::cout << "ERROR: Invalid product created!" << std::endl;
        } catch (const ProductException& e) {
            std::cout << "Correctly caught: " << e.what() << std::endl;
        }
    } catch (...) {
        std::cout << "Unexpected error in Product tests!" << std::endl;
    }

    // 6. Списки
    std::cout << "\n=== TESTING LISTS ===" << std::endl;
    try {
        List<Point> pointList;
        pointList.add(Point(1,2,3));
        pointList.add(Point(4,5,6));
        std::cout << "Point list contents:" << std::endl;
        pointList.print();
        
        List<Rectangle> rectList;
        rectList.add(Rectangle(0,0,0,1,0,0,1,1,0,0,1,0));
        std::cout << "Rectangle list contents:" << std::endl;
        rectList.print();
    } catch (...) {
        std::cout << "Unexpected error in List tests!" << std::endl;
    }

    std::cout << "\n===== ALL TESTS COMPLETED =====" << std::endl;
}

int main() {
    testAll();
    return 0;
}