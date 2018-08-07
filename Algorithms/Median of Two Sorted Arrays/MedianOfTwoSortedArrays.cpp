class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int i=0, j=0;
        vector<int> result;
        double median;
        while((i < nums1.size()) && (j < nums2.size()))
        {
            if(nums1[i] < nums2[j])
            {
                result.push_back(nums1[i]);
                i++;
            }
            else
            {
                result.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i<nums1.size())
        {
            result.push_back(nums1[i]);
            i++;
        }
        
        while(j<nums2.size())
        {
            result.push_back(nums2[j]);
            j++;
        }
        
        if((result.size()%2) == 0)
        {
            median = (result[(result.size()/2)] + result[(result.size()/2) - 1]) / 2.0; 
        }
        else
        {
            median = result[(result.size()/2)] * 1.0;
        }

        return median;
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
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        
        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
