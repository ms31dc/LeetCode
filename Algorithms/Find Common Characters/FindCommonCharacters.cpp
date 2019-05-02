class Solution 
{
public:
    vector<string> commonChars(vector<string>& A) 
    {
        vector<int> characters(26, INT_MAX);
        vector<string> result;
        for(int i=0; i<A.size(); i++)
        {
            vector<int> tempCharacters(26, 0);            
            for(int j=0; j<A[i].length(); j++)
            {
                tempCharacters[A[i][j] - 'a']++;
            }
            for(int j=0; j<26; j++)
            {
                characters[j] = min(characters[j], tempCharacters[j]);
            }
        }
        
        for(int i=0; i<26; i++)
        {
            for(int j=0; j<characters[i]; j++)
            {                
                string temp;
                temp.push_back(static_cast<char>(i+'a'));
                result.push_back(temp);
            }
        }
        
        return result;
    }
};
