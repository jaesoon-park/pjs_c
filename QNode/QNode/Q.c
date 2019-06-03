#include<stdio.h>
#include<malloc.h>

typedef char element;
typedef struct QNode{
	element data;
	struct QNode *link;
}QNode; 
typedef struct {
	
	struct QNode *front, *rear;
}LQueueuType;

LQueueuType *createLinkedQueue() {
	LQueueuType *LQ;
	LQ = (LQueueuType *)malloc(sizeof(LQueueuType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

int isEmpty(LQueueuType *LQ) {
	if (LQ->front == NULL) {
		printf(" Linked Queue is empty! ");
		return 1;
	}
	else return 0;
}

void enQueue(LQueueuType *LQ, element item) {
	QNode *newNode = (QNode *)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	} 
}

element deQueue(LQueueuType *LQ) {
	QNode *old = LQ->front;
	element item;
	if (isEmpty(LQ))return 0;
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);
		return item;
	}
}

element peek(LQueueuType *LQ) {
	element item;
	if(isEmpty(LQ)) return 0;
	else{
		item = LQ->front->data;
		return item;
	}
	
}

void printLQ(LQueueuType *LQ) {
	QNode *temp = LQ->front;
	printf(" Linked Queue : [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf(" ]");
}

void main(void) {
	LQueueuType *LQ = createLinkedQueue();
	element data;

	printf("\n ***** 연결 큐 연산 *****\n");
	printf("\n 삽입 A>>"); enQueue(LQ, 'A'); printLQ(LQ);
	printf("\n 삽입 B>>"); enQueue(LQ, 'B'); printLQ(LQ);
	printf("\n 삽입 C>>"); enQueue(LQ, 'C'); printLQ(LQ);
	data = peek(LQ);		printf(" peek item : %c \n", data);
	printf("\n 삭제 >>"); data = deQueue(LQ); printLQ(LQ);	
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\t삭제 데이터 : %c", data);
	printf("\n 삭제 >>"); data = deQueue(LQ); printLQ(LQ);
	printf("\t삭제 데이터 : %c", data);
}

