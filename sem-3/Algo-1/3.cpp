#include <iostream>

using namespace std;

int findMax(int A[], int size)
{
  int k = A[0];
  for (int i = 0; i < size; i++)
  {
    if (A[i] > k)
    {
      k = A[i];
    }
  }
  return k;
}

void countingSort(int A[], int B[], int C[], int k, int size)
{
  for (int i = 0; i <= k; i++)
  {
    C[i] = 0;
  }

  for (int j = 0; j < size; j++)
  {
    C[A[j]]++;
  }

  for (int i = 1; i <= k; i++)
  {
    C[i] = C[i] + C[i - 1];
  }

  for (int j = size - 1; j >= 0; j--)
  {
    B[C[A[j]] - 1] = A[j];
    C[A[j]]--;
  }

  for (int i = 0; i < size; i++)
  {
    cout << B[i] << " ";
  }
  cout << endl;
}

int main()
{
  int size;
  cout << "Enter size of array: ";
  cin >> size;

  int A[size];
  cout << "Enter elements: ";
  for (int i = 0; i < size; i++)
  {
    cin >> A[i];
  }

  int k = findMax(A, size);
  cout << "Max value: " << k << endl;

  int C[k + 1];
  int B[size];

  cout << "Sorted Array: ";
  countingSort(A, B, C, k, size);

  return 0;
}