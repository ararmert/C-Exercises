#include <stdio.h>


int findMin(int* array, int size) {
    int min = array[0];
    int i;
    for(i = 1; i < size; ++i) {
    
    if(array[i]<min) {
    
        min = array[i];
        
        } 
    }
    return min;

}

int main(int argc, char* argv[]) {
    int result;
    int arr[] = {5,3,2,3,5,5,33,4,4,4,43,3,3,3,2,3,3,3,2,2,3,5,5,5,7,7,8,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    result = findMin(arr,size);
    
    printf("Minimum of the array is: %d\n", result);




    return 0;
}
