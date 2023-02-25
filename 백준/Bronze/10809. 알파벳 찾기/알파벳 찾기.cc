#include<iostream>
#include<string>
using namespace std;

int main() {
    string A;
    cin >> A;
    int arr[26];
    for (char S = 'a'; S < 123; S++) {
        for (int i = 0; i < A.size(); i++) {
            if (A.at(i) == S) {
                arr[int(S - 'a')] = i;
                break;
            }
            else arr[S - 'a'] = -1;
        }
    }
    for (int i = 0; i < 26; i++) cout << arr[i] << " ";
    return 0;
}