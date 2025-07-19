class Solution {
  public:
  void floydWarshall(vector<vector<int>> &dist) {
    int size = dist.size();

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
          if (dist[j][i] != 1e8 && dist[i][k] != 1e8) {
            dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
          }
        }
      }
    }
  }
};