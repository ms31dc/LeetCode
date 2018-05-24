class Solution
{
public:
    int calPoints(vector<string>& ops)
    {
        vector<int> result;
        int output = 0, count = 0, temp = 0;
        for(int i = 0; i< ops.size(); i++)
        {
            if(ops[i] == "+")
            {
                temp = 0;
                temp = result[count-1] + result[count-2];
                output = output + temp;
                result.push_back(temp);
                count++;
            }
            else if(ops[i] == "C")
            {
                output = output - result[count-1];
                result.pop_back();
                count--;
            }
            else if(ops[i] == "D")
            {
                temp = 0;
                temp = 2 * result[count-1];
                output = output + temp;
                result.push_back(temp);
                count++;                
            }
            else
            {
                output = output + stoi(ops[i]);
                result.push_back(stoi(ops[i]));
                count++;                
            }
        }
        return output;
    }
};
