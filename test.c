#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct doubleListNode{
	char data[4];
	struct doubeListNode* llink;
	struct doubeListNode* rlink;
}doubleListNode;
typedef struct linkedList_h{
	doubleListNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h(){
	linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;

	return L;
}

void addLastNode(linkedList_h* DL, char* data){
	doubleListNode* newNode = (doubleListNode*)malloc(sizeof(doubleListNode));
	strcpy(newNode->data, data);
	newNode->llink = NULL;
	newNode->rlink = NULL;

	if (DL->head == NULL){
		DL->head = newNode;
		return;
	}

	doubleListNode* p = DL->head;

	while (p->rlink != NULL){
		*p = p->rlink;
	}

	p->rlink = newNode;
	newNode->llink = p;
}

void printNode(linkedList_h* DL){
	doubleListNode* p = DL->head;
	while (p != NULL){
		p = p->rlink;
		printf("%s\n", p->data);
	}
}

void main(){
	linkedList_h* DL = createLinkedList_h();

	addLastNode(DL, "aa");
	addLastNode(DL, "aa2");
	addLastNode(DL, "aa1");
}







































