class Solution
{
public:
  int power(long long a, int b, int mod)
  {
    long long ans = 1;
    while (b > 0)
    {
      if (b & 1)
      {
        ans = (ans * a) % mod;
      }
      a = (a * a) % mod;
      b >>= 1;
    }
    return (int)ans;
  }
  int countNumbers(int n)
  {
    int mod = 1e9 + 7;
    long long ans = power(4, n, mod) + power(3, n, mod) + 1;
    ans %= mod;
    return (int)ans;
  }
};