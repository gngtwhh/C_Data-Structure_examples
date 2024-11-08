#ifndef ADJACENT_MATRIX_H
#define ADJACENT_MATRIX_H

typedef struct graph_node_s {
    int vertex_num;
    int edge_num;
    int weighted; // 0 for unweighted graph, 1 for weighted graph
    int** matrix;
} *graph_t;

// Create a graph with n vertices and m edges
graph_t create_graph(const int n, const int m, const int weighted);
// Destroy a graph
void destroy_graph(graph_t *graph);
// Add an edge to the graph
void add_edge(graph_t graph, const int u, const int v, const int w);
// Remove an edge from the graph
void remove_edge(graph_t graph, const int u, const int v) ;
// Print the graph
void print_graph(graph_t graph);

#endif //ADJACENT_MATRIX_H
