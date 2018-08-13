class Solution 
{
public:
    string reverseVowels(string s) 
    {
        vector<char> vowelsArray;
        int index=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
               s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                vowelsArray.push_back(s[i]);
            }
        }
        
        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
               s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                s[i] = vowelsArray[index++];
            }
        }
        return s;
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
        
        string ret = Solution().reverseVowels(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
