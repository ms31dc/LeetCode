class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        int result = 0; 
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());        
        cout << "G: " << g.size();
        for(int i=0; i<g.size(); i++)
        {
            vector<int>::iterator it = std::lower_bound(s.begin(), s.end(), g[i]);            
            if(it != s.end())
            {
                int index = distance(s.begin(), it);
                s.erase(s.begin()+index);
                result++;
            }
        }
        return result;
    }
};

void trimLeftTrailingSpaces(string &input) 
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) 
    {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) 
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) 
    {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) 
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) 
    {
        output.push_back(stoi(item));
    }
    return output;
}

int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        vector<int> g = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> s = stringToIntegerVector(line);
        
        int ret = Solution().findContentChildren(g, s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
