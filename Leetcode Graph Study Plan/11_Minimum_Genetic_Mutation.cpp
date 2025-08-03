class Solution {
  public:
  int minMutation(string startGene, string endGene, vector<string> &bank) {
    string choice = "ACGT";
    unordered_set<string> set(bank.begin(), bank.end());
    unordered_set<string> visited;

    int ans = 0;
    queue<string> queue;
    queue.push(startGene);
    visited.insert(startGene);

    while (!queue.empty()) {
      int size = queue.size();

      for (int i = 0; i < size; i++) {
        string gene = queue.front();
        queue.pop();

        if (gene == endGene) {
          return ans;
        }

        for (int j = 0; j < 8; j++) {
          string mutatedGene = gene;
          for (int k = 0; k < 4; k++) {
            if (mutatedGene[j] == choice[k])
              continue;
            mutatedGene[j] = choice[k];

            if (set.count(mutatedGene)) {
              if (!visited.count(mutatedGene)) {
                visited.insert(mutatedGene);
                queue.push(mutatedGene);
              }
            }
          }
        }
      }

      ans++;
    }

    return -1;
  }
};