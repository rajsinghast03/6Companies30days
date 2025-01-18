class Solution
{
public:
  // int solve(int i,int j,vector<int>& nums1, vector<int>& nums2) {
  //     if(i < 0 || j < 0) return 0;

  //     if(nums1[i] == nums2[j]) {
  //          return 1 + solve(i-1,j-1,nums1,nums2);
  //     }else {
  //         return max(solve(i,j-1,nums1,nums2),solve(i-1,j,nums1,nums2));
  //     }
  // }
  int findLength(vector<int> &nums1, vector<int> &nums2)
  {
    int n1 = nums1.size(), n2 = nums2.size();
    // return solve(n1-1,n2-1,nums1,nums2);
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    int ans = 0;

    for (int i = 1; i <= n1; ++i)
    {
      for (int j = 1; j <= n2; ++j)
      {
        if (nums1[i - 1] == nums2[j - 1])
        {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          ans = max(ans, dp[i][j]);
        }
        else
          dp[i][j] = 0;
      }
    }

    return ans;
  }
};