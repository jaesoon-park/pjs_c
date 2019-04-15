#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct ListNode {
	 char data[4];
	struct ListNode* link;
}ListNode;

typedef struct {
	ListNode*head;
}LinkedList_h;

LinkedList_h* createLinkedList_h(void) {
	LinkedList_h* L;
	L = (LinkedList_h*)malloc(sizeof(LinkedList_h));
	L->head = NULL;
	return L;
}

void freeLinkedList_h(LinkedList_h*L) {
	ListNode*p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

void printList(LinkedList_h*L) {
	ListNode* p;
	printf("L =(");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

void insertFirstNode(LinkedList_h *L,char *x) {
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

void insertMiddleNode(LinkedList_h* L, ListNode *pre,char*x) {
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->data, x);
	if (L == NULL) {
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) {
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void insertLastNode(LinkedList_h *L, char *x) {
	ListNode* newNode;
	ListNode* temp;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {
		L->head = newNode;
		return;
	}
	temp = L->head;
	while (temp->link != NULL)temp = temp->link;
	temp->link = newNode;

}


int main()
{
	LinkedList_h* L;
	L = createLinkedList_h();
	printf("(1)  공백  리스트  생성하기! \n");
	printList(L); getchar();

	printf("(2)  리스트에 [수] 노드 삽입하기! \n");
	insertFirstNode(L, "수");
	printList(L); getchar();

	printf("(3)  리스트 마지막에 [금] 노드 삽입하기! \n");
	insertLastNode(L, "금");
	printList(L); getchar();

	printf("(4)  리스트 첫 번쨰에 [월] 노드 삽입하기! \n");
	insertFirstNode(L, "월");
	printList(L); getchar();

	printf("(5)  리스트 공간을 해제하여 공백 리스트로 만들기! \n");
	freeLinkedList_h(L);
	printList(L); getchar();

	getchar();


	return 0;

}



