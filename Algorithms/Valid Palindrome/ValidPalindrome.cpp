class Solution
{
public:
    bool isPalindrome(string s)
    {
        string filteredString="";
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] >=65 && s[i] <=90)
            {
                filteredString += s[i]+32;
            }
            else if(s[i] >=97 && s[i] <=122)
            {
                filteredString += s[i];
            }
            else if(s[i] >=48 && s[i] <=57)
            {
                filteredString += s[i];
            }
        }
        int j=filteredString.length()-1;
        bool result = true;
        for(int i=0; i<filteredString.length()/2; i++)
        {
            if(filteredString[i] != filteredString[j])
            {
                return false;
            }
            j--;
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

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        string s = stringToString(line);
        
        bool ret = Solution().isPalindrome(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
