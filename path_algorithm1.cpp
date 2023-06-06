/* This C++ program implements Dijkstra’s algorithm to get the shortest path (least cost) 
   between city i and city j, in which there are unidirectional and bidirectional connections. */

#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Connection
{
    int start, end, cost;
};

struct Node
{
    int vertex, cost;
};
 
class Graph
{
    public:
        vector<vector<Connection>> adjList;
        Graph(vector<Connection> const &connections, int N)
        {
            adjList.resize(N);
            for (Connection const &connection: connections)
            {
                adjList[connection.start].push_back(connection);
            }
    }
};
 
void printPath(vector<int> const &previous, int start, int end)
{
    if (end < 0) 
    {
        return;
    }
    printPath(previous, start, previous[end]);
    if (end != start) 
    {
        cout << " -> ";
    }
    cout << end;
}
 
struct compare
{
    bool operator()(const Node &lhs, const Node &rhs) const
    {
        return lhs.cost > rhs.cost;
    }
};
 
void findShortestPath(Graph const &graph, int start, int end, int N)
{
    priority_queue<Node, vector<Node>, compare> min_heap;
    min_heap.push({start, 0});
    vector<int> totalCost(N, INT_MAX);
    totalCost[start] = 0;
    vector<bool> done(N, false);
    done[start] = true;
    vector<int> previous(N, -1);
    while (!min_heap.empty())
    {
        Node node = min_heap.top();
        min_heap.pop();
        int u = node.vertex;
        for (auto i: graph.adjList[u])
        {
            int v = i.end;
            int cost = i.cost;
            if (!done[v] && (totalCost[u] + cost) < totalCost[v])
            {
                totalCost[v] = totalCost[u] + cost;
                previous[v] = u;
                min_heap.push({v, totalCost[v]});
            }
        }
        done[u] = true;
    }
    if (totalCost[end] != INT_MAX)
    {
        cout << "Shortest Path between " << start << " and " << end << ": Minimum Cost = " << totalCost[end] << ", Path = ";
        printPath(previous, start, end);
        cout << endl;
    }   
}
 
int main()
{
    int N = 5;
    vector<Connection> connections = {{0, 1, 9}, {0, 4, 2}, {1, 2, 3}, {1, 4, 4}, {2, 3, 10}, {3, 2, 6}, {4, 1, 1}, {4, 2, 8}, {4, 3, 2}};
    int start = 4, end = 2;
    Graph graph(connections, N);
    findShortestPath(graph, start, end, N);
    return 0;
}
