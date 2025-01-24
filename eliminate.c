// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
   // Initialize all elements to 0 (0 means "not eliminated")
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }

    // 'pos' is our current position in the circle
    int pos = 0;

    
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        while (1)  
        {
            // If this position is not eliminated, count it
            if (arr[pos] == 0)
            {
                count++;
                // If we have counted up to k, eliminate this position
                if (count == k)
                {
                    arr[pos] = 1;     // Mark eliminated
                    printf("%d\n", pos);
                    // Move one step beyond this position before breaking,
                    // so the next elimination starts counting from the next spot.
                    pos = (pos + 1) % n;
                    break;
                }
            }
            // Move to the next position in the circle
            pos = (pos + 1) % n;
        }
    }
  free (arr);
}

