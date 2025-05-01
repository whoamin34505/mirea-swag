#pragma once
#include "Point.h"
#include <cmath>


class Line : public Point {
    private:
     Point p;
     double length;
     
    public:
     Line(): Point(), p(0,0,0), length(0) {}
     
     Line(int x1, int y1, int z1, int x2, int y2, int z2): Point(x1,y1,z1), p(x2,y2,z2) { updateLength(); } 
     
     int getpX() const { return p.getX(); }
     int getpY() const { return p.getY(); }
     int getpZ() const { return p.getZ(); }
     double getLength() const { return length; }
     
     void updateLength () {
      length = sqrt(pow(p.getX() - x, 2) + pow(p.getY() - y, 2) + pow(p.getZ() - z, 2));
     }
     
     void setpX(int newX) { p.setX(newX); updateLength();}
     void setpY(int newY) { p.setY(newY); updateLength();}
     void setpZ(int newZ) { p.setZ(newZ); updateLength();}
    
     
     void printData() const {
        std::cout << "X_1 coord: " << getX() << "\n"
        << "Y_1 coord: " << getY() << "\n"
        << "Z_1 coord: " << getZ() << "\n"
    
        << "X_2 coord: " << p.getX() << "\n"
        << "Y_2 coord: " << p.getY() << "\n"
        << "Z_2 coord: " << p.getZ() << "\n"
    
        << "Length: " << getLength() << std::endl;
     }
     
    };