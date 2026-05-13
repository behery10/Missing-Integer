#include <stdio.h>
#include <stdlib.h>

// Non-Recursive
int findMissing(int A[], int N) {
    int present[N+1];
    for(int i = 0; i <= N; i++)
        present[i] = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] > 0 && A[i] <= N)
            present[A[i]] = 1;
    }
    for(int i = 1; i <= N; i++) {
        if(present[i] == 0)
            return i;
    }
    return N + 1;
}

// Recursive

void bubbleSort(int A[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int findRec(int A[], int N, int index, int expected) {
    if(index >= N)
        return expected;
    if(A[index] == expected)
        return findRec(A, N, index+1, expected+1);
    else if(A[index] < expected)
        return findRec(A, N, index+1, expected);
    else
        return expected;
}

int findMissingRecursive(int A[], int N) {
    bubbleSort(A, N);
    return findRec(A, N, 0, 1);
}

int main() {
    int N;

    printf("Enter number of elements: ");

    if (scanf("%d", &N) != 1){
        printf("Please enter a valid integer");
        return 1;
    }

    if (N <= 0) {
    printf("Invalid! Number of elements must be greater than zero.\n");
    return 1;
    }

    int A[N];
    printf("Enter elements:\n");
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int B[N];
    for(int i = 0; i < N; i++) {
        B[i] = A[i];
    }

    printf("Non-Recursive Result: %d\n", findMissing(A, N));
    printf("Recursive Result: %d\n", findMissingRecursive(B, N));

    return 0;
}
