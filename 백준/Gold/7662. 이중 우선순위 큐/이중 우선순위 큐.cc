#include<iostream>
#include<string>
#include<set>

using namespace std;

int T, k;
long long num;
char C;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while(T--){
        multiset<long long> MS;
        cin >> k;
        for(int i = 0 ;i < k ; i++){
            cin >> C >> num;
            if(C == 'I'){
                MS.insert(num);
            }else if(C == 'D'){
                if(!MS.size()) continue;
                if(num == 1){
                    MS.erase(--MS.end());
                }else{
                    MS.erase(MS.begin());
                }
            }
        }
        if(MS.size()) cout << *(--MS.end()) << " " << *MS.begin() << "\n";
        else cout << "EMPTY\n";
    }

    return 0;
}