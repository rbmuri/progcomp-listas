#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;


int main(){
    
    int n, k, l;
    string str;
    while (cin >> n){
        if (n==0) break;
        set<string> s;
        vector<string> v;
        bool bom = true;
        for (int i=0; i<n; i++){
            cin >> str;
            if (s.count(str)) bom = false;
            s.insert(str);
            v.push_back(str);
        }
        for (int i=0; i<n; i++){
            str = v[i];
            string sub = "";
            for (int l = 0; l<str.size()-1; l++){
                sub = sub + str[l];
                if (s.count(sub)) {
                    bom = false;
                    break;
                }
            }
            if (!bom) break;
        }
        if (bom) cout << "Conjunto Bom\n";
        else cout << "Conjunto Ruim\n";
    }
    
    return 0;
}