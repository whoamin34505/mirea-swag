#include <iostream>
#include "List_point.h"
#include "List_line.h"
#include "List_rectangle.h"
#include "List_parall.h"
#include "Parallelepiped.h"
#include "GeometryException.h"

int main() {
        std::cout << "Testing Line class exceptions...\n\n";
    
        // Тест 1: Попытка создать линию нулевой длины
        try {
            std::cout << "Test 1: Creating zero-length line... ";
            Line zeroLine(1, 2, 3, 1, 2, 3); // Одинаковые точки
            std::cout << "FAILED (exception not thrown)\n";
        } 
        catch (const InvalidLineException& e) {
            std::cout << "PASSED: " << e.what() << "\n";
        }
        catch (...) {
            std::cout << "FAILED (wrong exception type)\n";
        }
    
        // Тест 2: Некорректная координата X
        try {
            std::cout << "Test 2: Setting invalid X coordinate... ";
            Line line;
            line.setpX(1500); // Выход за допустимые границы
            std::cout << "FAILED (exception not thrown)\n";
        }
        catch (const InvalidPointException& e) {
            std::cout << "PASSED: " << e.what() << "\n";
        }
        catch (...) {
            std::cout << "FAILED (wrong exception type)\n";
        }
    
        // Тест 3: Некорректная координата Y
        try {
            std::cout << "Test 3: Setting invalid Y coordinate... ";
            Line line(0, 0, 0, 1, 1, 1);
            line.setpY(-1500); // Выход за допустимые границы
            std::cout << "FAILED (exception not thrown)\n";
        }
        catch (const InvalidPointException& e) {
            std::cout << "PASSED: " << e.what() << "\n";
        }
        catch (...) {
            std::cout << "FAILED (wrong exception type)\n";
        }
    
        // Тест 4: Корректное создание и изменение линии
        try {
            std::cout << "Test 4: Valid line operations... ";
            Line line(0, 0, 0, 1, 1, 1);
            line.setpZ(500); // Корректное значение
            line.printData();
            std::cout << "PASSED\n";
        }
        catch (const std::exception& e) {
            std::cout << "FAILED: " << e.what() << "\n";
        }
    
        // Тест 5: Комплексная проверка
        try {
            std::cout << "Test 5: Complex test... ";
            Line line;
            line.setpX(100);
            line.setpY(200);
            line.setpZ(300); // Все координаты корректные
            
            // Проверка длины
            if (line.getLength() <= 0) {
                throw std::runtime_error("Invalid length calculation");
            }
            
            std::cout << "PASSED (length = " << line.getLength() << ")\n";
        }
        catch (const std::exception& e) {
            std::cout << "FAILED: " << e.what() << "\n";
        }
    
        std::cout << "\nAll tests completed.\n";
        return 0;
    }


