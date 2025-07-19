using i64 = long long int;
class Solution {
  public:
  i64 subarrayXor(vector<int> &arr, int k) {
    int size = arr.size();
    unordered_map<int, i64> hash_map;
    i64 XOR = 0, ans = 0;
    hash_map[XOR] = 1;

    for (int i = 0; i < size; i++) {
      XOR = XOR ^ arr[i];

      i64 req = XOR ^ k;
      ans += hash_map[req];

      hash_map[XOR]++;
    }

    return ans;
  }
};