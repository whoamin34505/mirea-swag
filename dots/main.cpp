#include <iostream>
#include "List_point.h"
#include "List_line.h"
#include "List_rectangle.h"
#include "List_parall.h"
#include "Parallelepiped.h"


// int main() {

//     List<Product> products;
//     products.addProduct(Product(1, "Ahaha", 500, plug1));
//     products.addProduct(Product(2, "Ohoho", 1500, plug2));
//     products.addProduct(Product(3, "Ihihi", 300, plug3));
//     products.addProduct(Product(4, "Aboba", 700, plug1));

//     cout << "Original list:\n";
//     products.printListShort();

//     products.sortByName();
//     cout << "\nSorted by name:\n";
//     products.printListShort();

//     products.sortByPrice();
//     cout << "\nSorted by price:\n";
//     products.printListShort();

//     cout << "\nFiltered by price <= 700:\n";
//     products.filterByPrice(700);

//     cout << "\nFiltered by plug1:\n";
//     products.filterByPlug(plug1);

//     cout << "\nSublist with plug1:\n";
//     List<Product> sublist = products.createSublistByPlug(plug1);
//     sublist.printListShort();

//     cout << "\nSublist with price <= 700:\n";
//     List<Product> sublist2 = products.createSublistByPrice(700);
//     sublist2.printListShort();

//     products.deleteProductById(2);
//     cout << "\nList after deleting product with ID 2:\n";
//     products.printListShort();

//     products.saveToFile("products.txt");
//     cout << "\nProducts saved to file.\n";

//     return 0;
// }


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

//     std::cout << "Volume: " << par.getVolume() << std::endl; // Должно быть 60 (3*4*5)
//     par.printData();

//     return 0;
// }


int main() {
    List<Point> points;
    points.add(Point(1, 2, 3));
    List<Line> lines;
    lines.add(Line(1, 2, 3, 4, 5, 6));
    lines.saveToFile("lines.txt");
    lines.print();
    List<Parallelepiped> parallelepiped;
    Parallelepiped p1(0,0,0, 3,0,0, 3,4,0, 0,4,0,  // нижняя грань
        0,0,5, 3,0,5, 3,4,5, 0,4,5); // верхняя грань

// Создаем неправильный параллелепипед (некорректные точки)
Parallelepiped p2(0,0,0, 1,0,0, 1,1,0, 0,1,0,
        0,0,1, 2,0,1, 1,1,1, 0,1,1);

parallelepiped.add(p1);
parallelepiped.add(p2);

parallelepiped.print();

List<Rectangle> rectangle;
rectangle.add(Rectangle(1,0,0,1,0,2,1,2,3,4,5,6));
rectangle.print();

return 0;
}

