#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <queue>
 
//problema da mochila

const int INF = 0x3f3f3f3f;

using namespace std;



int main(){
    int tmax, n, wmax, hp, out, temp;
      
    
    while (cin >> n >> hp){
        int dano[n], w[n];
        out = -1, wmax=0;

        for (int ni=0; ni<n; ni++){
            cin >> dano[ni] >> w[ni];
        }      
        //cout << "break!\n";
        int tb[n+1][hp+1];
        //cout << "break!\n";
        for (int i=0; i<=n; i++){ 
            for (int j=0; j<=hp; j++){
                if ( i==0 || j==0) {tb[i][j] = INF; continue;}
                
                
                    
                    int var = j-dano[i-1]; 
                    if (var<0) var = 0;
                    tb[i][j] = min(
                        tb[i-1][j], 
                        tb[i-1][var]+w[i-1]
                    );
                    if (dano[i-1]>=j && w[i-1]<tb[i][j])
                        tb[i][j] = w[i-1];
                
            }
        }
        //cout << "break!!\n";
        
        /*
    cout << endl;
    for (int i=0;i<=n; i++){
        for (int j=0;j<=hp; j++){
            if (tb[i][j]!=INF)
            cout << tb[i][j] << " ";
            else
            cout << "INF ";
        }
            
        cout << endl;
    }
    */
    if (tb[n][hp]==INF) tb[n][hp] = -1;
        cout << tb[n][hp] << "\n";
    }

    return 0;
}
