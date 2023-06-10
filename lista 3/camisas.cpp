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
    int t, c, ppl;
	string tam1, tam2;
    cin >> t;
    for (int l=0; l<t; l++){
        cin >> c >> ppl;
		int h = ppl+7;
        struct dinitz d(ppl+8);
		d.add(h-1, h, c/6);
		d.add(h-2, h, c/6);
		d.add(h-3, h, c/6);
		d.add(h-4, h, c/6);
		d.add(h-5, h, c/6);
        d.add(h-6, h, c/6);

		for (int i = 1; i<=ppl; i++){
			cin >> tam1 >> tam2;
			d.add(0, i, 1);
			d.add(i, h-dic[tam1], 1);
			d.add(i, h-dic[tam2], 1);
		}
		
		if (d.max_flow(0, h)==ppl)
			cout << "YES" << endl;
		else cout << "NO" << endl;
        
    }

    return 0;
}  