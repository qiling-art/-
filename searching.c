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

Book* jcbookname()//�����򵥲�ѯ
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
            printf("\t���ߣ�%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("\t���ࣺ������ ");
            }
            else if (pre->type == 1)
            {
                printf("\t���ࣺ������ ");
            }
            else if (pre->type == 2)
            {
                printf("\t���ࣺС˵�� ");
            }
            else if (pre->type == 3)
            {
                printf("\t���ࣺ������ ");
            }
            else if (pre->type == 4)
            {
                printf("\t���ࣺ��ʷ�� ");
            }
            else if (pre->type == 5)
            {
                printf("\t���ࣺʫ���� ");
            }
            printf("\tISBN��Ϊ��%lld ", pre->Isbn);
            printf("\t����ʱ�䣺%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("\t״̬���ڿ�\n");
            }
            else if (pre->flag == 1)
            {
                printf("\t״̬���ѽ��\n");

            }
            b++;
        }
        pre = pre->next;

    }
    if (b == 0)
    {
        printf("\t���޴��飬����������");
    }
    fclose(fp);
    return head;
};
Book* jcwriter(Book* head)//���߼򵥲�ѯ
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
    int b = 0;
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
            printf("\t���ߣ�%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("\t���ࣺ������ ");
            }
            else if (pre->type == 1)
            {
                printf("\t���ࣺ������ ");
            }
            else if (pre->type == 2)
            {
                printf("\t���ࣺС˵�� ");
            }
            else if (pre->type == 3)
            {
                printf("\t���ࣺ������ ");
            }
            else if (pre->type == 4)
            {
                printf("\t���ࣺ��ʷ�� ");
            }
            else if (pre->type == 5)
            {
                printf("\t���ࣺʫ���� ");
            }
            printf("\tISBN��Ϊ��%lld ", pre->Isbn);
            printf("\t����ʱ�䣺%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("\t״̬���ڿ�\n");
            }
            else if (pre->flag == 1)
            {
                printf("\t״̬���ѽ��\n");

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
Book* jctype()//���򵥲�ѯ
{
    struct Book* head;
    head = (struct Book*)malloc(sizeof(struct Book));
    head->next = NULL;
    FILE* fp;
    char booktype[100];
    char a1[] = "������", a2[] = "������", a3[] = "С˵��", a4[] = "������", a5[] = "��ʷ��", a6[] = "ʫ����";

    int a = -1;
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
            printf("\t���ߣ�%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("\t���ࣺ������ ");
            }
            else if (pre->type == 1)
            {
                printf("\t���ࣺ������ ");
            }
            else if (pre->type == 2)
            {
                printf("\t���ࣺС˵�� ");
            }
            else if (pre->type == 3)
            {
                printf("\t���ࣺ������ ");
            }
            else if (pre->type == 4)
            {
                printf("\t���ࣺ��ʷ�� ");
            }
            else if (pre->type == 5)
            {
                printf("\t���ࣺʫ���� ");
            }
            printf("\tISBN��Ϊ��%lld ", pre->Isbn);
            printf("\t����ʱ�䣺%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("\t״̬���ڿ�\n");
            }
            else if (pre->flag == 1)
            {
                printf("\t״̬���ѽ��\n");

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
            printf("\t���ߣ�%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("\t���ࣺ������ ");
            }
            else if (pre->type == 1)
            {
                printf("\t���ࣺ������ ");
            }
            else if (pre->type == 2)
            {
                printf("\t���ࣺС˵�� ");
            }
            else if (pre->type == 3)
            {
                printf("\t���ࣺ������ ");
            }
            else if (pre->type == 4)
            {
                printf("\t���ࣺ��ʷ�� ");
            }
            else if (pre->type == 5)
            {
                printf("\t���ࣺʫ���� ");
            }
            printf("\tISBN��Ϊ��%lld ", pre->Isbn);
            printf("\t����ʱ�䣺%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("\t״̬���ڿ�\n");
            }
            else if (pre->flag == 1)
            {
                printf("\t״̬���ѽ��\n");

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
            printf("\t���ߣ�%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("\t���ࣺ������ ");
            }
            else if (pre->type == 1)
            {
                printf("\t���ࣺ������ ");
            }
            else if (pre->type == 2)
            {
                printf("\t���ࣺС˵�� ");
            }
            else if (pre->type == 3)
            {
                printf("\t���ࣺ������ ");
            }
            else if (pre->type == 4)
            {
                printf("\t���ࣺ��ʷ�� ");
            }
            else if (pre->type == 5)
            {
                printf("\t���ࣺʫ���� ");
            }
            printf("\tISBN��Ϊ��%lld ", pre->Isbn);
            printf("\t����ʱ�䣺%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("\t״̬���ڿ�\n");
            }
            else if (pre->flag == 1)
            {
                printf("\t״̬���ѽ��\n");

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
    struct Book* head;
    head = (struct Book*)malloc(sizeof(struct Book));
    head->next = NULL;
    FILE* fp;
    fp = fopen("database.txt", "r+");
    if (fp == NULL)
    {
        printf("error\n");

    }
    int b = 0;
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


    int flagw = 0;//�ж��Ƿ�д�룬��������Ϊ1������Ϊ0��
    int flagt = 0;
    int flagd = 0;
    int flagf = 0;
    char p1[2] = "0";
    char p2 = '0';
    char writer[50] = "0";
    char booktype[50] = "0";
    long long date = 0;
    char fletter = '0';
    printf("��ѡ��������Ҫ���в�ѯ�ļ���������룬������������0\n");
    printf("���������ߣ�");
    scanf("%s", writer);
    //printf("\n");
    getchar();
    printf("���������");
    scanf("%s", booktype);
    getchar();
    printf("����������ĸ��");
    scanf("%c", &fletter);
    //printf("\n");
    getchar();
    printf("������������ڣ�");
    scanf("%lld", &date);
    //printf("\n");
    int a = -1;
    if (strcmp(writer, p1) != 0)
    {
        flagw = 1;
    }
    if (strcmp(booktype, p1) != 0)
    {
        flagt = 1;
        char a1[] = "������", a2[] = "������", a3[] = "С˵��", a4[] = "������", a5[] = "��ʷ��", a6[] = "ʫ����";


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


    }
    if (fletter != p2)
    {
        flagf = 1;
    }
    if (date != 0)
    {
        flagd = 1;
    }

    struct Book* pre;
    pre = head;
    /*printf("%d %d %d %d ", flagw, flagt, flagf, flagd);*/
    if (flagw == 1 && flagt == 0 && flagf == 0 && flagd == 0)//��ʼ����ж� ���� ���
    {
        while (pre != NULL)
        {
            if (strcmp(pre->writer, writer) == 0)
            {
                printf("������%s ", pre->name);
                printf("\t���ߣ�%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 1)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 2)
                {
                    printf("\t���ࣺС˵�� ");
                }
                else if (pre->type == 3)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 4)
                {
                    printf("\t���ࣺ��ʷ�� ");
                }
                else if (pre->type == 5)
                {
                    printf("\t���ࣺʫ���� ");
                }
                printf("\tISBN��Ϊ��%lld ", pre->Isbn);
                printf("\t����ʱ�䣺%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t״̬���ڿ�\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t״̬���ѽ��\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 0 && flagt == 1 && flagf == 0 && flagd == 0)//��ʼ����ж� ���� ���
    {
        while (pre != NULL)
        {
            if (pre->type == a)
            {
                printf("������%s ", pre->name);
                printf("\t���ߣ�%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 1)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 2)
                {
                    printf("\t���ࣺС˵�� ");
                }
                else if (pre->type == 3)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 4)
                {
                    printf("\t���ࣺ��ʷ�� ");
                }
                else if (pre->type == 5)
                {
                    printf("\t���ࣺʫ���� ");
                }
                printf("\tISBN��Ϊ��%lld ", pre->Isbn);
                printf("\t����ʱ�䣺%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t״̬���ڿ�\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t״̬���ѽ��\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 0 && flagt == 0 && flagf == 1 && flagd == 0)//��ʼ����ж� ���� ���
    {
        while (pre != NULL)
        {
            if (pre->f_letter == fletter)
            {
                printf("������%s ", pre->name);
                printf("\t���ߣ�%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 1)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 2)
                {
                    printf("\t���ࣺС˵�� ");
                }
                else if (pre->type == 3)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 4)
                {
                    printf("\t���ࣺ��ʷ�� ");
                }
                else if (pre->type == 5)
                {
                    printf("\t���ࣺʫ���� ");
                }
                printf("\tISBN��Ϊ��%lld ", pre->Isbn);
                printf("\t����ʱ�䣺%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t״̬���ڿ�\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t״̬���ѽ��\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 0 && flagt == 0 && flagf == 0 && flagd == 1)//��ʼ����ж� ���� ���
    {
        while (pre != NULL)
        {
            if (pre->p_date == date)
            {
                printf("������%s ", pre->name);
                printf("\t���ߣ�%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 1)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 2)
                {
                    printf("\t���ࣺС˵�� ");
                }
                else if (pre->type == 3)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 4)
                {
                    printf("\t���ࣺ��ʷ�� ");
                }
                else if (pre->type == 5)
                {
                    printf("\t���ࣺʫ���� ");
                }
                printf("\tISBN��Ϊ��%lld ", pre->Isbn);
                printf("\t����ʱ�䣺%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t״̬���ڿ�\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t״̬���ѽ��\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 1 && flagt == 1 && flagf == 0 && flagd == 0)//��ʼ����ж� ���� ���
    {
        while (pre != NULL)
        {
            if (strcmp(pre->writer, writer) == 0 && pre->type == a)
            {
                printf("������%s ", pre->name);
                printf("\t���ߣ�%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 1)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 2)
                {
                    printf("\t���ࣺС˵�� ");
                }
                else if (pre->type == 3)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 4)
                {
                    printf("\t���ࣺ��ʷ�� ");
                }
                else if (pre->type == 5)
                {
                    printf("\t���ࣺʫ���� ");
                }
                printf("\tISBN��Ϊ��%lld ", pre->Isbn);
                printf("\t����ʱ�䣺%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t״̬���ڿ�\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t״̬���ѽ��\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 1 && flagt == 0 && flagf == 1 && flagd == 0)//���� ����ĸ
    {
        /* printf("%s %s %c %lld", writer, booktype, fletter, date);*/
        while (pre != NULL)
        {
            if (strcmp(pre->writer, writer) == 0 && pre->f_letter == fletter)
            {
                printf("������%s ", pre->name);
                printf("\t���ߣ�%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 1)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 2)
                {
                    printf("\t���ࣺС˵�� ");
                }
                else if (pre->type == 3)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 4)
                {
                    printf("\t���ࣺ��ʷ�� ");
                }
                else if (pre->type == 5)
                {
                    printf("\t���ࣺʫ���� ");
                }
                printf("\tISBN��Ϊ��%lld ", pre->Isbn);
                printf("\t����ʱ�䣺%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t״̬���ڿ�\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t״̬���ѽ��\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 1 && flagt == 0 && flagf == 0 && flagd == 1)//���� ��������
    {
        while (pre != NULL)
        {
            if (strcmp(pre->writer, writer) == 0 && pre->p_date == date)
            {
                printf("������%s ", pre->name);
                printf("\t���ߣ�%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 1)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 2)
                {
                    printf("\t���ࣺС˵�� ");
                }
                else if (pre->type == 3)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 4)
                {
                    printf("\t���ࣺ��ʷ�� ");
                }
                else if (pre->type == 5)
                {
                    printf("\t���ࣺʫ���� ");
                }
                printf("\tISBN��Ϊ��%lld ", pre->Isbn);
                printf("\t����ʱ�䣺%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t״̬���ڿ�\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t״̬���ѽ��\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 0 && flagt == 1 && flagf == 1 && flagd == 0)//��� ����ĸ
    {
        while (pre != NULL)
        {
            if (pre->f_letter == fletter && pre->type == a)
            {
                printf("������%s ", pre->name);
                printf("\t���ߣ�%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 1)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 2)
                {
                    printf("\t���ࣺС˵�� ");
                }
                else if (pre->type == 3)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 4)
                {
                    printf("\t���ࣺ��ʷ�� ");
                }
                else if (pre->type == 5)
                {
                    printf("\t���ࣺʫ���� ");
                }
                printf("\tISBN��Ϊ��%lld ", pre->Isbn);
                printf("\t����ʱ�䣺%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t״̬���ڿ�\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t״̬���ѽ��\n");

                }

            }
            pre = pre->next;

        }
    }
    else if (flagw == 0 && flagt == 1 && flagf == 0 && flagd == 1)//��� ��������
    {
        while (pre != NULL)
        {
            if ((pre->p_date) == date && pre->type == a)
            {
                printf("������%s ", pre->name);
                printf("\t���ߣ�%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 1)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 2)
                {
                    printf("\t���ࣺС˵�� ");
                }
                else if (pre->type == 3)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 4)
                {
                    printf("\t���ࣺ��ʷ�� ");
                }
                else if (pre->type == 5)
                {
                    printf("\t���ࣺʫ���� ");
                }
                printf("\tISBN��Ϊ��%lld ", pre->Isbn);
                printf("\t����ʱ�䣺%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t״̬���ڿ�\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t״̬���ѽ��\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 0 && flagt == 0 && flagf == 1 && flagd == 1)//����ĸ ����ʱ��
    {
        while (pre != NULL)
        {
            if (pre->f_letter == fletter && pre->p_date == date)
            {
                printf("������%s ", pre->name);
                printf("\t���ߣ�%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 1)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 2)
                {
                    printf("\t���ࣺС˵�� ");
                }
                else if (pre->type == 3)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 4)
                {
                    printf("\t���ࣺ��ʷ�� ");
                }
                else if (pre->type == 5)
                {
                    printf("\t���ࣺʫ���� ");
                }
                printf("\tISBN��Ϊ��%lld ", pre->Isbn);
                printf("\t����ʱ�䣺%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t״̬���ڿ�\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t״̬���ѽ��\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 1 && flagt == 1 && flagf == 1 && flagd == 0)// ���� ��� ����ĸ
    {
        while (pre != NULL)
        {
            if (strcmp(pre->writer, writer) == 0 && pre->type == a && pre->f_letter == fletter)
            {
                printf("������%s ", pre->name);
                printf("\t���ߣ�%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 1)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 2)
                {
                    printf("\t���ࣺС˵�� ");
                }
                else if (pre->type == 3)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 4)
                {
                    printf("\t���ࣺ��ʷ�� ");
                }
                else if (pre->type == 5)
                {
                    printf("\t���ࣺʫ���� ");
                }
                printf("\tISBN��Ϊ��%lld ", pre->Isbn);
                printf("\t����ʱ�䣺%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t״̬���ڿ�\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t״̬���ѽ��\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 1 && flagt == 1 && flagf == 0 && flagd == 1)//���� ��� ��������
    {
        while (pre != NULL)
        {
            if (strcmp(pre->writer, writer) == 0 && pre->type == a && pre->p_date == date)
            {
                printf("������%s ", pre->name);
                printf("\t���ߣ�%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 1)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 2)
                {
                    printf("\t���ࣺС˵�� ");
                }
                else if (pre->type == 3)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 4)
                {
                    printf("\t���ࣺ��ʷ�� ");
                }
                else if (pre->type == 5)
                {
                    printf("\t���ࣺʫ���� ");
                }
                printf("\tISBN��Ϊ��%lld ", pre->Isbn);
                printf("\t����ʱ�䣺%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t״̬���ڿ�\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t״̬���ѽ��\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 1 && flagt == 0 && flagf == 1 && flagd == 1)//���� ����ĸ ��������
    {
        while (pre != NULL)
        {


            if ((strcmp(pre->writer, writer) == 0) && (pre->p_date == date) && (pre->f_letter == fletter))
            {
                printf("������%s ", pre->name);
                printf("\t���ߣ�%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 1)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 2)
                {
                    printf("\t���ࣺС˵�� ");
                }
                else if (pre->type == 3)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 4)
                {
                    printf("\t���ࣺ��ʷ�� ");
                }
                else if (pre->type == 5)
                {
                    printf("\t���ࣺʫ���� ");
                }
                printf("\tISBN��Ϊ��%lld ", pre->Isbn);
                printf("\t����ʱ�䣺%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t״̬���ڿ�\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t״̬���ѽ��\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 0 && flagt == 1 && flagf == 1 && flagd == 1)//��� ����ĸ ��������
    {
        while (pre != NULL)
        {
            if (pre->f_letter == fletter && pre->type == a && pre->p_date == date)
            {
                printf("������%s ", pre->name);
                printf("\t���ߣ�%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 1)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 2)
                {
                    printf("\t���ࣺС˵�� ");
                }
                else if (pre->type == 3)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 4)
                {
                    printf("\t���ࣺ��ʷ�� ");
                }
                else if (pre->type == 5)
                {
                    printf("\t���ࣺʫ���� ");
                }
                printf("\tISBN��Ϊ��%lld ", pre->Isbn);
                printf("\t����ʱ�䣺%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t״̬���ڿ�\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t״̬���ѽ��\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 1 && flagt == 1 && flagf == 1 && flagd == 1)//���� ��� ����ĸ ��������
    {

        while (pre != NULL)
        {
            if (strcmp(pre->writer, writer) == 0 && pre->type == a && pre->f_letter == fletter && pre->p_date == date)
            {
                printf("������%s ", pre->name);
                printf("\t���ߣ�%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 1)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 2)
                {
                    printf("\t���ࣺС˵�� ");
                }
                else if (pre->type == 3)
                {
                    printf("\t���ࣺ������ ");
                }
                else if (pre->type == 4)
                {
                    printf("\t���ࣺ��ʷ�� ");
                }
                else if (pre->type == 5)
                {
                    printf("\t���ࣺʫ���� ");
                }
                printf("\tISBN��Ϊ��%lld ", pre->Isbn);
                printf("\t����ʱ�䣺%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t״̬���ڿ�\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t״̬���ѽ��\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    if (b == 0)
    {
        printf("���޴��飬����������");
    }

    return head;
}

int main() {

}


