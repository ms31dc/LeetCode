class Solution
{
public:
    int rotatedDigits(int N)
    {
        int result = 0, zeroOneEightCount=0, count=0, temp, rem;
        bool flag;
        for(int i = 1; i <= N; i++)
        {
            count=0;
            zeroOneEightCount=0;
            temp = i;
            flag = true;
            while(temp > 0)
            {
                if(flag)
                {
                    rem = temp % 10;
                    temp = temp / 10;
                    switch(rem)
                    {
                        case 0:
                        case 1:
                        case 8:
                            zeroOneEightCount++;
                        case 2:
                        case 5:
                        case 6:
                        case 9:
                            break;
                        default:
                            flag = false;
                            break;
                    }
                    count++;
                }
                else
                    break;
            }
            if(flag && !(count == zeroOneEightCount))
                result++;
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
        
        int ret = Solution().rotatedDigits(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
