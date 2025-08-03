class Solution {
  public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    int size = rooms.size();
    vector<bool> visited(size, false);

    queue<int> queue;
    queue.push(0);
    visited[0] = true;

    while (!queue.empty()) {
      int room = queue.front();
      queue.pop();

      for (int &key : rooms[room]) {
        if (!visited[key]) {
          visited[key] = true;
          queue.push(key);
        }
      }
    }

    for (bool seen : visited) {
      if (!seen)
        return false;
    }

    return true;
  }
};