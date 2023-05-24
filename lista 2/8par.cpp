o
 
//???
int vet[1000];
int dy[1000][1000];
using namespace std;

int func2(int x, int y);

int func1(int x, int y){
    if(dy[x][y]!=-1) return dy[x][y];
    if(x==y) return 0; 
    int res = max(
        vet[x] + func2(x+1, y), 
        vet[y] + func2(x, y-1)
        );
    dy[x][y] = res;
    return res;
}
int func2(int x, int y){
    if(dy[x][y]!=-1) return dy[x][y];
    if(x==y) return 0;
    int res = min(
        func1(x, y-1),
        func1(x+1, y)
        );
    dy[x][y] = res;
    return res;
}

int main(){
    int n, temp;
    cin >> n;
    while (n){
        memset(dy, -1, sizeof(dy));
        for (int i=0; i<(2*n); i++){
            cin >> temp;
            temp = temp%2;
            if (temp) vet[i] = 0;
            else vet[i] = 1;
        }
        cout << func1(0, (n*2)-1) << endl;
        cin >> n;
    }


    return 0;
}

