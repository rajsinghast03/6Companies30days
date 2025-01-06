class Solution
{
public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    int r = grid.size(), c = grid[0].size();
    queue<pair<int, pair<int, int>>> q;
    int drow[4] = {-1, 0, +1, 0};
    int dcol[4] = {0, +1, 0, -1};

    for (int i = 0; i < r; ++i)
    {
      for (int j = 0; j < c; ++j)
      {
        if (grid[i][j] == 2)
          q.push({0, {i, j}});
      }
    }

    int ans = 0;

    while (!q.empty())
    {
      auto it = q.front();
      int x = it.second.first, y = it.second.second, t = it.first;
      q.pop();

      for (int k = 0; k < 4; ++k)
      {
        int nx = x + drow[k];
        int ny = y + dcol[k];

        if (nx < 0 || ny < 0 || nx >= r || ny >= c || grid[nx][ny] == 0 || grid[nx][ny] == 2)
          continue;
        q.push({t + 1, {nx, ny}});
        ans = max(ans, t + 1);
        grid[nx][ny] = 2;
      }
    }

    for (int i = 0; i < r; ++i)
    {
      for (int j = 0; j < c; ++j)
      {
        if (grid[i][j] == 1)
          return -1;
      }
    }

    return ans;
  }
};