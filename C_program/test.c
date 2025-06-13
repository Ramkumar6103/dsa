#include <stdio.h>
#include <stdlib.h>

int main() {

    // Execute hello.exe and get the return value
    int returnCode = system("hello.exe");

    // Extract the exit status
    if (returnCode != -1) {
        printf("hello.exe returned: %d\n", returnCode);
    } else {
        printf("Error executing hello.exe\n");
    }

    return 0;
}
