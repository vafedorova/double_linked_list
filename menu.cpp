#include <unordered_map>
#include "menu.h"
#include <exception>

using namespace std;

DoubleList<int> list;

// 1
void push_front() {
  cout << "Enter the value to insert: ";
  int x;
  cin >> x;
  list.push_front(x);
}

// 2
void push_back() {
  cout << "Enter the value to insert: ";
  int x;
  cin >> x;
  list.push_back(x);
}

// 3
void push_before_current() {
  cout << "Enter the value to insert: ";
  int x;
  cin >> x;
  list.push_before_current(x);
}

// 4
void pop_front() {
  list.pop_front();
}

// 5
void pop_back() {
  list.pop_back();
}

// 6
void pop_current() {
  list.pop_current();
}

// 7
void clear_list() {
  list.clear_list();
}

// 8
void move_current() {
  while (true) {
    cout << "Choose the direction to move the current pointer (1 - move forward / 2 - move back): ";
    int x;
    cin >> x;
    if (x == 1 || x == 2) {
      bool move_succeded = list.move_current(x == 1);
      if (!move_succeded)  
        cerr << "You can't move the current, because you haven't got enough nodes!" << endl;
      break;
    }
    else {  
      cout << x << " is not a valid choice. Please try it again." << endl;
    }
  }
}

int show_menu() {
  cout << "\n";
  while (true) {
    cout << "My list: " << list;
    if (list.is_empty()) {
      cout << " (list is empty)";
    }
    cout << "\n\n";
    cout << "==========================================================\n";
    int i = 1;
    cout << i++ << ". Add an element in the front of the list.\n"
         << i++ << ". Add an element in the back of the list.\n"
         << i++ << ". Add an element before the current.\n"
         << i++ << ". Remove the first element.\n"
         << i++ << ". Remove the last element.\n"
         << i++ << ". Remove the current.\n"
         << i++ << ". Clear the list.\n"
         << i++ << ". Move the current.\n"
         << i++ << ". Exit the program.\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice >= i || choice < 1) {
      cerr << "Invalid choice. Try again." << endl;
      continue;
    }
    cout << "==========================================================\n";
    cout << "\n";
    return choice;
  }
}
