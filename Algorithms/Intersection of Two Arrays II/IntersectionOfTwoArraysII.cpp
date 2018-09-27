class Solution 
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        if(nums1.size() < nums2.size())
        {
            vector<bool> checkArray(nums2.size(), false);
            for(int i=0; i<nums1.size(); i++)
            {
                for(int j=0; j<nums2.size(); j++)
                {
                    if((nums1[i] == nums2[j]) && !checkArray[j])
                    {
                        result.push_back(nums1[i]);
                        checkArray[j] = true;
                        break;
                    }
                    else if(nums1[i] < nums2[j])
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            vector<bool> checkArray(nums1.size(), false);
            for(int i=0; i<nums2.size(); i++)
            {
                for(int j=0; j<nums1.size(); j++)
                {
                    if((nums2[i] == nums1[j]) && !checkArray[j])
                    {
                        result.push_back(nums2[i]);
                        checkArray[j] = true;
                        break;
                    }
                }
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
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        
        vector<int> ret = Solution().intersect(nums1, nums2);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
