#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() {
    // Get the current nice value
    errno = 0; // Clear any existing error
    int current_nice = nice(0); // Get current nice value

    if (current_nice == -1 && errno != 0) {
        perror("Error getting current nice value");
        return 1;
    }

    printf("Current nice value: %d\n", current_nice);

    // Increase the nice value by 5 (i.e., lower the priority)
    errno = 0; // Reset errno again
    int new_nice = nice(5); // Add 5 to the nice value

    if (new_nice == -1 && errno != 0) {
        perror("Error setting new nice value");
        return 1;
    }

    printf("New nice value: %d\n", new_nice);

    // Simulate CPU-intensive work
    for (volatile long i = 0; i < 100000000; ++i);

    printf("Finished CPU work with nice value: %d\n", new_nice);

    return 0;
}
