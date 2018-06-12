class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result = "", output = "";
        bool carry = false;
        
        int i=a.length()-1, j=b.length()-1;
        
        while(i >= 0 && j >= 0)
        {
            if((a[i] == '1') && (b[j] == '1'))
            {
                if(carry)
                    result = result + "1";
                else
                {
                    result = result + "0";
                    carry = true;
                }
            }
            
            if(((a[i] == '1') && (b[j] == '0')) || ((a[i] == '0') && (b[j] == '1')))
            {
                if(carry)
                    result = result + "0";
                else
                    result = result + "1";
            }
            
            if((a[i] == '0') && (b[j] == '0'))
            {
                if(carry)
                    result = result + "1";
                else
                    result = result + "0";
                
                carry = false;
            }
            
            i--;
            j--;
        }
        
        if(i == -1 && j >= 0)
        {
            while(j >= 0)
            {
                if(b[j] == '1')
                {
                    if(carry)
                        result = result + "0";
                    else
                    {
                        result = result + "1";
                        carry = false;
                    }
                }
                else if(b[j] == '0')
                {
                    if(carry)
                        result = result + "1";
                    else
                        result = result + "0";
                    carry = false;
                }
                
                j--;
            }
        }
        else if(j == -1 && i >= 0)
        {
            while(i >= 0)
            {
                if(a[i] == '1')
                {
                    if(carry)
                        result = result + "0";
                    else
                    {
                        result = result + "1";
                        carry = false;
                    }
                }
                else if(a[i] == '0')
                {
                    if(carry)
                        result = result + "1";
                    else
                        result = result + "0";
                    carry = false;
                }
                
                i--;
            }
        }

        if(i==-1 && j==-1)
        {
            if(carry)
                result = result + "1";
        }
        
        for(int ii=result.length()-1; ii>=0; ii--)
        {
            output = output + result[ii];
        }
        
        return output;
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
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);
        
        string ret = Solution().addBinary(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
