class Solution
{
public:
  string getHint(string secret, string guess)
  {
    int n = secret.size();
    unordered_map<char, int> mp;
    int ct1 = 0, ct2 = 0;

    for (auto &c : guess)
      mp[c]++;
    for (int i = 0; i < n; ++i)
    {
      if (secret[i] == guess[i])
      {
        mp[secret[i]]--;
        if (mp[secret[i]] == 0)
          mp.erase(secret[i]);
        ct1++;
      }
    }
    for (int i = 0; i < n; ++i)
    {
      if (secret[i] != guess[i])
      {
        if (mp.find(secret[i]) != mp.end())
        {
          ct2++;
          mp[secret[i]]--;
          if (mp[secret[i]] == 0)
            mp.erase(secret[i]);
        }
      }
    }

    string ans;
    ans += to_string(ct1);
    ans.push_back('A');
    ans += to_string(ct2);
    ans.push_back('B');

    return ans;
  }
};