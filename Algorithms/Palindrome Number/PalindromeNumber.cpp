class Solution
{
public:
    bool isPalindrome(int x) 
    {
        int temp = x, number = 0;
        while(temp > 0)
        {
            number = (number * 10) + (temp % 10);
            temp = temp / 10;
        }
        return (x == number);
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
        int x = stringToInteger(line);
        
        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
