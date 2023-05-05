#include <iostream>
#include <string>
using namespace std;

int main()
{
    char array[200];
    cin.getline (array, 200);
    for (int i = 1; array[i]!=0; i++)
    {
        if (array[i] == 41) break;
        while(array[i+1]!=44 && array[i+1]!=41)
        {
            array[i+1] = array[i+1] + (array[i]-48)*10;
            i++;
        }
        for(int j = 0; j<array[i]-48; j++)
        {
            cout<<"*";
        }
        cout << '\n';
        if(array[i+1]==44) 
        {
            i = i+2;
        }
        }

    return 0;
}