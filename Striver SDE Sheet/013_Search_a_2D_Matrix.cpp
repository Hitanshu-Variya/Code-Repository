class Solution {
  public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();

    // Binary Search on row
    int low = 0, high = row - 1;
    int ans_row = 0;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (matrix[mid][0] <= target && matrix[mid][col - 1] >= target) {
        ans_row = mid;
        break;
      }

      if (matrix[mid][0] < target)
        low = mid + 1;
      else
        high = mid - 1;
    }

    // Binary Search on column
    low = 0, high = col - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (matrix[ans_row][mid] == target) {
        return true;
      }

      if (matrix[ans_row][mid] < target)
        low = mid + 1;
      else
        high = mid - 1;
    }

    return false;
  }
};