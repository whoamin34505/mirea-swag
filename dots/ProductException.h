#pragma once
#include <exception>
#include <string>

class ProductException : public std::exception {
protected:
    std::string message;
public:
    explicit ProductException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class InvalidProductIdException : public ProductException {
public:
    explicit InvalidProductIdException(int id)
        : ProductException("Invalid product ID: " + std::to_string(id) + 
                         ". ID must be positive number.") {}
};

class InvalidProductNameException : public ProductException {
public:
    explicit InvalidProductNameException(const std::string& name)
        : ProductException("Invalid product name: '" + name + 
                         "'. Name must be 1-100 characters long.") {}
};

class InvalidProductPriceException : public ProductException {
public:
    explicit InvalidProductPriceException(double price)
        : ProductException("Invalid product price: " + std::to_string(price) + 
                         ". Price must be positive number.") {}
};

class InvalidProductPlugException : public ProductException {
public:
    explicit InvalidProductPlugException(int plug)
        : ProductException("Invalid product plug type: " + std::to_string(plug) + 
                         ". Must be 0, 1 or 2.") {}
};