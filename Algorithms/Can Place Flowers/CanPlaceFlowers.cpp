class Solution
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        if(n == 0)
        {
            return true;
        }
        
        if(flowerbed.size() == 1 && flowerbed[0] == 0 && n == 1)
        {
            return true;
        }
        else if(flowerbed.size() > 1)
        {
            if(flowerbed[0] == 0 && flowerbed[1] == 0 && n > 0)
            {
                n--;
                flowerbed[0] = 1;
            }
            for(int i=2; i<flowerbed.size()-2; i++)
            {
                if(n == 0)
                    break;
                if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            if(flowerbed[flowerbed.size()-2] == 0 && flowerbed[flowerbed.size()-1] == 0 && n > 0)
            {
                n--;
                flowerbed[flowerbed.size()-2] = 1;
            }            
            if(n > 0)
                return false;
            else
                return true;
        }
        return false;
    }
};

void trimLeftTrailingSpaces(string &input) 
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) 
    {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
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

int stringToInteger(string input) 
{
    return stoi(input);
}

string boolToString(bool input) 
{
    return input ? "True" : "False";
}

int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        vector<int> flowerbed = stringToIntegerVector(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        bool ret = Solution().canPlaceFlowers(flowerbed, n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
