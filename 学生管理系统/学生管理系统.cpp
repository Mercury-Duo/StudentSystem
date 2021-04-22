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
void SystemMenu(){}
void DeleteNode(struct Node* StudentNode,int data){
	struct Node* x = StudentNode;
	struct Node* y = StudentNode->Next;
	while(StudentNode->data==data){
		
	}

}
void PrintNode(struct Node* StudentNode){
	struct Node* pow = StudentNode->Next;
	while(pow){
		printf("%d",pow->data);
		pow = pow->Next;
	}
}
int main(void) {
	struct Node* StudentNode = CreatNode();
	CreatNodeList(StudentNode, 1);
	CreatNodeList(StudentNode, 2);
	CreatNodeList(StudentNode, 3);
	PrintNode(StudentNode);

}
	