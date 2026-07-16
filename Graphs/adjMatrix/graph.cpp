#include <iostream>

struct graph
{
    int V;
    int E;
    int** adjMatrix;
};

struct edge
{
    int source;
    int destination;
};

struct graph* createGraph(int numVertices)
{
    if (numVertices <= 0)
    {
        return nullptr;
    }

    struct graph* G = new graph;

    G->V = numVertices;
    G->E = 0;
    G->adjMatrix = new int*[numVertices];

    for (int i = 0; i < numVertices; i++)
    {
        G->adjMatrix[i] = new int[numVertices];

        for (int j = 0; j < numVertices; j++)
        {
            G->adjMatrix[i][j] = 0;
        }
    }

    return G;
}

struct edge newEdge(int source, int destination)
{
    return {source, destination};
}
/*struct edge newEdge(int source, int destination)
{
    struct edge E;

    E.source = source;
    E.destination = destination;

    return E;
}*/
bool isValidVertex(const struct graph* G, int vertex)
{
    if (G == nullptr)
    {
        return false;
    }

    return vertex >= 0 && vertex < G->V;
}

bool edgeExists(const struct graph* G, const struct edge& E)
{
    if (G == nullptr)
    {
        return false;
    }

    if (!isValidVertex(G, E.source) ||
        !isValidVertex(G, E.destination))
    {
        return false;
    }

    return G->adjMatrix[E.source][E.destination] == 1;
}

void insertEdge(struct graph* G, const struct edge& E)
{
    if (G == nullptr)
    {
        return;
    }

    if (!isValidVertex(G, E.source) ||
        !isValidVertex(G, E.destination))
    {
        std::cout << "Invalid edge: "
                  << E.source << " - "
                  << E.destination << '\n';

        return;
    }

    if (edgeExists(G, E))
    {
        std::cout << "Edge already exists: "
                  << E.source << " - "
                  << E.destination << '\n';

        return;
    }

    G->adjMatrix[E.source][E.destination] = 1;
    G->adjMatrix[E.destination][E.source] = 1;

    G->E++;
}

void removeEdge(struct graph* G, const struct edge& E)
{
    if (G == nullptr)
    {
        return;
    }

    if (!isValidVertex(G, E.source) ||
        !isValidVertex(G, E.destination))
    {
        std::cout << "Invalid edge: "
                  << E.source << " - "
                  << E.destination << '\n';

        return;
    }

    if (!edgeExists(G, E))
    {
        std::cout << "Edge does not exist: "
                  << E.source << " - "
                  << E.destination << '\n';

        return;
    }

    G->adjMatrix[E.source][E.destination] = 0;
    G->adjMatrix[E.destination][E.source] = 0;

    G->E--;
}

void displayGraph(const struct graph* G)
{
    if (G == nullptr)
    {
        std::cout << "Graph is empty\n";
        return;
    }

    std::cout << "    ";

    for (int vertex = 0; vertex < G->V; vertex++)
    {
        std::cout << vertex << ' ';
    }

    std::cout << '\n';

    for (int i = 0; i < G->V; i++)
    {
        std::cout << i << " : ";

        for (int j = 0; j < G->V; j++)
        {
            std::cout << G->adjMatrix[i][j] << ' ';
        }

        std::cout << '\n';
    }
}

void displayEdges(const struct graph* G)
{
    if (G == nullptr)
    {
        std::cout << "Graph is empty\n";
        return;
    }

    for (int source = 0; source < G->V; source++)
    {
        for (int destination = source + 1;
             destination < G->V;
             destination++)
        {
            if (G->adjMatrix[source][destination] == 1)
            {
                std::cout << source
                          << " - "
                          << destination
                          << '\n';
            }
        }
    }
}

void destroyGraph(struct graph* G)
{
    if (G == nullptr)
    {
        return;
    }

    for (int i = 0; i < G->V; i++)
    {
        delete[] G->adjMatrix[i];
    }

    delete[] G->adjMatrix;
    delete G;
}

int main()
{
    struct graph* G = createGraph(5);

    insertEdge(G, newEdge(0, 1));
    insertEdge(G, newEdge(0, 2));
    insertEdge(G, newEdge(1, 3));
    insertEdge(G, newEdge(2, 3));
    insertEdge(G, newEdge(3, 4));

    std::cout << "Adjacency Matrix:\n";
    displayGraph(G);

    std::cout << "\nEdges:\n";
    displayEdges(G);

    std::cout << "\nVertices: " << G->V << '\n';
    std::cout << "Edges: " << G->E << '\n';

    removeEdge(G, newEdge(2, 3));

    std::cout << "\nAfter removing edge 2 - 3:\n";
    displayGraph(G);

    destroyGraph(G);

    return 0;
}
