#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50

struct Node_SL{
    int Item;
    struct Node_SL *Next;
};

typedef struct Node_SL Node;

Node *First=NULL; //Is actually at the bottom depending on how you look 
Node *Last=NULL;

int isEmpty() {
    return (First==NULL);
}

// GETS
int getItem() {
    int Item;
    printf("\nEnter the Element: ");
    scanf("%d", &Item);
    return Item;
}

int NodeCount() {
    Node *temp = First;
    int NodeCount=0;
    if (!isEmpty()) {
        NodeCount=1;
        while (temp!=Last) {
            NodeCount++;
            temp = temp->Next;
        }
    }
    return NodeCount;
}

// Methods 
void Enqueue() {
    Node *NewNode = (Node *) malloc (sizeof(Node));
    int Item=getItem();
    NewNode -> Item = Item;
    if(isEmpty()) {
        NewNode -> Next = NewNode;
        First = NewNode;
        Last = NewNode;
    } else {
        NewNode -> Next = First;
        Last->Next=NewNode;
        Last=NewNode;
    }
}

int Dequeue() {
    Node *NewNode = (Node *) malloc (sizeof(Node));
    Node *Hold;
    if (isEmpty()) {
        printf("\n Stack is Empty. Cannot Pop an element.");
    } else if (First == Last) {
        First = NULL;
        Last = NULL;
    } else {
        Hold = First;
        printf("\n Popped Item: %d",First->Item);
        First=First->Next;
        Last->Next=First;
        free(Hold);
    }
}

void Display() {
    Node *temp = First ;
    printf("\n The Elements in the List are: [ ");
    if (!isEmpty()) {
        for (int i=0;temp!=Last;i++) {
            printf("%d,",temp->Item);
            temp=temp->Next;
        }
        printf("%d,",Last->Item);
    }
    printf("\b ]\b");
}

void menu(int *choice) {
    printf("\nMENU: Number of Stack Elements: %d\n\n1. Enqueue\n2. Dequeue\n3. Traverse\n\n=> ",NodeCount());
    scanf("%d",choice);
    switch (*choice)
    {
    case 1:
        Enqueue();
        break;
    case 2:
        Dequeue();
        break;
    case 3:
        Display();
        break;
    default:
        printf("\n[ERR 03]: Enter a Valid Option");
        break;
    }
}

int main(){
    int choice=0;

    do {
        system("clear");
        menu(&choice);
    } while (choice != 0);

    printf("\nExiting Program.");
}