#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int column = 52;
    int row = 2;

    vector<vector<int>> vec(column, vector<int>(row,0));
    vec[12][0]=15;
    vec[12][1]=2;

    for(int i = 0; i < column; i++)
    {
        for(int j = 0; j < row; j++)
        {
            cout << vec[i][j]<<"  ";
        }
        cout << endl;
    }
    
    
    //cout << vec[52][2];

    

     
    return 0;
}