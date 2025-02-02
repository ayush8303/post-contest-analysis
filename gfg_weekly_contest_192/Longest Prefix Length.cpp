class Solution
{
public:
  const long long p = 31, mod = 1e9 + 7;
  long long power(long long a, long long b)
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
    return ans;
  }
  long long poly_hash(string s)
  {
    long long hash = 0;
    long long p_power = 1;

    for (int i = 0; i < s.size(); i++)
    {
      hash += (s[i] - 'a' + 1) * p_power;
      p_power *= p;

      hash %= mod;
      p_power %= mod;
    }
    return hash;
  }
  long long inv(long long x)
  {
    // return power(x, mod-2);
    return 129032259;
  }
  bool check(int len, string &s, string &t)
  {
    int n = s.length(), m = t.length();
    unordered_set<long long> hash_values;
    for (long long i = 0, hash = 0, p_power = 1; i < m; i++)
    {
      hash += (t[i] - 'a' + 1) * p_power;
      if (i < len)
        p_power *= p;
      hash %= mod;
      p_power %= mod;
      if (len <= i)
      {
        hash = (hash - (t[i - len] - 'a' + 1) + mod) % mod;
        hash = (hash * inv(p)) % mod;
      }
      if ((len - 1) <= i)
      {
        hash_values.insert(hash);
      }
    }
    if (len == n)
      return poly_hash(s) == poly_hash(t.substr(0, n));
    vector<long long> pref(len + 1);
    for (long long i = 0, hash = 0, p_power = 1; i <= len; i++)
    {
      hash += (s[i] - 'a' + 1) * p_power;
      hash %= mod;
      p_power *= p;
      p_power %= mod;
      pref[i] = hash;
    }
    for (int i = 0; i <= len; i++)
    {
      long long left = (i > 0) ? pref[i - 1] : 0;
      long long right = (pref[len] - pref[i] + mod) % mod;
      right = (right * inv(p)) % mod;
      long long cur = (left + right) % mod;
      if (hash_values.find(cur) != hash_values.end())
        return true;
    }
    return false;
  }
  int longestPrefix(string &s, string &t)
  {
    int n = s.length(), m = t.length();
    int low = 1, high = min(n, m);

    int ans = 0;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (check(mid, s, t))
        ans = mid, low = mid + 1;
      else
        high = mid - 1;
    }
    return ans;
  }
};