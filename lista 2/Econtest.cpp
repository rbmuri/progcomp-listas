#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <queue>
 
//???

using namespace std;

int main(){
    int n, t, aux=0, sum;
    bool pos;
    cin >> t;
    for (int i=0; i<t; i++){
        int sum=0, high=0;
        cin >> n;
        cin >> high;
        if (high>0){
            pos = true;
        }
        if (high<0){
            pos = false;
        }
        for (int j=1; j<n; j++){
            if (pos){
                cin >> aux;
                if (aux>0) {
                    if (aux>high) high = aux;
                }
                if (aux<0) {
                    pos = false;
                    sum += high;
                    high = aux;
                }
                
            }
            else if (!pos){
                cin >> aux;
                if (aux<0){
                    if (aux>high) high = aux;
                }
                if (aux>0) {
                    pos = true;
                    sum += high;
                    high = aux;
                }
            }

        }
        if (sum==0) sum = high;
        cout << sum << endl;
    }
    return 0;
}
