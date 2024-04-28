#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

class Trie {
public:
    vector<vector<int>> adj;
    int n;
    unordered_set<int> end_nodes;
    Trie() : adj(1, vector<int>(26,0)), n(1) {
        
    }
    
    void insert(string word) {
        int current_node = 0;
        for (int i = 0; i<word.size(); ++i) {
            int c = word[i] - 'a';
            if (adj[current_node][c] != 0) current_node = adj[current_node][c];
            else {
                adj[current_node][c] = n;
                adj.push_back(vector<int>(26,0));
                current_node = n;
                n++;
            }
        }
        end_nodes.insert(current_node);
    }
    
    bool search(string word) {
        int current_node = 0;
        for (int i = 0; i < word.size(); ++i) {
            int c = word[i] - 'a';
            if (adj[current_node][c] == 0) return false;
            current_node = adj[current_node][c];
        }
        if (end_nodes.find(current_node) != end_nodes.end())
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        int current_node = 0;
        for (int i = 0; i < prefix.size(); ++i) {
            int c = prefix[i] - 'a';
            if (adj[current_node][c] == 0) return false;
            current_node = adj[current_node][c];
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    return 0;
}
