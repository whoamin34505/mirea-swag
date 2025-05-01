#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "Product.h"
#include "Node.h"

using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::string;


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
            add(temp->data);
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

    void add(const T& element) {
        Node<T>* newNode = new Node<T>(element);
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

    void filterByName(const std::string& name) const {
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
                sublist.add(temp->data);
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
                sublist.add(temp->data);
            }
            temp = temp->next;
        }
        return sublist;
    }

    List<T> createSublistByName(const std::string& name) const {
        List<T> sublist;
        Node<T>* temp = head;
        while (temp) {
            if (temp->data.getName() == name) {
                sublist.add(temp->data);
            }
            temp = temp->next;
        }
        return sublist;
    }

    void print() const {
        Node<T>* temp = head;
        while (temp) {
            temp->data.printData();
            temp = temp->next;
        }
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file) {
            std::cout << "Error opening file for writing!" << std::endl;
            return;
        }

        Node<T>* temp = head;
        while (temp) {
            const T& data = temp->data;
            file << data.getId() << " "
                 << data.getName() << " "
                 << data.getPrice() << " "
                 << data.getPlug() << std::endl;
            temp = temp->next;
        }
        file.close();
    }

    void loadFromFile(const std::string& filename) {
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
            add(newProduct);
        }

        file.close();
    }

    List<T>& operator+(const T& product) {
        add(product);
        return *this;
    }

    List<T>& operator-(const T& product) {
        deleteProductById(product.getId());
        return *this;
    }
    
};