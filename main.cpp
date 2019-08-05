#include <iostream>
#include <list>

class Graph
{
    private:
        int numVertex;
        std::list<int> *adj;
    public:
        Graph(int numVertex) : numVertex(numVertex)
        {
            adj = new std::list<int>[numVertex];
        }
        ~Graph() {}

        void addEdge(int v, int w)
        {
            this->adj[v].push_back(w);
            this->adj[w].push_back(v);
        }

        void Traverse(int v, bool *visited)
        {
            // ak ciel
            if (v == 1)
            {
                std::cout << "Nasiel ciel!" << std::endl;
                exit(0);
            }
            else
            {
                std::cout << "Navstivil som " << v << std::endl;
            }
            
            visited[v] = true;

            for (auto i = this->adj[v].begin(); i != this->adj[v].end(); ++i)
            {
                if (!visited[*i])
                    Traverse(*i, visited);
            }
        }

        void Traverse(int v)
        {
            bool *visited = new bool[numVertex];

            for (int i = 0; i < numVertex; i++)
                visited[i] = false;

            Traverse(v, visited);
        }
};

int main()
{
    int numV;
    int v, w;

    std::cout << "Zadajte pocet vrcholov: ";
    std::cin >> numV;

    Graph g(numV);

    while (1)
    {
        std::cout << "Zadajte hranu: ";
        std::cin >> v;
        std::cin >> w;

        if (!(v < 0 || w < 0))
        {
            g.addEdge(v, w);
        }
        else
        {
            break;
        }        
    }

    /*g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 5);
    g.addEdge(0, 6);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(4, 6);*/

    std::cout << "Koniec zadavania" << std::endl;

    g.Traverse(3);

    return 0;
}