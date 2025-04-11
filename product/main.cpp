#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

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
struct Node {
    Product product;  // Товар, хранящийся в узле
    Node* prev;       // Указатель на предыдущий узел
    Node* next;       // Указатель на следующий узел

    // Конструктор для создания узла
    Node(Product p) : product(p), prev(nullptr), next(nullptr) {}
};

// Класс "Список товаров"
class List {
private:
    Node* head;  // Указатель на начало списка
    Node* tail;  // Указатель на конец списка

public:
    // Конструктор по умолчанию
    List() : head(nullptr), tail(nullptr) {}

    // Конструктор копирования
    List(const List& other) : head(nullptr), tail(nullptr) {
        Node* temp = other.head;
        while (temp) {
            addProduct(temp->product);  // Копируем товары из другого списка
            temp = temp->next;
        }
    }

    // Конструктор перемещения
    List(List&& other) noexcept : head(other.head), tail(other.tail) {
        other.head = nullptr;  // Обнуляем указатели в исходном объекте
        other.tail = nullptr;
    }

    // Деструктор для освобождения памяти
    ~List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;  // Удаляем каждый узел
        }
    }

    // Метод для добавления товара в список
    void addProduct(const Product& product) {
        Node* newNode = new Node(product);  // Создаем новый узел
        if (!head) {
            head = tail = newNode;  // Если список пуст, новый узел становится головой и хвостом
        } else {
            tail->next = newNode;  // Добавляем узел в конец списка
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Метод для удаления товара по ID
    void deleteProduct(int productId) {
        Node* temp = head;
        while (temp) {
            if (temp->product.getId() == productId) {
                // Обновляем связи между узлами
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                if (temp == head) head = temp->next;  // Если удаляем голову, обновляем head
                if (temp == tail) tail = temp->prev;  // Если удаляем хвост, обновляем tail
                delete temp;  // Освобождаем память
                return;
            }
            temp = temp->next;
        }
    }

    // Метод для сортировки списка по цене (пузырьковая сортировка)
    void sortByPrice() {
        if (!head || !head->next) return;  // Если список пуст или содержит один элемент, выходим
        bool swapped;
        do {
            swapped = false;
            Node* temp = head;
            while (temp->next) {
                if (temp->product.getPrice() > temp->next->product.getPrice()) {
                    swap(temp->product, temp->next->product);  // Меняем местами товары
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }

    // Метод для сортировки списка по имени (пузырьковая сортировка)
    void sortByName() {
        if (!head || !head->next) return;
        bool swapped;
        do {
            swapped = false;
            Node* temp = head;
            while (temp->next) {
                if (temp->product.getName() > temp->next->product.getName()) {
                    swap(temp->product, temp->next->product);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }

    // Метод для сортировки списка по поставщику (пузырьковая сортировка)
    void sortByPlug() {
        if (!head || !head->next) return;
        bool swapped;
        do {
            swapped = false;
            Node* temp = head;
            while (temp->next) {
                if (temp->product.getPlug() > temp->next->product.getPlug()) {
                    swap(temp->product, temp->next->product);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }

    // Метод для фильтрации списка по цене (вывод товаров с ценой <= maxPrice)
    void filterByPrice(int maxPrice) const {
        Node* temp = head;
        while (temp) {
            if (temp->product.getPrice() <= maxPrice) {
                temp->product.printShort();  // Выводим информацию о товаре
            }
            temp = temp->next;
        }
    }

    // Метод для фильтрации списка по имени (вывод товаров с заданным именем)
    void filterByName(const string& name) const {
        Node* temp = head;
        while (temp) {
            if (temp->product.getName() == name) {
                temp->product.printShort();
            }
            temp = temp->next;
        }
    }

    // Метод для фильтрации списка по поставщику (вывод товаров с заданным поставщиком)
    void filterByPlug(plugs filterPlug) const {
        Node* temp = head;
        while (temp) {
            if (temp->product.getPlug() == filterPlug) {
                temp->product.printShort();
            }
            temp = temp->next;
        }
    }

    // Метод для создания подсписка по поставщику
    List createSublistByPlug(plugs filterPlug) const {
        List sublist;
        Node* temp = head;
        while (temp) {
            if (temp->product.getPlug() == filterPlug) {
                sublist.addProduct(temp->product);  // Добавляем товар в подсписок
            }
            temp = temp->next;
        }
        return sublist;
    }

    // Метод для создания подсписка по цене (товары с ценой <= maxPrice)
    List createSublistByPrice(int maxPrice) const {
        List sublist;
        Node* temp = head;
        while (temp) {
            if (temp->product.getPrice() <= maxPrice) {
                sublist.addProduct(temp->product);
            }
            temp = temp->next;
        }
        return sublist;
    }

    // Метод для создания подсписка по имени (товары с заданным именем)
    List createSublistByName(const string& name) const {
        List sublist;
        Node* temp = head;
        while (temp) {
            if (temp->product.getName() == name) {
                sublist.addProduct(temp->product);
            }
            temp = temp->next;
        }
        return sublist;
    }

    // Метод для вывода краткой информации о всех товарах в списке
    void printListShort() const {
        Node* temp = head;
        while (temp) {
            temp->product.printShort();
            temp = temp->next;
        }
    }

    // Метод для сохранения списка товаров в файл
    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (!file) {
            cerr << "Error opening file for writing!" << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            temp->product.saveToFile(file);  // Сохраняем каждый товар в файл
            temp = temp->next;
        }
        file.close();
    }

    // Метод для загрузки списка товаров из файла
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file for reading!" << endl;
            return;
        }

        // Очищаем текущий список перед загрузкой новых данных
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;

        int id, price, plug;
        string name;
        while (file >> id >> name >> price >> plug) {
            // Создаем новый товар и добавляем его в список
            Product newProduct(id, name, price, static_cast<plugs>(plug));
            addProduct(newProduct);
        }

        file.close();
    }
};

// Основная функция
int main() {
    List products;
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