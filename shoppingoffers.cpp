class Solution
{
public:
  int solve(int ind, vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
  {
    if (ind < 0)
    {
      int cost = 0;
      for (int i = 0; i < needs.size(); ++i)
      {
        cost += needs[i] * price[i];
      }
      return cost;
    }

    int take = 1e9, ntake = 1e9;
    bool canTake = true;
    for (int i = 0; i < needs.size(); ++i)
    {
      if (special[ind][i] > needs[i])
      {
        canTake = false;
        break;
      }
    }
    if (canTake)
    {
      for (int i = 0; i < needs.size(); ++i)
      {
        needs[i] -= special[ind][i];
      }
      take = special[ind][needs.size()] + solve(ind, price, special, needs);
      for (int i = 0; i < needs.size(); ++i)
      {
        needs[i] += special[ind][i];
      }
      ntake = solve(ind - 1, price, special, needs);
    }
    else
    {
      ntake = solve(ind - 1, price, special, needs);
    }

    return min(take, ntake);
  }
  int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
  {
    int n = special.size();
    return solve(n - 1, price, special, needs);
  }
};