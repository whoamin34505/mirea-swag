#pragma once
#include "Point.h"
#include "List.h"
#include <fstream>
#include <iostream>


template <>
class List<Point> {
private:
    Node<Point>* head;
    Node<Point>* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    List(const List& other) : head(nullptr), tail(nullptr) {
        Node<Point>* temp = other.head;
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
            Node<Point>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void add(const Point& point) {
        Node<Point>* newNode = new Node<Point>(point);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

   

    void print() const {
        Node<Point>* temp = head;
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

        Node<Point>* temp = head;
        while (temp) {
            const Point& p = temp->data;
            file << p.getX() << " " << p.getY() << " " << p.getZ() << "\n";
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

        int x, y, z;
        while (file >> x >> y >> z) {
            add(Point(x, y, z));
        }

        file.close();
        return !file.fail();
    }

    List<Point>& operator+=(const Point& point) {
        add(point);
        return *this;
    }


    friend List<Point> operator+(List<Point> list, const Point& point) {
        list += point;
        return list;
    }

};