#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct node {
    int val;
    int weight;
    struct node* next;
} Node;

typedef struct graph {
    int nvert;
    Node* adj_list[MAX_VERTICES];
} Graph;

Graph* createGraph(int nvert) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->nvert = nvert;
    for(int i = 0; i < nvert; i++) {
        g->adj_list[i] = NULL;
    }
    return g;
}

void addEdge(Graph* g, int src, int dest, int weight) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->val = dest;
    new_node->weight = weight;
    new_node->next = g->adj_list[src];
    g->adj_list[src] = new_node;
}

void unionGraphs(Graph* g1, Graph* g2, Graph* g3, int* visited, int node, int parent_weight) {
    visited[node] = 1;
    Node* temp1 = g1->adj_list[node];
    while(temp1) {
        int next_node = temp1->val;
        int weight = temp1->weight;
        if(parent_weight != -1) {
            Node* temp3 = g3->adj_list[parent_weight];
            while(temp3) {
                if(temp3->val == next_node) {
                    weight += temp3->weight;
                    break;
                }
                temp3 = temp3->next;
            }
        }
        addEdge(g3, parent_weight, next_node, weight);
        if(!visited[next_node]) {
            unionGraphs(g1, g2, g3, visited, next_node, node);
        }
        temp1 = temp1->next;
    }
    Node* temp2 = g2->adj_list[node];
    while(temp2) {
        int next_node = temp2->val;
        int weight = temp2->weight;
        if(parent_weight != -1) {
            Node* temp3 = g3->adj_list[parent_weight];
            while(temp3) {
                if(temp3->val == next_node) {
                    weight += temp3->weight;
                    break;
                }
                temp3 = temp3->next;
            }
        }
        addEdge(g3, parent_weight, next_node, weight);
        if(!visited[next_node]) {
            unionGraphs(g1, g2, g3, visited, next_node, node);
        }
        temp2 = temp2->next;
    }
}

void printGraphDFS(Graph* g, int node, int* visited) {
    visited[node] = 1;
    printf("%d -> ", node);
    Node* temp = g->adj_list[node];
    while(temp) {
        int next_node = temp->val;
        printf("(%d,%d) ", next_node, temp->weight);
        if(!visited[next_node]) {
            printGraphDFS(g, next_node, visited);
        }
        temp = temp->next;
    }
}

int main() {
    Graph* g1 = createGraph(5);
    addEdge(g1, 0, 1, 2);
    addEdge(g1, 0, 2, 3);
    addEdge(g1, 1, 2, 1);
    addEdge(g1, 2, 3,4);
addEdge(g1, 3, 4, 2);

Graph* g2 = createGraph(5);
addEdge(g2, 0, 1, 1);
addEdge(g2, 0, 2, 2);
addEdge(g2, 1, 2, 3);
addEdge(g2, 2, 3, 4);
addEdge(g2, 3, 4, 1);
addEdge(g2, 4, 0, 5);

Graph* g3 = createGraph(5);
int visited[5] = {0};
unionGraphs(g1, g2, g3, visited, 0, -1);

printf("Graph G1:\n");
for(int i = 0; i < 5; i++) {
    printf("Vertex %d: ", i);
    printGraphDFS(g1, i, visited);
    printf("\n");
}

printf("Graph G2:\n");
for(int i = 0; i < 5; i++) {
    printf("Vertex %d: ", i);
    printGraphDFS(g2, i, visited);
    printf("\n");
}

printf("Graph G3:\n");
for(int i = 0; i < 5; i++) {
    printf("Vertex %d: ", i);
    printGraphDFS(g3, i, visited);
    printf("\n");
}

return 0;
}