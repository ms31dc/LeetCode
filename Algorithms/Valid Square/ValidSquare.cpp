class Solution
{
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
    {
        vector<vector<double>> distances;
        
        // Case 1: Distances of all the point from point p1
        vector<double> temp1;
        temp1.push_back(sqrt((p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1])));
        temp1.push_back(sqrt((p1[0]-p3[0])*(p1[0]-p3[0]) + (p1[1]-p3[1])*(p1[1]-p3[1])));
        temp1.push_back(sqrt((p1[0]-p4[0])*(p1[0]-p4[0]) + (p1[1]-p4[1])*(p1[1]-p4[1])));
        sort(temp1.begin(), temp1.end());
        if(temp1[0] == 0 && temp1[1] == 0 && temp1[2] == 0)
        {
            return false;
        }
        distances.push_back(temp1);
        
        // Case 2: Distances of all the point from point p2
        vector<double> temp2;
        temp2.push_back(sqrt((p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1])));
        temp2.push_back(sqrt((p2[0]-p3[0])*(p2[0]-p3[0]) + (p2[1]-p3[1])*(p2[1]-p3[1])));
        temp2.push_back(sqrt((p2[0]-p4[0])*(p2[0]-p4[0]) + (p2[1]-p4[1])*(p2[1]-p4[1])));
        sort(temp2.begin(), temp2.end());
        if(temp2[0] == 0 && temp2[1] == 0 && temp2[2] == 0)
        {
            return false;
        }        
        distances.push_back(temp2);
        
        // Case 3: Distances of all the point from point p3
        vector<double> temp3;
        temp3.push_back(sqrt((p1[0]-p3[0])*(p1[0]-p3[0]) + (p1[1]-p3[1])*(p1[1]-p3[1])));
        temp3.push_back(sqrt((p2[0]-p3[0])*(p2[0]-p3[0]) + (p2[1]-p3[1])*(p2[1]-p3[1])));
        temp3.push_back(sqrt((p3[0]-p4[0])*(p3[0]-p4[0]) + (p3[1]-p4[1])*(p3[1]-p4[1])));
        sort(temp3.begin(), temp3.end());
        if(temp3[0] == 0 && temp3[1] == 0 && temp3[2] == 0)
        {
            return false;
        }        
        distances.push_back(temp3);
        
        // Case 4: Distances of all the point from point p4
        vector<double> temp4;
        temp4.push_back(sqrt((p1[0]-p4[0])*(p1[0]-p4[0]) + (p1[1]-p4[1])*(p1[1]-p4[1])));
        temp4.push_back(sqrt((p2[0]-p4[0])*(p2[0]-p4[0]) + (p2[1]-p4[1])*(p2[1]-p4[1])));
        temp4.push_back(sqrt((p3[0]-p4[0])*(p3[0]-p4[0]) + (p3[1]-p4[1])*(p3[1]-p4[1])));
        sort(temp4.begin(), temp4.end());
        if(temp4[0] == 0 && temp4[1] == 0 && temp4[2] == 0)
        {
            return false;
        }        
        distances.push_back(temp4);
        
        if((distances[0][0] == distances[0][1]) && (distances[1][0] == distances[1][1]) &&
           (distances[2][0] == distances[2][1]) && (distances[3][0] == distances[3][1]))
        {
            if(((round(distances[0][0]*distances[0][0]) + round(distances[0][1]*distances[0][1])) == round((distances[0][2]*distances[0][2]))) &&
               ((round(distances[1][0]*distances[1][0]) + round(distances[1][1]*distances[1][1])) == round((distances[1][2]*distances[1][2]))) &&
               ((round(distances[2][0]*distances[2][0]) + round(distances[2][1]*distances[2][1])) == round((distances[2][2]*distances[2][2]))) &&
               ((round(distances[3][0]*distances[3][0]) + round(distances[3][1]*distances[3][1])) == round((distances[3][2]*distances[3][2]))))
            {
                return true;
            }
        }
        
        return false;
    }
};

void trimLeftTrailingSpaces(string &input) 
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) 
    {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) 
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) 
    {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) 
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) 
    {
        output.push_back(stoi(item));
    }
    return output;
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
        vector<int> p1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> p2 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> p3 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> p4 = stringToIntegerVector(line);
        
        bool ret = Solution().validSquare(p1, p2, p3, p4);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
