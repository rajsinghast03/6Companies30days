class Solution
{
public:
  int findContentChildren(vector<int> &g, vector<int> &s)
  {
    int no_of_children = g.size(), no_of_cookies = s.size();

    sort(begin(g), end(g));
    sort(begin(s), end(s));

    int i = 0, j = 0;
    while (i < no_of_children && j < no_of_cookies)
    {
      if (s[j] >= g[i])
      {
        ++i;
        ++j;
      }
      else
      {
        ++j;
      }
    }

    return i;
  }
};