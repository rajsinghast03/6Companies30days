class Solution
{
public:
  int findPairs(vector<int> &nums, int k)
  {
    int n = nums.size(), ans = 0;
    sort(begin(nums), end(nums));

    for (int i = 0; i < n; ++i)
    {
      if (i == 0 || nums[i] != nums[i - 1])
      {
        auto it = lower_bound(begin(nums) + i + 1, end(nums), nums[i] + k);
        if (it == nums.end())
          return ans;
        int idx = it - begin(nums);

        int diff = abs(nums[idx] - nums[i]);
        if (diff == k)
          ans++;
      }
    }

    return ans;
  }
};