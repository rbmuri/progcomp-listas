#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

class segtree{
    public:
    vector<int> tree;
    int n;

    void build(vector<int> &vec, int node, int start, int end){
        if (start==end) {
            tree[node] = vec[start];
        } else {
            int 
        }
        
    }

    segtree(vector<int> &vec){
        int size = vec.size()*4;
        tree.resize(size);
        build(vec, 1, 0, size);
    }

};

int main(){
    

    return 0;
}