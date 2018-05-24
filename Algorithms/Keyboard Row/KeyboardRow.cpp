class Solution
{
public:
    vector<string> findWords(vector<string>& words)
    {
        int output = words.size();
        vector<string> result;
        for(int i = 0; i < words.size(); i++)
        {
            int j = 0, count1 = 0, count2 = 0, count3 = 0;
            while(words[i][j] != '\0')
            {
                switch(words[i][j])
                {
                    case 'q':
                    case 'w':
                    case 'e':
                    case 'r':
                    case 't':
                    case 'y':
                    case 'u':
                    case 'i':
                    case 'o':
                    case 'p':
                        count1 = 1;
                        break;
                    case 'a':
                    case 's':
                    case 'd':
                    case 'f':
                    case 'g':
                    case 'h':
                    case 'j':
                    case 'k':
                    case 'l':
                        count2 = 1;
                        break;
                    case 'z':
                    case 'x':
                    case 'c':
                    case 'v':
                    case 'b':
                    case 'n':
                    case 'm':
                        count3 = 1;
                        break;
                }
                j++;
            }
            if((count1 + count2 + count3) == 1)
                result.push_back(words[i]);
        }
        return result;
    }
};

