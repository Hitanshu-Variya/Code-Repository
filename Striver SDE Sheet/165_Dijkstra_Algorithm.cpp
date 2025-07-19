class Solution {
  public:
  vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    vector<vector<pair<int, int>>> adj(V);
    for (auto edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      adj[u].push_back({v, w});
    }

    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
      int weight = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      for (auto itr : adj[node]) {
        int neighbour = itr.first;
        int neighbour_dist = itr.second;

        if (weight + neighbour_dist < dist[neighbour]) {
          dist[neighbour] = weight + neighbour_dist;
          pq.push({dist[neighbour], neighbour});
        }
      }
    }

    return dist;
  }
};