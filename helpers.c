/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
/*    for(int i = 0;n > i;i++ ){
        if(value == values[i]){
            return true;
        }
    }*/
    if (n == 0) {
        return false;
    } else if (values[0] > value) {
        return false;
    } else if (values[n - 1] < value) {
        return false;
    }
    int first = 0;
    int last = n;
    while(first < last){
        int mid = first + (last - first) / 2;
        if(value<=values[mid]){
				last = mid;
			}
			else if(value>values[mid]){
				first = mid + 1;
			}
    }
    if (values[last] == value) {
        return true;
    } else {
        return false;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for(int i = 0; n-1 > i ;i++){
        int lastIndex = i;
        for(int j = i+1; n > j; j++){
            if(values[j]<values[lastIndex]){
                lastIndex = j;
            }
        }
        int buffer = values[i];
        values[i] = values[lastIndex];
        values[lastIndex] = buffer;
    }
    return;
}
