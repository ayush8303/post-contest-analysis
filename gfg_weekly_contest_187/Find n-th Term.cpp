class Solution
{
public:
  int numWays(string &s)
  {
    const int mod = 1000000007;
    int n = s.size();
    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
      if (s[i] == '0')
      {
        if (i + 1 < n)
        {
          dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
        }
        if (i + 2 < n)
        {
          dp[i + 2] = (dp[i + 2] + dp[i]) % mod;
        }
      }
      else
      {
        if (i + 1 < n)
        {
          dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
        }
      }
    }
    return dp[n - 1];
  }
};
