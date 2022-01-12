#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define RANGE 10;

void countsorting(long int arr[], long int n, long int n1)
{
    // creating an integer array of size n for sorted array
    long int outputArray[n];
    // creating an integer array of size n1, initialized by zero
    long int freqArray[n1];
    memset(freqArray, 0, sizeof(freqArray));
    // Using the value of each item in an input array as index,
    for (long int i = 0; i < n; i++)
    {
        freqArray[arr[i]]++;
    }
    // Calculating starting index for each long integer
    long int totalCount = 0;
    for (long int i = 0; i < n1; i++)
    {
        long int oldEleCount = freqArray[i];
        freqArray[i] = totalCount;
        totalCount += oldEleCount;
    }
    // Copying to output array, and preserving order of inputs with equal keys
    for (long int i = 0; i < n; i++)
    {
        outputArray[freqArray[arr[i]]] = arr[i];
        freqArray[arr[i]]++;
    }
    // copying output array back to the input array
    for (long int i = 0; i < n; i++)
    {
        arr[i] = outputArray[i];
    }

    
}
int main()
{
    FILE *fp;

    long int n = 1000;
    // variable to store time duration
    // of sorting algorithms
    double t[10];
    fp = fopen("countingSort100000.txt", "w+");
    fprintf(fp, "ArraySize  ExecutionTime\n");
    fclose(fp);

    printf("ArraySize  ExecutionTime\n");
    int it = 0;
    // generation n random numbers
    // storing them in arrays a;

    while (it++ < 5)
    {
    
        fp = fopen("countingSort100000.txt", "a+");
        long int a[n];
        long int mx=0;
        for (long int i = 0; i < n; i++)
        {
            long int no = rand() % n+i;
            a[i] = no;
            if(mx<a[i])
                mx=a[i];
        }
        
        long int len=sizeof(a)/sizeof(a[0]);
        // using clock_t to store time
        clock_t start, end;
        // quicksort
        start = clock();

        countsorting(a,len,mx+1);

        end = clock();

        t[it] = ((double)(end - start));

        // type conversion to long int for plotting
        // graph with integer values
        fprintf(fp, "%li\t\t%li\n", n, (long int)t[it]);
        printf("%li\t\t%li\n", n, (long int)t[it]);
        n += 100000;
        
        fclose(fp);
    }
    return 0;
}