#include <bits/stdc++.h>

using namespace std;

struct DSU
{
    vector<int> p, sz;

    DSU(int n)
    {
        p.resize(n+1);
        sz.resize(n+1, 1);

        for (int i = 1; i <= n; i++) p[i] = i;
    }

    int find(int v)
    {
        if (p[v] == v) return v;
        return p[v] = find(p[v]);
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        
        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }

};

int main()
{
    int t; cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, x, y; cin >> n >> x >> y;
        vector<int> p(n+1);
        for (int i = 1; i <= n; i++) cin >> p[i];

        DSU dsu(n);
        map<int, vector<int>> comps;

        for (int i = 1; i <= n; i++)
        {
            if (i + x <= n) dsu.unite(i, i+x);
            if (i + y  <= n) dsu.unite(i, i+y);
        }

        for (int i = 1; i <= n; i++) comps[dsu.find(i)].push_back(i);

        bool ok = true;

        for (auto& [root, idxes]: comps)
        {
            vector<int> vals;
            for (int idx: idxes) vals.push_back(p[idx]);
            sort(vals.begin(), vals.end());
            sort(idxes.begin(), idxes.end());

            if (vals != idxes)
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES": "NO") << "\n";
    }
}
