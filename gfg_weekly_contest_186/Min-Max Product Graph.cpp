class Solution
{
public:
  long minEdges(long size)
  {
    return size - 1;
  }
  long maxEdges(long size)
  {
    return size * (size - 1) / 2;
  }
  long minRemainingEdges(long n)
  {
    long twoSizeComponents = 0;
    long threeSizeComponents = n / 3;
    long rem = n % 3;

    if (rem == 1)
    {
      threeSizeComponents--;
      twoSizeComponents = 2;
    }
    else if (rem == 2)
    {
      twoSizeComponents = 1;
    }
    return threeSizeComponents * minEdges(3) + twoSizeComponents * minEdges(2);
  }

  long maxRemainingEdges(long n)
  {
    long fourSizeComponents = 0;
    long twoSizeComponents = 0;
    long threeSizeComponents = n / 3;

    long rem = n % 3;
    if (rem == 1)
    {
      fourSizeComponents = 1;
      threeSizeComponents--;
    }
    else if (rem == 2)
    {
      twoSizeComponents = 1;
    }
    long res = twoSizeComponents * maxEdges(2);
    res += threeSizeComponents * maxEdges(3);
    res += fourSizeComponents * maxEdges(4);

    return res;
  }

  int minmaxDifference(long n)
  {
    if (n <= 2)
    {
      return 0;
    }
    int mod = (int)(1e9 + 7);

    long res = (maxRemainingEdges(n) - minRemainingEdges(n)) % mod;
    return (int)res;
  }
};