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
    int n;
    bool found;
    cin >> n;
    int col[n];
    int high = 1;
    for (int i=0; i<n; i++){
        cin >> col[i];
    }
    for (int i=1; i<n; i++){
        found = true;
        if (high>i || high>n-1-i) continue;
        for (int j=0; j<(high+1); j++){
            if (! ( ((col[i-j])>=high+1-j) && ((col[i+j])>=high+1-j) ) ) {
                found = false;
                break;
            }
        }
        if (found) {
            high++;
            i--;
        }
    }
    cout << high << endl;

    return 0;
}

