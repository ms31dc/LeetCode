class Solution
{
public:
    int hammingDistance(int x, int y)
    {
      int count=0;
      bool flag1=false, flag2=false;
      while(x > 0 || y > 0)
      {
        if(x > 0)
        {
          if(x % 2 == 1)
          {
            flag1 = true;
          }
          x /= 2;
        }
        if(y > 0)
        {
          if(y % 2 == 1)
          {
            flag2 = true;
          }
          y /= 2;
        }
        if(flag1 != flag2)
          count++;
        flag1=false;
        flag2=false;
      }
      return count;
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        int x = stringToInteger(line);
        getline(cin, line);
        int y = stringToInteger(line);
        
        int ret = Solution().hammingDistance(x, y);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
