#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        while((str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='y')&&
           (str[i+1]=='a'||str[i+1]=='e'||str[i+1]=='i'||str[i+1]=='o'||str[i+1]=='u'||str[i+1]=='y'))
           str.erase(i+1,1);
    }
    cout<<str<<endl;
}
