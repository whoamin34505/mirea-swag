#pragma once
#include <string.h>
#include <iostream>

enum plugs {
    plug1,
    plug2,
    plug3
};

std::string plugTostring(plugs plug) {
    switch (plug) {
        case plug1: return "HERONWATER";
        case plug2: return "PLAYBOY CARTI";
        case plug3: return "BABY CUTE";
        default: return "Unknown";
    }
}

class Product {
private:
    int id;
    std::string name;
    int price;
    plugs plug;

public:
    Product() : id(0), name("null"), price(0), plug(plug1) {}
    Product(int a, std::string b, int c, plugs d) : id(a), name(b), price(c), plug(d) {}
    Product(const Product& other) : id(other.id), name(other.name), price(other.price), plug(other.plug) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    int getPrice() const { return price; }
    plugs getPlug() const { return plug; }

    void setId(int newId) { id = newId; }
    void setName(std::string newName) { name = newName; }
    void setPrice(int newPrice) { price = newPrice; }
    void setPlug(plugs newPlug) { plug = newPlug; }

    void printData() const {
        std::cout << "ID: " << id << ", Name: " << name << ", Price: " << price << ", Plug: " << plugTostring(plug) << std::endl;
    }

    void printDetailedData() const {
        std::cout << "Product with ID " << id << " called " << name 
             << ". Cost price is " << price << " and the supplier is " << plugTostring(plug) << "." << std::endl;
    }
    
};