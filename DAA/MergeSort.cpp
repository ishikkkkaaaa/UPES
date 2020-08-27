#include <iostream>
using namespace std;
int merge(int arr[], int start, int middle, int end)

{
  int i,j,k;
  int n1=middle-start+1;
  int n2=end-middle;

  int L[30], R[30];

  for(i=0;i<n1;i++)
  {
      L[i]=arr[start+1];
  }
  for(j=0;j<n2;j++)
  {
    R[j]=arr[middle+1+j];
  }
  i=0;
  j=0;
  k=start;

  while(i<n1 && j<n2)
  {
    if(L[i]<=R[j])
    {
      arr[k]=L[i];
      i++;
    }
    else
    {
      arr[k]=R[j];
      j++;
    }
    k++;
  }
  while(i<n1)
  {
    arr[k]=L[i];
    i++;
    j++;
  }
  while(j<n2)
  {
    arr[k]=R[j];
    j++;
    k++;
  }

}

int mergesort(int arr[],int start,int end)
{
  if(start<end)
  {
    int middle= start+(end-start)/2;
    mergesort(arr,start,middle);
    mergesort(arr,middle+1,end);
    merge(arr,start,middle,end);
  }
}

int main()
{
  int array[50],n,i;
  cout<<"Enter the number of elements in the array:";
  cin>>n;
  cout<<"Enter %d integers",n;
  for(int i=0;i<n;i++)
  {
    cin>>array[i];
  }
  mergesort(array,0,n-1);
  cout<<"\n Printing the sorted array:";
  for (i = 0; i < n; i++)
  {
    cout<<array[i];
  }
return 0;
}
