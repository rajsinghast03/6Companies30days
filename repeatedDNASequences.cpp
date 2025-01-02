class Solution
{
public:
  vector<string> findRepeatedDnaSequences(string s)
  {
    int n = s.size();
    unordered_map<string, int> mp;
    vector<string> ans;

    if (n < 10)
      return ans;

    for (int i = 0; i < n - 9; ++i)
    {
      mp[s.substr(i, 10)]++;
    }

    for (auto [k, v] : mp)
    {
      if (v > 1)
        ans.push_back(k);
    }

    return ans;
  }
};