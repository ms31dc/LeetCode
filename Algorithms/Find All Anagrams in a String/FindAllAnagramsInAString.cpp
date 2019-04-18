class Solution 
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> result;
        if(s.length() < p.length())
        {
            return result;
        }
        
        if(s == p)
        {
            return {0};
        }
        
        for(int i=0; i<=s.length()-p.length(); i++)
        {
            bool flag = true;
            vector<int> characters(26, 0);        
            string temp = s.substr(i, p.length());
            
            for(int j=0; j<p.length(); j++)
            {
                characters[temp[j] - 'a']++;
                characters[p[j] - 'a']--;
            }
            
            for(int j=0; j<26; j++)
            {
                if(characters[j] > 0)
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};
