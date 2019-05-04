class Solution 
{
public:
    int bitwiseComplement(int N) 
    {
        int count = 0;
        int result = 0;
        if(!N)
        {
            return 1;
        }
        
        while(N > 0)
        {
            int temp = N % 2;
            if(!temp)
            {
                result += pow(2, count);
            }
            N /= 2;
            count++;
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
        int N = stringToInteger(line);
        
        int ret = Solution().bitwiseComplement(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
