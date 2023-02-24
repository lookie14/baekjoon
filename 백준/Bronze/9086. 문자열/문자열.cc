#include<iostream>
using namespace std;

int main() {
    int t;
    char a, b;
    int aa = 0, bb;
    cin >> t;
    string sen;
    for (int i = 0; i < t; i++) {
        cin >> sen;
        bb = sen.size();
        cout << sen.at(aa) << sen.at(bb - 1) << endl;
    }
    return 0;
}