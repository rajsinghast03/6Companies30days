class Solution
{
public:
  bool solve(string &s, unordered_set<string> &st)
  {
    if (st.size() == 0)
      return false;
    int n = s.size();
    vector<int> dp(n + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
      for (int j = i - 1; j >= 0; --j)
      {
        if (dp[j])
        {
          string word = s.substr(j, i - j);
          if (st.count(word) > 0)
          {
            dp[i] = 1;
            break;
          }
        }
      }
    }

    return dp[n];
  }
  bool wordBreak(string s, vector<string> &wordDict)
  {
    unordered_set<string> st;
    for (auto it : wordDict)
      st.insert(it);

    return solve(s, st);
  }
};