/*
yinghong zhong
22/08/2019
finish the missing function from the graph ADT GraphAL.c in the week 7 Graph lecture
6. function_AL_freeGraph.c
7. function_AL_isEdge.c
8. function_AL_removeV.c
 */

int isEdge(Edge e, Graph g) {
    int found = 0;
    if (g != NULL && validV(g, e.v) && validV(g, e.w)) {
        List vx = g->edges[e.v];
        while (vx != NULL && !found) {
            if (vx->name == e.w) {
                found = 1;
            }
            vx = vx->next;
        }
    }
    return found;
}

Graph freeGraph(Graph g) {
    if (g != NULL) {
        for (int i = 0; i < g->nV; i++) { //free every node in the row linked list
            List vx = g->edges[i];
            while(vx != NULL) {
                List tmp = vx; //save this node 
                vx = vx->next; //move to the next node 
                free(tmp);
            }
        }
        free(g->edges);
        free(g);
        g = NULL;
    }
    return g;
}

//remove v from w's list
static int removeV(Graph g, Vertex v, Vertex w) { // return 1 if found&removed
    int success = 0;
    if (g == NULL) {
        fprintf(stderr, "removeV: graph not initialised\n");
    } else {
        if (!validV(g, v) || validV(g, w)) {
            fprintf(stderr, "removeV: invalid vertice\n");
        } else {
            List vx = g->edges[w];
            List pre = NULL; //previous node
            while (vx != NULL && !success) {
                if (vx->name == v) {
                    List vx_next = vx->next; 
                    if (pre == NULL) { //this is the first node
                        g->edges[w] = vx_next;
                    } else {
                        pre->next = vx_next;
                    }
                    success = 1;
                    free(vx);
                }
                pre = vx;
                vx = vx->next;
            }
        }
    }
    
    return success;
}
