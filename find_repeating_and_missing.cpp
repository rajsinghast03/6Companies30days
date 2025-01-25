int n = arr.size();
int curr_sum = 0;

for (auto it : arr)
  curr_sum += it;

int repeating = -1;

for (int i = 0; i < n; ++i)
{
  int ind = abs(arr[i]) - 1;

  if (arr[ind] < 0)
  {
    repeating = ind + 1;
    break;
  }
  else
  {
    arr[ind] = -arr[ind];
  }
}

curr_sum -= repeating;
int actual_sum = 0;
for (int i = 1; i <= n; ++i)
  actual_sum += i;

int missing = actual_sum - curr_sum;

return {repeating, missing};