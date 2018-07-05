class Solution 
{
public:
    bool isPowerOfFour(int num) 
    {
        bool flag = false;
        if(num < 1)
        {
            return false;
        }
        if(num == 1)
        {
            return true;
        }
        else if(num > 1)
        {
            while(num > 1)
            {
                if(num%4 != 0)
                {
                    flag = true;
                    break;
                }
                num= num/4;
            }
        }
        if(flag)
        {
            return false;
        }
        return true;        
    }
};

int stringToInteger(string input) 
{
    return stoi(input);
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
        int num = stringToInteger(line);
        
        bool ret = Solution().isPowerOfFour(num);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
