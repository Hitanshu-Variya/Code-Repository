class Solution {
  public:
  bool canReach(vector<int> &arr, int start) {
    int size = arr.size();
    if (arr[start] == 0) {
      return true;
    }

    vector<bool> visited(size, false);
    queue<int> queue;
    queue.push(start);
    visited[start] = true;

    while (!queue.empty()) {
      int index = queue.front();
      queue.pop();

      if (arr[index] == 0) {
        return true;
      }

      int forward = index + arr[index];
      int backward = index - arr[index];

      if (forward < size && !visited[forward]) {
        visited[forward] = true;
        queue.push(forward);
      }
      if (backward >= 0 && !visited[backward]) {
        visited[backward] = true;
        queue.push(backward);
      }
    }

    return false;
  }
};
