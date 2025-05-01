#pragma once
#include <iostream>

class Point {
    protected:
        int x, y, z; 
    
    public:
        Point() : x(0), y(0), z(0) {}
    
        Point(int xx, int yy, int zz) :x(xx), y(yy), z(zz) {}
        
        int getX() const { return x; }
        int getY() const { return y; }
        int getZ() const { return z; }
    
        void setX(int newX) { x = newX; }
        void setY(int newY) { y = newY; }
        void setZ(int newZ) { z = newZ; }
    
        void printData() const{ 
            std::cout << "X coord: " << x << "\n" << "Y coord: " << y << "\n" << "Z coord: " << z << std::endl;
        }
    };