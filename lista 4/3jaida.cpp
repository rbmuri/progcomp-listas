#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;


vector<ll> crivo2;
vector<ll> crivo;
void make(ll lim){
    crivo.resize(lim+1);
    fill(crivo.begin(), crivo.end(), 0);
    crivo[0] = -1;
    crivo[1] = -1;
    //cout << "breakpoint!!\n";
    for (ll i = 2; i<=lim; i++){
        if (crivo[i]==0){
            for (ll x = i*i; x<=lim; x = x+i){
                //cout << i << ": increasing n" << x << ", now at " << crivo[x] << endl;
                crivo[x]++;
            }
        }
        crivo2.push_back(i);
    }
}

int main(){
    //cout << "breakpoint!\n";
    make(1000000);

    int t;
    //cout << "breakpoint!!\n";
    cin >> t;
    for (int j = 0; j<t; j++){
        int n;
        ll ni, res;
        set<ll> set;
        vector<ll> v;
        cin >>n;
        //cout << "breakpoint!!\n";
        for (int i = 0; i<n; i++){
            cin >> ni;
            v.push_back(ni);
        }
        bool is = false;
        //cout << "breakpoint!!\n";
        if (v[0]!=1){
            cout << "break\n";
            res = 0;
        } else
        for (int i = 0; i<crivo2.size(); i++){
            for (int k=1; v[k]<=crivo2[i]; k++){
                if (v[k]==crivo2[i]){
                    is = true;
                    break;
                }
                if (!is){
                    res = crivo2[i]-1;
                    break;
                }
            }
            
        }
        //cout << "breakpoint!!\n";
        cout << res << endl;
    }

   
    return 0;
}