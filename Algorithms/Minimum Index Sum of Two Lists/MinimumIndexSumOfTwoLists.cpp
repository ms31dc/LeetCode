class Solution
{
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
    {
        int sum = list1.size() + list2.size();
        vector<string> result;
        for(int i=0; i<list1.size(); i++)
        {
            for(int j=0; j<list2.size(); j++)
            {
                if(list1[i].compare(list2[j]) == 0)
                {
                    if(sum > (i+j))
                    {
                        result.clear();
                        result.push_back(list1[i]);
                        sum = i+j;
                    }
                    else if(sum == (i+j))
                    {
                        result.push_back(list1[i]);
                        sum = i+j;
                    }
                }
            }
        }
        return result;
    }
};
