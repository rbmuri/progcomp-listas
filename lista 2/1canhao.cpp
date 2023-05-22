#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <queue>
 
//problema da mochila

using namespace std;

int main(){
    int tmax, n, wmax, res=-1, hp, out, temp;
    
    
    while (cin >> n){
        cin >> hp;
        int val[n], w[n];
        out = -1, wmax=0;
        for (int ni=0; ni<n; ni++){
            cin >> val[ni] >> temp;
            wmax += temp;
            w[ni] = temp;
        }
        
        
        
        int tb[n+1][wmax+1];
        for (int i=0; i<n+1; i++){
            for (int j=0; j<wmax+1; j++){
                if (i==0 || j==0) tb[i][j] = 0;
                else if (w[i-1] <= j) {
                    tb[i][j] = max(
                        tb[i-1][j], tb[i-1][j-w[i-1]]+val[i-1]
                    );
                } else tb[i][j] = tb[i-1][j];
            }
        }
        for (int i=1; i<wmax+1; i++){
            if (tb[n][i] >= hp) {
                res = tb[n][i];
                break;
            }
        }
        cout << res << "\n";
    }

    return 0;
}
