#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int n, i, j, temp;
    pid_t pid;

    printf("Enter number of integers: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    pid = fork();

    if (pid == 0) {  // Child process
        printf("\n--- Child Process ---\n");
        printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
        printf("Child sorting using Selection Sort...\n");

        // Selection Sort
        for (i = 0; i < n - 1; i++) {
            int min = i;
            for (j = i + 1; j < n; j++)
                if (arr[j] < arr[min])
                    min = j;

            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }

        printf("Sorted array by Child: ");
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\nChild process finished.\n");

        exit(0);
    }

    else if (pid > 0) {  // Parent process
        printf("\n--- Parent Process ---\n");
        printf("Parent PID: %d\n", getpid());
        printf("Parent sorting using Bubble Sort...\n");

        // Bubble Sort
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        printf("Sorted array by Parent: ");
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");

        printf("\nParent sleeping for 15 seconds... (Child becomes zombie now)\n");
        sleep(15); // Parent sleeps intentionally to create zombie

        printf("\nNow parent calling wait()...\n");
        wait(NULL);
        printf("Parent: Child process reaped successfully (no zombie now)\n");
    }

    else {
        printf("Fork failed!\n");
    }

    return 0;
}
