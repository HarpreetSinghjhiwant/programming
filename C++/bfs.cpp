#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class vertex {
public:
    int id = -1;
    int d = 999999;
    vertex* p = nullptr;
};

int ver = 0;
int ar[100][100] = {0};
vector<bool> visited;
vector<vertex*> v;

void bfs(int a) {
    for (int i = 0; i < ver; i++) {
        vertex* c = new vertex;
        c->id = i;
        visited.push_back(false);
        v.push_back(c);
    }
    v[a]->d = 0;
    queue<vertex*> q;
    q.push(v[a]);
    while (!q.empty()) {
        vertex* u = q.front();
        q.pop();
        for (int i = 0; i < ver; i++) {
            if (!visited[i] && ar[u->id][i] != 0) {
                if (v[i]->d > u->d + ar[u->id][i]) {
                    v[i]->d = u->d + ar[u->id][i];
                    v[i]->p = u;
                    q.push(v[i]);
                }
            }
        }
        visited[u->id] = true;
    }

    for (int i = 0; i < ver; i++) {
        cout << v[i]->id << " " << v[i]->d << endl;
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < ver; i++) {
        delete v[i];
    }
}

int main() {
    int a, b, c;
    cout << "Enter number of vertices\n";
    cin >> a;
    ver = a;
    int choice = -1;
    while (1) {
        cout << "Enter 1 - add edge\n";
        cout << "Enter 0 - bfs\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter initial vertex\n";
                cin >> b;
                cout << "Enter final vertex\n";
                cin >> c;
                if (b < ver && c < ver) {
                    ar[b][c] = 1;
                    cout << "Edge added\n";
                } else {
                    cout << "Invalid vertex indices\n";
                }
                break;
            case 0:
                cout << "Enter start vertex\n";
                int d;
                cin >> d;
                bfs(d);
                break;
            default:
                cout << "No match to your selection\n";
                break;
        }
    }

    return 0;
}
