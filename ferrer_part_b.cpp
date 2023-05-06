#include <iostream>
#include <string>
using namespace std;

int rpartition(int n, int k)
{
    if (n<k) return 0;
    if (n==k || k==1) return 1;
    return rpartition(n-1,k) + rpartition(n-k,k);
}
int qpartition(int n, int k)
{
    int a = 0;
    for(int i = 1; i<=k; i++)
    {
        a = a+rpartition(n-k,i);
    }
    return a;
}
int main()
{
    int n,k;
    cin >> n >> k;
    int qs = 0;
    for (int i = 1; i<=k; i++)
    {
        qs = qs + qpartition(n,i);
    };
    int s = 0;
    for(int i = 1; i <=k; i++)
    {
        s = s+rpartition(n,i);
    };
    cout << qs << " " << s << '\n';
    
}