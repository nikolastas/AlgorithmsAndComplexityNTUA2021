
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode *next;
};
struct AdjList
{
    struct AdjListNode *head; 
};

struct Graph
{
    int V;
    struct AdjList *array;
};

struct AdjListNode *newAdjListNode(int dest, int weight)
{
    struct AdjListNode *Nodex =
        (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    Nodex->dest = dest;
    Nodex->weight = weight;
    Nodex->next = NULL;
    return Nodex;
}

struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;

    
    graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));

    
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest, int weight)
{
    
    
    struct AdjListNode *Nodex = newAdjListNode(dest, weight);
    Nodex->next = graph->array[src].head;
    graph->array[src].head = Nodex;

    
    Nodex = newAdjListNode(src, weight);
    Nodex->next = graph->array[dest].head;
    graph->array[dest].head = Nodex;
}

struct MinHeapNode
{
    int v;
    int key;
};

struct MinHeap
{
    int size;     
    int capacity; 
    int *pos;     
    struct MinHeapNode **array;
};

struct MinHeapNode *newMinHeapNode(int v, int key)
{
    struct MinHeapNode *minHeapNode =
        (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->key = key;
    return minHeapNode;
}

struct MinHeap *createMinHeap(int capacity)
{
    struct MinHeap *minHeap =
        (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->pos = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array =
        (struct MinHeapNode **)malloc(capacity * sizeof(struct MinHeapNode *));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b)
{
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap *minHeap, int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->array[left]->key < minHeap->array[smallest]->key)
        smallest = left;

    if (right < minHeap->size &&
        minHeap->array[right]->key < minHeap->array[smallest]->key)
        smallest = right;

    if (smallest != idx)
    {
        
        struct MinHeapNode *smallestNode = minHeap->array[smallest];
        struct MinHeapNode *idxNode = minHeap->array[idx];

        
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

int isEmpty(struct MinHeap *minHeap)
{
    return minHeap->size == 0;
}

struct MinHeapNode *extractMin(struct MinHeap *minHeap)
{
    if (isEmpty(minHeap))
        return NULL;

    
    struct MinHeapNode *root = minHeap->array[0];

    
    struct MinHeapNode *lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    
    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

void decreaseKey(struct MinHeap *minHeap, int v, int key)
{
    
    int i = minHeap->pos[v];

    
    minHeap->array[i]->key = key;

    
    
    while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key)
    {
        
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

        
        i = (i - 1) / 2;
    }
}

bool isInMinHeap(struct MinHeap *minHeap, int v)
{
    if (minHeap->pos[v] < minHeap->size)
        return true;
    return false;
}

void printArr(int arr[], int n)
{
    int i;
    
    for (i = 1; i < n; ++i)
        
        
        printf("%d - %d\n", arr[i], i);
    
}

struct Graph *PrimMST(struct Graph *graph)
{
    int V = graph->V; 
    int *parent = (int *)malloc(V * sizeof(int));
    
    int *key = (int *)malloc(V * sizeof(int));
    

    
    struct MinHeap *minHeap = createMinHeap(V);

    
    
    int v;
    for (v = 1; v < V; ++v)
    {
        parent[v] = -1;
        key[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }

    
    
    key[0] = 0;
    minHeap->array[0] = newMinHeapNode(0, key[0]);
    minHeap->pos[0] = 0;

    
    minHeap->size = V;

    
    
    while (!isEmpty(minHeap))
    {
        
        struct MinHeapNode *minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v; 

        
        
        struct AdjListNode *pCrawl = graph->array[u].head;
        while (pCrawl != NULL)
        {
            int v = pCrawl->dest;

            
            
            
            if (isInMinHeap(minHeap, v) && pCrawl->weight < key[v])
            {
                key[v] = pCrawl->weight;
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
            pCrawl = pCrawl->next;
        }
    }
    struct Graph *mst = createGraph(V);
    int i;
    for (i = 1; i < V; ++i)
    {
        addEdge(mst, parent[i], i, key[i]);
    }
    return mst;
}
int *visited;
int **distances;

void DFS(struct Graph *graph, struct AdjListNode *root, int bottleneck, int source)
{

    int prev;

    while (root != NULL)
    {
        if (!visited[root->dest])
        {
            visited[root->dest] = 1;
            prev = bottleneck;

            if (bottleneck < root->weight)
                bottleneck = root->weight;

            distances[source][root->dest] = distances[root->dest][source] = bottleneck;

            DFS(graph, graph->array[root->dest].head, bottleneck, source);

            bottleneck = prev;
        }
        root = root->next;
    }
}

int main()
{

    int n, m, i, j, q;
    scanf("%d %d", &n, &m);

    struct Graph *graph = createGraph(n);

    int v1, v2, weight;

    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &v1, &v2, &weight);
        addEdge(graph, (v1 - 1), (v2 - 1), weight);
    }

    struct Graph *mst = PrimMST(graph);

    
    visited = (int *)malloc(n * sizeof(int));

    distances = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        distances[i] = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        distances[i][i] = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            visited[j] = 0;
        visited[i] = 1;
        DFS(mst, mst->array[i].head, 0, i);
    }

    scanf("%d", &q);
    for (i = 0; i < q; i++)
    {
        scanf("%d %d", &v1, &v2);
        printf("%d\n", distances[v1 - 1][v2 - 1]);
    }

    return 0;
}
