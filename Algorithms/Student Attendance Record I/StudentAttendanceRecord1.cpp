class Solution
{
public:
    bool checkRecord(string s)
    {
        int absent=0, late=0;
        bool flag = true;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == 'A')
            {
                absent++;
                if(absent > 1)
                {
                    flag = false;
                    break;
                }
            }
            
            if((s[i] == 'L') && (i+1 < s.length()))
            {
                if((s[i+1] == 'L') && (i+2 < s.length()))
                {
                    if(s[i+2] == 'L')
                    {                        
                        flag = false;
                        break;
                    }
                }
            }
        }
        return flag;
    }
};
