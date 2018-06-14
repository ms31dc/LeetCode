class Solution
{
public:
    int countPrimes(int n)
    {
        int result=0;
        bool primeNumbers[n+1];
        memset(primeNumbers, true, sizeof(primeNumbers));

        for (int i=2; i*i<=n; i++)
        {
            if (primeNumbers[i] == true)
            {
                for (int j=i*2; j<=n; j=j+i)
                    primeNumbers[j] = false;
            }
        }
        
        for (int i=2; i<n; i++)
           if (primeNumbers[i])
               result++;
        
        return result;
    }
};
