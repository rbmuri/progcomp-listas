#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <queue>
 
//

using namespace std;

int main(){
    int n, mana, dano;
    //long double ;
    while (cin){
        cin >> n >> mana >> dano;
        long double hp[n], pow[n], tempo=0; 
        priority_queue<long double> timesaved;
        for (int i=0; i<n; i++){  
            cin >> hp[i] >> pow[i];
            //cout << "recebe hp = " << hp[i] << " e pow = " << pow[i] << "\n";
        }
        for (int i=0; i<n; i++){
            tempo += hp[i]/dano;
            //cout << "tempo (" << tempo << ") = hp (" << hp[i] << ") / dano (" << dano << ")\n";

        }
        for (int i=0; i<n; i++){
            timesaved.push( (hp[i]/dano) - (hp[i]/(dano+pow[i])) );
            //cout << "pushed " << (hp[i]/dano) - (hp[i]/(dano+pow[i])) << endl;
        }
        for (int i=0; i<mana; i++){
            //cout << "tempo = " << tempo << ", menos " << timesaved.top() << " igual a ";
            tempo -= timesaved.top();
            //cout << tempo << endl;
            timesaved.pop();
        }
        printf("%.4Lf\n", tempo);
    }

    return 0;
}

