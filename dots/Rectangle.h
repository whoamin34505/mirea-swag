#pragma once
#include "Line.h"

class Rectangle: public Line {
    protected:
        Point p3, p4;
        double area;
    public:
        Rectangle(): Line(), p3(0,0,0), p4(0,0,0), area(0) {}
    
        Rectangle(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4): Line(x1, y1, z1, x2, y2, z2), p3(x3, y3, z3), p4(x4, y4, z4) { updateArea();}
        
        int getP3X() const { return p3.getX(); }
        int getP3Y() const { return p3.getY(); }
        int getP3Z() const { return p3.getZ(); }
        
        int getP4X() const { return p4.getX(); }
        int getP4Y() const { return p4.getY(); }
        int getP4Z() const { return p4.getZ(); }
    
        void setP3X(int newX) { p3.setX(newX); updateArea(); }
        void setP3Y(int newY) { p3.setY(newY); updateArea(); }
        void setP3Z(int newZ) { p3.setZ(newZ); updateArea(); }
        
        void setP4X(int newX) { p4.setX(newX); updateArea(); }
        void setP4Y(int newY) { p4.setY(newY); updateArea(); }
        void setP4Z(int newZ) { p4.setZ(newZ); updateArea(); }
    
        double getArea() const { return area; }
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
                area = -1; // возвращается -1 если не является прямоугольником
            }
        }
        void printData() const
        {
            std::cout << "X_3 coord: " << p3.getX() << "\n"
            << "Y_3 coord: " << p3.getY() << "\n"
            << "Z_3 coord: " << p3.getZ() << "\n"
    
            << "X_4 coord: " << p4.getX() << "\n"
            << "Y_4 coord: " << p4.getY() << "\n"
            << "Z_4 coord: " << p4.getZ() << "\n"
    
            << "Area: " << getArea() << std::endl;
        }
    };