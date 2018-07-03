class Solution 
{
public:
    bool isUgly(int num) 
    {
        if(num == 0)
            return false;
        while(num != 1)
        {
            if(num % 2 == 0)
            {
                num = num / 2;
            }
            else if(num % 3 == 0)
            {
                num = num / 3;
            }
            else if(num % 5 == 0)
            {
                num = num / 5;
            }
            else
            {
                return false;
            }
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
        
        bool ret = Solution().isUgly(num);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
