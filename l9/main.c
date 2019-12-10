#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char key[10];
    char name[20];
    int age;
}Data;
typedef struct Node
{
            Data nodeData;
    struct Node *nextNode;
}CLType;

CLType *CLAddEnd(CLType *head,Data nodeData)
{
    CLType *node,*htemp;
    if(!(node=(CLType *)malloc(sizeof(CLType))))
    {
        printf("申请内存失败！\n");
        return NULL;
    }
    else
    {
        node->nodeData=nodeData;
        node->nextNode=NULL;
        if(head==NULL)
        {
            head=node;
            return head;
        }
        htemp=head;
        
        while(htemp->nextNode!=NULL)
        {
            htemp=htemp->nextNode;
        }
        htemp->nextNode=node;
        return head;
    }
}

CLType *CLAddFirst(CLType *head,Data nodeData)
{
    CLType *node;
    if(!(node=(CLType *)malloc(sizeof(CLType))))
    {
        printf("申请内存失败！\n");
        return NULL;
    }
    else
    {
        node->nodeData=nodeData;
        node->nextNode=head;
        head=node;
        return head;
    }
}

CLType *CLFindNode(CLType *head,char *key)
{
    CLType *htemp;
    htemp=head;
    while(htemp)
    {
        if(strcmp(htemp->nodeData.key,key)==0)
        {
            return htemp;
        }
        htemp=htemp->nextNode;
    }
    return NULL;
}

CLType *CLInsertNode(CLType *head, char *findkey, Data nodeData)
{
    CLType *node,*nodetemp;
    if(!(node=(CLType *)malloc(sizeof(CLType))))
    {
        printf("申请内存失败！\n");
        return 0;
    }
    node->nodeData=nodeData;
    nodetemp=CLFindNode(head, findkey);
    if(nodetemp)
    {
        node->nextNode=nodetemp->nextNode;
        nodetemp->nextNode=node;
    }
    else
    {
        printf("未找到正确的插入位置！\n");
        free(node);
    }
    return head;
}

int CLDeleteNode(CLType *head,char *key)
{
    CLType *node,*htemp;
    htemp=head;
    node=head;
    while(htemp)
    {
        if(strcmp(htemp->nodeData.key,key)==0)
        {
            node->nextNode=htemp->nextNode;
            free(htemp);
            return 1;
        }
        else
        {
            node=htemp;
            htemp=htemp->nextNode;
        }
    }
    return 0;
}


int CLLength(CLType *head)
{
    CLType *htemp;
    int Len=0;
    htemp=head;
    while(htemp)
    {
        Len++;
        htemp=htemp->nextNode;
    }
    return Len;
}

void CLAllNode(CLType *head)
{
    CLType* htemp;
    Data nodeData;
    htemp=head;
    printf("当前链表共有%d个节点。链表所有数据如下：\n",CLLength(head));
    while(htemp)
    {
        nodeData=htemp->nodeData;
        printf("节点(%s,%s,%d)\n",nodeData.key,nodeData.name,nodeData.age);
        htemp=htemp->nextNode;
    }
}

void main ()
{
    CLType *node,*head=NULL;
    Data nodeData;
    char key[10],findkey[10];
    
    printf("链表测试。先输入链表中的数据，格式为：关键字 姓名 年龄\n");
    do
    {
        scanf("%s",nodeData.key);
        if(strcmp(nodeData.key,"0")==0)
        {
            break;
        }
        else
        {
            scanf("%s%d",nodeData.name,&nodeData.age);
            head=CLAddEnd(head,nodeData);
        }
    }while(1);
    CLAllNode(head);

    printf("\n演示插入节点，输入插入位置的关键字：");
    scanf("%s",&findkey);
    printf("输入插入节点的数据（关键字 姓名 年龄）：");
    scanf("%s%s%d",nodeData.key,nodeData.name,&nodeData.age);
    head=CLInsertNode(head,findkey,nodeData);   /*调用插入函数*/
    CLAllNode(head);
    
    printf("\n演示删除节点，输入要删除的关键字：");
    scanf("%s",key);
    CLDeleteNode(head,key);
    CLAllNode(head);
    
    printf("\n演示在链表中查找，输入查找关键字：");
    scanf("%s",key);
    node=CLFindNode(head, key);
    if(node)
    {
        nodeData=node->nodeData;
        printf("关键字%s对应的节点为（%s,%s,%d）\n",key,nodeData.key,nodeData.name,nodeData.age);
    }
    else
    {
        printf("在链表中未找到关键字为%s的节点！\n",key);
    }

}



















