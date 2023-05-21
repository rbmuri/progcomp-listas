#include <bits/stdc++.h>
 
//logica

using namespace std;

int a[101], b[101], c[101];
int mtx[101][101][101];

int it=0;

int rec(int x, int y, int z){
    it++;
    int res=0;
    if (mtx[x][y][z]!=-1) {
        return mtx[x][y][z];
        }

    if (x==0 && y==0 && z==0) {mtx[x][y][z]=1; 
    
    return 1;
    }
    if (x==0 && y==0 && c[z]%3!=0) {mtx[x][y][z]=0; return 0;}
    if (x==0 && z==0 && b[y]%3!=0) {mtx[x][y][z]=0; return 0;}
    if (y==0 && z==0 && a[x]%3!=0) {mtx[x][y][z]=0; return 0;}
    if (x==0 && b[y]%3!=0 && c[z]%3!=0 && (b[y]+c[z])%3!=0 ) 
    {mtx[x][y][z]=0; return 0;}
    if (y==0 && a[x]%3!=0 && c[z]%3!=0 && (a[x]+c[z])%3!=0 ) 
    {mtx[x][y][z]=0; return 0;}
    if (z==0 && b[y]%3!=0 && a[x]%3!=0 && (b[y]+a[x])%3!=0 ) 
    {mtx[x][y][z]=0; return 0;}

    if ( x!=0 && y!=0 && (a[x]+b[y])%3==0 ) {
        if (res<1)
        res = rec(x-1, y-1, z);
        }
    if ( x!=0 && z!=0 && (a[x]+c[z])%3==0 ) {
        if (res<1)
        res = rec(x-1, y, z-1);
        }
    if ( y!=0 && z!=0 && (b[y]+c[z])%3==0 ) {
        if (res<1)
        res = rec(x, y-1, z-1);
        
        }
    if ( x!=0 && y!=0 && z!=0 && (a[x]+b[y]+c[z])%3==0 ) {

        if (res<1)
        res = rec(x-1, y-1, z-1);
        }
       
    if ( x!= 0 && (a[x])%3==0 ) {
        if (res<1)
        res = rec(x-1, y, z);
        }
    if ( y!= 0 && (b[y])%3==0 ) {
        if (res<1)
        res = rec(x, y-1, z);
        }
    if ( z!= 0 && (c[z])%3==0 ) {
    
        if (res<1)
        res = rec(x, y, z-1);
        }

    mtx[x][y][z] = res;
    return mtx[x][y][z];
}

int main(){
    
    int n, i, temp, fin;
    cin >> n;
    while (n){
        memset(mtx, -1, sizeof(mtx));
        
        for (i=n; i>0; i--){
            cin >> a[i];
            cin >> b[i];
            cin >> c[i];
        }
        
        fin = rec(n, n, n);
        
        cout << fin << "\n";
        cin >> n;
        
    }
    


    return 0;
}
