class Solution
{
public:
  bool isPossible(string &s)
  {
    int win = 0;

    for (auto it : s)
    {
      if (it == 'W')
        win++;
    }

    int totalPossibleWins = win + (14 - s.size());

    return (totalPossibleWins >= 8);
  }
};
