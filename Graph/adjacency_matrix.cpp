#include <iostream>
#include <vector>
using namespace std;

/*
------------------------------------------------------------
Representation of undirected and unweighted graph
------------------------------------------------------------
*/
void add_edge(vector<vector<int>> &adjacency_matrix, int i, int j)
{
    adjacency_matrix[i][j] = 1;
    adjacency_matrix[j][i] = 1;
}

void display_adjaceny_matrix(vector<vector<int>> &adjaceny_matrix)
{
    for (int i = 0; i < adjaceny_matrix.size(); i++)
    {
        for (int j = 0; j < adjaceny_matrix.size(); j++)
        {
            cout << adjaceny_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int rows = 4, cols = 4; // rows == number of vertices
    vector<vector<int>> adjacency_matrix(rows, vector<int>(cols, 0));
    add_edge(adjacency_matrix, 0, 1);
    add_edge(adjacency_matrix, 0, 2);
    add_edge(adjacency_matrix, 1, 2);
    add_edge(adjacency_matrix, 2, 3);

    cout << "Adjacency Matrix Representation." << endl;
    display_adjaceny_matrix(adjacency_matrix);
    return 0;
}


/*
------------------------------------------------------------
Representation of directed and unweighted graph
------------------------------------------------------------
*/
void add_edge(vector<vector<int>> &adjacency_matrix, int i, int j)
{
    adjacency_matrix[i][j] = 1;
}

void display_adjaceny_matrix(vector<vector<int>> &adjaceny_matrix)
{
    for (int i = 0; i < adjaceny_matrix.size(); i++)
    {
        for (int j = 0; j < adjaceny_matrix.size(); j++)
        {
            cout << adjaceny_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int rows = 4, cols = 4; // rows == number of vertices
    vector<vector<int>> adjacency_matrix(rows, vector<int>(cols, 0));
    add_edge(adjacency_matrix, 0, 1);
    add_edge(adjacency_matrix, 0, 2);
    add_edge(adjacency_matrix, 1, 2);
    add_edge(adjacency_matrix, 2, 3);

    cout << "Adjacency Matrix Representation." << endl;
    display_adjaceny_matrix(adjacency_matrix);
    return 0;
}


/*
------------------------------------------------------------
Representation of undirected and weighted graph
------------------------------------------------------------
*/
void add_edge(vector<vector<int>> &adjacency_matrix, int i, int j, int weight)
{
    adjacency_matrix[i][j] = weight;
    adjacency_matrix[j][i] = weight;
}

void display_adjaceny_matrix(vector<vector<int>> &adjaceny_matrix)
{
    for (int i = 0; i < adjaceny_matrix.size(); i++)
    {
        for (int j = 0; j < adjaceny_matrix.size(); j++)
        {
            cout << adjaceny_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int rows = 4, cols = 4; // rows == number of vertices
    vector<vector<int>> adjacency_matrix(rows, vector<int>(cols, 0));
    add_edge(adjacency_matrix, 0, 1, 2);
    add_edge(adjacency_matrix, 0, 2, 4);
    add_edge(adjacency_matrix, 1, 2, 1);
    add_edge(adjacency_matrix, 2, 3, 3);

    cout << "Adjacency Matrix Representation." << endl;
    display_adjaceny_matrix(adjacency_matrix);
    return 0;
}


/*
------------------------------------------------------------
Representation of directed and weighted graph
------------------------------------------------------------
*/
void add_edge(vector<vector<int>> &adjacency_matrix, int i, int j, int weight)
{
    adjacency_matrix[i][j] = weight;
}

void display_adjaceny_matrix(vector<vector<int>> &adjaceny_matrix)
{
    for (int i = 0; i < adjaceny_matrix.size(); i++)
    {
        for (int j = 0; j < adjaceny_matrix.size(); j++)
        {
            cout << adjaceny_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int rows = 4, cols = 4; // rows == number of vertices
    vector<vector<int>> adjacency_matrix(rows, vector<int>(cols, 0));
    add_edge(adjacency_matrix, 0, 1, 2);
    add_edge(adjacency_matrix, 0, 2, 4);
    add_edge(adjacency_matrix, 1, 2, 1);
    add_edge(adjacency_matrix, 2, 3, 3);

    cout << "Adjacency Matrix Representation." << endl;
    display_adjaceny_matrix(adjacency_matrix);
    return 0;
}