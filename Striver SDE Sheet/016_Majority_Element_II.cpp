class Solution {
  public:
  vector<int> majorityElement(vector<int> &nums) {
    int bucket_1 = INT_MAX, count_1 = 0;
    int bucket_2 = INT_MAX, count_2 = 0;

    for (int num : nums) {
      if (num == bucket_1)
        count_1++;
      else if (num == bucket_2)
        count_2++;
      else if (count_1 == 0) {
        bucket_1 = num;
        count_1 = 1;
      } else if (count_2 == 0) {
        bucket_2 = num;
        count_2 = 1;
      } else {
        count_1--;
        count_2--;
      }
    }

    count_1 = 0;
    count_2 = 0;

    for (int num : nums) {
      if (num == bucket_1)
        count_1++;
      else if (num == bucket_2)
        count_2++;
    }

    vector<int> ans;
    int size = nums.size();
    if (count_1 > size / 3)
      ans.push_back(bucket_1);
    if (count_2 > size / 3)
      ans.push_back(bucket_2);

    return ans;
  }
};