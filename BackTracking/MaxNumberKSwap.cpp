#include<iostream>
#include<string>
using namespace std;
void maxNumber(
    string str, int k,int n,string& max)
{
    if (k == 0)
        return;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] < str[j]) {
                swap(str[i], str[j]);
                if (str.compare(max) > 0)
                    max = str;
                maxNumber(str, k - 1,n,max);
                swap(str[i], str[j]);
            }
        }
    }
}
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    int n=s.size();
    string max=s;
    maxNumber(s,k,n,max);
    cout<<max;
}