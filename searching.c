#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>
//jc Ϊ�򵥲�ѯ zcΪ��ϲ�ѯ mcΪģ����ѯ 
typedef struct Book {
    char  name[100];//���� 
    char  writer[100];//������
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

        fscanf(fp, "%s ", book->name);
        fscanf(fp, "%s ", book->writer);
        fscanf(fp, "%c ", &book->f_letter);
        fscanf(fp, "%d ", &book->type);
        fscanf(fp, "%lld ", &book->Isbn);
        fscanf(fp, "%lld ", &book->p_date);
        fscanf(fp, "%d ", &book->flag);
        book->next = NULL;
        p->next = book;
        p = book;
    }
    struct Book* pre;
    pre = head;
    int b = 0;
    while (pre != NULL)
    {

        if (strcmp(pre->name, bookname) == 0)
        {
            printf("������%s ", pre->name);
            printf("���ߣ�%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("���ࣺ������ ");
            }
            else if (pre->type == 1)
            {
                printf("���ࣺ������ ");
            }
            else if (pre->type == 2)
            {
                printf("���ࣺС˵�� ");
            }
            else if (pre->type == 3)
            {
                printf("���ࣺ������ ");
            }
            else if (pre->type == 4)
            {
                printf("���ࣺ��ʷ�� ");
            }
            else if (pre->type == 5)
            {
                printf("���ࣺʫ���� ");
            }
            printf("ISBN��Ϊ��%lld ", pre->Isbn);
            printf("����ʱ�䣺%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("״̬���ڿ�\n");
            }
            else if (pre->flag == 1)
            {
                printf("״̬���ѽ��\n");

            }
            b++;
        }
        pre = pre->next;

    }
    if (b == 0)
    {
        printf("���޴��飬����������");
    }
    fclose(fp);
    return head;
};
struct Book* jcwriter()//���߼򵥲�ѯ
{
    struct Book* head;
    head = (struct Book*)malloc(sizeof(struct Book));
    head->next = NULL;
    FILE* fp;
    char writername[50];
    printf("���������ߣ�");
    scanf("%s", writername);
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

        fscanf(fp, "%s ", book->name);
        fscanf(fp, "%s ", book->writer);
        fscanf(fp, "%c ", &book->f_letter);
        fscanf(fp, "%d ", &book->type);
        fscanf(fp, "%lld ", &book->Isbn);
        fscanf(fp, "%lld ", &book->p_date);
        fscanf(fp, "%d ", &book->flag);
        book->next = NULL;
        p->next = book;
        p = book;
    }
    struct Book* pre;
    pre = head;
    while (pre != NULL)
    {
        if (strcmp(pre->writer, writername) == 0)
        {
            printf("������%s ", pre->name);
            printf("���ߣ�%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("���ࣺ������ ");
            }
            else if (pre->type == 1)
            {
                printf("���ࣺ������ ");
            }
            else if (pre->type == 2)
            {
                printf("���ࣺС˵�� ");
            }
            else if (pre->type == 3)
            {
                printf("���ࣺ������ ");
            }
            else if (pre->type == 4)
            {
                printf("���ࣺ��ʷ�� ");
            }
            else if (pre->type == 5)
            {
                printf("���ࣺʫ���� ");
            }
            printf("ISBN��Ϊ��%lld ", pre->Isbn);
            printf("����ʱ�䣺%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("״̬���ڿ�\n");
            }
            else if (pre->flag == 1)
            {
                printf("״̬���ѽ��\n");

            }
            b++;
        }
        pre = pre->next;

    }
    if (b == 0)
    {
        printf("���޸����ߣ�����������");
    }
    fclose(fp);
    return head;
};
struct Book* jctype()//���򵥲�ѯ
{
    struct Book* head;
    head = (struct Book*)malloc(sizeof(struct Book));
    head->next = NULL;
    FILE* fp;
    char booktype[100];
    char a1[] = "������", a2[] = "������", a3[] = "С˵��", a4[] = "������", a5[] = "��ʷ��", a6[] = "ʫ����";

    int a = -1;
    do {
        printf("��������ࣺ");
        scanf("%s", booktype);
        if (strcmp(booktype, a1) == 0)
        {
            a = 0;
        }
        else if (strcmp(booktype, a2) == 0)
        {
            a = 1;
        }
        else if (strcmp(booktype, a3) == 0)
        {
            a = 2;
        }
        else if (strcmp(booktype, a4) == 0)
        {
            a = 3;
        }
        else if (strcmp(booktype, a5) == 0)
        {
            a = 4;
        }
        else  if (strcmp(booktype, a6) == 0)
        {
            a = 5;
        }

        if (a == -1)
        {
            printf("�޴����鼮������������\n");
            system("pause");
            system("cls");
        }
    } while (a == -1);

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

