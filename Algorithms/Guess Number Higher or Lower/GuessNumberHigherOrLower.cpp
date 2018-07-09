// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution 
{
public:
    int guessNumber(int n) 
    {
        int low = 1, high = n, num, returnValue;
        
        while(low < high)
        {
            num = low + (high-low)/2;
            returnValue = guess(num);
            if(returnValue == 0)
            {
                return num;
            }
            else if(returnValue > 0)
            {
                low = num+1;
            }
            else
            {               
                high = num;                
            }
        }
        return low;
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
        getline(cin, line);
        int pick = stringToInteger(line);
        
        int ret = Solution().guessNumber(n, pick);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
