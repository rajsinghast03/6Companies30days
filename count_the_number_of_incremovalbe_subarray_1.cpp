class Solution
{
public:
  int incremovableSubarrayCount(vector<int> &nums)
  {
    int n = nums.size();

    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
      for (int j = i; j < n; ++j)
      {
        int last = -1;
        bool flag = true;
        for (int k = 0; k < n; ++k)
        {
          if (k >= i && k <= j)
            continue;
          if (last >= nums[k])
          {
            flag = false;
            break;
          }
          last = nums[k];
        }
        if (flag)
          ans++;
      }
    }

    return ans;
  }
};