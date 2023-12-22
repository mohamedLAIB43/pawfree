#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    int V;

public:
    Graph(int vertex) {
        V = vertex;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool SansPatte(int start, vector<int>& colors) {
        // Fonction qui vérifie si le graphe est sans patte
        queue<int> q;
        q.push(start);
        colors[start] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adjList[u]) {
                if (colors[v] == -1) {
                    colors[v] = 1 - colors[u];
                    q.push(v);
                } else if (colors[v] == colors[u]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool Coloration() {
        // Fonction qui colore le graphe
        vector<int> colors(V, -1);
        for (int i = 0; i < V; ++i) {
            if (colors[i] == -1) {
                if (!SansPatte(i, colors)) {
                    cout << "Le graphe n'est pas sans patte." << endl;
                    return false;
                }
            }
        }

        cout << "Coloration des sommets de votre graphe" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "Sommet " << i << " : Couleur " << colors[i] << endl;
        }
        return true;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.Coloration();

    return 0;
}
