#include <stdio.h>
#include <stdlib.h>


struct Node {
    int coeff;
    int pow;
    struct Node* next;
};


struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}


void insertNode(struct Node** head, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}


void printPoly(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    int first = 1;
    while (head != NULL) {
        if (!first) printf(" + ");

        if (head->pow == 0)
            printf("%d", head->coeff);
        else if (head->pow == 1)
            printf("%dx", head->coeff);
        else
            printf("%dx^%d", head->coeff, head->pow);

        first = 0;
        head = head->next;
    }
    printf("\n");
}


struct Node* addPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            insertNode(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) {
            insertNode(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
        else { 
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0)
                insertNode(&result, sumCoeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    
    while (poly1 != NULL) {
        insertNode(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertNode(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}


void readPolynomial(struct Node** poly) {
    int terms;
    printf("Enter number of terms in polynomial: ");
    scanf("%d", &terms);

    for (int i = 0; i < terms; i++) {
        int coeff, pow;
        printf("Enter coefficient and power of term %d: ", i + 1);
        scanf("%d %d", &coeff, &pow);
        insertNode(poly, coeff, pow);
    }
}


int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;

    printf("Enter Polynomial 1:\n");
    readPolynomial(&poly1);

    printf("\nEnter Polynomial 2:\n");
    readPolynomial(&poly2);

    printf("\nPolynomial 1: ");
    printPoly(poly1);

    printf("Polynomial 2: ");
    printPoly(poly2);

    sum = addPoly(poly1, poly2);

    printf("Sum: ");
    printPoly(sum);

    return 0;
}
