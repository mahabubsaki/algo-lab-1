#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

vector<int> adj_list[N];
int visited[N];

bool dfs(int node)
{
    visited[node] = 1;
    for (int adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
        {
            visited[adj_node] = 1;
            bool is_cycle = dfs(adj_node);
            if (is_cycle)
            {
                return true;
            }
        }
        else if (visited[adj_node] == 1)
        {
            return true;
        }
    }
    visited[node] = 2;
    return false;
}
int main()
{

    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int from, to;
        cin >> from >> to;
        adj_list[from].push_back(to);
    }
    bool ok = false;
    for (int i = 1; i <= nodes; i++)
    {
        if (visited[i] == 0)
        {
            bool is_cycle = dfs(i);
            if (is_cycle)
            {
                ok = true;
                break;
            }
        }
    }
    if (ok)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}