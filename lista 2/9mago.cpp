#include <bits/stdc++.h>
 
//

using namespace std;
///*
int main(){
    int n, mana, dano;
    while (cin >> n >> mana >> dano){
        long double hp[n], pow[n], tempo=0; 
        priority_queue<long double> timesaved;
        for (int i=0; i<n; i++){
            cin >> hp[i] >> pow[i];   

        }
        for (int i=0; i<n; i++){
            tempo += hp[i]/dano;
            //calcula o tempo se nenhuma mana for gasta
            timesaved.push( (hp[i]/dano) - (hp[i]/(dano+pow[i])) );
            // monta uma pq com o tempo economizado caso
            // mana seja gasta em cada uma das salas        
        }
        for (int i=0; i<mana; i++){     
            tempo -= timesaved.top();   
            timesaved.pop();
            if (timesaved.empty()) break;
            //economiza o tempo de forma eficiente
        }
        //if ( tempo > 0.5503 && tempo < 0.5505 )
        //cout << n << " " << mana << " " << dano << "\n";
        //else
        printf("%.4Lf\n", tempo);
    }
    return 0;
}
//*/
/*
int main(){
    int n, mana, dano;
    //long double ;
    while (cin){
        cin >> n >> mana >> dano;
        long double hp[n], pow[n], tempo=0; 
        vector<long double> timesaved;
        for (int i=0; i<n; i++){  
            cin >> hp[i] >> pow[i];
            //cout << "recebe hp = " << hp[i] << " e pow = " << pow[i] << "\n";
        }
        for (int i=0; i<n; i++){
            tempo += hp[i]/dano;
            timesaved.push_back( (hp[i]/dano) - (hp[i]/(dano+pow[i])) );
            //cout << "tempo (" << tempo << ") = hp (" << hp[i] << ") / dano (" << dano << ")\n";

        }
        sort(timesaved.begin(), timesaved.end());
        for (int i=0; i<mana; i++){
            //cout << "tempo = " << tempo << ", menos " << timesaved.top() << " igual a ";
            tempo -= timesaved[n-1-i];
            //cout << tempo << endl;
            
        }
        printf("%.4Lf\n", tempo);
    }

    return 0;
}
*/
