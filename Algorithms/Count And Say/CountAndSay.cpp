class Solution
{
public:
    string countAndSay(int n)
    {
        string result="1", temp="";
        int oneCount=0, twoCount=0, threeCount=0;
        bool flagOne=false, flagTwo=false, flagThree=false;
        
        if(n == 1)
        {
            return result;
        }
        
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<result.length(); j++)
            {
                switch(result[j])
                {
                    case '1':
                        oneCount++;
                        break;
                    case '2':
                        twoCount++;
                        break;
                    case '3':
                        threeCount++;
                        break;
                }
                if(oneCount > 0 && twoCount > 0)
                {
                    if(result[j] == '1')
                    {
                        if(twoCount == 1)
                        {
                            temp = temp + "12";
                        }
                        else if(twoCount == 2)
                        {
                            temp = temp + "22";
                        }
                        else if(twoCount == 3)
                        {
                            temp = temp + "32";
                        }                        
                    }
                    else
                    {
                        if(oneCount == 1)
                        {
                            temp = temp + "11";
                        }
                        else if(oneCount == 2)
                        {
                            temp = temp + "21";
                        }
                        else if(oneCount == 3)
                        {
                            temp = temp + "31";
                        }                        
                    }
                    j--;
                    oneCount=0;
                    twoCount=0;
                    threeCount=0;
                }
                else if(oneCount > 0 && threeCount > 0)
                {
                    if(result[j] == '1')
                    {
                        if(threeCount == 1)
                        {
                            temp = temp + "13";
                        }
                        else if(threeCount == 2)
                        {
                            temp = temp + "23";
                        }
                        else if(threeCount == 3)
                        {
                            temp = temp + "33";
                        }                        
                    }
                    else
                    {
                        if(oneCount == 1)
                        {
                            temp = temp + "11";
                        }
                        else if(oneCount == 2)
                        {
                            temp = temp + "21";
                        }
                        else if(oneCount == 3)
                        {
                            temp = temp + "31";
                        }                        
                    }
                    j--;
                    oneCount=0;
                    twoCount=0;
                    threeCount=0;                    
                }
                else if(twoCount > 0 && threeCount > 0)
                {
                    if(result[j] == '2')
                    {
                        if(threeCount == 1)
                        {
                            temp = temp + "13";
                        }
                        else if(threeCount == 2)
                        {
                            temp = temp + "23";
                        }
                        else if(threeCount == 3)
                        {
                            temp = temp + "33";
                        }                        
                    }
                    else
                    {
                        if(twoCount == 1)
                        {
                            temp = temp + "12";
                        }
                        else if(twoCount == 2)
                        {
                            temp = temp + "22";
                        }
                        else if(twoCount == 3)
                        {
                            temp = temp + "32";
                        }                        
                    }
                    j--;
                    oneCount=0;
                    twoCount=0;
                    threeCount=0;                    
                }
            }
            if((oneCount > 0) && (twoCount == 0) && (threeCount == 0))
            {
                if(oneCount == 1)
                {
                    temp = temp + "11";
                }
                else if(oneCount == 2)
                {
                    temp = temp + "21";
                }
                else if(oneCount == 3)
                {
                    temp = temp + "31";
                }                
            }
            else if((oneCount == 0) && (twoCount > 0) && (threeCount == 0))
            {
                if(twoCount == 1)
                {
                    temp = temp + "12";
                }
                else if(twoCount == 2)
                {
                    temp = temp + "22";
                }
                else if(twoCount == 3)
                {
                    temp = temp + "32";
                }        
            }
            else if((oneCount == 0) && (twoCount == 0) && (threeCount > 0))
            {
                if(threeCount == 1)
                {
                    temp = temp + "13";
                }
                else if(threeCount == 2)
                {
                    temp = temp + "23";
                }
                else if(threeCount == 3)
                {
                    temp = temp + "33";
                }                                        
            }
            result = temp;
            temp = "";
            oneCount=0;
            twoCount=0;
            threeCount=0;            
        }
        return result;
    }
};

int stringToInteger(string input) 
{
    return stoi(input);
}

int main() 
{
    string line;
    while (getline(cin, line)) 
    {
        int n = stringToInteger(line);
        
        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
