// Using Merge Sort
class Solution {
  private:
  int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;
    int count = 0;

    while (left <= mid && right <= high) {
      if (arr[left] <= arr[right]) {
        temp.push_back(arr[left++]);
      } else {
        count += (mid - left + 1);
        temp.push_back(arr[right++]);
      }
    }

    while (left <= mid) {
      temp.push_back(arr[left++]);
    }

    while (right <= high) {
      temp.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++) {
      arr[i] = temp[i - low];
    }

    return count;
  }

  int merge_sort(vector<int> &arr, int low, int high) {
    int count = 0;

    if (low < high) {
      int mid = low + (high - low) / 2;
      count += merge_sort(arr, low, mid);
      count += merge_sort(arr, mid + 1, high);
      count += merge(arr, low, mid, high);
    }

    return count;
  }

  public:
  int inversionCount(vector<int> &arr) {
    int size = arr.size();
    return merge_sort(arr, 0, size - 1);
  }
};



// Using Fenwick Tree
class Fenwick {
  private:
  vector<int> bits;
  int n;

  void init(int n) {
    this->n = n;
    bits.resize(n + 2, 0);
  }

public:
  Fenwick(int n = 0) { 
    init(n); 
  }

  void update(int index, int val) {
    for (int i = index; i <= n; i += (i & -i))
      bits[i] += val;
  }

  int query(int index) {
    int sum = 0;
    for (int i = index; i > 0; i -= (i & -i))
      sum += bits[i];

    return sum;
  }
};

class Solution {
  public:
  int inversionCount(vector<int> &arr) {
    int size = arr.size();

    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    unordered_map<int, int> hash_map;

    int rank = 1;
    for (int i = 0; i < size; i++) {
      if (hash_map.find(sorted[i]) == hash_map.end()) {
        hash_map[sorted[i]] = rank++;
      }
    }

    Fenwick BIT(rank + 1);
    int count = 0;

    for (int i = 0; i < size; i++) {
      int pos = hash_map[arr[i]];
      count += (BIT.query(rank) - BIT.query(pos));

      BIT.update(pos, 1);
    }

    return count;
  }
};