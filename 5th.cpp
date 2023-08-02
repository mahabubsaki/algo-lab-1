#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int visited[N];
vector<int> adj_list[N];

void bfs(int src)
{
    queue<int> q;
    visited[src] = 1;

    q.push(src);
    while (!q.empty())
    {
        int head = q.front();
        q.pop();

        for (int adj_node : adj_list[head])
        {
            if (visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                q.push(adj_node);
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    int count = 0;
    for (int i = 0; i < edges; i++)
    {
        int from, to;
        cin >> from >> to;
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }

    for (int i = 0; i < nodes; i++)
    {
        if (visited[i] == 0)
        {
            bfs(i);
            count++;
        }
    }

    cout << count;

    return 0;
}