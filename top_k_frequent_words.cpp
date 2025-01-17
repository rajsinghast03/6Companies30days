class Solution
{
public:
  struct MyComp
  {
    bool operator()(const pair<int, string> &a, const pair<int, string> &b)
    {
      if (a.first != b.first)
      {
        return a.first > b.first;
      }
      else
      {
        return a.second < b.second;
      }
    }
  };
  vector<string> topKFrequent(vector<string> &words, int k)
  {
    map<string, int> mp;
    for (auto &word : words)
      mp[word]++;

    priority_queue<pair<int, string>, vector<pair<int, string>>, MyComp> pq;

    for (auto it : mp)
    {
      pq.push({it.second, it.first});
      if (pq.size() > k)
      {
        pq.pop();
      }
    }

    vector<string> ans;
    while (!pq.empty())
    {
      ans.insert(ans.begin(), pq.top().second);
      pq.pop();
    }

    return ans;
  }
};