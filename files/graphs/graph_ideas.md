# Graph — Unique Ideas / Patterns

## 1. Basic BFS / DFS Traversal
- Used for reachability / connected components.
- Mark `visited` when adding a node to the queue, not when popping.
- Example: Keys and Rooms.

## 2. Grid BFS
- Treat each cell as a graph node.
- `directions[]` represents the edges.
- The grid itself can sometimes be used as `visited` / distance.
- Example: Shortest Path in Binary Matrix.

## 3. Unweighted Shortest Path → BFS
- In an unweighted graph, BFS finds the shortest path.
- The first time a node is reached, its distance is minimum.
- Maintain `dist[]` if the actual distance is needed.

## 4. BFS With Additional State / Constraint
- Sometimes `node` alone is NOT enough to describe a state.
- State can be something like:
  - `(node, stops)`
  - `(node, remaining moves)`
  - `(node, number of operations used)`
- Example: Cheapest Flights Within K Stops.

## 5. Dijkstra
- Used for weighted graphs with non-negative edge weights.
- `dist[node]` = currently known minimum distance.
- Min-heap gives the next smallest tentative distance.
- Ignore stale priority queue entries when using the standard implementation.

## 6. Dijkstra + Number of Shortest Paths
Maintain two arrays:
- `dist[v]` → shortest distance
- `ways[v]` → number of shortest paths

When relaxing an edge:
- `newDist < dist[v]`
  - Update `dist[v]`
  - Set `ways[v] = ways[u]`
- `newDist == dist[v]`
  - `ways[v] += ways[u]`

Example: Count Ways to Arrive at Destination.

## 7. Dijkstra Is Not Just "BFS With a Priority Queue"
- Algorithm depends on the graph's properties.
- Unweighted → BFS.
- Non-negative weighted → Dijkstra.
- Additional constraints can change the state and therefore the algorithm.

## 8. Shortest Path in a DAG
- A DAG has a topological ordering.
- Process nodes in topological order and relax outgoing edges.
- Can solve shortest paths in `O(V + E)`.

## 9. Topological Sort
### DFS
- Visit children first.
- Push node into stack after processing all outgoing edges.

### Kahn's Algorithm
- Calculate indegrees.
- Start with nodes having `indegree == 0`.
- Remove them and decrease the indegree of their neighbors.

Used for directed dependency problems.

## 10. Directed Cycle Detection
DFS needs to distinguish:
- `0` → never visited
- `1` → currently in recursion stack
- `2` → completely processed

If DFS encounters a node with state `1`, there is a cycle.

## 11. Eventually Safe Nodes
- A node is safe if every possible path eventually reaches a terminal node.
- Nodes involved in cycles are unsafe.
- Nodes that can eventually reach a cycle are also unsafe.
- DFS + cycle detection can be used.

Mental model:

> Safe = cannot reach a cycle.

## 12. Tree Properties
A tree is:
- Connected
- Acyclic

Therefore:

> There is exactly one path between any two nodes.

Useful consequence:
- When traversing a tree, sometimes `parent` is enough to prevent going backward.
- A full `visited[]` array may not be necessary.

## 13. Tree With Directed Edges
Sometimes the underlying graph is a tree but every edge has a direction.

Useful approach:
- Treat each directed edge as two traversal possibilities.
- Store whether the original direction points toward or away from the desired root.

Example:

```cpp
adj[u].push_back({v, 1}); // original u -> v
adj[v].push_back({u, 0}); // original direction is opposite
````

Example: Reorder Routes to Make All Paths Lead to City Zero.

## 14. Encode Information Directly on Edges

Instead of using an expensive auxiliary structure to determine edge properties, store the property with the edge.

For example:

```cpp
pair<int, int>
```

can represent:

```text
{neighbor, weight}
{neighbor, direction}
{neighbor, cost}
```

General idea:

> Put useful information directly on the edge.

## 15. Don't Rebuild an Existing Adjacency List

If the input is already:

```cpp
rooms[u] = {neighbors of u};
```

then `rooms` is already the adjacency list.

Don't unnecessarily create:

```cpp
vector<vector<int>> adj;
```

and copy everything.

Example: Keys and Rooms.

## 16. Reverse Graph / Reverse Thinking

Sometimes the easier question is not:

> "What nodes can this node reach?"

but:

> "What nodes can reach this node?"

Constructing a reverse graph can make these problems much easier.

Useful for:

* Predecessor problems
* Dependency propagation
* Safe nodes
* Reachability toward a target

## 17. Graph Propagation

If some node becomes affected/suspicious/invalid:

* Start BFS/DFS from it.
* Propagate the property through reachable nodes.

General pattern:

```cpp
visited[start] = 1;

DFS/BFS(start):
    for neighbor:
        if not visited[neighbor]:
            visit(neighbor)
```

Example: Remove Methods / suspicion propagation problem.

## 18. Reverse Edges for Predecessor Problems

If you need to find:

> "Which nodes point toward these nodes?"

it can be useful to construct:

```text
reverse[v].push_back(u)
```

instead of following the original direction.

## 19. Graph Representation Matters

### Simple adjacency list

```cpp
vector<vector<int>> adj;
```

Use when you only need neighbors.

### Weighted / metadata adjacency list

```cpp
vector<vector<pair<int, int>>> adj;
```

Can represent:

```text
{neighbor, weight}
{neighbor, direction}
{neighbor, cost}
```

### Reverse adjacency list

```cpp
reverse[v].push_back(u);
```

Useful when reasoning backward through directed edges.

Don't automatically use:

* `unordered_map`
* `unordered_set`

if the graph structure already allows a simpler representation.

## 20. Use the Graph's Structural Guarantees

| Property                          | Think                     |
| --------------------------------- | ------------------------- |
| Unweighted graph                  | BFS                       |
| Grid with uniform movement cost   | BFS                       |
| Non-negative edge weights         | Dijkstra                  |
| DAG                               | Topological order         |
| Tree                              | DFS/BFS + parent          |
| Directed dependencies             | Topological sort          |
| Possible cycles in directed graph | Cycle detection           |
| Need predecessors                 | Reverse graph             |
| Need shortest distance + count    | `dist[] + ways[]`         |
| Extra restriction/state           | Expand BFS/Dijkstra state |

---

# Most Important Ideas I've Learned So Far

### 1. Node alone may NOT be the complete state

For example:

```text
(node)
```

might need to become:

```text
(node, stops)
```

or:

```text
(node, remaining_k)
```

when the problem has an additional constraint.

### 2. Tree structure can replace `visited[]`

Because a tree has exactly one path between any two nodes:

```cpp
if (neighbor != parent)
```

can sometimes be enough to prevent going backward.

### 3. Edge metadata can eliminate auxiliary data structures

Instead of:

```cpp
unordered_set
```

to remember something about an edge, store it directly:

```cpp
{neighbor, property}
```

### 4. Shortest distance and number of shortest paths are separate information

Maintain:

```cpp
dist[]
ways[]
```

and update them differently depending on whether a new path is:

```text
shorter
equal
longer
```

### 5. Graph representation can BE the solution

Before coding, ask:

> What information do I actually need from each edge?

Maybe the edge should store:

```text
neighbor
weight
direction
cost
state
```

rather than just the neighbor.

### 6. Problem constraints often tell you the algorithm

Instead of memorizing algorithms independently:

```text
Unweighted → BFS
Weighted + non-negative → Dijkstra
DAG → Topological DP / relaxation
Tree → DFS/BFS
Dependencies → Topological Sort
Cycle → Cycle Detection
Backward reachability → Reverse Graph
Extra constraint → Add state
```

