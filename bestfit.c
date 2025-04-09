#include <stdio.h>

struct process {
    int size;
    int id;  
} p[20];

struct block {
    int no;   
    int size; 
    int id;   
} b[20];

int main() {
    int nb, np, i, j;

    printf("\nEnter the number of memory blocks: ");
    scanf("%d", &nb);

    for (i = 0; i < nb; i++) {
        printf("Enter the size of Block #%d: ", i + 1);
        scanf("%d", &b[i].size);
        b[i].no = i + 1;
        b[i].id = 0; 
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &np);

    for (i = 0; i < np; i++) {
        printf("Enter the size of Process #%d: ", i + 1);
        scanf("%d", &p[i].size);
        p[i].id = 0; 
    }

    for (i = 0; i < nb - 1; i++) {
        for (j = 0; j < nb - i - 1; j++) {
            if (b[j].size > b[j + 1].size) {
                struct block temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < np; i++) {
        for (j = 0; j < nb; j++) {
            if (b[j].id == 0 && p[i].size <= b[j].size) {
                b[j].id = i + 1;
                p[i].id = b[j].no;
                break;
            }
        }
    }

    printf("\n\nMemory Blocks:\n");
    printf("Block_ID\tBlock_Size\tProcess_ID\tProcess_Size\n");
    for (i = 0; i < nb; i++) {
        if (b[i].id != 0)
            printf("%-9d\t%-10d\t%-10d\t%-13d\n", b[i].no, b[i].size, b[i].id, p[b[i].id - 1].size);
        else
            printf("%-9d\t%-10d\t%-10s\t%-13s\n", b[i].no, b[i].size, "Empty", "Empty");
    }

    
    printf("\nProcesses:\n");
    printf("Process_ID\tProcess_Size\tBlock_ID\tBlock_Size\n");
    for (i = 0; i < np; i++) {
        if (p[i].id != 0)
            printf("%-11d\t%-13d\t%-8d\t%-10d\n", i + 1, p[i].size, p[i].id, b[p[i].id - 1].size);
        else
            printf("%-11d\t%-13d\t%-8s\t%-10s\n", i + 1, p[i].size, "Waiting", "Waiting");
    }

    return 0;
}
