#pragma once

#include "List.h"
#include "Parallelepiped.h"


template <>
class List<Parallelepiped> {
private:
    Node<Parallelepiped>* head;
    Node<Parallelepiped>* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    List(const List& other) : head(nullptr), tail(nullptr) {
        Node<Parallelepiped>* temp = other.head;
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
        clear();
    }

    void clear() {
        while (head) {
            Node<Parallelepiped>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void add(const Parallelepiped& parallelepiped) {
        Node<Parallelepiped>* newNode = new Node<Parallelepiped>(parallelepiped);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }


    void print() const {
        Node<Parallelepiped>* temp = head;
        while (temp) {
            temp->data.printData();
            temp = temp->next;
        }
    }

    bool saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file) {
            std::cerr << "Error opening file for writing: " << filename << std::endl;
            return false;
        }

        Node<Parallelepiped>* temp = head;
        while (temp) {
            int x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7, x8, y8, z8;            
            const Parallelepiped& parallelepiped = temp->data;
            file << parallelepiped.getX() << " " << parallelepiped.getY() << " " << parallelepiped.getZ() << " "
                 << parallelepiped.getpX() << " " << parallelepiped.getpY() << " " << parallelepiped.getpZ() <<  " "
                 << parallelepiped.getP5X() << " " << parallelepiped.getP5Y() << " " << parallelepiped.getP5Z() <<  " "
                 << parallelepiped.getP6X() << " " << parallelepiped.getP6Y() << " " << parallelepiped.getP6Z() <<  " " 
                 << parallelepiped.getP7X() << " " << parallelepiped.getP7Y() << " " << parallelepiped.getP7Z() <<  " "
                 << parallelepiped.getP8X() << " " << parallelepiped.getP8Y() << " " << parallelepiped.getP8Z() <<  " " << "\n";
            temp = temp->next;
        }
        
        file.close();
        return !file.fail();
    }

    bool loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Error opening file for reading: " << filename << std::endl;
            return false;
        }

        clear();

        int x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7, x8, y8, z8;
        while (file >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3 >> x4 >> y4 >> z4 >> x5 >> y5 >> z5 >> x6 >> y6 >> z6 >> x7 >> y7 >> z7 >> x8 >> y8 >> z8) {
            add(Parallelepiped(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5, x6, y6, z6, x7, y7, z7, x8, y8, z8));
        }

        file.close();
        return !file.fail();
    }

    List<Parallelepiped>& operator+=(const Parallelepiped& Parallelepiped) {
        add(Parallelepiped);
        return *this;
    }


    friend List<Parallelepiped> operator+(List<Parallelepiped> list, const Parallelepiped& Parallelepiped) {
        list += Parallelepiped;
        return list;
    }

};