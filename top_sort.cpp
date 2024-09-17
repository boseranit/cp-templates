#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forr(i,a,n) for (int i = (a); i < (n); ++i)
#define rforr(i,a,n) for (int i = (a); i > (n); --i)
#define ALL(x) x.begin(),x.end()
#define LEN(X) ((int)(X).size())
#define CASET int _T; cin >> _T; forr(caset,0,_T)
#define sq(x) (x)*(x)
//#define int ll

/*
 * See Competitive Programmers Handbook p150.
 * Topological sort of a directed graph is an ordering of the nodes
 * such that node a appears before b if there is a path from a to b 
 * The idea is to go through nodes and always begin a DFS at node if it has not
 * been processed yet. There are three possible states:
 * state 0: initial state
 * state 1: a search has reached the node 
 * state 2: all successors of the node have been processed
 */

bool dfs(int node, vector<vector<int>>& graph, vector<int>& state, vector<int>& order) {
    for (int nb : graph[node]) {
        if (state[nb] == 1) { // there is a cycle in the graph
            return false;
        } else if (state[nb] == 2) { // already done processing this
            continue;
        }
        state[nb] = 1;
        bool b = dfs(nb, graph, state, order);
        if (!b) return false;
    }
    state[node] = 2; // done processing
    order.push_back(node);
    return true;
}

vector<int> topologicalSort(int k, vector<vector<int>>& graph) {
    vector<int> order;
    vector<int> state (k,0);
    for (int s = 0; s < k; ++s) {
        // start at s
        if (state[s] == 2) continue;
        state[s] = 1;
        bool b = dfs(s, graph, state, order);
        if (!b) return vector<int>();
    }
    reverse(order.begin(),order.end());
    return order;
}
