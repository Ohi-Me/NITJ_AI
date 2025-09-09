#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key) {
    if(left > right){
        return -1;
    } 
    else{
        int mid = left + (right - left) / 2;
        
        if(arr[mid] == key){
            return mid;
        } 
        else if(arr[mid] < key){
            return binarySearch(arr, mid + 1, right, key);
        } 
        else{
            return binarySearch(arr, left, mid - 1, key);
        }
    }
}

int main() {
    int n, key;
    
    
    scanf("%d", &n);
    printf("Enter the number of book IDs: %d\n",n);

    int arr[n];
    printf("Enter the book IDs: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        printf("%d ",arr[i]);
    }
    printf("\n");

    
    scanf("%d", &key);
    printf("Enter the book ID to search: %d\n",key);

    int result = binarySearch(arr, 0, n - 1, key);

    if(result != -1){
        printf("Book ID %d found at index %d\n", key, result);
    } 
    else{
        printf("Book ID %d not found in the system\n", key);
    }

    return 0;
}
