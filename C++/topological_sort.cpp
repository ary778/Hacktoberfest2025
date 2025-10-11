/*
    Problem: Topological Sort (Kahn’s Algorithm - BFS)
    Difficulty: Medium
    Topic: Graphs, BFS, Sorting, DAG

    --------------------------------------------
    Problem Statement:
    Given a Directed Acyclic Graph (DAG) with 'n' vertices and 'm' edges,
    perform a Topological Sort and print the ordering of nodes.

    Topological Sort of a DAG is a linear ordering of vertices such that
    for every directed edge (u -> v), vertex 'u' comes before 'v' in the ordering.

    --------------------------------------------
    Input:
    n = 6, m = 6
    Edges:
    5 0
    5 2
    4 0
    4 1
    2 3
    3 1

    Output:
    4 5 0 2 3 1
    (Any valid topological order is acceptable)

    --------------------------------------------
    Approach:
    - Use Kahn’s Algorithm (BFS-based approach).
    - Compute in-degree of all nodes.
    - Start with all nodes having in-degree = 0.
    - Pop from queue, append to result, and decrease in-degree of adjacent nodes.
    - Continue until all nodes are processed.

    --------------------------------------------
    Time Complexity: O(V + E)
    Space Complexity: O(V)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
        for (auto v : adj[i])
            indegree[v]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (auto v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }
    return topo;
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Enter edges (u v): \n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> result = topologicalSort(n, adj);

    cout << "Topological Sort Order: ";
    for (int node : result)
        cout << node << " ";
    cout << endl;

    return 0;
}
