#include <stdio.h>
void ActivitySelection(int start[], int finish[], int n)
{
   printf("The following activities are selected:\n");
   int j = 0;
   printf("%d ", j);
   int i;
   for (i = 1; i < n; i++)
     {
         if (start[i] >= finish[j])
               {
                     printf("%d ", i);
                      j = i;
                }
       }
}
int main()
{
 int start[] = {1, 3, 2, 0, 5, 8, 11};
 int finish[] = {3, 4, 5, 7, 9, 10, 12};
 int n = sizeof(start) / sizeof(start[0]);
 ActivitySelection(start, finish, n);
 return 0;
}






// start contains n
//second contains ending ones
//given interval,watch max movies
//first sort in ascending, 0 gets picked up,  issliye ending sorted in ascending,
//i ending timing>=j for non laping
//linear time complexity "n"
