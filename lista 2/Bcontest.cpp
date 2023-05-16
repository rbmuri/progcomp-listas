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
    string str;
    int q=0;
    cin >> str;
    for (int i = 0; i<str.size(); i++){
        if(str[i]=='Q') for(int j = i+1; j<str.size(); j++){
            if(str[j]=='A') for(int k = j+1; k<str.size(); k++){
                if(str[k]=='Q') q++;

        }

        }

        }
    cout << q << endl;
    return 0;
}
