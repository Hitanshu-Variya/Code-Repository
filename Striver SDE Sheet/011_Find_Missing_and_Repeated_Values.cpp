using i64 = long long int;
class Solution {
  public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
    int size = grid.size();

    i64 sum = 0, square_sum = 0;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        sum += grid[i][j];
        square_sum += (grid[i][j] * grid[i][j]);
      }
    }

    i64 n = 1LL * size * size;
    i64 expected_sum = (n * (n + 1)) / 2;
    i64 expected_square_sum = (n * (n + 1) * (2 * n + 1)) / 6;

    i64 diff = expected_sum - sum;
    i64 add = (expected_square_sum - square_sum) / diff;

    i64 original = (add + diff) / 2;
    i64 duplicate = (add - original);

    return {static_cast<int>(duplicate), static_cast<int>(original)};
  }
};