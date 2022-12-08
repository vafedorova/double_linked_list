#ifndef _DOUBLE_LIST_H_
#define _DOUBLE_LIST_H_
#include "node.h"

template <typename T>
class DoubleList
{
    Node<T> *head;
    Node<T> *tail;
    Node<T> *current;

public:
    DoubleList() : head(nullptr), tail(nullptr), current(nullptr) {}
    ~DoubleList() { clear_list(); }
    const Node<T> *get_head() const { return head; }
    const Node<T> *get_tail() const { return tail; }
    const Node<T> *get_current() const { return current; }
    bool is_empty() const { return head == nullptr; }
    void pop_front() {}
    void push_back(const T &value);
    void push_front(const T &value);
    void clear_list()
    {
        while (!is_empty())
            pop_front();
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }
};

// operator <<
template <typename T>
std::ostream &operator<<(std::ostream &out, const DoubleList<T> &l)
{
    out << "x";
    const Node<T> *curr = l.get_head();
    while (curr != nullptr)
    {
        if (curr == l.get_head())
        {
            out << " <- ";
        }
        if (curr == l.get_current())
        {
            out << "[" << *curr << "]";
        }
        else
        {
            out << *curr;
        }
        if (curr->next != nullptr)
        {
            out << " <-> ";
        }
        else
        {
            out << " -> x";
        }
        curr = curr->next;
    }
    return out;
}

// push front
template <typename T>
void DoubleList<T>::push_front(const T &value) {
    if (is_empty()) {
        head = new Node<T>(value);
        current = head;
        tail = head;
        return;
    }
    Node<T> *new_node = new Node<T>(value);
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
    current = new_node;
}

// push back
template <typename T>
void DoubleList<T>::push_back(const T &value) {

}

#endif //_DOUBLE_LIST_H_