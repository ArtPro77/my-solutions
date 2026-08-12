#include <bits/stdc++.h>

using namespace std;

int n, k; 
int ans = 0;
vector<int> c;
vector<vector<int>> graph;

int dfs(int v)
{
    stack<pair<int, int>> st;
    vector<bool> visited(n+1);
    st.push({1, c[1]});
    visited[1] = true;

    while (!st.empty())
    {
        int cur = st.top().first;
        int cnt = st.top().second;
        st.pop();

        if (cnt > k) continue;
        if (cur != 1 && graph[cur].size() == 1)
        {
            ans++;
            continue;
        }
        for (int to: graph[cur])
        {
            if (!visited[to])
            {
                visited[to] = true;
                if (c[to] == 1) st.push({to, cnt+1});
                else st.push({to, 0});
            }
        }
    }
    return ans;
}

int main()
{
    cin >> n >> k;
    c.assign(n+1, 0);
    graph.assign(n+1, {});

    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 0; i + 1 < n; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << dfs(1) << "\n";
}
