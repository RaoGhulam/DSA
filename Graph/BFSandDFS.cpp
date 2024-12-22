#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class node
{
public:
    int data;
    node(int data) : data(data) {}
    void print()
    {
        cout << data << " ";
    }
};

void BFS(vector<node> &vertices, const vector<vector<int>> &adjacency_matrix, int size)
{
    queue<int> q;
    vector<bool> visited(size, false);
    int start_node_index = 0;

    vertices[start_node_index].print();
    visited[start_node_index] = true;
    q.push(start_node_index);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int j = 0; j < size; j++)
        {
            if (adjacency_matrix[current][j] == 1 && !visited[j])
            {
                vertices[j].print();
                visited[j] = true;
                q.push(j);
            }
        }
    }
}

void DFS(vector<node> &vertices, const vector<vector<int>> &adjacency_matrix, int i, vector<bool> &visited)
{
    vertices[i].print();
    visited[i] = true;
    for (int j = 0; j < adjacency_matrix.size(); j++)
    {
        if (adjacency_matrix[i][j] == 1 && !visited[j])
        {
            DFS(vertices, adjacency_matrix, j, visited);
        }
    }
}

int main()
{
    vector<node> vertices = {node(100), node(200), node(300), node(400), node(500), node(600), node(700)};

    vector<vector<int>> adjacency_matrix = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    cout << "BFS Traversal: ";
    BFS(vertices, adjacency_matrix, 7);

    cout << "\nDFS Traversal: ";
    vector<bool> visited(7, false);
    DFS(vertices, adjacency_matrix, 0, visited);

    return 0;
}
