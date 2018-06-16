class Solution 
{
public:
    int getSum(int a, int b) 
    {
        while(b != 0)
        {
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
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
        int a = stringToInteger(line);
        getline(cin, line);
        int b = stringToInteger(line);
        
        int ret = Solution().getSum(a, b);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
