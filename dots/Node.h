#pragma once

template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;
    Node(T d) : data(d), prev(nullptr), next(nullptr) {}
};