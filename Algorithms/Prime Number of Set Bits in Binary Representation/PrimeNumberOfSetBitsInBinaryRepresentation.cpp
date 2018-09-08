class Solution 
{
public:
    int countPrimeSetBits(int L, int R) 
    {
        int result=0;
        bool primeCount=false;
        for(int i=L; i<=R; i++)
        {
            int temp = i;
            int count=0;
            while(temp > 0)
            {
                if(temp%2 != 0)
                    count++;
                temp = temp/2;
            }
            for(int j=2; j<count; j++)
            {
                if(count%j == 0)
                {
                    primeCount = true;
                    break;
                }
            }
            if(!primeCount && !(count == 1))
            {
                result++;               
            }
            primeCount=false; 
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
        int L = stringToInteger(line);
        getline(cin, line);
        int R = stringToInteger(line);
        
        int ret = Solution().countPrimeSetBits(L, R);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
