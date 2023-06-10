#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

// Dinitz
//
// O(min(m * max_flow, n^2 m))
// Grafo com capacidades 1: O(min(m sqrt(m), m * n^(2/3)))
// Todo vertice tem grau de entrada ou saida 1: O(m sqrt(n))

struct dinitz {
	const bool scaling = false; // com scaling -> O(nm log(MAXCAP)),
	int lim;                    // com constante alta
	struct edge {
		int to, cap, rev, flow;
		bool res;
		edge(int to_, int cap_, int rev_, bool res_)
			: to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
	};

	vector<vector<edge>> g;
	vector<int> lev, beg;
	ll F;
	dinitz(int n) : g(n), F(0) {}

	void add(int a, int b, int c) {
		g[a].emplace_back(b, c, g[b].size(), false);
		g[b].emplace_back(a, 0, g[a].size()-1, true);
	}
	bool bfs(int s, int t) {
		lev = vector<int>(g.size(), -1); lev[s] = 0;
		beg = vector<int>(g.size(), 0);
		queue<int> q; q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto& i : g[u]) {
				if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
				if (scaling and i.cap - i.flow < lim) continue;
				lev[i.to] = lev[u] + 1;
				q.push(i.to);
			}
		}
		return lev[t] != -1;
	}
	int dfs(int v, int s, int f = INF) {
		if (!f or v == s) return f;
		for (int& i = beg[v]; i < g[v].size(); i++) {
			auto& e = g[v][i];
			if (lev[e.to] != lev[v] + 1) continue;
			int foi = dfs(e.to, s, min(f, e.cap - e.flow));
			if (!foi) continue;
			e.flow += foi, g[e.to][e.rev].flow -= foi;
			return foi;
		}
		return 0;
	}
	ll max_flow(int s, int t) {
		for (lim = scaling ? (1<<30) : 1; lim; lim /= 2)
			while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
		return F;
	}
};

map<string, int> dic{
	{"XS", 1},
	{"S", 2},
	{"M", 3},
	{"L", 4},
	{"XL", 5},
	{"XXL", 6}
};

int main(){

	int nt, nc, nj, t1, t2;
    char c;
    cin >> nt >> nc >> nj;
    while (nt) {
        int total = ( nc*nt*(nt-1) )/2;
        int timespt[nt] = {0}; 
        int jogos[nt-1][nt];
        for (int i=0; i<nt-1; i++){
            for (int j=0; j<nt; j++){
                jogos[i][j] = nc;
            }
        }
        int l=1;
        int njr=0;
        
        for (int i = 0; i<nj; i++){
             cin >> t1 >> c >> t2;
             //cout << "break pt" << t1 <<
             //" = " << timespt[t1] << " pt" <<
             //t2 << " = " << timespt[t2] << endl;
             if (c=='=') {
                timespt[t1]++;
                timespt[t2]++;
             }
             if (c=='<') {
                timespt[t2]++;
                timespt[t2]++;
             }
             if (t1>t2) jogos[t2][t1]--;
             if (t2>t1) jogos[t1][t2]--;
             //cout << "break pt" << t1 <<
             //" = " << timespt[t1] << " pt" <<
             //t2 << " = " << timespt[t2] << endl;
        }
		
		int v = nt+total+2;
		struct dinitz d(v);
        for (int i = 1; i<nt; i++){
			if (jogos[0][i]>0) {
                timespt[0] += 2*jogos[0][i];
                jogos[0][i] = 0;
                }

		}
        
        for (int i = 1; i<nt-1; i++){
			for (int j = i+1; j<nt; j++){
                
                
                if (jogos[i][j]>0)
                for (int o = 0; o<jogos[i][j]; o++){
                d.add(0, nt+l, 2);
                d.add(nt+l, i, 2);
                d.add(nt+l, j, 2);
                njr++;
                l++;
                }
                }
		}
        
		for (int i = 1; i<nt; i++){
			d.add(i, v-1, timespt[0]-timespt[i]-1);
            //cout << "break " << i << " val ="
            // << timespt[0] << " "<< timespt[i] << endl;
		}
		//cout << "break max flow= " << d.max_flow(0, v-1) << endl;
		if (d.max_flow(0, v-1)==njr*2) cout << "Y" << endl;
        else cout << "N" << endl;
		
        cin >> nt >> nc >> nj;
    }

    return 0;
}  