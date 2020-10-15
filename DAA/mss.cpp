#include <iostream>

using namespace std;
int max(int a, int b)
{
  if (a>b)
  {
    return a;
  }
  else
  {
    return b;
  }
}

int maxSubArraySum(int arr[], int low, int high)
{

  if (low == high)
  {
    return arr[low];
  }
  int mid = (low+high)/2;

  int leftsubarray = maxSubArraySum(arr, low, mid);

  int rightsubarray = maxSubArraySum(arr, mid+1, high);
  int left_sum  = INT_MIN, right_sum = INT_MIN;
  int sum =0;

  for (int i = mid; i <high ; ++i)
  {
    sum = sum + arr[i];
    right_sum = max(right_sum, sum);
  }
  sum =0;

  for (int i = low; i < mid; ++i)
  {
    sum = sum + arr[i];
    left_sum = max(left_sum, sum);
  }
  int ans = max(leftsubarray,rightsubarray);
  return max(ans,left_sum+right_sum);
}
int main()
{
  int arr[10],a;
    for (a=0;a<10;a++)
    {
      cout<<"Enter the array values:"<<a<<endl;
      cin>>arr[a];
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    int low = 0, high = n-1;
    cout<<"maximum subarray sum is"<<maxSubArraySum(arr,low,high);
    return 0;
}
