#include <stdio.h>

// Function to move disks between towers
void moveDisk(char source, char dest, int disk) {
    printf("Move disk %d from %c to %c\n", disk, source, dest);
}

// Tower of Hanoi function using recursion
void towerOfHanoi(int num_disks, char source, char aux, char dest) {
    if (num_disks == 1) {
        moveDisk(source, dest, 1);
        return;
    }

    towerOfHanoi(num_disks - 1, source, dest, aux);
    moveDisk(source, dest, num_disks);
    towerOfHanoi(num_disks - 1, aux, source, dest);
}

int main() {
    int num_disks = 3; // Number of disks
    char source = 'A', aux = 'B', dest = 'C';

    // Solve Tower of Hanoi problem
    towerOfHanoi(num_disks, source, aux, dest);

    return 0;
}


