class Solution
{
public:
  int maxRotateFunction(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> dp(n, 0);
    int sum = 0;

    int ans = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
      sum += nums[i];
      dp[0] += nums[i] * i;
    }
    ans = dp[0];
    for (int i = 1; i < n; ++i)
    {
      dp[i] = dp[i - 1] + sum - n * (nums[n - i]);
      ans = max(dp[i], ans);
    }

    return ans;
  }
};