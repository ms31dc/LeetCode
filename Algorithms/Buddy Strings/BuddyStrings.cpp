class Solution 
{
public:
    bool buddyStrings(string A, string B) 
    {
        if(A.length() != B.length())
        {
            return false;
        }
        else
        {
            if(A.length() == 0)
                return false;
        }
            
        vector<int> characterIndex;
        for(int i=0; i<A.length(); i++)
        {
            if(A[i] != B[i])
            {
                characterIndex.push_back(i);
            }
        }
        
        if(A == B)
        {
            int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, i=0, j=0, k=0, l=0, m=0,
                n=0, o=0, p=0, q=0, r=0, s=0, t=0, u=0, v=0, w=0, x=0, y=0, z=0;
            for(int ii=0; ii<A.size(); ii++)
            {
                switch(A[ii])
                {
                    case 'a':
                        a++;
                        break;
                    case 'b':
                        b++;
                        break;
                    case 'c':
                        c++;
                        break;
                    case 'd':
                        d++;
                        break;
                    case 'e':
                        e++;
                        break;
                    case 'f':
                        f++;
                        break;
                    case 'g':
                        g++;
                        break;
                    case 'h':
                        h++;
                        break;
                    case 'i':
                        i++;
                        break;
                    case 'j':
                        j++;
                        break;
                    case 'k':
                        k++;
                        break;
                    case 'l':
                        l++;
                        break;
                    case 'm':
                        m++;
                        break;
                    case 'n':
                        n++;
                        break;
                    case 'o':
                        o++;
                        break;
                    case 'p':
                        p++;
                        break;
                    case 'q':
                        q++;
                        break;
                    case 'r':
                        r++;
                        break;
                    case 's':
                        s++;
                        break;
                    case 't':
                        t++;
                        break;
                    case 'u':
                        u++;
                        break;
                    case 'v':
                        v++;
                        break;
                    case 'w':
                        w++;
                        break;
                    case 'x':
                        x++;
                        break;
                    case 'y':
                        y++;
                        break;
                    case 'z':
                        z++;
                        break;                        
                }
            }
            if(a<=1 && b<=1 && c<=1 && d<=1 && e<=1 && f<=1 && g<=1 && h<=1 && i<=1 && j<=1 && k<=1 && l<=1 && m<=1 && n<=1 && o<=1 && p<=1 && q<=1 && r<=1 && s<=1 && t<=1 && u<=1 && v<=1 && w<=1 && x<=1 && y<=1 && z<=1)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        
        if(characterIndex.size() == 2)
        {
            int index1 = characterIndex[0];
            int index2 = characterIndex[1];
            if((A[index1] == B[index2]) && (A[index2] == B[index1]))
            {
                return true;
            }
        }
        return false;
    }
};

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

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        string A = stringToString(line);
        getline(cin, line);
        string B = stringToString(line);
        
        bool ret = Solution().buddyStrings(A, B);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
