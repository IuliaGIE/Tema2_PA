#include <fstream>
#include <vector>
using namespace std;

const int NMAX = int(1e5) + 7;
int N, M;
vector<int> g[NMAX * 2], gt[NMAX * 2], s;
vector<bool> visited(NMAX * 2, false), truthValue(NMAX * 2, false);

int non(int v) {
    if (v > N) {
        return v - N;
    } else {
        return v + N;
    }
}

void addEdge(int a, int b) {
    g[non(a)].push_back(b);
    g[non(b)].push_back(a);
    gt[a].push_back(non(b));
    gt[b].push_back(non(a));
}

void df(int v) {
    visited[v] = true;
    for (int i = 0; i < (int)g[v].size(); i++) {
        if (!visited[g[v][i]]) {
            df(g[v][i]);
        }
    }
    s.push_back(v);
}

void df1(int v, bool *solution) {
    if (truthValue[v]) {
        *solution = false;
    }
    truthValue[non(v)] = true;
    visited[v] = true;
    for (int i = 0; i < (int)gt[v].size(); i++) {
        if (!visited[gt[v][i]]) {
            df1(gt[v][i], solution);
        }
    }
}

int main() {
    ifstream fin("scandal.in");
    ofstream fout("scandal.out");

    fin >> N >> M;
    int a, b, t;
    bool solution = true;

    // adaugam conform cazurilor
    for (int i = 0; i < M; i++) {
        fin >> a >> b >> t;
        if (t == 0) {
            addEdge(a, b);
            continue;
        }
        if (t == 1) {
            addEdge(b + N, a);
            continue;
        }
        if (t == 2) {
            addEdge(a + N, b);
            continue;
        }
        addEdge(a + N, b + N);
    }

    for (int i = 1; i <= (N * 2); i++) {
        if (!visited[i]) {
            df(i);
        }
    }
    fill(visited.begin(), visited.end(), false);

    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        if (!visited[*it] && !visited[non(*it)]) {
            df1(*it, &solution);
        }
    }
    if (solution) {
        int nr = 0;
        for (int i = 1; i <= N; i++) {
            nr += truthValue[i];
        }

        fout << nr << "\n";
        for (int i = 1; i <= N; i++) {
            if (truthValue[i]) {
                fout << i << "\n";
            }
        }
        return 0;
    }

    fout << -1;
    return 0;
}
