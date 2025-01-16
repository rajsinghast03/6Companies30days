class Solution
{
public:
  int maxEnvelopes(vector<vector<int>> &envelopes)
  {
    int n = envelopes.size();
    sort(begin(envelopes), end(envelopes), [](vector<int> &a, vector<int> &b)
         {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0]; });

    vector<int> temp;
    int ans = 1;

    for (auto it : envelopes)
    {
      int h = it[1];
      if (temp.size() == 0 || temp.back() < h)
        temp.push_back(h);
      else
      {
        int idx = lower_bound(begin(temp), end(temp), h) - begin(temp);
        temp[idx] = h;
      }

      ans = max(ans, (int)temp.size());
    }

    return ans;
  }
};