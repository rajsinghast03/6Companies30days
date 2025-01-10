class Solution
{
public:
  string convertToTitle(int num)
  {
    string ans;

    while (num > 0)
    {
      num--;
      int ld = num % 26;
      num /= 26;
      ans.push_back('A' + ld);
    }
    reverse(begin(ans), end(ans));
    return ans;
  }
};