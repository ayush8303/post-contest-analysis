class Solution
{
public:
  int maxLength(vector<int> &arr)
  {

    unordered_map<int, int> freq;
    for (int x : arr)
      freq[x]++;

    vector<vector<int>> v;
    for (pair<int, int> pr : freq)
      v.push_back({pr.first, pr.second});

    unordered_map<int, int> sum;
    for (int i = 0; i < v.size(); i++)
    {

      sum[v[i][0]] += v[i][1];

      sum[v[i][0] * 2] += v[i][1] / 2;

      for (int j = i + 1; j < v.size(); j++)
      {
        sum[v[j][0] + v[i][0]] += min(v[j][1], v[i][1]);
      }
    }
    int res = 1;
    for (auto it : sum)
      res = max(res, it.second);

    return res - 1;
  }
};