#include <stdio.h>
#include <string.h>

struct process {
    int size;
    char name[20];
    int id;
};

struct block {
    int size;
    int id;
};

int main() {
    struct process p[20];
    struct block b[20];

    int nb, np, i, j;

    printf("\nEnter The No Of Blocks: ");
    scanf("%d", &nb);

    for (i = 0; i < nb; i++) {
        printf("Enter The Size of Block #%d: ", i + 1);
        scanf("%d", &b[i].size);
        b[i].id = 0; 
    }

    printf("\nEnter The No Of Processes: ");
    scanf("%d", &np);

    for (i = 0; i < np; i++) {
        printf("Enter The Name of Process #%d: ", i + 1);
        scanf("%s", p[i].name);
        printf("Enter The Size of Process #%d: ", i + 1);
        scanf("%d", &p[i].size);
        p[i].id = 0; 
    }

    
    for (i = 0; i < np; i++) {
        for (j = 0; j < nb; j++) {
            if (b[j].id == 0 && p[i].size <= b[j].size) {
                b[j].id = i + 1;  
                p[i].id = j + 1;  
                break;
            }
        }
    }

    
    printf("\n\nBlock Allocation\n----------------------------\n");
    printf("Block ID\tBlock Size\tProcess Name\tProcess Size\n");
    for (i = 0; i < nb; i++) {
        if (b[i].id != 0)
            printf("%-9d\t%-10d\t%-13s\t%-13d\n", i + 1, b[i].size, p[b[i].id - 1].name, p[b[i].id - 1].size);
        else
            printf("%-9d\t%-10d\t%-13s\t%-13s\n", i + 1, b[i].size, "Empty", "Empty");
    }

    
    printf("\n\nProcess Allocation\n----------------------------\n");
    printf("Process Name\tProcess Size\tBlock ID\tBlock Size\n");
    for (i = 0; i < np; i++) {
        if (p[i].id != 0)
            printf("%-13s\t%-13d\t%-8d\t%-10d\n", p[i].name, p[i].size, p[i].id, b[p[i].id - 1].size);
        else
            printf("%-13s\t%-13d\t%-8s\t%-10s\n", p[i].name, p[i].size, "Waiting", "Waiting");
    }

    return 0;
}
