#pragma once

#include "List.h"
#include "Line.h"

template <>
class List<Line> {
private:
    Node<Line>* head;
    Node<Line>* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    List(const List& other) : head(nullptr), tail(nullptr) {
        Node<Line>* temp = other.head;
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
            Node<Line>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void add(const Line& line) {
        Node<Line>* newNode = new Node<Line>(line);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }


    void print() const {
        Node<Line>* temp = head;
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

        Node<Line>* temp = head;
        while (temp) {
            const Line& line = temp->data;
            file << line.getX() << " " << line.getY() << " " << line.getZ() << " "
                 << line.getpX() << " " << line.getpY() << " " << line.getpZ() << "\n";
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

        int x1, y1, z1, x2, y2, z2;
        while (file >> x1 >> y1 >> z1 >> x2 >> y2 >> z2) {
            add(Line(x1, y1, z1, x2, y2, z2));
        }

        file.close();
        return !file.fail();
    }

    List<Line>& operator+=(const Line& Line) {
        add(Line);
        return *this;
    }



};