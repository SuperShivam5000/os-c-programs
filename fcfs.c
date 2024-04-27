#include <stdio.h>
#include <stdlib.h>

struct process {
    int id;
    int at;
    int bt;
    int wt;
    int tat;
    int isStarted;
    struct process *next;
};

void bubbleSort(struct process *start) {
    int swapped, i;
    struct process *ptr1;
    struct process *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr) {
            if (ptr1->at > ptr1->next->at) {
                // Swap data of two nodes
                int tempId = ptr1->id;
                int tempAt = ptr1->at;
                int tempBt = ptr1->bt;
                ptr1->id = ptr1->next->id;
                ptr1->at = ptr1->next->at;
                ptr1->bt = ptr1->next->bt;
                ptr1->next->id = tempId;
                ptr1->next->at = tempAt;
                ptr1->next->bt = tempBt;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
void fcfsalgo(struct process *node) {
    int t = 0;
    while (node != NULL) {
        if(t>=node->at){
            while(node->bt>0){
                if(node->isStarted==0){
                    node->isStarted=1;
                    node->wt=t-node->at;
                    node->tat=node->bt+node->wt;
                }
                node->bt--;
                printf("At T= %d, Process ID: %d\n", t,node->id);
                t++;
            }
            node = node->next;
        } else {
            printf("At T= %d, Idle\n",t);
            t++;
        }
    }
}

// Function to print linked list
void printList(struct process *node) {
    while (node != NULL) {
        if(node->isStarted==1)
        printf("ID: %d, AT: %d, BT: %d, WT: %d, TAT: %d\n", node->id, node->at, node->bt, node->wt, node->tat);
        else
        printf("ID: %d, AT: %d, BT: %d\n", node->id, node->at, node->bt);
        node = node->next;
    }
}

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct process *head = NULL;
    struct process *temp = NULL;
    struct process *newnode = NULL;

    // Create linked list of n processes
    for (i = 0; i < n; i++) {
        newnode = (struct process*) malloc(sizeof(struct process));
        printf("Enter ID for process %d: ", i + 1);
        scanf("%d", &newnode->id);
        printf("Enter AT for process %d: ", i + 1);
        scanf("%d", &newnode->at);
        printf("Enter BT for process %d: ", i + 1);
        scanf("%d", &newnode->bt);
        newnode->isStarted=0;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("List before sorting:\n");
    printList(head);
    bubbleSort(head);
    fcfsalgo(head);
    printf("\nList after sorting:\n");
    printList(head);

    return 0;
}
