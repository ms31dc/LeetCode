class Solution
{
public:
    int romanToInt(string s)
    {
        int result = 0;
        bool flag;
        for(int i=0; i<s.length(); i++)
        {
            flag = true;
            if(s[i] == 'I')
            {
                if(i+1 < s.length())
                {
                    if(s[i+1] == 'V' || s[i+1] == 'X')
                    {
                        if(s[i+1] == 'V')
                        {
                            result = result + 4;
                        }
                        else
                        {
                            result = result + 9;
                        }
                        flag = false;
                        i++;
                    }
                }
                if(flag)
                    result = result + 1;
            }
            else if(s[i] == 'X')
            {
                if(i+1 < s.length())
                {
                    if(s[i+1] == 'L' || s[i+1] == 'C')
                    {
                        if(s[i+1] == 'L')
                        {
                            result = result + 40;
                        }
                        else
                        {
                            result = result + 90;
                        }
                        flag = false;
                        i++;
                    }
                }
                if(flag)
                    result = result + 10;
            }
            else if(s[i] == 'C')
            {
                if(i+1 < s.length())
                {
                    if(s[i+1] == 'D' || s[i+1] == 'M')
                    {
                        if(s[i+1] == 'D')
                        {
                            result = result + 400;
                        }
                        else
                        {
                            result = result + 900;
                        }
                        flag = false;
                        i++;
                    }
                }
                if(flag)
                    result = result + 100;
            }
            else if(s[i] == 'V')
            {
                result = result + 5;
            }
            else if(s[i] == 'L')
            {
                result = result + 50;
            }
            else if(s[i] == 'D')
            {
                result = result + 500;
            }
            else if(s[i] == 'M')
            {
                result = result + 1000;
            }
        }
        return result;
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
        }
        else
        {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        string s = stringToString(line);
        
        int ret = Solution().romanToInt(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
