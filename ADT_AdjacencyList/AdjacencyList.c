#include "AdjacencyList.h"
#include <stdio.h>
#include <stdlib.h>

// Create a graph with n vertices and m edges
graph_t create_graph(const int n, const int weighted) {
    graph_t graph = malloc(sizeof(graph_t));
    if (graph == NULL) return NULL;
    graph->vertex_num = n;
    graph->edge_num = 0;
    graph->weighted = weighted;
    graph->head = (edge_t**)malloc(sizeof(edge_t*) * (n + 1));
    if (graph->head == NULL) {
        free(graph);
        return NULL;
    }
    for (int i = 0; i <= n; ++i)
        graph->head[i] = NULL;
    return graph;
}

// Destroy a graph
void destroy_graph(graph_t *graph) {
    if (graph == NULL) return;
    const graph_t g = *graph;
    if (g == NULL) return;
    for (int i = 1; i <= g->vertex_num; ++i) {
        edge_t* p = g->head[i];
        while (p != NULL) {
            edge_t* q = p;
            p = p->next;
            free(q);
        }
    }
    free(g->head);
    free(g);
    *graph = NULL;
}

// Add an edge to the graph
void add_edge(graph_t graph, const int u, const int v, const int w) {
    if (graph == NULL) return;
    edge_t* p = malloc(sizeof(edge_t));
    if (p == NULL) return;
    p->dest = v;
    p->weight = graph->weighted ? w : 1;
    p->next = graph->head[u];
    graph->head[u] = p;
    ++graph->edge_num;
}

// Remove an edge from the graph
void remove_edge(graph_t graph, const int u, const int v) {
    if (graph == NULL) return;
    edge_t* p = graph->head[u];
    if (p == NULL) return;
    if (p->dest == v) {
        graph->head[u] = p->next;
        free(p);
        --graph->edge_num;
        return;
    }
    while (p->next != NULL) {
        if (p->next->dest == v) {
            edge_t* q = p->next;
            p->next = q->next;
            free(q);
            --graph->edge_num;
            return;
        }
        p = p->next;
    }
}

// Print the graph
void print_graph(graph_t graph) {
    if (graph == NULL) return;
    printf("Vertex number: %d\n", graph->vertex_num);
    printf("Edge number: %d\n", graph->edge_num);
    printf("Weighted: %s\n", graph->weighted ? "Yes" : "No");
    for (int i = 1; i <= graph->vertex_num; ++i) {
        printf("%d: ", i);
        edge_t* p = graph->head[i];
        if (p == NULL) putchar('^');
        while (p != NULL) {
            printf("%d", p->dest);
            if (graph->weighted)
                printf("(%d)", p->weight);
            printf(" ");
            p = p->next;
        }
        printf("\n");
    }
}