        fscanf(fp, "%s ", book->name);
        fscanf(fp, "%s ", book->writer);
        fscanf(fp, "%c ", &book->f_letter);
        fscanf(fp, "%d ", &book->type);
        fscanf(fp, "%lld ", &book->Isbn);
        fscanf(fp, "%lld ", &book->p_date);
        fscanf(fp, "%d ", &book->flag);
        book->next = NULL;
        p->next = book;
        p = book;
    }
    struct Book* pre;
    pre = head;
    int b = 0;
    while (pre != NULL)
    {
        if (pre->type == a)
        {
            printf("������%s ", pre->name);
            printf("���ߣ�%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("���ࣺ������ ");
            }
            else if (pre->type == 1)
            {
                printf("���ࣺ������ ");
            }
            else if (pre->type == 2)
            {
                printf("���ࣺС˵�� ");
            }
            else if (pre->type == 3)
            {
                printf("���ࣺ������ ");
            }
            else if (pre->type == 4)
            {
                printf("���ࣺ��ʷ�� ");
            }
            else if (pre->type == 5)
            {
                printf("���ࣺʫ���� ");
            }
            printf("ISBN��Ϊ��%lld ", pre->Isbn);
            printf("����ʱ�䣺%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("״̬���ڿ�\n");
            }
            else if (pre->flag == 1)
            {
                printf("״̬���ѽ��\n");

            }
            b++;


        }
        pre = pre->next;

    }if (b == 0)
    {
        printf("���޴��飬����������");
    }
    fclose(fp);
    return head;
}
struct Book* jcisbn()//isbn�򵥲�ѯ
{

    struct Book* head;
    head = (struct Book*)malloc(sizeof(struct Book));
    head->next = NULL;
    FILE* fp;
    long long isbn;
    printf("������isbn�룺");
    scanf("%lld", &isbn);
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

        fscanf(fp, "%s ", book->name);
        fscanf(fp, "%s ", book->writer);
        fscanf(fp, "%c ", &book->f_letter);
        fscanf(fp, "%d ", &book->type);
        fscanf(fp, "%lld ", &book->Isbn);
        fscanf(fp, "%lld ", &book->p_date);
        fscanf(fp, "%d ", &book->flag);
        book->next = NULL;
        p->next = book;
        p = book;
    }
    struct Book* pre;
    pre = head;
    int b = 0;
    while (pre != NULL)
    {

        if (pre->Isbn == isbn)
        {
            printf("������%s ", pre->name);
            printf("���ߣ�%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("���ࣺ������ ");
            }
            else if (pre->type == 1)
            {
                printf("���ࣺ������ ");
            }
            else if (pre->type == 2)
            {
                printf("���ࣺС˵�� ");
            }
            else if (pre->type == 3)
            {
                printf("���ࣺ������ ");
            }
            else if (pre->type == 4)
            {
                printf("���ࣺ��ʷ�� ");
            }
            else if (pre->type == 5)
            {
                printf("���ࣺʫ���� ");
            }
            printf("ISBN��Ϊ��%lld ", pre->Isbn);
            printf("����ʱ�䣺%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("״̬���ڿ�\n");
            }
            else if (pre->flag == 1)
            {
                printf("״̬���ѽ��\n");

            }
            b++;
        }
        pre = pre->next;

    }
    if (b == 0)
    {
        printf("���޴��飬����������");
    }
    fclose(fp);
    return head;
};
struct Book* jcdate()//�������ڼ򵥲�ѯ
{

    struct Book* head;
    head = (struct Book*)malloc(sizeof(struct Book));
    head->next = NULL;
    FILE* fp;
    long long date;
    printf("������������ڣ�");
    scanf("%lld", &date);
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

        fscanf(fp, "%s ", book->name);
        fscanf(fp, "%s ", book->writer);
        fscanf(fp, "%c ", &book->f_letter);
        fscanf(fp, "%d ", &book->type);
        fscanf(fp, "%lld ", &book->Isbn);
        fscanf(fp, "%lld ", &book->p_date);
        fscanf(fp, "%d ", &book->flag);
        book->next = NULL;
        p->next = book;
        p = book;
    }
    struct Book* pre;
    pre = head;
    int b = 0;
    while (pre != NULL)
    {

        if (pre->p_date == date)
        {
            printf("������%s ", pre->name);
            printf("���ߣ�%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("���ࣺ������ ");
            }
            else if (pre->type == 1)
            {
                printf("���ࣺ������ ");
            }
            else if (pre->type == 2)
            {
                printf("���ࣺС˵�� ");
            }
            else if (pre->type == 3)
            {
                printf("���ࣺ������ ");
            }
            else if (pre->type == 4)
            {
                printf("���ࣺ��ʷ�� ");
            }
            else if (pre->type == 5)
            {
                printf("���ࣺʫ���� ");
            }
            printf("ISBN��Ϊ��%lld ", pre->Isbn);
            printf("����ʱ�䣺%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("״̬���ڿ�\n");
            }
            else if (pre->flag == 1)
            {
                printf("״̬���ѽ��\n");

            }
            b++;
        }
        pre = pre->next;

    }
    if (b == 0)
    {
        printf("���޴��飬����������");
    }
    fclose(fp);
    return head;
};
struct Book* combsearch()//��ϲ�ѯ
{

}


