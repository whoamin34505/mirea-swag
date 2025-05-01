#pragma once
#include <iostream>
#include "GeometryException.h"

class Point {
    protected:
        int x, y, z; 
    
    public:
        Point() : x(0), y(0), z(0) {}
    
        Point(int xx, int yy, int zz) {
            if (xx < -1000 || xx > 1000 || yy < -1000 || yy > 1000 || zz < -1000 || zz > 1000) {
                throw InvalidPointException("Coordinates out of range [-1000, 1000]");
            }
            x = xx; y = yy; z = zz;
        }
        
        int getX() const { return x; }
        int getY() const { return y; }
        int getZ() const { return z; }
    
        void setX(int newX) {
            if (newX < -1000 || newX > 1000) {
                throw InvalidPointException("X coordinate " + std::to_string(newX) + " out of range [-1000, 1000]");
            }
            x = newX;
        }
        void setY(int newY) {
            if (newY < -1000 || newY > 1000) {
                throw InvalidPointException("Y coordinate " + std::to_string(newY) + " out of range [-1000, 1000]");
            }
            y = newY;
        }
        void setZ(int newZ) {
            if (newZ < -1000 || newZ > 1000) {
                throw InvalidPointException("Z coordinate " + std::to_string(newZ) + " out of range [-1000, 1000]");
            }
            z = newZ;
        }
    
        void printData() const{ 
            std::cout << "X coord: " << x << "\n" << "Y coord: " << y << "\n" << "Z coord: " << z << std::endl;
        }
    };