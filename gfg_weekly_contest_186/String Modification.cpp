class Solution
{
public:
  int f(char a, char b)
  {
    if (a > b)
      swap(a, b);
    int d = b - a;
    d = min(d, 26 - d);
    return d;
  }

  string findSmallest(string &s, int k)
  {
    int n = s.length();
    vector<vector<int>> cost((n + 1) / 2, vector<int>(26));
    int dp[n];
    int i = 0, j = n - 1;

    while (i <= j)
    {
      dp[i] = 1e9 + 7;
      for (int c = 0; c < 26; c++)
      {
        cost[i][c] = f(s[i], char(c + 'a')) + f(s[j], char(c + 'a'));
        if (i == j)
        {
          cost[i][c] /= 2;
        }
        dp[i] = min(dp[i], cost[i][c]);
      }
      k -= dp[i];
      ++i, --j;
    }

    if (k < 0)
      return "";

    i = 0, j = n - 1;
    while (i <= j)
    {
      for (int c = 0; c < 26; c++)
      {
        if (cost[i][c] - dp[i] <= k)
        {
          k -= (cost[i][c] - dp[i]);
          s[i] = s[j] = char(c + 'a');
          break;
        }
      }
      ++i, --j;
    }

    return s;
  }
};
