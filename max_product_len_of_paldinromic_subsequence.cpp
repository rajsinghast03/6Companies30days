class Solution
{
public:
  bool isPalindrome(string &s)
  {
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
      if (s[i] != s[j])
        return false;
      i++;
      --j;
    }
    return true;
  }

  int res = 0;

  void solve(int i, string &s1, string &s2, string &s)
  {
    if (i < 0)
    {
      if (isPalindrome(s1) && isPalindrome(s2))
      {
        res = max(res, (int)s1.size() * (int)s2.size());
      }
      return;
    }

    s1.push_back(s[i]);
    solve(i - 1, s1, s2, s);
    s1.pop_back();

    s2.push_back(s[i]);
    solve(i - 1, s1, s2, s);
    s2.pop_back();

    solve(i - 1, s1, s2, s);
  }

  int maxProduct(string s)
  {
    int n = s.size();
    string s1, s2;
    solve(n - 1, s1, s2, s);

    return res;
  }
};