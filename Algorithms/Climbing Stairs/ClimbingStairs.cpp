class Solution
{
public:
    int climbStairs(int n)
    {
        int result=0, first=0, second=1;
        for(int i=0; i<n; i++)
        {
            result = first + second;
            first = second;
            second = result;
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
        
        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
