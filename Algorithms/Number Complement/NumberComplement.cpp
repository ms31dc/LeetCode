class Solution
{
public:
    int findComplement(int num)
    {        
        vector<int> number;
        int index = 1, temp = num, result = 0, pow = 2;
        while(num > 0)
        {
            if(num % 2 == 1)
                number.push_back(0);
            else
                number.push_back(1);
            num = num / 2;
            if(number.size() > 1)
            {
                result = result + (number[index] * pow); 
                index++;
                pow = pow * 2;
            }
        }
        if(temp == 0)
            return 1;
        return (result + number[0]);
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
        int num = stringToInteger(line);
        
        int ret = Solution().findComplement(num);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
