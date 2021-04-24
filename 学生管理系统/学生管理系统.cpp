#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<String.h>
//初始化所有函数
void SystemMenu();
void KeyRecive();
void InsertNode();
struct Node* CreatNode();
struct Node* CreatNewNode(struct Student data);
void CreatNodeList(struct Node* HeadNode, struct Student data);
void deletestudent();
void deletenode(struct Node* headnode, char* name);
//struct Node* changenode(struct Node* S);
struct Node* SearchNode(struct Node* StudentNode, char* name);
void PrintNode(struct Node* StudentNode);
void PrintList(struct Node* StudentNode);
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
	printf("\t\t\t4.查找信息\n");
	printf("\t\t\t5.退出系统\n");
	printf("-----------------------------------------------------------------------------------\n");

}
void KeyRecive() {
	int x;	struct Student s;
	scanf("%d", &x);
	switch (x)
	{
	case 0:
		InsertNode();
		printf("插入操作执行完成！-------------");
		break;
	case 1:
		printf("\t【浏览信息】\n");
		PrintNode(StudentNode);
		printf("浏览操作执行完成--------------");
		break;
	case 2:
		printf("\t【删除信息】\n");
		deletestudent();
		printf("删除操作执行完成---------------");
		break;
	case 3:
		printf("\t【更改信息】\n");
		printf("请输入更改的姓名：");
		scanf("%s", &s.name);
		if (SearchNode(StudentNode, s.name) == NULL) {
			printf("未找到相关信息！\n");
		}
		else
		{
			struct Node* s1 = SearchNode(StudentNode, s.name);
			printf("请输入新的学生信息");
			printf("请输入同学姓名，年龄，电话，住址");
			scanf("%s%d%s%s", &s1->data.name, &s1->data.age, &s1->data.tel, &s1->data.addr);
			printf("修改操作执行完成---------------");
		}
		break;
	case 5:
		printf("\t【退出系统】\n");
		exit(0);
		break;
	case 4:
		printf("\t【查找信息】\n");
		printf("请输入查找的姓名：");
		scanf("%s",&s.name);
		if (SearchNode(StudentNode, s.name) == NULL) {
			printf("未找到相关信息！\n");
		}
		else
		{
			PrintList(SearchNode(StudentNode, s.name));
			printf("查找操作执行完成---------------");
		}
		
		break;
	default:printf("输入数据有误，重新输入");KeyRecive();
		break;
	}
}
void InsertNode() {//插入函数
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
struct Node* CreatNode() //建立头节点
{
	struct Node* HeadNode = (struct Node*)malloc(sizeof(struct Node));
	HeadNode->Next = NULL;
	return HeadNode;
}
struct Node* CreatNewNode(struct Student data) {//建立新结点函数
	struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
	NewNode->data = data;
	NewNode->Next = NULL;
	return NewNode;
}
void CreatNodeList(struct Node* HeadNode, struct Student data) {//建立新节点并插入数据
	struct Node* NewNode = CreatNewNode(data);
	NewNode->Next = HeadNode->Next;
	HeadNode->Next = NewNode;
 }
void deletestudent() {//删除节点|
	char name[10];
	printf("请输入需要删除的学生名字");
	scanf("%s",&name);
	deletenode(StudentNode,name);
}
void deletenode(struct Node* headnode, char *name) {//删除节点
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
struct Node* SearchNode(struct Node* StudentNode, char* name) {//查找节点
	struct Node* pMove = StudentNode->Next;
	if (pMove == NULL) { 
		printf("未找到该学生");
		return(pMove);
	}
	else
	{
		while (strcmp(pMove->data.name, name)) {
			pMove = pMove->Next;
			if (pMove == NULL)break;
		}
		return pMove;
	}
}
void PrintList(struct Node* StudentNode) {//打印单个节点
	printf("姓名\t年龄\t电话\t住址\n");
	printf("%s\t%d\t%s\t%s\n",StudentNode->data.name,StudentNode->data.age,StudentNode->data.tel,StudentNode->data.addr);
}
void PrintNode(struct Node* StudentNode){//浏览信息
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
	