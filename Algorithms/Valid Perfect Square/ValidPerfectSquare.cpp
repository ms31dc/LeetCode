class Solution 
{
public:
    bool isPerfectSquare(int num) 
    {
        int i=0;
        long square;
        if(num > 2147483640)
            return false;
        while(i<=num)
        {
            square = i*i;
            if(square == num)
                return true;
            if(square > num)
                break;
            i++;
        }
        return false;
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
        
        bool ret = Solution().isPerfectSquare(num);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
