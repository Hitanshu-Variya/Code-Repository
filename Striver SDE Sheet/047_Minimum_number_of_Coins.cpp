class Solution {
  public:
  vector<int> minPartition(int N) {
    vector<int> denominations = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    vector<int> needs;

    for (int denomination : denominations) {
      while (N >= denomination) {
        needs.push_back(denomination);
        N -= denomination;
      }
    }

    return needs;
  }
};