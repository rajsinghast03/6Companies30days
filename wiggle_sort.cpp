class Solution
{
public:
  void wiggleSort(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return;
    int maxi = *max_element(begin(nums), end(nums));

    vector<int> temp(maxi + 1, 0);
    for (int i = 0; i < n; ++i)
      temp[nums[i]]++;

    int k = 1;
    for (int i = maxi; i >= 0 && k < n; --i)
    {
      while (temp[i] > 0 && k < n)
      {
        nums[k] = i;
        k += 2;
        temp[i]--;
      }
    }

    k = 0;
    for (int i = maxi; i >= 0 && k < n; --i)
    {
      while (temp[i] > 0 && k < n)
      {
        nums[k] = i;
        k += 2;
        temp[i]--;
      }
    }
  }
};