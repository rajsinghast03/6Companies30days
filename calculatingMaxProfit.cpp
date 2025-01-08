class Solution
{
public:
  int dp[1001][2][101];
  int solve(int i, int canBuy, int k, vector<int> &prices, int n)
  {
    if (i >= n || k <= 0)
    {
      return 0;
    }
    if (dp[i][canBuy][k] != -1)
      return dp[i][canBuy][k];

    int take = -1e8, ntake = -1e8;
    if (canBuy)
    {
      take = -prices[i] + solve(i + 1, 0, k, prices, n);
      ntake = solve(i + 1, 1, k, prices, n);
    }
    else
    {
      take = prices[i] + solve(i + 1, 1, k - 1, prices, n);
      ntake = solve(i + 1, 0, k, prices, n);
    }

    return dp[i][canBuy][k] = max(take, ntake);
  }
  int maxProfit(int k, vector<int> &prices)
  {
    int n = prices.size();
    memset(dp, -1, sizeof(dp));
    return solve(0, 1, k, prices, n);
  }
};