#include "double_list.h"
using namespace std;
int main() {
    DoubleList<int> list;
    cout << list << endl;
    for (int i = 1; i <= 5; i++) {
        int x;
        cin >> x;
        list.push_front(x);
        cout << list << endl;
    } 
    return 0;
}