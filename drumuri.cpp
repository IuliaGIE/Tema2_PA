#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <limits>
using namespace std;

const int MAXN = 1e5 + 5;
const long long INF = 1e18;

// dijkstra pentru calculul distantei minime de la un nod la toate celelalte
void dijkstra(int src, int idx, vector<pair<int, int>> adjList[],
              long long dist[][MAXN], int N) {
    queue<int> q;
    fill(dist[idx], dist[idx] + N + 1, INF);
    dist[idx][src] = 0;
    q.push(src);

    // cat timp mai exista noduri
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Parcurge vecinii nodului curent
        for (int i = 0; i < (int)adjList[u].size(); i++) {
            // distana pana la nodul curent plus costul muchiei
            // <
            // distanta pana la vecinul curent
            if (dist[idx][u] + adjList[u][i].second <
                dist[idx][adjList[u][i].first]) {
                // actualizez distanta pana la vecin
                dist[idx][adjList[u][i].first] = dist[idx][u] +
                                                 adjList[u][i].second;
                // adaug vecinul in coada
                q.push(adjList[u][i].first);
            }
        }
    }
}

int main() {
    ifstream fin("drumuri.in");
    ofstream fout("drumuri.out");

    int N, M, x, y, z;
    fin >> N >> M;
    vector<pair<int, int>> adj[MAXN], rev_adj[MAXN];
    long long dist[3][MAXN];
    for (int i = 1; i <= M; i++) {
        fin >> x >> y >> z;
        adj[x].push_back({y, z});
        rev_adj[y].push_back({x, z});
    }
    fin >> x >> y >> z;

    // algoritmul Dijkstra pentru fiecare din cele 3 noduri
    dijkstra(x, 0, adj, dist, N);
    dijkstra(y, 1, adj, dist, N);
    dijkstra(z, 2, rev_adj, dist, N);

    long long ans = INF;
    // parcurg toate nodurile
    for (int i = 1; i <= N; i++) {
        // parcurg vecinii fiecarui nod
        for (int j = 0; j < (int)adj[i].size(); j++) {
            // minimul dintre raspunsul curent si suma distantelor
            // de la x, y si z la nodul curent
            ans = min(ans, dist[0][i] + adj[i][j].second +
                        dist[1][adj[i][j].first] + dist[2][adj[i][j].first]);
        }
    }
    fout << ans;
    fin.close();
    fout.close();
    return 0;
}
