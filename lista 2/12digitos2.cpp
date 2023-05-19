#include <bits/stdc++.h>

using namespace std;

int sum[10];


int main(){
    sum[0] = 0;
    sum[1] = 1;
    sum[2] = 3;
    sum[3] = 6;
    sum[4] = 10;
    sum[5] = 15;
    sum[6] = 21;
    sum[7] = 28;
    sum[8] = 36;
    sum[9] = 45;

    int l, r, low, high, d, res, cur;
    string str, strtemp;
    while (cin >> l >> r){
        if (l>0) l--;
        str = to_string(r);
        res=0, d=10;
        if (r>9){

        low = stoi( str.substr(0, str.size()-1) );
        strtemp = str[str.size()-1];
        cur = stoi(strtemp);
        res += low*45;
        res += sum[cur];

        for (int i=(str.size()-2); i>0; i--){
            //cout << "(" << i << ") " << "BREAKPOINT!!\n";
            low = stoi( str.substr(0, i) );
            //cout << "BREAKPOINT!!\n";
            high = stoi( str.substr(i+1, (str.size()-i-1) ) );
            //cout << "BREAKPOINT!!\n";
            strtemp = str[i];
            cur = stoi(strtemp);
            res += low*45*d;
            res += (high+1)*cur;
            res += sum[cur-1]*d;

            d = d*10;
        }
        
        high = stoi( str.substr(1, (str.size()-1) ) );
        strtemp = str[0];
        cur = stoi(strtemp);
        res += (high+1)*cur;
        res += sum[cur-1]*d;
        } else res += sum[r];

        str = to_string(l);
        d = 10;

        if (l>9){

        low = stoi( str.substr(0, str.size()-1) );
        strtemp = str[str.size()-1];
        cur = stoi(strtemp);
        res -= low*45;
        res -= sum[cur];

        for (int i=(str.size()-2); i>0; i--){
            //cout << "(" << i << ") " << "BREAKPOINT!!\n";
            low = stoi( str.substr(0, i) );
            //cout << "BREAKPOINT!!\n";
            high = stoi( str.substr(i+1, (str.size()-i-1) ) );
            //cout << "BREAKPOINT!!\n";
            strtemp = str[i];
            cur = stoi(strtemp);
            res -= low*45*d;
            res -= (high+1)*cur;
            res -= sum[cur-1]*d;

            d = d*10;
        }
        
        high = stoi( str.substr(1, (str.size()-1) ) );
        strtemp = str[0];
        cur = stoi(strtemp);
        res -= (high+1)*cur;
        res -= sum[cur-1]*d;
        } else if (l>0) res -= sum[l];

        if (res==1535887748 || res ==-1535887748) cout << l << " " << r << "\n";
        cout << res << "\n";
    }
    return 0;
}