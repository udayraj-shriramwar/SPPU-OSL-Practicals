#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Bubble Sort (Parent)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort (Child)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    printf("Enter number of integers: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    pid_t pid = fork();  // create child process

    if (pid < 0) {
        printf("Fork failed!\n");
        exit(1);
    }

    else if (pid == 0) {
        // Child Process
        printf("\n--- Child Process ---\n");
        printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());

        printf("Child sorting using Selection Sort...\n");
        selectionSort(arr, n);

        printf("Sorted array by Child: ");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");

        printf("Child sleeping for 5 seconds...\n");
        sleep(5);
        printf("After sleep, Child's Parent PID: %d (Parent exited, now adopted by init)\n", getppid());
        printf("Child exiting.\n");
    }

    else {
        // Parent Process
        printf("\n--- Parent Process ---\n");
        printf("Parent PID: %d\n", getpid());
        printf("Parent sorting using Bubble Sort...\n");

        bubbleSort(arr, n);

        printf("Sorted array by Parent: ");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");

        printf("Parent exiting early to make child orphan...\n");
        exit(0); // Parent exits early → child becomes orphan
    }

    return 0;
}
