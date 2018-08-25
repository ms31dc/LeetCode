class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        bool flag=true;
        vector<int> temp = temperatures;
        sort(temp.begin(), temp.end());
        int greatest = temp[temp.size()-1];
        for(int i=0; i<temperatures.size(); i++)
        {
            if(temperatures[i] < greatest)
            {
                for(int j=i+1; j<temperatures.size(); j++)
                {
                    if(temperatures[j] > temperatures[i])
                    {
                        temperatures[i] = j-i;
                        flag = false;
                        break;
                    }
                }
                if(flag)
                {
                    temperatures[i] = 0;
                }
                flag = true;
            }
            else
            {
                temperatures[i] = 0;
            }
        }
        return temperatures;
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

string integerVectorToString(vector<int> list, int length = -1) 
{
    if (length == -1) 
    {
        length = list.size();
    }

    if (length == 0) 
    {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) 
    {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        vector<int> T = stringToIntegerVector(line);
        
        vector<int> ret = Solution().dailyTemperatures(T);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
