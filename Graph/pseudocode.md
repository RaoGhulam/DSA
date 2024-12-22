https://www.yeschat.ai/gpts-9t557IAonxQ-Pseudocode-Translator

# Pseudocode for BFS
BFS(adjacency_matrix, size):
    Initialize queue q
    Initialize visited array of size `size` with all false
    start_node = 0
    Print start_node
    visited[start_node] = true
    Push start_node to q

    while q is not empty:
        node = front of q
        Pop node from q

        for each adjacent node j from 0 to size-1:
            if adjacency_matrix[node][j] == 1 and not visited[j]:
                Print j
                visited[j] = true
                Push j to q


# Pseudocode for DFS
DFS(adjacency_matrix, i, visited):
    Mark visited[i] as true
    Print i

    for each node j from 0 to 6:
        if adjacency_matrix[i][j] == 1 and not visited[j]:
            Call DFS(adjacency_matrix, j, visited)