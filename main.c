#include <SingleLinkList.h>

int main()
{
    int data,dataTemp;

    /*����һ����������*/
    node* list;
    list = single_link_list_create_r();
    /*��ӡ����*/
    printSingleLinklist(list);

    lengthOfList = singleLinkListLength(list);

    printf("The length of list is %d\n",lengthOfList);

    list = reverseSingleLinkListNode(list);
    printf("Rverse:\n");
    printSingleLinklist(list);
    //clearSingleLinkList(list);

    //printSingleLinklist(list);
    printf("����Ҫɾ���Ľڵ�\n");
    scanf("%d",&data);
    deleteSigleLinkListNode(list,data);

    printf("����Ҫ���ӵĽڵ�\n");
    scanf("%d",&data);
    addSingleLinkListNode(list,data);
    printSingleLinklist(list);

    printf("����Ҫ���ҵĽڵ�\n");
    scanf("%d",&data);
    searceSingleLinkListNode(list,data);
    printSingleLinklist(list);

    printf("����Ҫ�޸ĵĽڵ�\n");
    scanf("%d",&data);
    printf("�����µ�����\n");
    scanf("%d",&dataTemp);
    modifySingleLinkListNode(list,data,dataTemp);
    printSingleLinklist(list);

    return 1;
}
