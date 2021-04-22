#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* Next;
};
struct Student {

};
void SystemMenu() {
	printf("-----------------------------学生信息管理系统--------------------------------------\n");
	printf("\t\t\t1.\n");
	printf("\t\t\t1.\n");
	printf("\t\t\t1.\n");
	printf("\t\t\t1.\n");
	printf("-----------------------------------------------------------------------------------\n");

}
void KeyRecive() {
	int x;
	scanf("%d", &x);
	switch (x)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	default:printf("输入数据有误，重新输入");KeyRecive();
		break;
	}
}
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

void deletenode(struct Node* headnode, int x) {
	struct Node* posnode = headnode->Next;
	struct Node* posnodefront = headnode;
	if (posnode->data == NULL) {
		printf("链表为空，无法删除");

	}
	else
	{
		while (posnode->data != x) {
			posnodefront = posnode;
			posnode = posnodefront->Next;
			if (posnode == NULL) { printf("未找到指定位置，无法删除"); return; }
		}
		posnodefront->Next = posnode->Next;
		free(posnode);
	}
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
	SystemMenu();
	struct Node* StudentNode = CreatNode();
	CreatNodeList(StudentNode, 1);
	CreatNodeList(StudentNode, 2);
	CreatNodeList(StudentNode, 3);
	PrintNode(StudentNode);
	//DeleteNode(StudentNode,1);
	deletenode(StudentNode,1);
	PrintNode(StudentNode);

}
	