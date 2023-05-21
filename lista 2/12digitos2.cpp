#include <bits/stdc++.h>

using namespace std;

//int tb[10000000] = {-1};
int sum[10];

int func(int r){
    //if (tb[r]!=-1) return tb[r];
    int low, cur, res=0, high, d=10;
    string str = to_string(r), strtemp;
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
    //tb[r] = res;
    return res;
}



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
        if (l==0) l++;
        int res = func(r)-func(l-1);

        cout << res << "\n";
    }
    return 0;
}