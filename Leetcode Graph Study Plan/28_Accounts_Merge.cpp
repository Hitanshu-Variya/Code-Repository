class Solution {
  private:
  vector<int> parent, size;
  int find(int node) {
    if (parent[node] == node)
      return node;
    return (parent[node] = find(parent[node]));
  }

  void Union(int node1, int node2) {
    node1 = find(node1);
    node2 = find(node2);

    if (node1 != node2) {
      if (size[node1] > size[node2]) {
        swap(node1, node2);
      }

      parent[node1] = node2;
      size[node2] += size[node1];
    }
  }

  public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    int n = accounts.size();
    parent.resize(n), size.resize(n, 1);
    iota(parent.begin(), parent.end(), 0);

    unordered_map<string, int> hashMap;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < accounts[i].size(); j++) {
        string mail = accounts[i][j];

        if (hashMap.find(mail) == hashMap.end()) {
          hashMap[mail] = i;
        } else {
          Union(i, hashMap[mail]);
        }
      }
    }

    unordered_map<int, vector<string>> merge;
    for (auto [mail, id] : hashMap) {
      int parent = find(id);
      merge[parent].push_back(mail);
    }

    vector<vector<string>> ans;
    for (auto [id, mails] : merge) {
      sort(mails.begin(), mails.end());
      vector<string> entry = {accounts[id][0]};
      entry.insert(entry.end(), mails.begin(), mails.end());
      ans.push_back(entry);
    }

    return ans;
  }
};