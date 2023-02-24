#include<iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int k = N / 4;
    for (int i = 0; i < k; i++) {
        cout << "long ";
    }
    cout << "int";
    return 0;
}