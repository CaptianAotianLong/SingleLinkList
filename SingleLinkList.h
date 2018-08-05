#ifndef SINGLELINKLIST_H_INCLUDED
#define SINGLELINKLIST_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
typedef int NODE_DATA_TYPE;//结构体的数据类型

int lengthOfList;  //链表长度

/*定义一个简单节点的结构体*/
typedef struct Node
{
    NODE_DATA_TYPE data;
    struct Node* p_next;
}node;

/*初始化线性表*/
node* init_single_link_list( );
/*头插法建立单向链表*/
node* single_link_list_create_h( );
/*尾插法建立单向链表*/
node* single_link_list_create_r( );
/*打印链表*/
 void printSingleLinklist(node* sl_node);
/*返回单链表的长度*/
 int singleLinkListLength(node* sl_node);
/*清除链表中的所有元素*/
void clearSingleLinkList(node* sl_node);
/*删除某个节点*/
int deleteSigleLinkListNode(node* sl_node,NODE_DATA_TYPE data);
/*增加节点*/
int addSingleLinkListNode(node* sl_node,NODE_DATA_TYPE data);
/*链表反转*/
node* reverseSingleLinkListNode(node* sl_node);
/*查找某个节点*/
int searceSingleLinkListNode(node* sl_node,NODE_DATA_TYPE data);
/*修改某个节点*/
int modifySingleLinkListNode(node* sl_node,NODE_DATA_TYPE dataToChange,NODE_DATA_TYPE dataNew);
#endif // SINGLELINKLIST_H_INCLUDED
