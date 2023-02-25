#include<iostream>
#include<string>
using namespace std;

int main() {
    string A;
    int count, point;
    while (1) {
        cin >> A;
        if (A == "0") break;
        point = 0;
        count = A.size() / 2;
        for (int i = 0; i < count; i++) {
            if (A.at(i) != A.at(A.size() - 1 - i)) {
             cout << "no" << endl;
             break;
             }
            point++;
        }
        if (point == count) cout << "yes" << endl;
    }
    return 0;
}