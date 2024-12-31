class Solution
{
public:
  bool inside(int xc, int yc, int x, int y, int r)
  {
    return (x - xc) * (x - xc) + (y - yc) * (y - yc) <= r * r;
  }
  bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
  {
    if (x1 <= xCenter && x2 >= xCenter && y1 <= yCenter && y2 >= yCenter)
      return true;
    for (int i = x1; i <= x2; ++i)
    {
      if (inside(xCenter, yCenter, i, y1, radius))
        return true;
    }
    for (int i = x1; i <= x2; ++i)
    {
      if (inside(xCenter, yCenter, i, y2, radius))
        return true;
    }
    for (int i = y1; i <= y2; ++i)
    {
      if (inside(xCenter, yCenter, x1, i, radius))
        return true;
    }
    for (int i = y1; i <= y2; ++i)
    {
      if (inside(xCenter, yCenter, x2, i, radius))
        return true;
    }

    return false;
  }
};