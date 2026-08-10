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
