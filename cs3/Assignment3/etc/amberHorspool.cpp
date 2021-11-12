const int size = 256;
int Table[size];

void ShiftTable(char Pattern[25])
{
    int m = strlen(Pattern);

    for (int i = 0; i < size - 1; i++) //Assign the length of the pattern to all locations on the shift table
        Table[i] = m;

    for (int i = 0; i <= m - 2; i++) //Update shift table for values that appear in pattern
        Table[Pattern[i]] = m - i - 1;
}

int * HorspoolMatching(char Pattern[25], char Text[100])
{
    int * Pos = new int[1000]; //Table to hold positions of alloccurances of pattern within text

    ShiftTable(Pattern);

    int n = strlen(Text); //Length of Text
    int m = strlen(Pattern); //Length of Pattern

    int k, j = m - 1;  //Position of the patterns right end

    while( j <= n - 1)
    {
        k = 0;  //Number of matched characters
        while ((k <= m-1) && (Pattern[m-1-k] == Text[j-k])) 
        {
            k++;
            HorComp++;
        }
        if (k == m)
        {
            Pos[HorCount] = (j - m + 1); //Pattern is found at position j-m+1
            HorCount ++; //Increment counter for how many times pattern is found
            j = j + Table[Text[j]]; //Shift to start looking for next occurance 
        }
        else 
            j = j + Table[Text[j]];  //Shift j based on shift table
    } 
    return Pos;
}
