#pragma once
#include <string>
#include <iostream>
#include "ProductException.h"

enum plugs {
    plug1 = 0,
    plug2 = 1,
    plug3 = 2
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
    double price;
    plugs plug;

    void validate() const {
        if (id <= 0) throw InvalidProductIdException(id);
        if (name.empty() || name.length() > 100) throw InvalidProductNameException(name);
        if (price <= 0) throw InvalidProductPriceException(price);
        if (plug < plug1 || plug > plug3) throw InvalidProductPlugException(static_cast<int>(plug));
    }

public:
    Product() : id(0), name("null"), price(0), plug(plug1) {}
    
    Product(int a, std::string b, double c, plugs d) : id(a), name(b), price(c), plug(d) {
        validate();
    }

    int getId() const { return id; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    plugs getPlug() const { return plug; }

    void setId(int newId) { 
        if (newId <= 0) throw InvalidProductIdException(newId);
        id = newId; 
    }
    
    void setName(std::string newName) { 
        if (newName.empty() || newName.length() > 100) 
            throw InvalidProductNameException(newName);
        name = newName; 
    }
    
    void setPrice(double newPrice) { 
        if (newPrice <= 0) throw InvalidProductPriceException(newPrice);
        price = newPrice; 
    }
    
    void setPlug(plugs newPlug) { 
        if (newPlug < plug1 || newPlug > plug3) 
            throw InvalidProductPlugException(static_cast<int>(newPlug));
        plug = newPlug; 
    }

    void printData() const {
        std::cout << "ID: " << id 
                  << ", Name: " << name 
                  << ", Price: " << price 
                  << ", Plug: " << plugTostring(plug) << std::endl;
    }
};