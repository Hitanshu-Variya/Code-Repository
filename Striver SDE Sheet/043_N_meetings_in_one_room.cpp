class Solution {
  public:
  int maxMeetings(vector<int> &start, vector<int> &end) {
    int size = start.size();
    vector<pair<int, int>> meetings;

    for (int i = 0; i < size; i++) {
      meetings.push_back({end[i], start[i]});
    }

    sort(meetings.begin(), meetings.end());
    int count = 1, next = meetings[0].first;

    for (int i = 1; i < size; i++) {
      if (meetings[i].second > next) {
        count++;
        next = meetings[i].first;
      }
    }

    return count;
  }
};