//
// Created by WAHAHA on 2023/12/30.
//

#include <stdio.h>
#include "AdjacentMatrix.h"

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    graph_t graph = create_graph(n, m,1);
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(graph, u, v, w);
    }
    print_graph(graph);
    destroy_graph(&graph);
    return 0;
}
