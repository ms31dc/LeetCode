class Solution
{
public:
    int repeatedStringMatch(string A, string B)
    {
        int maxLength = 2*(B.length());
        string initialA = A, tempA = A, tempB = B;
        int result = 1, countA = 1, countB = 1;
        
        sort(tempA.begin(), tempA.end());
        sort(tempB.begin(), tempB.end());
        
        for(int i=1; i< tempA.length(); i++)
        {
            if(tempA[i-1] != tempA[i])
            {
                countA++;
            }
        }
        
        for(int i=1; i< tempB.length(); i++)
        {
            if(tempB[i-1] != tempB[i])
            {
                countB++;
            }
        }
        
        if(countA < countB)
        {
            return -1;
        }
        
        if(A.length() < B.length())
        {
            while((A.find(B) == std::string::npos) && (A.length() < maxLength))
            {
                A = A + initialA;
                result++;
            }
            if(A.find(B) == std::string::npos)
            {
                return -1;
            }
        }
        else
        {
            if(A.find(B) == std::string::npos)
            {
                A = A + initialA;
                result++;
                if(A.find(B) == std::string::npos)
                {
                    return -1;
                }
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
        string A = stringToString(line);
        getline(cin, line);
        string B = stringToString(line);
        
        int ret = Solution().repeatedStringMatch(A, B);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
