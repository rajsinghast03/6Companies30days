class Solution
{
public:
  vector<vector<int>> rects;
  int x, y, i = 0;
  Solution(vector<vector<int>> &rects)
  {
    this->rects = rects;
    x = rects[0][0], y = rects[0][1];
  }

  vector<int> pick()
  {
    vector<int> ans = {x, y};
    x++;
    if (x > rects[i][2])
    {
      x = rects[i][0];
      y++;
    }
    if (y > rects[i][3])
    {
      if (i + 1 < rects.size())
      {
        ++i;
      }
      else
      {
        i = 0;
      }
      x = rects[i][0], y = rects[i][1];
    }

    return ans;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */