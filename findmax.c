
int findMax(int* arr, int size) {
    int max = arr[0];
    int i;
    
    for (i=1; i<size; ++i) {
    if (arr[i]>max) {
    
        max = arr[i];
    
    }
    
    }

    return max;
}





int main(int argc, char* argv[]) {
    int result;
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    result = findMax(arr, size);

    printf("Result is: %d\n", result);

    return 0;


}
