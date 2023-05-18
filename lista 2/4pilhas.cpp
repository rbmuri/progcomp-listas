#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <queue>
 
//logica

using namespace std;

int a[101], b[101], c[101];
int mtx[101][101][101] = {-1};



int rec(int x, int y, int z){
    if (mtx[x][y][z]!=-1) return mtx[x][y][z];
    if (mtx)
    if (x=y=z=0) return 1;
    if ( (x+y)%3==0 )
    if ( (x+z)%3==0 )
    if ( (y+z)%3==0 )
    if ( (x+y+z)%3==0 )
    if ( (x)%3==0 )
    if ( (y)%3==0 )
    if ( (z)%3==0 )
}

int main(){
    int n, i, temp;
    cin >> n;
    while (n){
        for (i=1; i<n+1; i++){
            cin >> a[i];
            cin >> b[i];
            cin >> c[i];
        }
        
    }
    


    return 0;
}
