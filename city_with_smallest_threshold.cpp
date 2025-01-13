class Solution
{
public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
  {
    vector<vector<int>> dist(n, vector<int>(n, 1e8));

    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];
      int edgWt = it[2];
      dist[u][u] = 0, dist[v][v] = 0;

      dist[u][v] = edgWt;
      dist[v][u] = edgWt;
    }

    for (int k = 0; k < n; ++k)
    {
      for (int i = 0; i < n; ++i)
      {
        for (int j = 0; j < n; ++j)
        {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    int sm_city = 0, sm_count = n + 1;

    for (int i = 0; i < n; ++i)
    {
      int ct = 0;
      for (int j = 0; j < n; ++j)
      {
        if (dist[i][j] <= distanceThreshold)
          ct++;
      }
      if (ct <= sm_count)
      {
        sm_city = i;
        sm_count = ct;
      }
    }

    return sm_city;
  }
};