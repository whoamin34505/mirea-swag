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