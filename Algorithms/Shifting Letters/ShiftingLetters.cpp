class Solution
{
public:
    string shiftingLetters(string S, vector<int>& shifts)
    {
        string result;
        unsigned long long sum=0;
        
        for(int i=0; i<shifts.size(); i++)
        {
            sum = sum + shifts[i];
        }
        
        for(int i=0; i< S.length(); i++)
        {
            int temp = int(S[i]) + (sum % 26);
            if(temp > 122)
                temp = temp - 26;
            S[i] = char(temp);
            sum = sum - shifts[i];
        }
        
        return S;
    }
};
