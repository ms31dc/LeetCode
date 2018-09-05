class Solution 
{
public:
    bool stoneGame(vector<int>& piles) 
    {
        int i = 0;
        int j = piles.size()-1;
        int alexSum = 0, leeSum=0;
        bool alexTurn = true;
        while(i <= j)
        {
            if(alexTurn)
            {                
                if(piles[i] >= piles[j])
                {
                    alexSum = alexSum + piles[i];
                    i++;
                }
                else
                {
                    alexSum = alexSum + piles[j];
                    j--;
                }
                alexTurn = false;
            }
            else
            {
                if(piles[i] <= piles[j])
                {
                    leeSum = leeSum + piles[i];
                    i++;
                }
                else
                {
                    leeSum = leeSum + piles[j];
                    j--;
                }
                alexTurn = true;
            }
        }       
        return(alexSum > leeSum);
    }
};
