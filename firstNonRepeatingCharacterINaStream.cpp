class Solution
{
public:
  int firstUniqChar(string s)
  {
    int n = s.size();
    vector<int> mark(26, 1);
    unordered_map<int, int> mp;

    for (int i = 0; i < n; ++i)
    {
      int c = s[i] - 'a';
      if (mp.find(c) != mp.end())
      {
        mark[c] = 0;
      }
      mp[c] = i;
    }

    for (int i = 0; i < n; ++i)
    {
      if (mark[s[i] - 'a'] == 1)
        return i;
    }

    return -1;
  }
};