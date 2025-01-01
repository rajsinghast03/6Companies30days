class Solution
{
public:
  int minMoves2(vector<int> &nums)
  {
    int n = nums.size(), ans = 0;
    sort(begin(nums), end(nums));
    int median = nums[n / 2];

    for (int i = 0; i < n; ++i)
      ans += abs(median - nums[i]);

    return ans;
  }
};