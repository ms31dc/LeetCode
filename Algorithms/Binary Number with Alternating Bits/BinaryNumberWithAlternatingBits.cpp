class Solution
{
public:
    bool hasAlternatingBits(int n) 
    {
        int previous, next;
        if(n > 0)
        {
            previous = n%2;
            n = n/2;
        }
        
        while(n > 0)
        {
            next = n%2;
            n = n/2;
            if(previous == 0)
            {
                if(next == 1)
                {
                    previous = 1;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(next == 0)
                {
                    previous = 0;
                }
                else
                {
                    return false;
                }
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
        int n = stringToInteger(line);
        
        bool ret = Solution().hasAlternatingBits(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
