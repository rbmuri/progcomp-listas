#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;




int main(){
    unsigned long long n, total=0;
    cin >> n;
    while (n){
        total += n & 1;
        n >>= 1;
    }
    cout << (1<<(total)); 
    cout << endl;
   
     
    return 0;
}