#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int matrix[n][n];
    vector<vector<int>> adj_list(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1)
            {
                adj_list[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " : ";
        for (int adj_node : adj_list[i])
        {
            cout << adj_node << " ";
        }
        cout << endl;
    }

    return 0;
}
