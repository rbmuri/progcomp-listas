#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main(){
    int n, p;
    cin >> n >> p;
    int pts = n*p;
    for (int i=1; i<=9; i++){
        int res = (i*pts/10);
        if ( (i*pts) % 10 != 0 ) res++;
        cout << res << ' ';
    }
    cout << endl;
   
     
    return 0;
}