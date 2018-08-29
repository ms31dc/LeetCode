class Solution
{
public:
    int minSteps(int n)
    {
        int result=0, i=2;
        if(n == 1)
        {
            return 0;
        }
        else if(n > 1)
        {
            while(n > 1)
            {
                if(n%i == 0)
                {
                    result = result + i;
                    n = n / i;
                }
                else
                {
                    i++;   
                }
            }
        }
        return result;
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
        int n = stringToInteger(line);
        
        int ret = Solution().minSteps(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
