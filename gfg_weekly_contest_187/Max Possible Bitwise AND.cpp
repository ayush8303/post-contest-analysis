class Solution
{
public:
  long long maxAND(int k, vector<int> &arr)
  {
    int n = arr.size();
    vector<long long> subarraySum;
    for (int i = 0; i < n; i++)
    {
      long long cur = 0;
      for (int j = i; j < n; j++)
      {
        cur += arr[j];
        subarraySum.push_back(cur);
      }
    }
    long long ans = 0;
    for (int bit = 40; bit >= 0; bit--)
    {
      int cnt = 0;
      for (long long sum : subarraySum)
      {
        int val = (sum >> bit) & 1ll;
        cnt += val;
      }
      if (cnt < k)
        continue;
      ans |= (1ll << bit);
      for (long long &sum : subarraySum)
      {
        int val = (sum >> bit) & 1ll;
        if (val == 0)
        {
          sum = 0;
        }
      }
    }
    return ans;
  }
};
