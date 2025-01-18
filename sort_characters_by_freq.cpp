class Solution
{
public:
  string frequencySort(string s)
  {
    unordered_map<char, int> mp;
    for (auto &c : s)
      mp[c]++;

    sort(begin(s), end(s), [&](char a, char b)
         {
            if(mp[a] == mp[b]) return a < b;
            return mp[a] > mp[b]; });

    return s;
  }
};