class Solution
{
public:
  int numFriendRequests(vector<int> &ages)
  {
    int n = ages.size();
    sort(begin(ages), end(ages));

    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
      int temp_age = ages[i] * 0.5 + 7;
      int idx1 = upper_bound(begin(ages), end(ages), temp_age) - begin(ages);
      int idx2 = upper_bound(begin(ages), end(ages), ages[i]) - begin(ages);
      if (idx2 - idx1 > 0)
        ans += idx2 - idx1 - 1;
    }

    return ans;
  }
};