#include <bits/stdc++.h>
using namespace std;
int pa[300005];
int find(int x)
{
    return pa[x] == x ? x : pa[x] = find(pa[x]);
}
void merge(int x, int y) { pa[find(x)] = find(y); }
int n, m;
vector<pair<int, int>> vp;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        pa[i] = i;
    }
    vp.resize(m + 1);
    vector<int> vis(n + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> vp[i].first >> vp[i].second;
        if (find(vp[i].first) == find(vp[i].second))
        {
            cout << "No" << endl;
            return 0;
        }
        merge(vp[i].first, vp[i].second);
        vis[vp[i].first] = 1;
        vis[vp[i].second] = 1;
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= m - 1; i++)
    {
        if (find(vp[i].first) != find(vp[i + 1].first))
        {
            cout << vp[i].first << " " << vp[i + 1].first << endl;
            cout << vp[i + 1].first << " " << vp[i].second << endl;
            merge(vp[i].first, vp[i + 1].first);
        }
        else
        {
            cout << vp[i].first << " " << vp[i].second << endl;
        }
    }
    cout << vp[m].first << " ";
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            cout << i << endl
                 << i << " ";
    }
    cout << vp[m].second << endl;
}