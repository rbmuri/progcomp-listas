#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main(){
    int n, alberto;
    bool alto=true;
    cin >> n >> alberto;
    for (int i=1; i<n; i++){
        int amigo;
        cin >> amigo;
        if (amigo>alberto){
            alto = false;
            break;
        }
    }
    if (alto) cout << 'S' << endl;
    else cout << 'N' << endl;
    return 0;
}