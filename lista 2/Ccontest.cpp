#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <queue>
 
//???
int res=0;

int func(int n){
    int mdc=n, i;
    if (n==1) return 1;
    for (i=2;i*i<=n; i++){
        if (n%i==0){
            mdc = i;
            break;
        }
    }
    return n + func(n/mdc);
}

using namespace std;

int main(){
    int n;
    cin >> n;
    cout << func(n) << endl;
    return 0;
}
