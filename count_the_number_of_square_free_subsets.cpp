class Solution
{
public:
  int dp[1001][1 << 11];
  int M = 1e9 + 7;
  vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  int solve(int i, int mask, vector<int> &nums, int n)
  {
    if (i >= n)
      return 1;
    if (dp[i][mask] != -1)
      return dp[i][mask];
    int flag = 1;
    int temp = mask;
    for (int j = 0; j < 10; ++j)
    {
      int num = nums[i], prime = primes[j];
      int count = 0;
      while (num % prime == 0)
      {
        count++;
        num /= prime;
      }

      if (count >= 2 or ((count == 1) && ((mask >> j) & 1)))
      {
        flag = 0;
        break;
      }
      if (count)
        temp = temp | (1 << j);
    }

    if (flag)
    {
      return dp[i][mask] = (solve(i + 1, temp, nums, n) + solve(i + 1, mask, nums, n)) % M;
    }
    else
    {
      return dp[i][mask] = solve(i + 1, mask, nums, n);
    }
  }
  int squareFreeSubsets(vector<int> &nums)
  {
    int n = nums.size();
    memset(dp, -1, sizeof(dp));
    return (solve(0, 0, nums, n) - 1 + M) % M;
  }
};