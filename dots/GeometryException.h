#pragma once
#include <exception>
#include <string>

class GeometryException : public std::exception {
private:
    std::string message;
public:
    explicit GeometryException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};


class InvalidPointException : public GeometryException {
public:
    explicit InvalidPointException(const std::string& msg) 
        : GeometryException("Invalid Point: " + msg) {}
};

class InvalidLineException : public GeometryException {
public:
    explicit InvalidLineException(const std::string& msg)
        : GeometryException("Invalid Line: " + msg) {}
};

class InvalidRectangleException : public GeometryException {
public:
    explicit InvalidRectangleException(const std::string& msg)
        : GeometryException("Invalid Rectangle: " + msg) {}
};

class InvalidParallelepipedException : public GeometryException {
public:
    explicit InvalidParallelepipedException(const std::string& msg)
        : GeometryException("Invalid Parallelepiped: " + msg) {}
};