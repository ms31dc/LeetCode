class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int i=0, count=0;
        while(moves[i] != '\0')
        {
            switch(moves[i])
            {
                case 'U':
                case 'R':
                    count++;
                    break;
                case 'D':
                case 'L':
                    count--;
                    break;
            }
            i++;
        }
        if(!count)
            return true;
        return false;
    }
};

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++)
    {
        char currentChar = input[i];
        if (input[i] == '\\')
        {
            char nextChar = input[i+1];
            switch (nextChar)
            {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string moves = stringToString(line);
        
        bool ret = Solution().judgeCircle(moves);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
