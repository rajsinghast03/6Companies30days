char order[] = {'!', '#', '$', '%', '&', '*', '?', '@', '^'};
int pos = 0;
for (int i = 0; i < 9; ++i)
{
  for (int j = 0; j < n; ++j)
  {
    if (order[i] == nuts[j])
    {
      swap(nuts[j], nuts[pos]);
      bolts[pos] = order[i];
      pos++;
    }
  }
}