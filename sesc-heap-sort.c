 #include <stdio.h>
 #include <stdlib.h>

void heapmax(int arr[], int n, int i) { 
  int largest = i;
  int left = 2*i + 1; 
  int right = 2*i + 2; 
  if (left < n && arr[left] > arr[largest]) 
    largest = left; 
  if (right < n && arr[right] > arr[largest]) 
    largest = right; 
  if (largest != i) { 
    int temp;
    temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp; 
    heapmax(arr, n, largest); 
  } 
} 

void heapsort(int arr[], int n) 
{ 
  for (int i = n/2 - 1; i >= 0; i--) 
    heapmax(arr, n, i); 
  for (int i = n - 1; i >= 0; i--) { 
    int temp;
    temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    heapmax(arr, i, 0); 
  } 
}

int main() {
  int n = 0, j;
  scanf("%d", &n);
  int arr[n];
  for(j = 0; j < n; j++) {
    scanf("%d", &arr[j]);
  }
  heapsort(arr, n);
  for(j = n - 1 ; j >= 0; j--) {
    printf("%d ", arr[j]);
  }
  return 0;
 }