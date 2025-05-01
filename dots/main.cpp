#include <iostream>
#include <string>
#include <math.h>
#include <fstream>


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

    void print_product() const{ 
        cout << "X coord: " << x << "\n" << "Y coord: " << y << "\n" << "Z coord: " << z << std::endl;
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

 
 void print_product() const {
    cout << "X_1 coord: " << getX() << "\n"
    << "Y_1 coord: " << getY() << "\n"
    << "Z_1 coord: " << getZ() << "\n"

    << "X_2 coord: " << p.getX() << "\n"
    << "Y_2 coord: " << p.getY() << "\n"
    << "Z_2 coord: " << p.getZ() << "\n"

    << "Length: " << getLenght() << endl;
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
    void print_product() const
    {
        cout << "X_3 coord: " << p3.getX() << "\n"
        << "Y_3 coord: " << p3.getY() << "\n"
        << "Z_3 coord: " << p3.getZ() << "\n"

        << "X_4 coord: " << p4.getX() << "\n"
        << "Y_4 coord: " << p4.getY() << "\n"
        << "Z_4 coord: " << p4.getZ() << "\n"

        << "Area: " << getArea() << endl;
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

// Перечисление для поставщиков
enum plugs {
    plug1,  // Поставщик 1
    plug2,  // Поставщик 2
    plug3   // Поставщик 3
};

// Функция для преобразования значения перечисления в строку
string plugToString(plugs plug) {
    switch (plug) {
        case plug1: return "HERONWATER";  // Возвращаем строку для plug1
        case plug2: return "PLAYBOI CARTI";  // Возвращаем строку для plug2
        case plug3: return "BABY CUTE";  // Возвращаем строку для plug3
        default: return "Unknown";  // Возвращаем "Unknown" для неизвестных значений
    }
}

// Класс "Товар"
class Product {
private:
    int id;       // Уникальный идентификатор товара
    string name;  // Название товара
    int price;    // Цена товара
    plugs plug;   // Поставщик товара

public:
    // Конструктор по умолчанию
    Product() : id(0), name("null"), price(0), plug(plug1) {}

    // Параметризованный конструктор
    Product(int a, string b, int c, plugs d) : id(a), name(b), price(c), plug(d) {}

    // Конструктор копирования
    Product(const Product& other) : id(other.id), name(other.name), price(other.price), plug(other.plug) {}

    // Геттеры
    int getId() const { return id; }
    string getName() const { return name; }
    int getPrice() const { return price; }
    plugs getPlug() const { return plug; }

    // Сеттеры
    void setId(int newId) { id = newId; }
    void setName(string newName) { name = newName; }
    void setPrice(int newPrice) { price = newPrice; }
    void setPlug(plugs newPlug) { plug = newPlug; }

    // Метод для вывода краткой информации о товаре
    void printShort() const {
        cout << "ID: " << id << ", Name: " << name << ", Price: " << price << ", Plug: " << plugToString(plug) << endl;
    }

    // Метод для вывода подробной информации о товаре
    void printDetailed() const {
        cout << "Product with ID " << id << " called " << name 
             << ". Cost price is " << price << " and the supplier is " << plugToString(plug) << "." << endl;
    }

    // Метод для сохранения информации о товаре в файл
    void saveToFile(ofstream& file) const {
        file << id << " " << name << " " << price << " " << plug << endl;
    }
};

// Структура "Узел" для двусвязного списка
template <typename T>
class Node {
public:
    T tovar;
    Node* prev;
    Node* next;

    Node(T new_tovar) : tovar(new_tovar), prev(nullptr), next(nullptr) {}
};

// Класс "Список товаров"
template <typename F>
class List {
private:
    Node<F>* head;
    Node<F>* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    List(const List& other) : head(nullptr), tail(nullptr) {
        Node<F>* temp = other.head;
        while (temp) {
            addProduct(temp->tovar);
            temp = temp->next;
        }
    }

    List(List&& other) noexcept : head(other.head), tail(other.tail) {
        other.head = nullptr;
        other.tail = nullptr;
    }

    ~List() {
        while (head) {
            Node<F>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addProduct(const F& product) {
        Node<F>* newNode = new Node<F>(product);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteProduct(int productId) {
        Node<F>* temp = head;
        while (temp) {
            if (temp->tovar.getId() == productId) {
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                if (temp == head) head = temp->next;
                if (temp == tail) tail = temp->prev;
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    void sortByPrice() {
        if (!head || !head->next) return;
        bool swapped;
        do {
            swapped = false;
            Node<F>* temp = head;
            while (temp->next) {
                if (temp->tovar.getPrice() > temp->next->tovar.getPrice()) {
                    swap(temp->tovar, temp->next->tovar);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }

    void sortByName() {
        if (!head || !head->next) return;
        bool swapped;
        do {
            swapped = false;
            Node<F>* temp = head;
            while (temp->next) {
                if (temp->tovar.getName() > temp->next->tovar.getName()) {
                    swap(temp->tovar, temp->next->tovar);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }

    void sortByPlug() {
        if (!head || !head->next) return;
        bool swapped;
        do {
            swapped = false;
            Node<F>* temp = head;
            while (temp->next) {
                if (temp->tovar.getPlug() > temp->next->tovar.getPlug()) {
                    swap(temp->tovar, temp->next->tovar);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }

    void filterByPrice(int maxPrice) const {
        Node<F>* temp = head;
        while (temp) {
            if (temp->tovar.getPrice() <= maxPrice) {
                temp->tovar.printShort();
            }
            temp = temp->next;
        }
    }

    void filterByName(const string& name) const {
        Node<F>* temp = head;
        while (temp) {
            if (temp->tovar.getName() == name) {
                temp->tovar.printShort();
            }
            temp = temp->next;
        }
    }

    void filterByPlug(plugs filterPlug) const {
        Node<F>* temp = head;
        while (temp) {
            if (temp->tovar.getPlug() == filterPlug) {
                temp->tovar.printShort();
            }
            temp = temp->next;
        }
    }

    List<F> createSublistByPlug(plugs filterPlug) const {
        List<F> sublist;
        Node<F>* temp = head;
        while (temp) {
            if (temp->tovar.getPlug() == filterPlug) {
                sublist.addProduct(temp->tovar);
            }
            temp = temp->next;
        }
        return sublist;
    }

    List<F> createSublistByPrice(int maxPrice) const {
        List<F> sublist;
        Node<F>* temp = head;
        while (temp) {
            if (temp->tovar.getPrice() <= maxPrice) {
                sublist.addProduct(temp->tovar);
            }
            temp = temp->next;
        }
        return sublist;
    }

    List<F> createSublistByName(const string& name) const {
        List<F> sublist;
        Node<F>* temp = head;
        while (temp) {
            if (temp->tovar.getName() == name) {
                sublist.addProduct(temp->tovar);
            }
            temp = temp->next;
        }
        return sublist;
    }

    void printListShort() const {
        Node<F>* temp = head;
        while (temp) {
            temp->tovar.printShort();
            temp = temp->next;
        }
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (!file) {
            cerr << "Error opening file for writing!" << endl;
            return;
        }
        Node<F>* temp = head;
        while (temp) {
            temp->tovar.saveToFile(file);
            temp = temp->next;
        }
        file.close();
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file for reading!" << endl;
            return;
        }

        while (head) {
            Node<F>* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;

        int id, price, plug;
        string name;
        while (file >> id >> name >> price >> plug) {
            F newProduct(id, name, price, static_cast<plugs>(plug));
            addProduct(newProduct);
        }

        file.close();
    }
};

// Основная функция
int main() {
    List<Product> products;
    // Добавляем товары в список
    products.addProduct(Product(1, "Ahaha", 500, plug1));
    products.addProduct(Product(2, "Ohoho", 1500, plug2));
    products.addProduct(Product(3, "Ihihi", 300, plug3));
    products.addProduct(Product(4, "Aboba", 700, plug1));

    cout << "Original list:" << endl;
    products.printListShort();  // Выводим список товаров
    
    products.sortByName();  // Сортируем список по имени
    cout << "\nSorted by name:" << endl;
    products.printListShort();

    products.sortByPrice();  // Сортируем список по цене
    cout << "\nSorted by price:" << endl;
    products.printListShort();
    
    cout << "\nFiltered by price <= 700:" << endl;
    products.filterByPrice(700);  // Фильтруем список по цене
    
    cout << "\nFiltered by plug1:" << endl;
    products.filterByPlug(plug1);  // Фильтруем список по поставщику
    
    cout << "\nSublist with plug1:" << endl;
    List sublist = products.createSublistByPlug(plug1);  // Создаем подсписок по поставщику
    sublist.printListShort();
    
    cout << "\nSublist with price <= 700:" << endl;
    List sublist2 = products.createSublistByPrice(700);  // Создаем подсписок по цене
    sublist2.printListShort();
    
    products.deleteProduct(2);  // Удаляем товар с ID 2
    cout << "\nList after deleting product with ID 2:" << endl;
    products.printListShort();
    
    products.saveToFile("products.txt");  // Сохраняем список в файл
    cout << "\nProducts saved to file." << endl;
    
    return 0;
}

// int main() {
//     // Создаем прямоугольный параллелепипед 3x4x5
//     Parallelepiped par(
//         0, 0, 0,  // A (нижнее основание)
//         3, 0, 0,  // B
//         3, 4, 0,  // C
//         0, 4, 0,  // D
//         0, 0, 5,  // E (верхнее основание)
//         3, 0, 5,  // F
//         3, 4, 5,  // G
//         0, 4, 5   // H
//     );

//     cout << "Volume: " << par.getVolume() << endl; // Должно быть 60 (3*4*5)
//     par.printParallelepiped();

//     return 0;
// }