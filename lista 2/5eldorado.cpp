#include <bits/stdc++.h>

using namespace std;

int func()

int main(){
    int n, k, past, res, count, temp;
    cin >> n >> k;
    while (n) {
        res=0, count=0;
        for (int i=0; i<n; i++){
            cin >> temp;
            if (temp>past){
                if (count==k) res++;
                else count++;
            } else {
                count = 0;
            }
        }
        cout << res << "\n";
        cin >> n >> k;
    }
    return 0;
}
