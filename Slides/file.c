#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
    int key;
    struct edge *next;
} edge;

typedef struct graph {
    int nv;
    struct edge **adj;
} graph;

int is_empty(graph *g) {
    return (g == NULL || g->nv <= 0);
}

int reach(graph *g, int from, int to) {
    int reached = 0;
    if (is_empty(g)) return reached;

    if (from < 0 || from >= g->nv) return reached;
    if (to < 0 || to >= g->nv) return reached;

    edge *head = g->adj[from];
    while (head != NULL && head->key != to) {
        head = head->next;
    }

    return head != NULL;
}

graph *empty_graph(int nv) {
    graph *g = (graph *)malloc(sizeof(graph));

    if (g != NULL) {
        g->nv = nv;
        g->adj = (edge **)calloc(nv, sizeof(edge *));

        if (g->adj == NULL) {
            free(g);
            g = NULL;
        }
    }

    return g;
}

void add_edge(graph *g, int from, int to) {
    if (is_empty(g)) return;

    if (reach(g, from, to)) return;

    edge *new = (edge *)malloc(sizeof(edge));
    if (new == NULL) return;
    new->key = to;
    new->next = g->adj[from];
    g->adj[from] = new;
}

void delete_edge(graph *g, int from, int to) {
    if (is_empty(g)) return;

    if (!reach(g, from, to)) return;

    edge *curr = g->adj[from];
    edge *prev = curr;

    while (curr != NULL && curr->key != to) {
        prev = curr;
        curr = curr->next;
    }

    // sto eliminando la testa
    if (prev == curr) {
        g->adj[from] = curr->next;
        free(curr);
    } else {
        prev->next = curr->next;
        free(curr);
    }
}

void print_graph(graph *g) {
    int i = 0;
    if (is_empty(g)) {
        printf("Errore nella stampa del grafo: il grafo è vuoto\n");
        return;
    }

    for (i = 0; i < g->nv; i++) {
        edge *head = g->adj[i];

        printf("[%d]: ", i);
        while (head != NULL) {
            printf("%d -> ", head->key);
            head = head->next;
        }
        printf("-|\n");
    }

    printf("\n\n");
}

void fill_graph(graph *g) {
    int scelta,
        from,
        to;

    printf("RIEMPIMENTO GRAFO\n");

    do {
        printf("[0] per uscire\n");
        printf("[1] per inserire\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        if (scelta == 1) {
            printf("\nInserisci arco\n");
            printf("da: ");
            scanf("%d", &from);

            printf("a: ");
            scanf("%d", &to);

            add_edge(g, from, to);

            printf("\n\n");
        }
    } while (scelta != 0);
}

graph *graph_union(graph *g1, graph *g2) {
    graph *g3 = NULL;
    int *weight;
    int *flag;

    if (!is_empty(g1) && !is_empty(g2)) {
        g3 = empty_graph(g1->nv);
        if (g3 != NULL) {
            weight = (int *)calloc(g1->nv, sizeof(int));
            flag = (int *)calloc(g1->nv, sizeof(int));

            for (int i = 0; i < g1->nv; i++) {
                edge *head;

                head = g1->adj[i];
                while (head != NULL) {
                    weight[head->key] += head->weight;
                    flag[head->key] = 1;
                    head = head->next;
                }

                head = g2->adj[i];
                while (head != NULL) {
                    weight[head->key] += head->weight;
                    flag[head->key] = 1;
                    head = head->next;
                }

                for (int j = 0; j < g1->nv; j++) {
                    if (flag[j]) add_edge(g3, i, j, weight[j]);

                    flag[j] = 0;
                    weight[j] = 0;
                }
            }
        }
    }

    return g3;
}

//////////////////////////////////////////////////

typedef struct btree {
    int key;
    struct btree *left;
    struct btree *right;
} btree;

btree *max(btree *tree) {
    if (tree == NULL) return NULL;
    if (tree->right == NULL) return tree;

    return max(tree->right);
}

btree *min(btree *tree) {
    if (tree == NULL) return NULL;
    if (tree->left == NULL) return tree;

    return min(tree->left);
}

int is_binary_search_tree(btree *tree) {
    if (tree == NULL) return 1;

    btree *max_left_node = max(tree->left);
    if (max_left_node != NULL && max_left_node->key > tree->key) return 0;

    btree *min_right_node = min(tree->right);
    if (min_right_node != NULL && min_right_node->key < tree->key) return 0;

    if (!(is_binary_search_tree(tree->left))) return 0;

    if (!(is_binary_search_tree(tree->right))) return 0;

    return 1;
}

