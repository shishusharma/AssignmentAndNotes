#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



// A utility function to get maximum value in arr[]
long int getMax(long int arr[], long int n)
{
    long int mx = arr[0];
    for (long int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(long int arr[], long int n, long int exp)
{
    long int output[n]; // output array
    long int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(long int arr[], long int n)
{
    // Find the maximum number to know number of digits
    long int m = getMax(arr, n);
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (long int exp = 1; m / exp > 0; exp *= 10)
             countSort(arr, n, exp);
}

int main()
{
    FILE *fp;

    long int n = 100000;
    // variable to store time duration
    // of sorting algorithms
    double t[10];
    fp = fopen("radixsort100000.txt", "w+");
    fprintf(fp, "ArraySize  ExecutionTime\n");
    fclose(fp);

    printf("ArraySize  ExecutionTime\n");
    int it = 0;
    // generation n random numbers
    // storing them in arrays a;

    while (it++ < 5)
    {
    
        fp = fopen("radixsort100000.txt", "a+");
        long int a[n];
    
        for (long int i = 0; i < n; i++)
        {
            long int no = rand() % n+i;
            a[i] = no;
           
        }
        
      
        // using clock_t to store time
        clock_t start, end;
        // quicksort
        start = clock();
       
       radixsort(a, n);

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
