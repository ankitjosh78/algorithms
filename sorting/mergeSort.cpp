#include <iostream>

void mergeTwoSorted(int a[], int leftStart, int mid, int rightEnd);

void mergeSort(int a[], int left, int right);

int main() {
  int n;
  printf("Enter the size of the array:");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements of the array:");
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  mergeSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}

void mergeSort(int a[], int left, int right) {
  if (left >= right)
    return;

  int mid = (left + right) / 2;
  mergeSort(a, left, mid);
  mergeSort(a, mid + 1, right);
  mergeTwoSorted(a, left, mid, right);
}

void mergeTwoSorted(int a[], int leftStart, int mid, int rightEnd) {
  int temp[rightEnd - leftStart];
  int i = leftStart, j = mid + 1;
  int k = 0;
  while (i <= mid && j <= rightEnd) {
    if (a[i] < a[j]) {
      temp[k] = a[i];
      i++;
    } else {
      temp[k] = a[j];
      j++;
    }
    k++;
  }
  if (i > mid) {
    while (j <= rightEnd) {
      temp[k] = a[j];
      j++;
      k++;
    }
  } else if (j > rightEnd) {
    while (i <= mid) {
      temp[k] = a[i];
      i++;
      k++;
    }
  }
  k = 0;
  for (int start = leftStart; start <= rightEnd; start++, k++) {
    a[start] = temp[k];
  }
}
