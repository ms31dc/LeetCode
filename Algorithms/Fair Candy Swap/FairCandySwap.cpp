class Solution 
{
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) 
    {
        int sumA=0, sumB=0;
        vector<int> result;
        for(int i=0; i<A.size(); i++)
        {
            sumA = sumA + A[i];
        }
        
        for(int j=0; j<B.size(); j++)
        {
            sumB = sumB + B[j];
        }
        
        for(int i=0; i<A.size(); i++)
        {
            for(int j=0; j<B.size(); j++)
            {
                int tempA = sumA, tempB = sumB;
                tempA = tempA - A[i] + B[j];
                tempB = tempB - B[j] + A[i];
                if(tempA == tempB)
                {
                    result.push_back(A[i]);
                    result.push_back(B[j]);
                    return result;
                }
            }
        }
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
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> B = stringToIntegerVector(line);
        
        vector<int> ret = Solution().fairCandySwap(A, B);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
