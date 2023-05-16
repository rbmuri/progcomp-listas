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
    int t, n, k, res;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> n >> k;
        res = k*(n/k) + min( (n%k), (k/2) );
        cout << res << endl;

    }

    return 0;
}
