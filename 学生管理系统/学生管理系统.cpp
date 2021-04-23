#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<String.h>
void SystemMenu();
void KeyRecive();
void InsertNode();
struct Node* CreatNode();
struct Node* CreatNewNode(struct Student data);
void CreatNodeList(struct Node* HeadNode, struct Student data);
void deletestudent();
void deletenode(struct Node* headnode, char* name);
void changenode(struct Node* S);
void PrintNode(struct Node* StudentNode);
struct Node* StudentNode;
struct Student {
	char name[20];//名字
	int age;//年龄
	char tel[20];//电话
	char addr[20];//住址
};
struct Node {
	struct Student data;
	struct Node* Next;
};
void SystemMenu() {
	printf("-----------------------------学生信息管理系统--------------------------------------\n");
	printf("\t\t\t0.插入信息\n");
	printf("\t\t\t1.浏览信息\n");
	printf("\t\t\t2.删除信息\n");
	printf("\t\t\t3.修改信息\n");
	printf("\t\t\t4.退出系统\n");
	printf("-----------------------------------------------------------------------------------\n");

}
void KeyRecive() {
	int x;
	scanf("%d", &x);
	switch (x)
	{
	case 0:
		InsertNode();
		printf("插入成功！");
		break;
	case 1:
		printf("\t【浏览信息】\n");
		PrintNode(StudentNode);
		printf("浏览完成");
		break;
	case 2:
		printf("\t【删除信息】\n");
		deletestudent();
		printf("删除完成");
		break;
	case 3:
		printf("\t【修改信息】\n");
		changenode(StudentNode);
		printf("修改完成");
		break;
	case 4:
		printf("\t【退出系统】\n");
		exit(0);
		break;
	default:printf("输入数据有误，重新输入");KeyRecive();
		break;
	}
}
void InsertNode() {
    int x;
	struct Student S;
	printf("请输入学生个数");
	scanf("%d",&x);
	for (int i = 1;i <= x; i++) {
		printf("请输入第%d个同学姓名，年龄，电话，住址",i);
		scanf("%s%d%s%s", &S.name, &S.age, &S.tel, &S.addr);
		CreatNodeList(StudentNode,S);
	}
}
struct Node* CreatNode() {
	struct Node* HeadNode = (struct Node*)malloc(sizeof(struct Node));
	HeadNode->Next = NULL;
	return HeadNode;
}
struct Node* CreatNewNode(struct Student data) {
	struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
	NewNode->data = data;
	NewNode->Next = NULL;
	return NewNode;
}
void CreatNodeList(struct Node* HeadNode, struct Student data) {
	struct Node* NewNode = CreatNewNode(data);
	NewNode->Next = HeadNode->Next;
	HeadNode->Next = NewNode;
 }
void deletestudent() {
	char name[10];
	printf("请输入需要删除的学生名字");
	scanf("%s",&name);
	deletenode(StudentNode,name);
}
void deletenode(struct Node* headnode, char *name) {
	struct Node* posnode = headnode->Next;
	struct Node* posnodefront = headnode;
	if (posnode == NULL) {
		printf("数据为空，无法删除");

	}
	else
	{
		while (strcmp(posnode->data.name,name)) {
			posnodefront = posnode;
			posnode = posnodefront->Next;
			if (posnode == NULL) { printf("未找到指定位置，无法删除"); return; }
		}
		posnodefront->Next = posnode->Next;
		free(posnode);
	}
}
void changenode(struct Node* S) {
	char name[10];
	printf("请输入需要修改人名字");
	scanf("%s",&name);
	struct Node* posnode = S->Next;
	/*if (posnode == NULL) {
		printf("数据为空，无法修改");
	}
	if(strcmp(posnode->data.name,name)){
		printf("请输入修改人的年龄电话地址");
		scanf("%d%s%s", &posnode->data.age, &posnode->data.tel, &posnode->data.addr);
	}
	else
	{
		posnode = posnode->Next;
	}
*/
	//struct Node* posnodefront =S;
	if (posnode == NULL) {
		printf("数据为空，无法修改");

	}
	else
	{
		while (strcmp(posnode->data.name, name)) {
			//posnodefront = posnode;
			printf("请输入修改人的年龄电话地址");
			scanf("%d%s%s", &posnode->data.age, &posnode->data.tel, &posnode->data.addr);
			return;
		}
		//posnodefront->Next = posnode->Next;
		//free(posnode);
		
		posnode = posnode->Next;
		if (posnode == NULL) { printf("未找到指定位置，无法更改"); return; }
	}
}


void PrintNode(struct Node* StudentNode){
	struct Node* pow = StudentNode->Next;
	printf("姓名\t年龄\t电话\t住址\n");
	while(pow){
		printf("%s\t%d\t%s\t%s\n",pow->data.name,pow->data.age,pow->data.tel,pow->data.addr);
		pow = pow->Next;
	}
}
int main(void) {
	StudentNode = CreatNode();
	
	while (1) { 
		SystemMenu();
		KeyRecive();
		system("pause");
		system("cls");
		
	}

}
	