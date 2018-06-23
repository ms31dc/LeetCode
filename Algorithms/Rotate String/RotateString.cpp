class Solution 
{
public:
    bool rotateString(string A, string B) 
    {
        string rotatedString;
        int stringLength = 0;
        if(A == B)
            return true;
        else
        {
            while(A[stringLength] != '\0')
            {
                stringLength++;
            }
            int numberOfLoops = stringLength;
            string rotatedString = A;
            while(numberOfLoops > 0)
            {
                rotatedString[0] = A[stringLength-1];
                for(int i = 0; i < stringLength - 1; i++)
                {
                    rotatedString[i+1] = A[i];
                }
                if(rotatedString == B)
                {
                    return true;
                    break;
                }
                A = rotatedString;
                numberOfLoops--;
            }
        }
        return false;
    }
};
