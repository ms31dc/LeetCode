class Solution
{
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        vector<string> transformedArray;
        string result;
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                switch(words[i][j])
                {
                    case 'a' :
                        result = result + ".-";
                        break;
                    case 'b' :
                        result = result + "-...";
                        break;
                    case 'c' :                        
                        result = result + "-.-.";
                        break;
                    case 'd' :                        
                        result = result + "-..";
                        break;
                    case 'e' :
                        result = result + ".";
                        break;
                    case 'f' :
                        result = result + "..-.";
                        break;
                    case 'g' :
                        result = result + "--.";
                        break;
                    case 'h' :
                        result = result + "....";
                        break;
                    case 'i' :
                        result = result + "..";
                        break;
                    case 'j' :
                        result = result + ".---";
                        break;
                    case 'k' :
                        result = result + "-.-";
                        break;
                    case 'l' :
                        result = result + ".-..";
                        break;
                    case 'm' :
                        result = result + "--";
                        break;
                    case 'n' :
                        result = result + "-.";
                        break;
                    case 'o' :
                        result = result + "---";
                        break;
                    case 'p' :
                        result = result + ".--.";
                        break;
                    case 'q' :
                        result = result + "--.-";
                        break;
                    case 'r' :
                        result = result + ".-.";
                        break;
                    case 's' :
                        result = result + "...";
                        break;
                    case 't' :
                        result = result + "-";
                        break;
                    case 'u' :
                        result = result + "..-";
                        break;
                    case 'v' :
                        result = result + "...-";
                        break;
                    case 'w' :
                        result = result + ".--";
                        break;
                    case 'x' :
                        result = result + "-..-";
                        break;                    
                    case 'y' :
                        result = result + "-.--";
                        break;
                    case 'z' :
                        result = result + "--..";
                        break;                        
                }
            }
            transformedArray.push_back(result);
            result = "";
        }
        set<string> unique(transformedArray.begin(), transformedArray.end());
        return (unique.size());
    }
};
