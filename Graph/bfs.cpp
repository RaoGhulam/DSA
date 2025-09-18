#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct path_relation
{
    int child_index;
    int parent_index;
    path_relation(int a, int b) : child_index(a), parent_index(b) {}
};

// Global Variables
vector<char> vertices = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
vector<vector<int>> adjacency_matrix = {
    {0, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0}};

vector<int> path_reconstruction(vector<path_relation> v, int end_index)
{
    vector<int> path;
    path.push_back(end_index);
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i].child_index == end_index)
        {
            path.push_back(v[i].parent_index);
            end_index = v[i].parent_index;
        }
    }
    reverse(path.begin(), path.end());
    return path;
}

void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << vertices[v[i]] << " ";
    }
    cout << endl;
}

// BFS Algorithm
void bfs(char start, char end)
{
    int start_index = -1, end_index = -1;
    int n = vertices.size();

    for (int i = 0; i < n; i++)
    {
        if (vertices[i] == start)
            start_index = i;
        if (vertices[i] == end)
            end_index = i;
    }

    if (start_index == -1 || end_index == -1)
    {
        cout << "Start or end node not found." << endl;
        return;
    }

    vector<bool> visited(n, false);
    vector<path_relation> path;
    queue<int> q;

    q.push(start_index);
    visited[start_index] = true;

    while (!q.empty())
    {
        int current_index = q.front();
        q.pop();

        if (current_index == end_index)
        {
            cout << "Goal Found" << endl;
            // Display visited in order (if required, build a visited_order list)
            vector<int> final_path = path_reconstruction(path, end_index);
            display(final_path);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (adjacency_matrix[current_index][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
                path.emplace_back(i, current_index);
            }
        }
    }
    cout << "\nGoal Not Found" << endl;
}

int main()
{
    bfs('A', 'E');
    return 0;
}