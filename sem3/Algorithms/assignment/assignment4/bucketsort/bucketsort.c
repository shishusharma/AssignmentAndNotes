#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
long int getMax(long int a[], long int n) // function to get maximum element from the given array  
{  
  long int max = a[0];  
  for (long int i = 1; i < n; i++)  
    if (a[i] > max)  
      max = a[i];  
  return max;  
}  
void bucket(long int a[], long int n) // function to implement bucket sort  
{  
  long int max = getMax(a, n); //max is the maximum element of array  
  long int bucket[max], i;  
  for (long int i = 0; i <= max; i++)  
  {  
    bucket[i] = 0;  
  }  
  for (long int i = 0; i < n; i++)  
  {  
    bucket[a[i]]++;  
  }  
  for (long int i = 0, j = 0; i <= max; i++)  
  {  
    while (bucket[i] > 0)  
    {  
      a[j++] = i;  
      bucket[i]--;  
    }  
  }  
}  

int main()
{
    FILE *fp;

    long int n = 100000;
    // variable to store time duration
    // of sorting algorithms
    double t[10];
    fp = fopen("bucketsort100000.txt", "w+");
    fprintf(fp, "ArraySize  ExecutionTime\n");
    fclose(fp);

    printf("ArraySize  ExecutionTime\n");
    int it = 0;
    // generation n random numbers
    // storing them in arrays a;

    while (it++ < 5)
    {

        fp = fopen("bucketsort100000.txt", "a+");
        long int a[n];

        for (long int i = 0; i < n; i++)
        {
            long int no = rand() % n + i;
            a[i] = no;
        }

        // using clock_t to store time
        clock_t start, end;
        // quicksort
        start = clock();

        bucket(a, n);

        end = clock();

        t[it] = ((double)(end - start));

        // type conversion to long int for plotting
        // graph with integer values
        fprintf(fp, "%li\t\t%li\n", n, (long int)t[it]);
        printf("%li\t\t%li\n", n, (long int)t[it]);
        n += 20000;

        fclose(fp);
    }
    return 0;
}

