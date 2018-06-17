class Solution
{
public:
    int firstUniqChar(string s)
    {   
        vector<char> uniqueChars;
        int result=s.length();
        int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, i=0, j=0, k=0, l=0, m=0, 
            n=0, o=0, p=0, q=0, r=0, ss=0, t=0, u=0, v=0, w=0, x=0, y=0, z=0;
        for(int ii=0; ii<s.length(); ii++)
        {
            switch(s[ii])
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
                    ss++;
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
        
        if(a == 1)
            uniqueChars.push_back('a');
        if(b == 1)
            uniqueChars.push_back('b');
        if(c == 1)
            uniqueChars.push_back('c');
        if(d == 1)
            uniqueChars.push_back('d');
        if(e == 1)
            uniqueChars.push_back('e');
        if(f == 1)
            uniqueChars.push_back('f');
        if(g == 1)
            uniqueChars.push_back('g');
        if(h == 1)
            uniqueChars.push_back('h');
        if(i == 1)
            uniqueChars.push_back('i');
        if(j == 1)
            uniqueChars.push_back('j');
        if(k == 1)
            uniqueChars.push_back('k');
        if(l == 1)
            uniqueChars.push_back('l');
        if(m == 1)
            uniqueChars.push_back('m');
        if(n == 1)
            uniqueChars.push_back('n');
        if(o == 1)
            uniqueChars.push_back('o');
        if(p == 1)
            uniqueChars.push_back('p');
        if(q == 1)
            uniqueChars.push_back('q');
        if(r == 1)
            uniqueChars.push_back('r');
        if(ss == 1)
            uniqueChars.push_back('s');
        if(t == 1)
            uniqueChars.push_back('t');
        if(u == 1)
            uniqueChars.push_back('u');
        if(v == 1)
            uniqueChars.push_back('v');
        if(w == 1)
            uniqueChars.push_back('w');
        if(x == 1)
            uniqueChars.push_back('x');
        if(y == 1)
            uniqueChars.push_back('y');
        if(z == 1)
            uniqueChars.push_back('z');
        
        for(int ii=0; ii<uniqueChars.size(); ii++)
        {
            if(s.find_first_of(uniqueChars[ii]) < result)
                result = s.find_first_of(uniqueChars[ii]);
        }
        
        if(s.length() == 0 || uniqueChars.size() == 0)
            return -1;
        
        return result;
            
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

int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        string s = stringToString(line);
        
        int ret = Solution().firstUniqChar(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
