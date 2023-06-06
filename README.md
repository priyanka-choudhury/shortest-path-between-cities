# shortest-path-between-cities

# Introduction
The utilization of a shortest path algorithm between two cities serves the crucial purpose of determining the most efficient route between them. By applying this algorithm, one can find the path with the minimum distance, time, or cost required to travel from the origin city to the destination city. This is particularly valuable in transportation planning, logistics management, and navigation systems, where it allows for optimized resource allocation, reduced travel time, and cost-effective decision-making. The algorithm's ability to identify the shortest path aids in enhancing efficiency, reducing fuel consumption, minimizing congestion, and ensuring timely deliveries. Moreover, it enables individuals to plan their journeys effectively, choose optimal routes, and make informed decisions regarding transportation options, resulting in improved overall transportation networks and enhanced user experiences.

In this project, I have developed two distinct variations of a program focused on finding the shortest path between two cities. These programs encompass slightly different scenarios, each employing a unique algorithm tailored to compute the most efficient route between any given pair of cities. By leveraging innovative approaches, these variations offer enhanced capabilities in determining optimal paths, resulting in improved navigation, streamlined logistics, and more effective resource allocation.

# Algorithm 1
I have implemented Dijkstra's algorithm to calculate the shortest path between two cities, i and j. This algorithm is designed to handle both unidirectional and bidirectional connections between cities. By employing the concept of relaxation, the algorithm can provide a more accurate approximation of the minimum cost for the shortest path.

To determine the shortest path, the algorithm utilizes a priority queue. It greedily selects the closest unvisited city and sequentially applies the relaxation step to all its connections. This iterative process ensures that the shortest path is gradually refined.

The time complexity of using Dijkstra's algorithm with a priority queue to find the shortest path is O(V + E log V), where V represents the number of vertices (cities) and E represents the number of edges (connections). Additionally, the space complexity is O(V) as it requires storage for the visited cities.

By employing Dijkstra's algorithm, we can efficiently find the shortest path between cities, considering various connections and achieving accurate results for the minimum cost of travel.

Steps for Dijkstra’s Algorithm
1. Set all costs for connections between cities to infinity except for city i (start). The
cost for connecting this city to itself is set to 0.
2. Push the starting city in a priority queue in the form (cost, city), in which the
comparisons in the priority queue are dependent on the cities’ cost of connections.
3. Go to the city with the minimum cost from the priority queue.
4. Update the costs of the connected cities to the visited city by adding the current
city cost and required cost of connection in this ongoing path. Then, this city is
pushed with the new cost to the priority queue.
5. If the current city being evaluated has already been visited, then continue without
using it.
6. Repeat this set of instructions until the priority queue is empty.

# Experiment for Algorithm 1
Test Case 1 (Shortest Path Between Cities 1 and 3) ✔
Input: N = 5,  connections = [[0,1,9],[0, 4, 2],[1,2,3],[1,4,4],[2,3,10],[3,2,6],[4,1,1], [4,2,8],[4,3,2]], i = 1, j = 3
Expected Output:
Minimum Cost = 6, Path = 1 -> 4 -> 3 
Actual Output: 
Minimum Cost = 6, Path = 1 -> 4 -> 3 

Test Case 2 (Shortest Path Between Cities 4 and 2) ✔
Input: N = 5,  connections = [[0,1,9],[0, 4, 2],[1,2,3],[1,4,4],[2,3,10],[3,2,6],[4,1,1], [4,2,8],[4,3,2]], i = 4, j = 2
Expected Output:
Minimum Cost = 4, Path = 4 -> 1 -> 2 
Actual Output: 
Minimum Cost = 4, Path = 4 -> 1 -> 2 

# Algorithm 2
I have integrated the Floyd-Warshall algorithm to efficiently determine the shortest paths between all pairs of cities within a graph, accommodating both unidirectional and bidirectional connections. By leveraging this algorithm, any given graph, represented by an adjacency matrix, can be processed to populate the "cost[]" array with the shortest possible paths, ensuring the least cost for each route.

In Floyd-Warshall's algorithm, the "cost[i][k]" entry represents the shortest path between cities i and k, considering only the first K cities. Similarly, the "cost[k][j]" entry denotes the shortest path between cities k and j. To identify the overall shortest path between cities i and j, the algorithm concatenates the shortest path from i to k with the shortest path from k to j, forming a comprehensive and optimized route.

The Floyd-Warshall algorithm boasts an efficient time complexity of O(V^3), where V signifies the number of vertices or cities present in the graph. Moreover, the space complexity is O(V^2), further highlighting its scalability and effectiveness in managing larger graphs and datasets.

In summary, the successful implementation of the Floyd-Warshall algorithm enables accurate computations of the shortest paths between all pairs of cities, accommodating various connection types. This approach, relying on an adjacency matrix representation, effectively populates the "cost[]" array with optimal routes, ensuring minimal costs for each path. With its favorable time and space complexities, Floyd-Warshall's algorithm proves to be a reliable and efficient solution for solving the shortest path problem in graphs with multiple cities or vertices.

Steps for Floyd-Warshall’s Algorithm
1. Set the shortest paths between any two cities with infinity.
2. Get all pairs of shortest paths which use 0 intermediate cities and then get the
shortest paths that use one additional intermediate city until using all N cities as
intermediate cities.
3. Minimize the shortest paths between any two pairs in the previous instruction.
4. For any 2 cities (i, j), costs between this pair should be minimized using the first
K nodes. The shortest path will be minimumCost(cost[i][k] + cost[k][j],
cost[i][j]).

# Experiment for Algorithm 2
Test Case 1 ✔
In this test case, there is one important city k that is used in the order of 0, 1, 2, 3 for each
two cities. There are 4 subsets of 3 shortest paths between two cities, where each subset
has an important city k going in ascending order from 0 to 3.
Input: [[0,I,-2,I],[4,0,3,I],[I,I,0,2],[I,-1,I,0]]
Expected Output:
Shortest Path between 0 and 1: 0 -> 2 -> 3 -> 1
Shortest Path between 0 and 2: 0 -> 2
Shortest Path between 0 and 3: 0 -> 2 -> 3
Shortest Path between 1 and 0: 1 -> 0
Shortest Path between 1 and 2: 1 -> 0 -> 2
Shortest Path between 1 and 3: 1 -> 0 -> 2 -> 3
Shortest Path between 2 and 0: 2 -> 3 -> 1 -> 0
Shortest Path between 2 and 1: 2 -> 3 -> 1
Shortest Path between 2 and 3: 2 -> 3
Shortest Path between 3 and 0: 3 -> 1 -> 0
Shortest Path between 3 and 1: 3 -> 1
Shortest Path between 3 and 2: 3 -> 1 -> 0 -> 2
Actual Output: 
Shortest Path between 0 and 1: 0 -> 2 -> 3 -> 1
Shortest Path between 0 and 2: 0 -> 2
Shortest Path between 0 and 3: 0 -> 2 -> 3
Shortest Path between 1 and 0: 1 -> 0
Shortest Path between 1 and 2: 1 -> 0 -> 2
Shortest Path between 1 and 3: 1 -> 0 -> 2 -> 3
Shortest Path between 2 and 0: 2 -> 3 -> 1 -> 0
Shortest Path between 2 and 1: 2 -> 3 -> 1
Shortest Path between 2 and 3: 2 -> 3
Shortest Path between 3 and 0: 3 -> 1 -> 0
Shortest Path between 3 and 1: 3 -> 1
Shortest Path between 3 and 2: 3 -> 1 -> 0 -> 2
