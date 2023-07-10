#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

ll sqrdist(ll x, ll y){
    return x*x + y*y;
}

int main(){
    ll t;
    cin >> t;
    while (t){
        ll x[t], y[t];
        ll num=0;
        for (ll i=0; i<t; i++){
            cin >> x[i] >> y[i];
        }
        for (ll i=0; i<t; i++){
            for (ll j=i+1; j<t; j++){
                for (ll k=j+1; k<t; k++){
                    ll a = sqrdist(x[i]-x[j], y[i]-y[j]);
                    ll b = sqrdist(x[j]-x[k], y[j]-y[k]);
                    ll c = sqrdist(x[k]-x[i], y[k]-y[i]);
                    if ( a==b || b==c || c==a ) num++;                         
                }
            }
        }
        cout << num << endl;
        cin >> t;
    }

    return 0;
}