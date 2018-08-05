#ifndef SINGLELINKLIST_H_INCLUDED
#define SINGLELINKLIST_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
typedef int NODE_DATA_TYPE;//�ṹ�����������

int lengthOfList;  //������

/*����һ���򵥽ڵ�Ľṹ��*/
typedef struct Node
{
    NODE_DATA_TYPE data;
    struct Node* p_next;
}node;

/*��ʼ�����Ա�*/
node* init_single_link_list( );
/*ͷ�巨������������*/
node* single_link_list_create_h( );
/*β�巨������������*/
node* single_link_list_create_r( );
/*��ӡ����*/
 void printSingleLinklist(node* sl_node);
/*���ص�����ĳ���*/
 int singleLinkListLength(node* sl_node);
/*��������е�����Ԫ��*/
void clearSingleLinkList(node* sl_node);
/*ɾ��ĳ���ڵ�*/
int deleteSigleLinkListNode(node* sl_node,NODE_DATA_TYPE data);
/*���ӽڵ�*/
int addSingleLinkListNode(node* sl_node,NODE_DATA_TYPE data);
/*����ת*/
node* reverseSingleLinkListNode(node* sl_node);
/*����ĳ���ڵ�*/
int searceSingleLinkListNode(node* sl_node,NODE_DATA_TYPE data);
/*�޸�ĳ���ڵ�*/
int modifySingleLinkListNode(node* sl_node,NODE_DATA_TYPE dataToChange,NODE_DATA_TYPE dataNew);
#endif // SINGLELINKLIST_H_INCLUDED
