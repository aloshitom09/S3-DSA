#include <stdio.h>
#include <stdlib.h>

struct Node {
    char url[100];
    struct Node *prev, *next;
};

struct Node *current = NULL;
struct Node *head = NULL;

struct Node* createNode(char url[]) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    int i = 0;
    while (url[i] != '\0') {
        newNode->url[i] = url[i];
        i++;
    }
    newNode->url[i] = '\0';
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void visitPage(char url[]) {
    struct Node *newNode = createNode(url);
    if (current != NULL) {
        struct Node *temp = current->next;
        while (temp != NULL) {
            struct Node *del = temp;
            temp = temp->next;
            free(del);
        }
        current->next = newNode;
        newNode->prev = current;
    } else {
        head = newNode;
    }
    current = newNode;
    printf("Visited: %s\n", current->url);
}

void goBack() {
    if (current == NULL || current->prev == NULL) {
        printf("No previous page.\n");
        return;
    }
    current = current->prev;
    printf("Went Back to: %s\n", current->url);
}

void goForward() {
    if (current == NULL || current->next == NULL) {
        printf("No forward page.\n");
        return;
    }
    current = current->next;
    printf("Went Forward to: %s\n", current->url);
}

void showHistory() {
    if (head == NULL) {
        printf("No browsing history.\n");
        return;
    }
    printf("\nBrowser History:\n");
    struct Node *temp = head;
    while (temp != NULL) {
        if (temp == current)
            printf("-> %s (Current)\n", temp->url);
        else
            printf("   %s\n", temp->url);
        temp = temp->next;
    }
}

int main() {
    int choice;
    char url[100];
    while (1) {
        printf("\nBrowser Menu\n");
        printf("1. Visit new page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Show History\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visitPage(url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                showHistory();
                break;
            case 5:
                printf("Exiting browser.\n");
                return 0;
           default:
           printf("Invalid choice. Try again.");
        }
    }
}