class Solution 
{
public:
    uint32_t reverseBits(uint32_t n) 
    {
        vector<int> binaryInput;
        for(int i=0; i<32; i++)
        {
            binaryInput.push_back(n%2);
            n /= 2;
        } 
        
        for(int i=31; i>=0; i--)
        {
            if(binaryInput[i])
            {
                n += pow(2, 31-i);
            }
        }
        return n;
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
        
        int ret = Solution().reverseBits(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
