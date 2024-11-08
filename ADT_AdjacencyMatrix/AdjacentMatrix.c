#include "AdjacentMatrix.h"
#include <stdio.h>
#include <stdlib.h>

// Create a graph with n vertices and m edges
graph_t create_graph(const int n, const int m, const int weighted) {
    graph_t graph = malloc(sizeof(graph_t));
    if (graph == NULL) return NULL;
    graph->vertex_num = n;
    graph->edge_num = m;
    graph->weighted = weighted;
    graph->matrix = (int**)malloc(sizeof(int*) * (n + 1));
    if (graph->matrix == NULL) {
        free(graph);
        return NULL;
    }
    graph->matrix[0] = NULL;
    for (int i = 1; i <= n; ++i) {
        graph->matrix[i] = (int*)malloc(sizeof(int) * (n + 1));
        if (graph->matrix[i] == NULL) {
            for (int j = 1; j <= i; ++j)
                free(graph->matrix[j]);
            free(graph->matrix);
            free(graph);
            return NULL;
        }
        for (int j = 1; j <= n; ++j)
            graph->matrix[i][j] = 0;
    }

    return graph;
}

// Destroy a graph
void destroy_graph(graph_t *graph) {
    graph_t g = *graph;
    for (int i = 1; i <= g->vertex_num; ++i)
        free(g->matrix[i]);
    free(g->matrix);
    free(g);
    *graph = NULL;
}

// Add an edge to the graph
void add_edge(graph_t graph, const int u, const int v, const int w) {
    graph->matrix[u][v] = graph->weighted ? w : 1;
}

// Remove an edge from the graph
void remove_edge(graph_t graph, const int u, const int v) {
    graph->matrix[u][v] = 0;
}

// Print the graph
void print_graph(graph_t graph) {
    for (int i = 1; i <= graph->vertex_num; ++i) {
        for (int j = 1; j <= graph->vertex_num; ++j)
            printf("%d ", graph->matrix[i][j]);
        printf("\n");
    }
}
