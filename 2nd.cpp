#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

vector<int> adj_list[N];
int visited[N], level[N];

void bfs(int src_node)
{
    queue<int> bfs_queue;
    visited[src_node] = 1;
    level[src_node] = 0;
    bfs_queue.push(src_node);
    while (!bfs_queue.empty())
    {
        int head = bfs_queue.front();
        bfs_queue.pop();
        for (int adj_node : adj_list[head])
        {
            if (visited[adj_node] == 0)
            {
                level[adj_node] = level[head] + 1;
                visited[adj_node] = 1;
                bfs_queue.push(adj_node);
            }
        }
    }
}
int main()
{
    // creating the graph with adjacent list
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int from, to;
        cin >> from >> to;
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }
    // considering 0 as source
    int src = 0;
    bfs(src);
    // printing the level of nodes
    for (int i = 0; i < nodes; i++)
    {
        cout << "node " << i << " --> level : " << level[i];
        cout << endl;
    }

    return 0;
}