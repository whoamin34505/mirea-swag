#pragma once

#include "List.h"
#include "Rectangle.h"


template <>
class List<Rectangle> {
private:
    Node<Rectangle>* head;
    Node<Rectangle>* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    List(const List& other) : head(nullptr), tail(nullptr) {
        Node<Rectangle>* temp = other.head;
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
            Node<Rectangle>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void add(const Rectangle& rectangle) {
        Node<Rectangle>* newNode = new Node<Rectangle>(rectangle);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }


    void print() const {
        Node<Rectangle>* temp = head;
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

        Node<Rectangle>* temp = head;
        while (temp) {
            int x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;            
            const Rectangle& Rectangle = temp->data;
            file << Rectangle.getX() << " " << Rectangle.getY() << " " << Rectangle.getZ() << " "
                 << Rectangle.getpX() << " " << Rectangle.getpY() << " " << Rectangle.getpZ() <<  " "
                 << Rectangle.getP3X() << " " << Rectangle.getP3Y() << " " << Rectangle.getP3Z() <<  " "
                 << Rectangle.getP4X() << " " << Rectangle.getP4Y() << " " << Rectangle.getP4Z() <<  "\n";
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

        int x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
        while (file >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3 >> x4 >> y4 >> z4) {
            add(Rectangle(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4));
        }

        file.close();
        return !file.fail();
    }

    List<Rectangle>& operator+=(const Rectangle& Rectangle) {
        add(Rectangle);
        return *this;
    }


    friend List<Rectangle> operator+(List<Rectangle> list, const Rectangle& Rectangle) {
        list += Rectangle;
        return list;
    }

};