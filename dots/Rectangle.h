#pragma once
#include "Line.h"
#include "GeometryException.h"

class Rectangle: public Line {
    protected:
        Point p3, p4;
        double area;
    public:
        Rectangle(): Line(), p3(0,0,0), p4(0,0,0), area(0) {}
    
        Rectangle(int x1, int y1, int z1, int x2, int y2, int z2, 
            int x3, int y3, int z3, int x4, int y4, int z4) 
       : Line(x1,y1,z1,x2,y2,z2), p3(x3,y3,z3), p4(x4,y4,z4) {
       
       if (x3 < -1000 || x3 > 1000 || y3 < -1000 || y3 > 1000 || z3 < -1000 || z3 > 1000 ||
           x4 < -1000 || x4 > 1000 || y4 < -1000 || y4 > 1000 || z4 < -1000 || z4 > 1000) {
           throw InvalidPointException("Coordinates out of range [-1000, 1000]");
       }
       
       updateArea();
   }

        int getP3X() const { return p3.getX(); }
        int getP3Y() const { return p3.getY(); }
        int getP3Z() const { return p3.getZ(); }
        
        int getP4X() const { return p4.getX(); }
        int getP4Y() const { return p4.getY(); }
        int getP4Z() const { return p4.getZ(); }
    
        void setP3(const Point& p) {
            if (p.getX() < -1000 || p.getX() > 1000 ||
                p.getY() < -1000 || p.getY() > 1000 ||
                p.getZ() < -1000 || p.getZ() > 1000) {
                throw InvalidPointException("Coordinates out of range [-1000, 1000]");
            }
            p3 = p;
            updateArea();
        }
    
        void setP4(const Point& p) {
            if (p.getX() < -1000 || p.getX() > 1000 ||
                p.getY() < -1000 || p.getY() > 1000 ||
                p.getZ() < -1000 || p.getZ() > 1000) {
                throw InvalidPointException("Coordinates out of range [-1000, 1000]");
            }
            p4 = p;
            updateArea();
        }
    
        double getArea() const { 
            if (area <= 0) {
                throw InvalidRectangleException("Invalid rectangle - area must be positive");
            }
            return area; 
        }
        void updateArea() {
            // Координаты всех точек прямоугольника
            int Ax = getX(), Ay = getY(), Az = getZ();
            int Bx = getpX(), By = getpY(), Bz = getpZ();
            int Cx = p3.getX(), Cy = p3.getY(), Cz = p3.getZ();
            int Dx = p4.getX(), Dy = p4.getY(), Dz = p4.getZ();
        
            // Векторы AB и BC (стороны прямоугольника)
            int ABx = Bx - Ax, ABy = By - Ay;
            int BCx = Cx - Bx, BCy = Cy - By;
        
            
            if ((Az == Bz) && (Bz == Cz) && (Cz == Dz) && ((ABx * BCx + ABy * BCy) == 0)) {
                double lengthAB = sqrt(ABx*ABx + ABy*ABy);
                double lengthBC = sqrt(BCx*BCx + BCy*BCy);
                area = lengthAB * lengthBC;
            } else {
                throw InvalidRectangleException("All points must be in the same plane");
            }
        }
        void printData() const {
            std::cout << "P1: (" << getX() << ", " << getY() << ", " << getZ() << ")\n"
                      << "P2: (" << getpX() << ", " << getpY() << ", " << getpZ() << ")\n"
                      << "P3: (" << p3.getX() << ", " << p3.getY() << ", " << p3.getZ() << ")\n"
                      << "P4: (" << p4.getX() << ", " << p4.getY() << ", " << p4.getZ() << ")\n"
                      << "Area: " << getArea() << std::endl;
        }
    };