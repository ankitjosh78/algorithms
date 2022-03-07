#include <stdio.h>

int partition(int a[], int left, int right);
void quickSort(int a[], int left, int right);

int main() {
  int n;
  printf("Enter the size of the array:");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements of the array:");
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  quickSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}

void quickSort(int a[], int left, int right) {
  if (left >= right)
    return;

  int c = partition(a, left, right);
  quickSort(a, left, c - 1);
  quickSort(a, c + 1, right);
}

int partition(int a[], int left, int right) {
  int x = a[left];
  int count_smaller = 0;
  for (int i = left; i <= right; i++)
    if (a[i] < x)
      count_smaller++;
  int c = left + count_smaller;
  for (int i = left + 1; i <= c; i++) {
    int temp = a[i];
    a[i] = a[i - 1];
    a[i - 1] = temp;
  }
  int i = left, j = right;
  while (i != c && j != c) {
    if (a[i] < x) {
      i++;
    }
    if (a[j] >= x) {
      j--;
    } else if (a[i] >= x && a[j] < x) {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      i++;
      j--;
    }
  }

  return c;
}
