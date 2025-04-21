#include <iostream>
#include <string>
#include <math.h>


using namespace std;

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

    void printP() const {
        cout << "x = " << x << "; y = " << y << "; z = " << z << "." << endl;
    }

   

};

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
 double getLenght() const { return length; }
 
 void updateLength () {
  length = sqrt(pow(p.getX() - x, 2) + pow(p.getY() - y, 2) + pow(p.getZ() - z, 2));
 }
 
 void setpX(int newX) { p.setX(newX); updateLength();}
 void setpY(int newY) { p.setY(newY); updateLength();}
 void setpZ(int newZ) { p.setZ(newZ); updateLength();}

 
 void printL() const {
  cout<< "1st point: "<<x<<", "<<y<<", "<<z<<". 2nd point: "<<p.getX()<<", "<<p.getY()<<", "<<p.getZ()<<". Length: "<<length<<endl;
 }
 
};

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
            area = -1; // криво
        }
    }


};

class Parallelepiped: public Rectangle {
private:
    Point p5, p6, p7, p8;
    double volume;
public:
    Parallelepiped(): Rectangle(), p5(0,0,0), p6(0,0,0), p7(0,0,0), p8(0,0,0), volume(0) {}
    Parallelepiped(int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4, int x5, int y5, int z5, int x6, int y6, int z6, int x7, int y7, int z7, int x8, int y8, int z8): Rectangle(x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4), p5(x5,y5,z5), p6(x6,y6,z6), p7(x7,y7,z7), p8(x8,y8,z8) { updateVolume(); }

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

    void setP5X(int newX) { p5.setX(newX); updateVolume(); }
    void setP5Y(int newY) { p5.setY(newY); updateVolume(); }
    void setP5Z(int newZ) { p5.setZ(newZ); updateVolume(); }

    void setP6X(int newX) { p6.setX(newX); updateVolume(); }
    void setP6Y(int newY) { p6.setY(newY); updateVolume(); }
    void setP6Z(int newZ) { p6.setZ(newZ); updateVolume(); }

    void setP7X(int newX) { p7.setX(newX); updateVolume(); }
    void setP7Y(int newY) { p7.setY(newY); updateVolume(); }
    void setP7Z(int newZ) { p7.setZ(newZ); updateVolume(); }

    void setP8X(int newX) { p8.setX(newX); updateVolume(); }
    void setP8Y(int newY) { p8.setY(newY); updateVolume(); }
    void setP8Z(int newZ) { p8.setZ(newZ); updateVolume(); }

    double getVolume() const { return volume; }
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
            volume = -1;
            return;
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

    void printParallelepiped() const {
        cout << "Points of the parallelepiped:" << endl;
        cout << "P1: " << getX() << ", " << getY() << ", " << getZ() << endl;
        cout << "P2: " << getpX() << ", " << getpY() << ", " << getpZ() << endl;
        cout << "P3: " << getP3X() << ", " << getP3Y() << ", " << getP3Z() << endl;
        cout << "P4: " << getP4X() << ", " << getP4Y() << ", " << getP4Z() << endl;
        cout << "P5: " << p5.getX() << ", " << p5.getY() << ", " << p5.getZ() << endl;
        cout << "P6: " << p6.getX() << ", " << p6.getY() << ", " << p6.getZ() << endl;
        cout << "P7: " << p7.getX() << ", " << p7.getY() << ", " << p7.getZ() << endl;
        cout << "P8: " << p8.getX() << ", " << p8.getY() << ", " << p8.getZ() << endl;
        cout << "Volume: " << volume << endl;
    }
};

int main() {
    // Создаем прямоугольный параллелепипед 3x4x5
    Parallelepiped par(
        0, 0, 0,  // A (нижнее основание)
        3, 0, 0,  // B
        3, 4, 0,  // C
        0, 4, 0,  // D
        0, 0, 5,  // E (верхнее основание)
        3, 0, 5,  // F
        3, 4, 5,  // G
        0, 4, 5   // H
    );

    cout << "Volume: " << par.getVolume() << endl; // Должно быть 60 (3*4*5)
    par.printParallelepiped();

    return 0;
}