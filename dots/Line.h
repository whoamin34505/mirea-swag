#pragma once
#include "Point.h"
#include <cmath>
#include "GeometryException.h"


class Line : public Point {
    private:
     Point p;
     double length;
     
    public:
     Line(): Point(), p(0,0,0), length(0) {}
     
     Line(int x1, int y1, int z1, int x2, int y2, int z2): Point(x1,y1,z1), p(x2,y2,z2) { 
        if (x1 < -1000 || x1 > 1000 || y1 < -1000 || y1 > 1000 || z1 < -1000 || z1 > 1000 ||
            x2 < -1000 || x2 > 1000 || y2 < -1000 || y2 > 1000 || z2 < -1000 || z2 > 1000) {
            throw InvalidPointException("Coordinates out of range [-1000, 1000]");
        }
        
        updateLength();
    } 


     
     int getpX() const { return p.getX(); }
     int getpY() const { return p.getY(); }
     int getpZ() const { return p.getZ(); }
     double getLength() const { return length; }
     
     void updateLength() {
      double newLength = sqrt(pow(p.getX() - x, 2) + pow(p.getY() - y, 2) + pow(p.getZ() - z, 2));
      if (newLength <= 0) {
          throw InvalidLineException("Length must be positive, " + std::to_string(newLength));
      }
      length = newLength;
  }
     
     void setpX(int newX) {
      if (newX < -1000 || newX > 1000) {
          throw InvalidPointException("X coordinate " + std::to_string(newX) + " out of range [-1000, 1000]");
      }
      p.setX(newX); updateLength();
   }
   void setpY(int newY) {
      if (newY < -1000 || newY > 1000) {
            throw InvalidPointException("Y coordinate " + std::to_string(newY) + " out of range [-1000, 1000]");
      }
      p.setY(newY); updateLength();
   }
   void setpZ(int newZ) {
      if (newZ < -1000 || newZ > 1000) {
          throw InvalidPointException("Z coordinate " + std::to_string(newZ) + " out of range [-1000, 1000]");
      }
      p.setZ(newZ); updateLength();
   }

    
     
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