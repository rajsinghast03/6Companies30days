class Solution
{
public:
  int atMostK(vector<int> &nums, int k)
  {
    int n = nums.size();
    int ct = 0, ctOdd = 0;
    int i = 0, j = 0;

    while (j < n)
    {
      if (nums[j] & 1)
        ctOdd++;
      while (ctOdd > k)
      {
        if (nums[i] & 1)
          ctOdd--;
        ++i;
      }
      ct += j - i + 1;
      ++j;
    }

    return ct;
  }
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    return atMostK(nums, k) - atMostK(nums, k - 1);
  }
};