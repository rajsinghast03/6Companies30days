deque<int> dq;
vector<int> ans;
int n = arr.size(), i = 0, j = 0;

while (j < n)
{
  int el = arr[j];
  while (!dq.empty() && arr[dq.back()] < el)
    dq.pop_back();
  dq.push_back(j);

  while (j - i + 1 > k)
  {
    if (dq.front() == i)
      dq.pop_front();
    ++i;
  }

  if (j - i + 1 == k)
    ans.push_back(arr[dq.front()]);
  j++;
}

return ans;