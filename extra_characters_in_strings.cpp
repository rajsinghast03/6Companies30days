class Solution
{
public:
  unordered_set<string> dict;
  int dp[51];
  int solve(int ind, string &s, int n)
  {
    if (ind >= n)
      return 0;
    if (dp[ind] != -1)
      return dp[ind];

    int res = 1 + solve(ind + 1, s, n);
    for (int i = ind; i < n; ++i)
    {
      string st = s.substr(ind, i - ind + 1);
      if (dict.count(st) > 0)
      {
        res = min(res, solve(i + 1, s, n));
      }
    }

    // ntake = 1+solve(ind+1,s,n);

    return dp[ind] = res;
  }
  int minExtraChar(string s, vector<string> &dictionary)
  {
    for (auto &st : dictionary)
      dict.insert(st);
    int n = s.size();
    memset(dp, -1, sizeof(dp));

    return solve(0, s, n);
  }
};