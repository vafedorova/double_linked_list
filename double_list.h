#ifndef _DOUBLE_LIST_H_
#define _DOUBLE_LIST_H_
#include "node.h"

template <typename T>
class DoubleList {
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
    void pop_front();
    void pop_back();
    void pop_current();
    void push_before_current(const T &value);
    void push_back(const T &value);
    void push_front(const T &value);
    bool move_current(bool move_forward = true);
    void clear_list() {
        while (!is_empty())
            pop_front();
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }
};

// operator <<
template <typename T>
std::ostream &operator<<(std::ostream &out, const DoubleList<T> &l) {
    out << "x";
    const Node<T> *curr = l.get_head();
    while (curr != nullptr) {
        if (curr == l.get_head()) {
            out << " <- ";
        }
        if (curr == l.get_current()) {
            out << "[" << *curr << "]";
        }
        else {
            out << *curr;
        }
        if (curr->next != nullptr) {
            out << " <-> ";
        }
        else {
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
    if (is_empty()) {
      push_front(value);
      return;
    }
    Node<T> *new_node = new Node<T>(value);
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
    current = new_node;
}

// pop back
template <typename T>
void DoubleList<T>::pop_back() {
    if (is_empty()) {
        return;
    }
    Node<T> *new_tail = tail->prev;
    if (current == tail) {
      current = new_tail;
    }
    if (head == tail) {
      head = new_tail;
    }
    delete tail;
    tail = new_tail;
    if (tail!= nullptr)
      tail->next = nullptr;
}

// pop front
template <typename T>
void DoubleList<T>::pop_front() {
    if (is_empty()) {
        return;
    }
    Node<T> *new_head = head->next;
    if (current == head) {
      current = new_head;
    }
    if (tail == head) {
      tail = new_head;
    }
    delete head;
    head = new_head;
    if (head != nullptr)
      head->prev = nullptr;
}

// pop current
template <typename T>
void DoubleList<T>::pop_current() {
    if (is_empty()) {
      return;
    }
    if (current == head) {
      pop_front();
      return;
    }
    if (current == tail) {
      pop_back();
      return;
    }
    Node<T> *curr_next = current->next; // != nullptr
    Node<T> *curr_prev = current->prev; // != nullptr
    curr_prev->next = curr_next;
    curr_next->prev = curr_prev;
    delete current;
    current = curr_prev;
}

// push before current
template <typename T>
void DoubleList<T>::push_before_current(const T &value) {
    if (is_empty() || current == head) {
      push_front(value);
      return;
    }
    Node<T> *new_node = new Node<T>(value);
    Node<T> *curr_prev = current->prev;
    curr_prev->next = new_node;
    new_node->prev = curr_prev;
    new_node->next = current;
    current->prev = new_node;
    current = new_node;
}

// move current
template <typename T>
bool DoubleList<T>::move_current(bool move_forward) {
    if (is_empty()) {
        return false;
    }
    if (move_forward) {
        if (current == tail) {
           return false; 
        }
        current = current->next;
        return true;
    }
    else {
        if (current == head) {
           return false;
        }
        current = current->prev;
        return true;
    }
}

#endif //_DOUBLE_LIST_H_