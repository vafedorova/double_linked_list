#include "node.h"
#include "menu.h"

int main() {
  while (true) {
    switch (show_menu()) {
    case 1:
      push_front();
      break;
    case 2:
      push_back();
      break;
    case 3:
      push_before_current();
      break;
    case 4:
      pop_front();
      break;
    case 5:
      pop_back();
      break;
    case 6:
      pop_current();
      break;
    case 7:
      clear_list();
      break;
    case 8:
      move_current();
      break;
    default:
      return 0;
    }
  }
}