class Solution
{
public:
  long long maximumSubarraySum(vector<int> &nums, int k)
  {
    long long sum = 0, ans = 0;
    int n = nums.size(), i = 0, j = 0;

    unordered_map<int, int> mp;

    while (j < n)
    {
      sum += nums[j];
      mp[nums[j]]++;

      while (j - i + 1 > k || mp[nums[j]] > 1)
      {
        sum -= nums[i];
        mp[nums[i]]--;
        if (mp[nums[i]] == 0)
          mp.erase(nums[i]);
        ++i;
      }

      if (j - i + 1 == k)
        ans = max(ans, sum);
      j++;
    }

    return ans;
  }
};