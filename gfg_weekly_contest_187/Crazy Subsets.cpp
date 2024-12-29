class Solution
{
public:
  long long power(long long a, long long b, long long m)
  {
    long long ans = 1;
    while (b > 0)
    {
      if (b & 1)
      {
        ans = (ans * a) % m;
      }
      a = (a * a) % m;
      b >>= 1;
    }
    return ans % m;
  }

  int cntSubsets(vector<int> &arr, int l, int r)
  {
    const int mod = 1e9 + 7;
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int num : arr)
    {
      mp[num]++;
    }

    long long ans = 0;
    long long cur = 1;
    int prev = 0;

    for (int i = 0; i < l; i++)
    {
      if (mp[i] == 0)
      {
        return 0;
      }

      prev += mp[i];
      cur *= (power(2, mp[i], mod) - 1 + mod);
      cur %= mod;
    }

    for (int i = l; i <= r; i++)
    {
      long long here = cur * power(2, n - prev - mp[i], mod);
      here %= mod;
      ans += here;
      ans %= mod;

      if (mp[i] == 0)
      {
        return ans;
      }

      prev += mp[i];
      cur *= (power(2, mp[i], mod) - 1 + mod);
      cur %= mod;
    }

    return int(ans);
  }
};
