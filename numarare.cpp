#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ifstream fin("numarare.in");
    ofstream fout("numarare.out");

    int N, M;
    fin >> N >> M;

    vector<set<int>> graph(N + 1);

    int x, y;

    // Citim primul graf
    for (int i = 0; i < M; i++) {
        fin >> x >> y;
        graph[x].insert(y);
    }

    // vectorul de numarare a lanturilor elementare din nodul 1
    vector<int> pathCt(N + 1, 0);
    pathCt[1] = 1;

    // citim al doilea graf si numaram lanturile elementare simultan
    for (int i = 0; i < M; i++) {
        fin >> x >> y;
        // verificam daca muchia exista in primul graf
        if (graph[x].find(y) != graph[x].end()) {
            pathCt[y] = (pathCt[y] + pathCt[x]) % MOD;
        }
    }

    fout << pathCt[N] << endl;

    fin.close();
    fout.close();
    return 0;
}
