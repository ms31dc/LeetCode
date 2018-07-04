class Solution
{
public:
    int bulbSwitch(int n)
    {
        /* 32/35 TCs passed and rest are giving timeout therefore opting existing solution.
        vector<bool> result(n);
        int count=0;
        for(int i=0; i<n; i++)
        {
            count++;
            for(int j=i; j<n; j=j+count)
            {
                result[j] = !(result[j]);
            }
        }
        count = 0;
        for(int i=0; i<n; i++)
        {
            if(result[i])
            {
                count++;
            }
        }
        return count;
        */
        return(int(sqrt(n)));
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
        
        int ret = Solution().bulbSwitch(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
