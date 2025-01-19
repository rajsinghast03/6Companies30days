class Solution
{
public:
  int maximumProduct(vector<int> &nums, int k)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0] + k;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i)
      pq.push(nums[i]);

    while (k > 0)
    {
      int num1 = pq.top();
      pq.pop();
      int num2 = pq.top();
      pq.pop();

      if (num1 == num2)
      {
        num1++;
        k--;
      }
      else if (num1 < num2)
      {
        int diff = num2 - num1;
        if (diff <= k)
        {
          num1 += diff;
          k -= diff;
        }
        else
        {
          num1 += k;
          k = 0;
        }
      }
      else
      {
        int diff = num1 - num2;
        if (diff <= k)
        {
          num2 += diff;
          k -= diff;
        }
        else
        {
          num2 += k;
          k = 0;
        }
      }

      pq.push(num1);
      pq.push(num2);
    }

    long long ans = 1;
    int M = 1e9 + 7;

    while (!pq.empty())
    {
      ans *= pq.top();
      pq.pop();
      ans %= M;
    }

    return ans;
  }
};