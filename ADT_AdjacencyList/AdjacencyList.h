/*
 * @
 */

#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

typedef struct edge_s {
    int dest;
    int weight;
    struct edge_s* next;
} edge_t;

typedef struct graph_obj_s {
    int vertex_num;
    int edge_num;
    int weighted; // 0 for unweighted graph, 1 for weighted graph
    edge_t** head;
}* graph_t;

// Create a graph with n vertices
graph_t create_graph(const int n, const int weighted);
// Destroy a graph
void destroy_graph(graph_t *graph);
// Add an edge to the graph
void add_edge(graph_t graph, const int u, const int v, const int w) ;
// Remove an edge from the graph
void remove_edge(graph_t graph, const int u, const int v);
// Print the graph
void print_graph(graph_t graph);

#endif //ADJACENCY_LIST_H
