class Solution 
{
public:
    int binaryGap(int N) 
    {
        vector<int>bitArray;
        int distance=0;
        int found=0;
        
        while(N > 0)
        {
            bitArray.push_back(N%2);
            N = N / 2;
        }
        
        reverse(bitArray.begin(), bitArray.end());
        
        for(int i=1; i<bitArray.size(); i++)
        {
            if(bitArray[i])
            {
                if((i-found) > distance)
                {
                    distance = i-found;
                }
                found = i;
            }
        }
        return distance;
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
        
        int ret = Solution().binaryGap(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
