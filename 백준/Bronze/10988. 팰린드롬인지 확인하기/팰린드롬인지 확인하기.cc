#include<iostream>
#include<string>
using namespace std;
int main() {
    string a;
    int point = 0;
    cin >> a;
    int N = a.size();
    for (int i = 0; i < N/2; i++) {
        if (a.at(i) == a.at(N - 1 - i)) point++;
    }
    if (point == N / 2) cout << 1;
    else cout << 0;
    return 0;
}