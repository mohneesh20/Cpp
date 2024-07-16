#include<iostream>
#include<vector>
using namespace std;
int smallestSubWithSum(int arr[], int n, int x)
{
     int min_len = n + 1;
     for (int start=0; start<n; start++)
     {
          int curr_sum = arr[start];
          if (curr_sum > x) return 1;
          for (int end=start+1; end<n; end++)
          {
              curr_sum += arr[end];
              if (curr_sum > x && (end - start + 1) < min_len)
                 min_len = (end - start + 1);
          }
     }
     return min_len;
}
int main(){
    int arr1[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    cout<<smallestSubWithSum(arr1,6,x);
}