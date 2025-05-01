#pragma once
#include "Rectangle.h"
#include "GeometryException.h"

class Parallelepiped: public Rectangle {
    private:
        Point p5, p6, p7, p8;
        double volume;
    public:
        Parallelepiped(): Rectangle(), p5(0,0,0), p6(0,0,0), p7(0,0,0), p8(0,0,0), volume(0) {}
        Parallelepiped(int x1, int y1, int z1, int x2, int y2, int z2, 
            int x3, int y3, int z3, int x4, int y4, int z4,
            int x5, int y5, int z5, int x6, int y6, int z6,
            int x7, int y7, int z7, int x8, int y8, int z8)
  : Rectangle(x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4), 
    p5(x5,y5,z5), p6(x6,y6,z6), p7(x7,y7,z7), p8(x8,y8,z8) {
  
  if (x5 < -1000 || x5 > 1000 || y5 < -1000 || y5 > 1000 || z5 < -1000 || z5 > 1000 ||
      x6 < -1000 || x6 > 1000 || y6 < -1000 || y6 > 1000 || z6 < -1000 || z6 > 1000 ||
      x7 < -1000 || x7 > 1000 || y7 < -1000 || y7 > 1000 || z7 < -1000 || z7 > 1000 ||
      x8 < -1000 || x8 > 1000 || y8 < -1000 || y8 > 1000 || z8 < -1000 || z8 > 1000) {
      throw InvalidPointException("Coordinates out of range [-1000, 1000]");
  }
  
  updateVolume();
}
    

        int getP5X() const { return p5.getX(); }
        int getP5Y() const { return p5.getY(); }
        int getP5Z() const { return p5.getZ(); }
    
        int getP6X() const { return p6.getX(); }
        int getP6Y() const { return p6.getY(); }
        int getP6Z() const { return p6.getZ(); }
    
        int getP7X() const { return p7.getX(); }
        int getP7Y() const { return p7.getY(); }
        int getP7Z() const { return p7.getZ(); }
    
        int getP8X() const { return p8.getX(); }
        int getP8Y() const { return p8.getY(); }
        int getP8Z() const { return p8.getZ(); }


        void setP5(const Point& p) {
            if (p.getX() < -1000 || p.getX() > 1000 ||
                p.getY() < -1000 || p.getY() > 1000 ||
                p.getZ() < -1000 || p.getZ() > 1000) {
                throw InvalidPointException("Coordinates out of range [-1000, 1000]");
            }
            p5 = p;
            updateVolume();
        }

        void setP6(const Point& p) {
            if (p.getX() < -1000 || p.getX() > 1000 ||
                p.getY() < -1000 || p.getY() > 1000 ||
                p.getZ() < -1000 || p.getZ() > 1000) {
                throw InvalidPointException("Coordinates out of range [-1000, 1000]");
            }
            p6 = p;
            updateVolume();
        }

        void setP7(const Point& p) {
            if (p.getX() < -1000 || p.getX() > 1000 ||
                p.getY() < -1000 || p.getY() > 1000 ||
                p.getZ() < -1000 || p.getZ() > 1000) {
                throw InvalidPointException("Coordinates out of range [-1000, 1000]");
            }
            p7 = p;
            updateVolume();
        }

        void setP8(const Point& p) {
            if (p.getX() < -1000 || p.getX() > 1000 ||
                p.getY() < -1000 || p.getY() > 1000 ||
                p.getZ() < -1000 || p.getZ() > 1000) {
                throw InvalidPointException("Coordinates out of range [-1000, 1000]");
            }
            p8 = p;
            updateVolume();
        }
    
    
        double getVolume() const { 
            if (volume < 0) {
                throw InvalidParallelepipedException("Invalid parallelepiped - volume cannot be negative");
            }
            return volume; 
        }
        void updateVolume() {
            // Получение координат всех 8 вершин. ABCD - вершины нижнего основания, EFGH - верхнего основания
            int Ax = getX(), Ay = getY(), Az = getZ();
            int Bx = getpX(), By = getpY(), Bz = getpZ();
            int Cx = getP3X(), Cy = getP3Y(), Cz = getP3Z();
            int Dx = getP4X(), Dy = getP4Y(), Dz = getP4Z();
            int Ex = p5.getX(), Ey = p5.getY(), Ez = p5.getZ();
            int Fx = p6.getX(), Fy = p6.getY(), Fz = p6.getZ();
            int Gx = p7.getX(), Gy = p7.getY(), Gz = p7.getZ();
            int Hx = p8.getX(), Hy = p8.getY(), Hz = p8.getZ();
    
            // Точке A соответствует точка E, точке B - F, точке C - G, точке D - H
            Rectangle base1(Ax, Ay, Az, Bx, By, Bz, Cx, Cy, Cz, Dx, Dy, Dz);
            Rectangle base2(Ex, Ey, Ez, Fx, Fy, Fz, Gx, Gy, Gz, Hx, Hy, Hz);
        
            if (base1.getArea() <= 0 || base2.getArea() <= 0) {
                throw InvalidParallelepipedException("Base area must be positive");
            }
        
            int AEx = Ex - Ax, AEy = Ey - Ay, AEz = Ez - Az; // AE - вектор, показывающий как смещается точка A в точку E
            
            // Проверяется, что верхнее основание (EFGH) является точной параллельной копией нижнего основания (ABCD), смещённой на вектор AE = (AEx, AEy, AEz)
            if ((Fx - Bx) != AEx || (Fy - By) != AEy || (Fz - Bz) != AEz ||
                (Gx - Cx) != AEx || (Gy - Cy) != AEy || (Gz - Cz) != AEz ||
                (Hx - Dx) != AEx || (Hy - Dy) != AEy || (Hz - Dz) != AEz) {
                volume = -1;
                return;
            }
            
            double height = sqrt(AEx*AEx + AEy*AEy + AEz*AEz);
            volume = base1.getArea() * height;
        }
    
        void printData() const {
            std::cout << "Points of the parallelepiped:" << std::endl;
            std::cout << "P1: " << getX() << ", " << getY() << ", " << getZ() << std::endl;
            std::cout << "P2: " << getpX() << ", " << getpY() << ", " << getpZ() << std::endl;
            std::cout << "P3: " << getP3X() << ", " << getP3Y() << ", " << getP3Z() << std::endl;
            std::cout << "P4: " << getP4X() << ", " << getP4Y() << ", " << getP4Z() << std::endl;
            std::cout << "P5: " << p5.getX() << ", " << p5.getY() << ", " << p5.getZ() << std::endl;
            std::cout << "P6: " << p6.getX() << ", " << p6.getY() << ", " << p6.getZ() << std::endl;
            std::cout << "P7: " << p7.getX() << ", " << p7.getY() << ", " << p7.getZ() << std::endl;
            std::cout << "P8: " << p8.getX() << ", " << p8.getY() << ", " << p8.getZ() << std::endl;
            std::cout << "Volume: " << volume << std::endl;
        }
    };