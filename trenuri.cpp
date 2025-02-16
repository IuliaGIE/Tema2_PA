#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

// functia de cautarea in adancime (DFS)
int dfs(string city, string end, map<string, vector<string>>& adj,
        map<string, int>& maxCities, map<string, bool>& visited) {
    // daca orasul este orasul de destinatie
    if (city == end) {
        return 1;
    }
    // daca orasul a fost vizitat
    if (visited[city]) {
        // returneaza numarul maxim de orase de la acest oras
        return maxCities[city];
    }
    // orasul curent vizitat
    visited[city] = true;

    // pentru fiecare oras adiacent
    for (int i = 0; i < (int)adj[city].size(); i++) {
        // actualizam numarul maxim de orase de la acest oras
        maxCities[city] = max(maxCities[city],
                              dfs(adj[city][i], end,
                                  adj, maxCities, visited) + 1);
    }
    // numarul maxim de orase de la acest oraa
    return maxCities[city];
}

int main() {
    ifstream fin("trenuri.in");
    ofstream fout("trenuri.out");
    map<string, vector<string>> adj;
    map<string, int> maxCities;
    map<string, bool> visited;
    string start, end;
    fin >> start >> end;

    int M;
    fin >> M;

    // ruta directa
    for (int i = 0; i < M; i++) {
        string x, y;
        // orasele rutei directe
        fin >> x >> y;
        // adauga ruta la lista de adiacenta
        adj[x].push_back(y);
    }

    // DFS de la orasul de start la orasul de destinatie
    fout << dfs(start, end, adj, maxCities, visited);
    fin.close();
    fout.close();
    return 0;
}
