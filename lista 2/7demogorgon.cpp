#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <queue>
 
//problema da mochila

using namespace std;

int dem(int hp, int n){
    if ()  
}

int main(){
    int tmax, n, wmax, hp, out, temp;
    
    
    while (cin >> n){
        cin >> hp;
        int val[n], w[n];
        out = -1, wmax=0;

        for (int ni=0; ni<n; ni++){
            cin >> val[ni] >> w[ni];
        }      
        cout << "break!\n";
        int tb[n+1][1000001];
        cout << "break!\n";
        for (int i=0; i<n+1; i++){
            for (int j=0; j<1000001; j++){
                if (i==0 || j==0) tb[i][j] = 0;
                else if (w[i-1] <= j) {
                    tb[i][j] = max(
                        tb[i-1][j], tb[i-1][j-w[i-1]]+val[i-1]
                    );
                } else tb[i][j] = tb[i-1][j];
            }
        }
        cout << "break!!\n";
        for (int i=1; i<1000001; i++){
            //cout << "break! " << tb[n][i] << endl;
            if (tb[n][i] >= hp) {
                out = i;
                break;
            }
        }
        cout << out << "\n";
    }

    return 0;
}
