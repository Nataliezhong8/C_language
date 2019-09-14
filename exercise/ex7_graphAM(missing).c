
/*yinghong zhong
22/08/2019
There are 2 functions missing from the graph ADT GraphAM.c in the week 7 Graph lecture.

int isEdge(Graph g, Edge e) returns true if the edge e exists in the graph

as it is an adjacency matrix, this is very simple to determine
Graph freeGraph(Graph g) returns the pointer to graph after freeing all its memory

the adjacency matrix is two dimensional, so in effect, each row of data in the matrix must be freed
 */
int isEdge(Edge e, Graph g) {
    int found = 0;
    if (g != NULL && validV(g, e.v) && validV(g, e.w)) {
        if(g->edges[e.v][e.w] == 1 && g->edges[e.w][e.v] == 1) {
            found = 1;
        }
    }
    return found;
}

Graph freeGraph(Graph g) {
    if (g != NULL) {
        for (int i = 0; i < g->nV; i++) { //free every row of the matrix
            free(g->edge[i]);
        }
        free(g->edge); //free the whole matrix
        free(g);
        g = NULL;
    }
    return g;
}