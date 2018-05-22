class Solution
{
public:
    vector<int> numberOfLines(vector<int>& widths, string S)
    {
        vector<int> output;
        int widthValue, result = 0, rowcount = 1;
        for(int i = 0; i < S.length(); i++)
        {
            switch(S[i])
            {
                case 'a' :
                    widthValue = widths[0];
                    break;
                case 'b' :
                    widthValue = widths[1];
                    break;
                case 'c' :
                    widthValue = widths[2];
                    break;
                case 'd' :
                    widthValue = widths[3];
                    break;
                case 'e' :
                    widthValue = widths[4];
                    break;
                case 'f' :
                    widthValue = widths[5];
                    break;
                case 'g' :
                    widthValue = widths[6];
                    break;
                case 'h' :
                    widthValue = widths[7];
                    break;
                case 'i' :
                    widthValue = widths[8];
                    break;
                case 'j' :
                    widthValue = widths[9];
                    break;
                case 'k' :
                    widthValue = widths[10];
                    break;
                case 'l' :
                    widthValue = widths[11];
                    break;
                case 'm' :
                    widthValue = widths[12];
                    break;
                case 'n' :
                    widthValue = widths[13];
                    break;
                case 'o' :
                    widthValue = widths[14];
                    break;
                case 'p' :
                    widthValue = widths[15];
                    break;
                case 'q' :
                    widthValue = widths[16];
                    break;
                case 'r' :
                    widthValue = widths[17];
                    break;
                case 's' :
                    widthValue = widths[18];
                    break;
                case 't' :
                    widthValue = widths[19];
                    break;
                case 'u' :
                    widthValue = widths[20];
                    break;
                case 'v' :
                    widthValue = widths[21];
                    break;
                case 'w' :
                    widthValue = widths[22];
                    break;
                case 'x' :
                    widthValue = widths[23];
                    break;                    
                case 'y' :
                    widthValue = widths[24];
                    break;
                case 'z' :
                    widthValue = widths[25];
                    break;                                        
            }
            result = result + widthValue;
            if(result == 100)
            {
                rowcount++;
                result = 0;
            }
            if(result > 100)
            {
                rowcount++;
                result = 0;
                result = result + widthValue;
            }
        }
        output.push_back(rowcount);
        output.push_back(result);
        return output;
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

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++)
    {
        char currentChar = input[i];
        if (input[i] == '\\')
        {
            char nextChar = input[i+1];
            switch (nextChar)
            {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        }
        else
        {
          result.push_back(currentChar);
        }
    }
    return result;
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
        vector<int> widths = stringToIntegerVector(line);
        getline(cin, line);
        string S = stringToString(line);
        
        vector<int> ret = Solution().numberOfLines(widths, S);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
