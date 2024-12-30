class Solution
{
public:
  int nthTerm(int n)
  {
    int mod = 1e9 + 7;
    long long f[n + 1];
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++)
    {
      f[i] = (i * f[i - 1]) % mod;
      f[i] = (f[i] - ((i - 1) * f[i - 2]) % mod + mod) % mod;
      f[i] = (f[i] + (i - 2) * 3) % mod;
    }
    return (int)f[n];
  }
};