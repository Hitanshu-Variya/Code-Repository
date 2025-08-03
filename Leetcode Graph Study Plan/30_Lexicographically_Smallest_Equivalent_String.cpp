class Solution {
  private:
  vector<char> parent;
  char find(char node) {
    if (parent[node - 'a'] == node)
      return node;
    return (parent[node - 'a'] = find(parent[node - 'a']));
  }

  void Union(char node1, char node2) {
    node1 = find(node1);
    node2 = find(node2);

    if (node1 != node2) {
      if (node1 > node2) {
        swap(node1, node2);
      }

      parent[node2 - 'a'] = node1;
    }
  }

  public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    int size = s1.size();
    parent.resize(26);
    iota(parent.begin(), parent.end(), 'a');

    for (int i = 0; i < size; i++) {
      Union(s1[i], s2[i]);
    }

    string ans;
    for (char character : baseStr) {
      ans.push_back(find(character));
    }

    return ans;
  }
};