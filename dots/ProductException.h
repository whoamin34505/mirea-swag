#pragma once
#include <exception>
#include <string>

class ProductException : public std::exception {
private:
    std::string message;
public:
    explicit ProductException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidProductIdException : public ProductException {
public:
    explicit InvalidProductIdException(const std::string& msg)
        : ProductException("Invalid ID: " + msg) {}
};

class InvalidProductNameException : public ProductException {
public:
    explicit InvalidProductNameException(const std::string& msg)
        : ProductException("Invalid Name: " + msg) {}
};

class InvalidProductPriceException : public ProductException {
public:
    explicit InvalidProductPriceException(const std::string& msg)
        : ProductException("Invalid Price: " + msg) {}
};

class InvalidProductPlugException : public ProductException {
public:
    explicit InvalidProductPlugException(const std::string& msg)
        : ProductException("Invalid Plug: " + msg) {}
};