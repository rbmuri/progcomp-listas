#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main(){
    string s;
    cin >> s;
    for (int i=0; i<s.size(); i++){
        if (s[i+0]=='z' || s[i+0]=='Z')
        if (s[i+1]=='e' || s[i+1]=='E')
        if (s[i+2]=='l' || s[i+2]=='L')
        if (s[i+3]=='d' || s[i+3]=='D')
        if (s[i+4]=='a' || s[i+4]=='A')
        {
            cout << "Link Bolado\n";
            return 0;
        }
    }
    cout << "Link Tranquilo\n";
    return 0;
}