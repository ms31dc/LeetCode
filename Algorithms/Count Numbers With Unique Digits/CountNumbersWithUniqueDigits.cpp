class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        int result = 1;
        int number = 9;
        int multiplier = 9;
        for(int i=0; i<n; i++)
        {
            result = result + multiplier;
            multiplier = multiplier * number;
            number--;
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
        
        int ret = Solution().countNumbersWithUniqueDigits(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
