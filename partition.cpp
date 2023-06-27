#include<iostream>
#include <bits/stdc++.h>
#define MAX 25
using namespace std;
void findset(int num, int rank, int sets[MAX][MAX])
{
    if (rank==1)
    {
        for(int i = 0; i<num; i++)
        {
            sets[i][0]=i+1;
            for(int j = 1; j<MAX; j++)
            {
                sets[i][j]=0;
            }
        }
        for(int i = num; i<MAX;i++)
        {
            for(int j = 0; j<MAX; j++)
            {
                sets[i][j]=0;
            }
        }
        return;
    }
    findset(num, rank-1, sets);
    int x = 0;
    for(x = 0; x<MAX; x++)
    {
        if (sets[x][0]==0) break;
    }
    x=x-1;
    if(sets[x][1]==0 && sets[x-1][1]==0)
    {
        
        sets[x-1][1]=sets[x][0];
        sets[x][0]=0;
        return;
    }
    if(sets[x][1]==0)
    {
        int flag=0;
        for(int i = x; i>=0; i--)
        {
            int j = 0;
            for(j = 0; j<MAX && sets[i][j]!=0; j++)
            {};
            int k = j-1;
            for(int l = k; l>=1; l--)
            {
                if(sets[i][l]<sets[x][0])
                {
                    flag=1;
                    int temp = sets[i][l];
                    sets[i][l]=sets[x][0];
                    int arr[MAX];
                    for(int m=0; m<MAX; m++)
                    {
                        arr[m]=0;
                    }
                    int count=1;
                    arr[0]=temp;
                    for(int a=i+1; a<x;a++)
                    {
                        for(int b=0; b<MAX&&sets[a][b]!=0; b++)
                        {
                            arr[count]=sets[a][b];
                            count++;
                        }
                        
                    }
                    sort(arr, arr+count);
                    for(int c=0;c<count;c++)
                    {
                        sets[i+1][0]=arr[c];
                        sets[i+1][1]=0;
                        i++;
                        
                    }
                    
                }
                
                
            }
        }
        if(flag==0)
        {
                    int temp = sets[x-1][1];
                    sets[x-1][1]=sets[x][0];
                    for(int d = 2; d<MAX && sets[x-1][d-1]!=0; d++)
                    {
                        int temp2=sets[x-1][d];
                        sets[x-1][d]=temp;
                        temp = temp2;
                    };
                    
                    sets[x][0]=0;
                    
                }
                return;
    }
    int flag2=0;
    int e=0;
    for(e=0; e<MAX && sets[x][e]!=0; e++)
    {};
    e=e-1;
    int g=0;
    for(g = 0; g<MAX&&sets[x-1][g]!=0;g++)
    {};
    g=g-1;
    if(g<=e)
    {
        if(sets[x][g]<sets[x-1][g])
        flag2=1;
    }
    if(flag2==1)
    {
        int arr[MAX];
        for(int i = 0; i<MAX; i++)
        {
            arr[i]=0;
        }
        for(int i = 1; i<=g; i++)
        {
            arr[i-1]=sets[x-1][i];
        }
        for(int i = 1; i<=g+1; i++)
        {
            sets[x-1][i]=sets[x][i-1];
        }
        for(int i = g; i<=e;i++)
        {
            arr[i]=sets[x][i];
        }
        sort(arr, arr+e);
        for(int i = 0; i<=e;i++)
        {
            sets[x][i]=0;
        }
        for(int i = 0; i<e;i++)
        {
            sets[x+i][0]=arr[i];
        }
        return;
    }
    int flag=0;
    for(int f=0; f<MAX && sets[x][f]!=0; f++)
    {
        
        for(int i = x-1; i>=0; i--)
        {
            int j = 0;
            for(j = 0; j<MAX && sets[i][j]!=0; j++)
            {};
            int k = j-1;
            for(int l = k; l>=1; l--)
            {
                if(sets[i][l]<sets[x][f])
                {
                    flag=1;
                    int temp = sets[i][l];
                    sets[i][l]=sets[x][f];
                    int arr[MAX];
                    for(int m=0; m<MAX; m++)
                    {
                        arr[m]=0;
                    }
                    int count=1;
                    arr[0]=temp;
                    for(int a=i+1; a<x;a++)
                    {
                        for(int b=0; b<MAX&&sets[a][b]!=0; b++)
                        {
                            arr[count]=sets[a][b];
                            count++;
                        }
                        
                    }
                    for(int b=0; b<MAX&&sets[x][b]!=0;b++)
                    {
                        if(sets[x][b]==sets[x][f]) continue;
                        arr[count]=sets[x][b];
                        count++;
                    }
                    sort(arr, arr+count);
                    
                    for(int c=0;c<count;c++)
                    {
                        sets[i+1][0]=arr[c];
                        for(int z=1;z<MAX;z++)
                        {
                        sets[i+1][z]=0;
                        }
                        i++;
                        
                    }
                    
                }
                
                
            }
        }
        
            
    
    }
    if(flag==0)
        {
            int j = 0;
            for(j = 0; j<MAX && sets[x-1][j]<sets[x][0]&&sets[x-1][j]!=0; j++)
            {};
            int temp=sets[x-1][j];
            sets[x-1][j]=sets[x][0];
            int z=j+1;
            for(z=j+1;z<MAX&&sets[x-1][z]!=0;z++)
            {
                int temp2=sets[x-1][z];
                sets[x-1][z]=temp;
                temp=temp2;
                
            }
            sets[x-1][z]=temp;
            
            for(int y = 0; y<MAX&&sets[x][y]!=0; y++)
            {
                sets[x+y][0]=sets[x][y+1];
            }
            for(int h=1; h<MAX&&sets[x][h]; h++)
            {
                sets[x][h]=0;
            }
            
        }
        
    return;
}
void printset(int sets[MAX][MAX])
{
    for(int i = 0; i<MAX; i++)
    {
        for(int j = 0; j<MAX; j++)
        {
            if (sets[i][j]!=0) {
                cout << sets[i][j] << " ";
            }
        }
        if(sets[i][0]!=0) cout << '\n';
    }

}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i<n; i++) {
        int number;
        cin>>number;
        int rank;
        cin >> rank;
        int sets[MAX][MAX];
        findset(number, rank, sets);
        printset(sets);
        cout<<'\n';
    }
}
