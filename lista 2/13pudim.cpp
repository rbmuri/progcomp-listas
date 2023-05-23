
#include <bits/stdc++.h>

using namespace std;

int mtx[5001][50001] = {0};

int main(){
    string str1, str2;

    getline(cin, str1);
    getline(cin, str2);
    for (int i=1; i<=str1.size(); i++){
        for (int j=1; j<=str2.size(); j++){
            if (str1[i-1]==str2[j-1]){
                //cout << str1[i-1] << str2[j-1] << endl;
                //cout << "mtx[" << i << "][" << j << 
                //"] = " << mtx[i-1][j-1] << " + 1";
                mtx[i][j] = mtx[i-1][j-1] + 1;
                //cout << " = " << mtx[i][j] << endl;
            } else mtx[i][j] = max ( mtx[i][j-1], mtx[i-1][j] );
        }
    }
//    for (int i=0;i<=str1.size(); i++){
//        for (int j=0;j<=str2.size(); j++)
//            cout << mtx[i][j] << " ";
//        cout << endl;
//    }
    cout << mtx[str1.size()][str2.size()] << endl;
    return 0;
}