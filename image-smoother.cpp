class Solution
{
public:
  vector<vector<int>> imageSmoother(vector<vector<int>> &img)
  {
    int r = img.size(), c = img[0].size();
    vector<vector<int>> ans(r, vector<int>(c, 0));

    for (int i = 0; i < r; ++i)
    {
      for (int j = 0; j < c; ++j)
      {
        int ct = 0, sum = 0;
        for (int k = i - 1; k <= i + 1; ++k)
        {
          for (int l = j - 1; l <= j + 1; ++l)
          {
            if (k < 0 || k >= r || l < 0 || l >= c)
              continue;
            ct++;
            sum += img[k][l];
          }
        }
        ans[i][j] = sum / ct;
      }
    }

    return ans;
  }
};