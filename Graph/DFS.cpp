#include <iostream>
using namespace std;

void DFS(int adjacency_matrix[7][7], int i, bool visited[7]) {
    visited[i] = true;
    cout << i << " ";

    for (int j = 0; j < 7; j++) {
        // Recur for all adjacent nodes that are not yet visited
        if (adjacency_matrix[i][j] == 1 && !visited[j]) {
            DFS(adjacency_matrix, j, visited);
        }
    }
}

int main() {
    int adjacency_matrix[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    bool visited[7] = {false};
    DFS(adjacency_matrix, 4, visited);
    return 0;
}
