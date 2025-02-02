class Solution
{
public:
  int minCharacter(string &s, string &t)
  {
    int n = s.size(), m = t.size();
    int ans = n;
    for (int start = 0; start < m; start++)
    {
      int j = start, i = 0;
      int del = 0;
      while (i < n && j < m)
      {
        if (s[i] == t[j])
          j++;
        else
          del++;
        i++;
      }
      ans = min(ans, del + n - i);
    }
    return ans;
  }
};
