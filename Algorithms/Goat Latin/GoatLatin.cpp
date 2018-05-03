class Solution {
public:
    string toGoatLatin(string S) 
    {
        istringstream inputString(S);
        string result = "", word, stringOfA = "a";
        int countWords = 0;
        while(inputString >> word)
        {
            if(countWords > 0)
                result = result + " ";
            if(word[0] == 'a' || word[0] == 'e' ||
               word[0] == 'i' || word[0] == 'o' ||
               word[0] == 'u' || word[0] == 'A' ||
               word[0] == 'E' || word[0] == 'I' ||
               word[0] == 'O' || word[0] == 'U')
            {
                result = result + word + "ma" + stringOfA;
            }
            else
            {
                for(int i=1; i<word.length(); i++)
                {
                    result = result + word[i];
                }
                result = result + word[0] + "ma" + stringOfA;
            }
            stringOfA = stringOfA + "a";
            countWords++;
        }
        return result;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
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
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string S = stringToString(line);
        
        string ret = Solution().toGoatLatin(S);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
