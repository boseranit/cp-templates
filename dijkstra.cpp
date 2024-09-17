#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'shortestReach' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 *  3. INTEGER s
 */
// tested on hackerrank Dijkstra: Shortest Reach 2

vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    vector<vector<pair<int,int>>> adj (n);
    for (vector<int> row : edges) {
        int a = row[0]; int b = row[1]; int c = row[2];
        adj[a-1].push_back(make_pair(b-1, c));
        adj[b-1].push_back(make_pair(a-1, c));
    }
    vector<int> dist (n,-1);
    dist[s-1] = 0;
    // min heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; 
    q.push(make_pair(0,s-1));
    while (!q.empty()) {
        // node in q with smallest distance
        auto [d, node] = q.top();
        q.pop();
        if (dist[node] < d) continue; // already considered better path
        for (auto [nb, eval] : adj[node]){ // neighbours which are in q
            int alt = d + eval;
            if (alt < dist[nb] || dist[nb] == -1) {
                dist[nb] = alt;
                q.push(make_pair(alt,nb));
            }
        }
    }
    dist.erase(dist.begin()+(s-1));
    return dist;
}

// with make_heap instead of priority queue
vector<int> shortestReach2(int n, vector<vector<int>> edges, int s) {
    vector<vector<pair<int,int>>> adj (n);
    for (vector<int> row : edges) {
        int a = row[0]; int b = row[1]; int c = row[2];
        adj[a-1].push_back(make_pair(b-1, c));
        adj[b-1].push_back(make_pair(a-1, c));
    }
    vector<int> dist (n,-1);
    dist[s-1] = 0;
    vector<pair<int,int>> q; // priority queue as heap
    q.push_back(make_pair(0,s-1));
    make_heap(q.begin(), q.end(), greater<>{}); // min heap
    while (!q.empty()) {
        // node in q with smallest distance
        auto [d, node] = q.front();
        pop_heap(q.begin(),q.end(), greater<>{}); q.pop_back();
        if (dist[node] < d) continue; // already considered better path
        for (pair<int,int> nbpair : adj[node]){ // neighbours which are in q
            auto [nb, eval] = nbpair;
            int alt = d + eval;
            if (alt < dist[nb] || dist[nb] == -1) {
                dist[nb] = alt;
                q.push_back(make_pair(alt,nb));
                push_heap(q.begin(), q.end(), greater<>{});
            }
        }
    }
    dist.erase(dist.begin()+(s-1));
    return dist;
}

int main()
{
    ofstream fout("output.txt");
    ifstream fin("input07.txt");

    string t_temp;
    getline(fin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(fin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(3);

            string edges_row_temp_temp;
            getline(fin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 3; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(fin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = shortestReach(n, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
