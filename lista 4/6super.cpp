#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

int pd(int x){
    if (x==2 || x==3 || x==5 || x==7) return 1;
    else return 0;
}

int f(int x){ //retorna 0 se nao for super, 1 se for
    int res = 1;
    if (x>9) res = f(x/10);

    if (res==0) return 0;

    int y = x%10;
    
    return pd(y);
}
int main(){
    int num;
    int res;
    while (cin >> num){
        if (num==1) {
            cout << "Nada\n";
            continue;
        }
        res = 1;
        for (int i=2; i*i<=num; i++){
            if (num%i==0){
                res = 0;
                break;
            }
        }
        if (res>0){
            res = res + f(num);
        }
        if (res==0) cout << "Nada\n";
        if (res==1) cout << "Primo\n";
        if (res==2) cout << "Super\n";
    }
    
    return 0;
}