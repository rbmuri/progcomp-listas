#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;


int main(){
    ll n, k, l;
    while (cin >> n >> k >> l){
        ll aux = n%10;
        n = n/10;
        ll num = l+(k*k);
        ll res = pow(num, n);
        if (aux) res = res*k;
        res = res%1000000;
        cout << res << endl;

    }
    
    return 0;
}