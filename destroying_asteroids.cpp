class Solution
{
public:
  bool asteroidsDestroyed(int mass, vector<int> &a)
  {
    int n = a.size();
    sort(begin(a), end(a));
    long long m = mass;

    int i = 0;
    while (i >= 0 && a[i] > mass)
      --i;

    if (i < 0)
      return false;

    m += a[i];
    for (int j = i + 1; j < n; ++j)
    {
      if (m >= a[j])
        m += a[j];
      else
        return false;
    }

    return true;
  }
};