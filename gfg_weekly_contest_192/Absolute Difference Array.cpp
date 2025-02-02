class Solution
{
public:
  bool isVowel(char c)
  {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

  vector<int> absDifference(string &s)
  {
    int n = s.size();
    vector<int> ans(n);
    int v = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
      if (isVowel(s[i]))
        v++;
      else
        c++;
      ans[i] = abs(v - c);
    }
    return ans;
  }
};