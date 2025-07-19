class Solution {
  private:
  void getNextPermutation(vector<int> &arr, int &size) {
    int index = -1;
    for (int i = size - 2; i >= 0; i--) {
      if (arr[i] < arr[i + 1]) {
        index = i;
        break;
      }
    }

    if (index == -1) {
      reverse(arr.begin(), arr.end());
      return;
    }

    for (int i = size - 1; i > index; i--) {
      if (arr[i] > arr[index]) {
        swap(arr[i], arr[index]);
        break;
      }
    }

    reverse(arr.begin() + index + 1, arr.end());
  }

  public:
  string getPermutation(int n, int k) {
    vector<int> sequence(n);
    iota(sequence.begin(), sequence.end(), 1);

    while (--k) {
      getNextPermutation(sequence, n);
    }

    string ans;
    for (auto num : sequence)
      ans += (to_string(num));

    return ans;
  }
};