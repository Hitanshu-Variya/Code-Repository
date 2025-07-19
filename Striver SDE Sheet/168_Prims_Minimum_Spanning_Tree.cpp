// Using Priority Queue
class Solution {
  public:
  int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<bool> visited(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    int sum = 0;
    while (!pq.empty()) {
      int weight = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      if (visited[node]) continue;
      sum += weight;
      visited[node] = true;

      for (auto &itr : adj[node]) {
        int neighbour = itr[0], neighbour_weight = itr[1];
        if (!visited[neighbour]) {
          pq.push({neighbour_weight, neighbour});
        }
      }
    }

    return sum;
  }
};

// Using Greedy
class Solution {
  public:
  int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<bool> MST(V, false);
    vector<int> dist(V, INT_MAX), parent(V, -1);

    dist[0] = 0;
    parent[0] = -1;
    int sum = 0;

    for (int i = 0; i < V; i++) {
      int mini = INT_MAX, mini_vertex = 0;
      for (int j = 0; j < V; j++) {
        if (!MST[j] && dist[j] < mini) {
          mini = dist[j];
          mini_vertex = j;
        }
      }

      MST[mini_vertex] = true;
      sum += dist[mini_vertex];

      for (auto &itr : adj[mini_vertex]) {
        int neighbour = itr[0], neighbour_weight = itr[1];
        if (!MST[neighbour] && dist[neighbour] > neighbour_weight) {
          dist[neighbour] = neighbour_weight;
          parent[neighbour] = mini_vertex;
        }
      }
    }

    return sum;
  }
};