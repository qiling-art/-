#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>
//jc Ϊ�򵥲�ѯ zcΪ��ϲ�ѯ mcΪģ����ѯ 
typedef struct Book {
    char * name;//���� 
    char * writer;//������
    char f_letter;//ƴ������ĸ
    int type;//������࣬0 ������ 1 ������ 2 С˵�� 3 ������ 4 ��ʷ�� 5 ʫ����
    long long Isbn;//���ISBN��
    long long p_date;//��������
    int flag;//�ж��Ȿ����û�б����
    struct Book* next;
}Book;

struct Book* jcbookname()//�����򵥲�ѯ
{

    struct Book* head;
    head = (struct Book*)malloc(sizeof(struct Book));
    head->next = NULL;
    FILE* fp;
    char bookname[50];
    printf("������������");
    scanf("%s", bookname);
    fp = fopen("database.txt", "r+");
    if (fp == NULL)
    {
        printf("error\n");

    }
    struct Book* book;
    struct Book* p;
    p = book = head;
    while (!feof(fp))
    {
        book = (struct Book*)malloc(sizeof(struct Book));
        fscanf(fp, "%s", book->name);
        fscanf(fp, "%s", book->writer);
        fscanf(fp, "%c", &book->f_letter);
        fscanf(fp, "%d", &book->type);
        fscanf(fp, "%lld", &book->Isbn);
        fscanf(fp, "%lld", &book->p_date);
        fscanf(fp, "%d", &book->flag);
        book->next = NULL;
        p->next = book;
        p = p->next;
    }
    struct Book* pre;
    pre = head;
    while (pre != NULL)
    {
        if (strcmp(pre->name, bookname) == 0)
        {
            printf(" % s % s % c % d % lld % lld % d\n", pre->name, pre->writer, pre->f_letter, pre->type, pre->Isbn, pre->p_date, pre->flag);
        }
        pre = pre->next;

    }
    fclose(fp);
    return head;
};
int main() {
    jcbookname();
    return 0;
}


