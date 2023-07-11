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
            vector<ll> v;
            for (ll j=0; j<t; j++){
                ll a = sqrdist(x[i]-x[j], y[i]-y[j]);
                v.push_back(a);                         
            }
            sort(v.begin(), v.end());
            ll temp = v[0];
            ll var=0;
            //cout << "vector[0]: " << v[0] << endl;
            for (ll j=1; j<t; j++){
                //cout << "vector[" << j << "]: " << v[j] << endl;
                if (temp==v[j]){
                    var++;
                }
                else {
                    num = num+ (var+1)*(var)/2;
                    var = 0;
                    temp = v[j];
                    //cout << "num: " << num << endl;
                }
            }
            num = num+ (var+1)*(var)/2;
        }
        cout << num << endl;
        cin >> t;
    }

    return 0;
}