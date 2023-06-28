#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

const ll limk = 2000000;


ll hiper[limk+1];
vector<ll> crivo;
void make(ll lim){
    hiper[1] = 0;
    crivo.resize(lim+1);
    fill(crivo.begin(), crivo.end(), 0);
    //cout << "breakpoint!\n";
    crivo[0] = -1;
    crivo[1] = -1;
    //cout << "breakpoint!!\n";
    for (ll i = 2; i<=lim; i++){
        
            for (ll x = i+i; x<=lim; x = x+i){
                //cout << i << ": increasing n" << x << ", now at " << crivo[x] << endl;
                crivo[x]++;
        }
        //cout << i << " breakpoint!\n";
        hiper[i] = hiper[i-1];
        if (crivo[crivo[i]+2]==0) hiper[i]++;
    }
}

int main(){
    //cout << "breakpoint!\n";
    make(limk);
    ll n;

    
    //cout << "breakpoint!!\n";
    while (cin >> n){
        cout << hiper[n] << endl;
    }
   
    return 0;
}