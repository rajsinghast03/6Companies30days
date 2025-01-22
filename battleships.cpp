class Solution
{
public:
  void dfs(int curr_i, int curr_j, vector<vector<int>> &vis, vector<vector<char>> &board, int n, int m)
  {
    vis[curr_i][curr_j] = 1;
    for (int i = curr_i + 1; i < n; ++i)
    {
      if (!vis[i][curr_j] && board[i][curr_j] != '.')
      {
        dfs(i, curr_j, vis, board, n, m);
      }
      else
        break;
    }

    for (int j = curr_j + 1; j < m; ++j)
    {
      if (!vis[curr_i][j] && board[curr_i][j] != '.')
      {
        dfs(curr_i, j, vis, board, n, m);
      }
      else
        break;
    }
  }
  int countBattleships(vector<vector<char>> &board)
  {
    int n = board.size(), m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        if (!vis[i][j] && board[i][j] != '.')
        {
          ans++;
          dfs(i, j, vis, board, n, m);
        }
      }
    }

    return ans;
  }
};