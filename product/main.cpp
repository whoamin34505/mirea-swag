#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum plugs {
    plug1,
    plug2,
    plug3
};

string plugToString(plugs plug) {
    switch (plug) {
        case plug1: return "HERONWATER";
        case plug2: return "PLAYBOI CARTI";
        case plug3: return "BABY CUTE";
        default: return "Unknown";
    }
}

class Product {
private:
    int id;
    string name;
    int price;
    plugs plug;

public:
    Product() : id(0), name("null"), price(0), plug(plug1) {}
    Product(int a, string b, int c, plugs d) : id(a), name(b), price(c), plug(d) {}
    Product(const Product& other) : id(other.id), name(other.name), price(other.price), plug(other.plug) {}

    int getId() const { return id; }
    string getName() const { return name; }
    int getPrice() const { return price; }
    plugs getPlug() const { return plug; }

    void setId(int newId) { id = newId; }
    void setName(string newName) { name = newName; }
    void setPrice(int newPrice) { price = newPrice; }
    void setPlug(plugs newPlug) { plug = newPlug; }

    void printData() const {
        cout << "ID: " << id << ", Name: " << name << ", Price: " << price << ", Plug: " << plugToString(plug) << endl;
    }

    void printDetailedData() const {
        cout << "Product with ID " << id << " called " << name 
             << ". Cost price is " << price << " and the supplier is " << plugToString(plug) << "." << endl;
    }

    void saveToFile(ofstream& file) const {
        file << id << " " << name << " " << price << " " << plug << endl;
    }
    
};


template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;
    Node(T d) : data(d), prev(nullptr), next(nullptr) {}
};

// Шаблонный класс List
template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    List(const List& other) : head(nullptr), tail(nullptr) {
        Node<T>* temp = other.head;
        while (temp) {
            addProduct(temp->data);
            temp = temp->next;
        }
    }

    List(List&& other) noexcept : head(other.head), tail(other.tail) {
        other.head = nullptr;
        other.tail = nullptr;
    }

    ~List() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addProduct(const T& product) {
        Node<T>* newNode = new Node<T>(product);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteProductById(int id) {
        Node<T>* temp = head;
        while (temp) {
            if (temp->data.getId() == id) {
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
            Node<T>* temp = head;
            while (temp->next) {
                if (temp->data.getPrice() > temp->next->data.getPrice()) {
                    swap(temp->data, temp->next->data);
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
            Node<T>* temp = head;
            while (temp->next) {
                if (temp->data.getName() > temp->next->data.getName()) {
                    swap(temp->data, temp->next->data);
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
            Node<T>* temp = head;
            while (temp->next) {
                if (temp->data.getPlug() > temp->next->data.getPlug()) {
                    swap(temp->data, temp->next->data);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }

    void filterByPrice(int maxPrice) const {
        Node<T>* temp = head;
        while (temp) {
            if (temp->data.getPrice() <= maxPrice) {
                temp->data.printData();
            }
            temp = temp->next;
        }
    }

    void filterByName(const string& name) const {
        Node<T>* temp = head;
        while (temp) {
            if (temp->data.getName() == name) {
                temp->data.printData();
            }
            temp = temp->next;
        }
    }

    void filterByPlug(plugs plug) const {
        Node<T>* temp = head;
        while (temp) {
            if (temp->data.getPlug() == plug) {
                temp->data.printData();
            }
            temp = temp->next;
        }
    }

    List<T> createSublistByPlug(plugs plug) const {
        List<T> sublist;
        Node<T>* temp = head;
        while (temp) {
            if (temp->data.getPlug() == plug) {
                sublist.addProduct(temp->data);
            }
            temp = temp->next;
        }
        return sublist;
    }

    List<T> createSublistByPrice(int maxPrice) const {
        List<T> sublist;
        Node<T>* temp = head;
        while (temp) {
            if (temp->data.getPrice() <= maxPrice) {
                sublist.addProduct(temp->data);
            }
            temp = temp->next;
        }
        return sublist;
    }

    List<T> createSublistByName(const string& name) const {
        List<T> sublist;
        Node<T>* temp = head;
        while (temp) {
            if (temp->data.getName() == name) {
                sublist.addProduct(temp->data);
            }
            temp = temp->next;
        }
        return sublist;
    }

    void printListShort() const {
        Node<T>* temp = head;
        while (temp) {
            temp->data.printData();
            temp = temp->next;
        }
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file for writing!" << endl;
            return;
        }
        Node<T>* temp = head;
        while (temp) {
            temp->data.saveToFile(file);
            temp = temp->next;
        }
        file.close();
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file for reading!" << endl;
            return;
        }

        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;

        int id, price, plug;
        string name;
        while (file >> id >> name >> price >> plug) {
            T newProduct(id, name, price, static_cast<plugs>(plug));
            addProduct(newProduct);
        }

        file.close();
    }
};

int main() {
    List<Product> products;
    products.addProduct(Product(1, "Ahaha", 500, plug1));
    products.addProduct(Product(2, "Ohoho", 1500, plug2));
    products.addProduct(Product(3, "Ihihi", 300, plug3));
    products.addProduct(Product(4, "Aboba", 700, plug1));

    cout << "Original list:\n";
    products.printListShort();

    products.sortByName();
    cout << "\nSorted by name:\n";
    products.printListShort();

    products.sortByPrice();
    cout << "\nSorted by price:\n";
    products.printListShort();

    cout << "\nFiltered by price <= 700:\n";
    products.filterByPrice(700);

    cout << "\nFiltered by plug1:\n";
    products.filterByPlug(plug1);

    cout << "\nSublist with plug1:\n";
    List<Product> sublist = products.createSublistByPlug(plug1);
    sublist.printListShort();

    cout << "\nSublist with price <= 700:\n";
    List<Product> sublist2 = products.createSublistByPrice(700);
    sublist2.printListShort();

    products.deleteProductById(2);
    cout << "\nList after deleting product with ID 2:\n";
    products.printListShort();

    products.saveToFile("products.txt");
    cout << "\nProducts saved to file.\n";

    return 0;
}
