#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[11], t, n, temp, temp2[11];
    string question;
    queue<int> q;

    cin >> t;
    for (int i = 0; i<t; i++){
        //cout << "break!!\n";
        cin >> n;
        int arr[11] = {0}, temp2[11] = {0};
        arr[5] = 1;
        for (int j = 0; j<n; j++){
            cin >> temp;
            for (int k=0; k<11; k++){
                temp2[k] = arr[k];
                //cout << temp2 << " " << temp << " " << "break!!\n";
                arr[k] = 0;
            }
            for (int k=0; k<11; k++){
                int wdif = k-5;
                //cout << temp2 << " " << temp << " " << "break!!\n";
                if (temp2[k]){
                    if ( (wdif+temp) < 6 && (wdif+temp) > -6 ){
                        //cout << k << " " << temp << " " << "break!!\n";
                        arr[k+temp] = 1;
                    }
                    if ( (wdif-temp) < 6 && (wdif-temp) > -6 ){
                        //cout << k << " " << temp << " " << "break!!\n";
                        arr[k-temp] = 1;
                    }
                }
            }

        }
        question = "Ho Ho Ho!\n";
        for (int j=0; j<11; j++){
            if (arr[j]){
                //cout << j << "\n";
                question = "Feliz Natal!\n";
                
            }
        }
        cout << question;
        
    }
    return 0;
}