btree *build_node(int k) {
    btree *new_node = (btree *)malloc(sizeof(btree));
    new_node->key = k;

    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void print_in_order(btree *tree) {
    if (tree == NULL) return;

    print_in_order(tree->left);
    printf("%d ", tree->key);
    print_in_order(tree->right);
}

btree *minNodeInAbr(btree *tree) {
    if(tree == NULL) return NULL;
    if(tree->left == NULL) return tree;

    return minNodeInAbr(tree->left); 
    
}


void deleteFromAbr(btree **root, int value){
	
	btree *node = *root; 
	
	if(node){
		if(node->value < value){
			deleteFromAbr(&node->right, value); 
		} else if(node->value > value){
			deleteFromAbr(&node->left, value); 
		} else {
			if(!node->left && !node->right){
				free(*root); 
				*root = NULL; 
			} else {
				if(!node->left){
					*root = node->right; 
					free(node); 
				} else if(!node->right){
					*root = node->left; 
					free(node); 
				} else {
					btree *min = minNodeInAbr(node->right); 
					node->value = min->value; 
					if(min->right){
						node->right = min->right; 
					}
					deleteFromAbr(&(node->right), min->value); 
				}
			}
		}
	}
	
}


////////////////////////////////////////////////////////////////////////////

typedef struct List {
    int key;

    struct List *next;
    struct List *prev;
} List;

List *build_node(int key) {
    List *new_node = (List *)malloc(sizeof(List));

    if (new_node != NULL) {
        new_node->next = NULL;
        new_node->prev = NULL;
        new_node->key = key;
    }

    return new_node;
}

void insert_node(List **list, List *new_node) {
    if (new_node == NULL) return;
    new_node->next = *list;

    if (*list != NULL) {
        new_node->prev = (*list)->prev;

        if ((*list)->prev != NULL) (*list)->prev->next = new_node;

        (*list)->prev = new_node;
    }

    *list = new_node;
}

void insert_sorted_node(List **list, List *new_node) {
    if (new_node == NULL) return;

    List *curr = *list;
    List *prev = *list;

    while (curr != NULL && new_node->key >= curr->key) {
        prev = curr;
        curr = curr->next;
    }

    // inserisco in testa
    if (prev == curr) {
        new_node->prev = NULL;
        new_node->next = curr;

        if (curr != NULL) curr->prev = new_node;

        *list = new_node;
    } else {
        new_node->next = curr;
        new_node->prev = prev;

        if (prev != NULL) {
            prev->next = new_node;
        }

        if (curr != NULL) {
            curr->prev = new_node;
        }
    }
}

List *delete_node(List **list) {
    List *deleted_node = *list;

    if (deleted_node != NULL) {
        *list = (*list)->next;
        if (*list != NULL) (*list)->prev = deleted_node->prev;

        deleted_node->next = NULL;
        deleted_node->prev = NULL;
    }

    return deleted_node;
}

void print_list(List *list) {
    if (list == NULL) {
        printf("-|\n\n");
        return;
    }

    List *curr = delete_node(&list);
    printf("%d -> ", curr->key);
    print_list(list);
    insert_node(&list, curr);
}

void fill_list(List **list) {
    int scelta;
    int valore;

    do {
        printf("RIEMPI LISTA\n");
        printf("[1] per inserire\n");
        printf("[0] per uscire\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        if (scelta == 1) {
            printf("\nInserisci valore: ");
            scanf("%d", &valore);

            insert_node(list, build_node(valore));
        }

        printf("\n\n");

    } while (scelta);
}

void sort_list(List **list) {
    if (*list == NULL) return;

    List *curr = delete_node(list);

    sort_list(list);

    insert_sorted_node(list, curr);
}

/////////////////////////////////////////////////////////////////////////////

// lo stack verrà allocato con dimensione STACK_MAX_SIZE+1
#define STACK_MAX_SIZE <inserisci_valore>

int empty_stack(int S[]) {
    return S[0] == 0;
}

int full_stack(int S[]) {
    return S[0] == STACK_MAX_SIZE;
}

void push(int S[], int val) {
    if (!full_stack(S)) {
        S[0] = S[0] + 1;
        S[S[0]] = val;
    }
}

int pop(int S[]) {
    int val = 0;

    if (!empty_stack(S)) {
        S[0] = S[0] - 1;
        val = S[S[0] + 1];
    }

    return val;
}

void stampa(int S[]) {
    if (!empty_stack(S)) {
        int valore = pop(S);
        printf("%d ", valore);
        stampa(S);
        push(S, valore);
    } else {
        printf("\n");
    }
}

void new_stack(int S[]) {
    int num_elementi, valore;
    S[0] = 0;

    printf("\nQuanti elementi (max %d elementi): ", STACK_MAX_SIZE);
    scanf("%d", &num_elementi);

    while (num_elementi > STACK_MAX_SIZE) {
        printf("\nmax %d elementi: ", STACK_MAX_SIZE);
        scanf("%d", &num_elementi);
    }

    while (num_elementi) {
        printf("\nInserire un valore: ");
        scanf("%d", &valore);

        push(S, valore);
        --num_elementi;
    }
}

///////////////////////////////////////////////////////////////////////////

// la coda verrà allocata con dimensione QUEUE_MAX_SIZE+2
#define QUEUE_MAX_SIZE <inserisci_valore>

int empty_queue(int Q[]) {
    return Q[0] == 0;
}

int full_queue(int Q[]) {
    return Q[0] == Q[QUEUE_MAX_SIZE + 1];
}

void enqueue(int Q[], int val) {
    if (!full_queue(Q)) {
        Q[Q[QUEUE_MAX_SIZE + 1]] = val;

        if (empty_queue(Q)) Q[0] = 1;

        Q[QUEUE_MAX_SIZE + 1] = (Q[QUEUE_MAX_SIZE + 1] % QUEUE_MAX_SIZE) + 1;
    }
}

int dequeue(int Q[]) {
    int valore = Q[Q[0]];
    Q[0] = (Q[0] % QUEUE_MAX_SIZE) + 1;

    if (full_queue(Q)) {
        Q[0] = 0;
        Q[QUEUE_MAX_SIZE + 1] = 1;
    }

    return valore;
}

void new_queue(int Q[]) {
    int num_elementi, valore;
    Q[0] = 0;
    Q[QUEUE_MAX_SIZE + 1] = 1;

    printf("\nQuanti elementi (max %d elementi): ", QUEUE_MAX_SIZE);
    scanf("%d", &num_elementi);

    while (num_elementi > QUEUE_MAX_SIZE) {
        printf("\nmax %d elementi: ", QUEUE_MAX_SIZE);
        scanf("%d", &num_elementi);
    }

    while (num_elementi) {
        printf("\nInserire un valore: ");
        scanf("%d", &valore);

        enqueue(Q, valore);
        num_elementi--;
    }
}

/////////////////////////////////////////

void swap(int *a, int *b) {
	
	int temp = *a; 
	*a = *b;
	*b = temp;  
	
}


void heapify(int A[], int N, int i) {
	
 	int max = i; 
 	int left = 2 * i + 1; 
 	int right = 2 * i + 2; 
 	
 	if(left < N && A[left] > A[max]) max = left; 
 	if(right < N && A[right] > A[max]) max = right; 
 	
 	if(max != i) {
 		swap(&A[max], &A[i]); 
 		heapify(A, N, max); 
	 }
  	
}
	
void buildHeap(int A[], int arraySize) {
		
	int i; 
		
	for(i = (arraySize/2)-1; i>= 0; i--)
		heapify(A, arraySize, i); 
	
}

int *generateHeap(int heapSize) {
    srand(time(NULL));

	int i; 
    int *heap = (int *)malloc(heapSize * sizeof(int));

    if (heap == NULL) {
        printf("Errore allocazione");
        exit(-1);
    }

    for (i = 0; i < heapSize; i++) {
        heap[i] = rand() % 90 + 10;
    }

    buildHeap(heap, heapSize);

    return heap;
}


void printHeap(int heap[], int heapSize){
	
	int i; 
	
	printf("[Heap]-> "); 
	for(i = 0; i < heapSize; i++){
		printf("%d - ", heap[i]); 
	}
	printf("\n"); 
	
}


int isHeap(int heap[], int heapSize, int root) {
    if (root >= heapSize) return 1;

    int leftChild = 2 * root + 1;
    int rightChild = 2 * root + 2;

    if (leftChild >= heapSize || rightChild >= heapSize) 
				return 1;

    if (heap[root] < heap[leftChild] || heap[root] < heap[rightChild]) {
        return 0;
    }

    // se a sinistra � stato trovato un errore, � inutile scendere anche a destra
    if (isHeap(heap, heapSize, leftChild) == 0) 
				return 0;

    return isHeap(heap, heapSize, rightChild);
}

