#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* Next;
};
struct Node* CreatNode() {
	struct Node* HeadNode = (struct Node*)malloc(sizeof(struct Node));
	HeadNode->Next = NULL;
	return HeadNode;
}
struct Node* CreatNewNode(int data) {
	struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
	NewNode->data = data;
	NewNode->Next = NULL;
	return NewNode;
}
void CreatNodeList(struct Node* HeadNode, int data) {
	struct Node* NewNode = CreatNewNode(data);
	NewNode->Next = HeadNode->Next;
	HeadNode->Next = NewNode;
 }
bvoid SystemMenu(){}
void DeleteNode(struct Node* StudentNode,int data){
	if (StudentNode == NULL)return;
	struct Node* FrontNode = StudentNode;
	struct Node* PosNode = StudentNode->Next;
	while (PosNode->data != data) {
		PosNode->Next = PosNode;
		PosNode = PosNode->Next;
		if (PosNode == NULL) {
			printf("无相关内容\n");
			return;
		}
}
	PosNode->Next = PosNode->Next;
	free(PosNode);
}
void PrintNode(struct Node* StudentNode){
	struct Node* pow = StudentNode->Next;
	while(pow){
		printf("%d",pow->data);
		printf("\n");
		pow = pow->Next;
	}
}
int main(void) {
	struct Node* StudentNode = CreatNode();
	CreatNodeList(StudentNode, 1);
	CreatNodeList(StudentNode, 2);
	CreatNodeList(StudentNode, 3);
	PrintNode(StudentNode);
	DeleteNode(StudentNode,2);
	PrintNode(StudentNode);

}
	