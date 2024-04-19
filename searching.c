#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>
//jc 为简单查询 zc为组合查询 mc为模糊查询 
typedef struct Book {
    char  name[100];//书名 
    char  writer[100];//作者名
    char f_letter;//拼音首字母
    int type;//书的种类，0 科普类 1 教育类 2 小说类 3 传记类 4 历史类 5 诗歌类
    long long Isbn;//书的ISBN码
    long long p_date;//出版日期
    int flag;//判断这本书有没有被借出
    struct Book* next;
}Book;

struct Book* jcbookname()//书名简单查询
{

    struct Book* head;
    head = (struct Book*)malloc(sizeof(struct Book));
    head->next = NULL;
    FILE* fp;
    char bookname[50];
    printf("请输入书名：");
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
            printf("书名：%s ", pre->name);
            printf("作者：%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("分类：科普类 ");
            }
            else if (pre->type == 1)
            {
                printf("分类：教育类 ");
            }
            else if (pre->type == 2)
            {
                printf("分类：小说类 ");
            }
            else if (pre->type == 3)
            {
                printf("分类：传记类 ");
            }
            else if (pre->type == 4)
            {
                printf("分类：历史类 ");
            }
            else if (pre->type == 5)
            {
                printf("分类：诗歌类 ");
            }
            printf("ISBN码为：%lld ", pre->Isbn);
            printf("出版时间：%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("状态：在库\n");
            }
            else if (pre->flag == 1)
            {
                printf("状态：已借出\n");

            }
            b++;
        }
        pre = pre->next;

    }
    if (b == 0)
    {
        printf("查无此书，请重新输入");
    }
    fclose(fp);
    return head;
};
struct Book* jcwriter()//作者简单查询
{
    struct Book* head;
    head = (struct Book*)malloc(sizeof(struct Book));
    head->next = NULL;
    FILE* fp;
    char writername[50];
    printf("请输入作者：");
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
            printf("书名：%s ", pre->name);
            printf("作者：%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("分类：科普类 ");
            }
            else if (pre->type == 1)
            {
                printf("分类：教育类 ");
            }
            else if (pre->type == 2)
            {
                printf("分类：小说类 ");
            }
            else if (pre->type == 3)
            {
                printf("分类：传记类 ");
            }
            else if (pre->type == 4)
            {
                printf("分类：历史类 ");
            }
            else if (pre->type == 5)
            {
                printf("分类：诗歌类 ");
            }
            printf("ISBN码为：%lld ", pre->Isbn);
            printf("出版时间：%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("状态：在库\n");
            }
            else if (pre->flag == 1)
            {
                printf("状态：已借出\n");

            }
            b++;
        }
        pre = pre->next;

    }
    if (b == 0)
    {
        printf("查无该作者，请重新输入");
    }
    fclose(fp);
    return head;
};
struct Book* jctype()//类别简单查询
{
    struct Book* head;
    head = (struct Book*)malloc(sizeof(struct Book));
    head->next = NULL;
    FILE* fp;
    char booktype[100];
    char a1[] = "科普类", a2[] = "教育类", a3[] = "小说类", a4[] = "传记类", a5[] = "历史类", a6[] = "诗歌类";

    int a = -1;
    do {
        printf("请输入分类：");
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
            printf("无此类书籍，请重新输入\n");
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
            printf("书名：%s ", pre->name);
            printf("作者：%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("分类：科普类 ");
            }
            else if (pre->type == 1)
            {
                printf("分类：教育类 ");
            }
            else if (pre->type == 2)
            {
                printf("分类：小说类 ");
            }
            else if (pre->type == 3)
            {
                printf("分类：传记类 ");
            }
            else if (pre->type == 4)
            {
                printf("分类：历史类 ");
            }
            else if (pre->type == 5)
            {
                printf("分类：诗歌类 ");
            }
            printf("ISBN码为：%lld ", pre->Isbn);
            printf("出版时间：%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("状态：在库\n");
            }
            else if (pre->flag == 1)
            {
                printf("状态：已借出\n");

            }
            b++;


        }
        pre = pre->next;

    }if (b == 0)
    {
        printf("查无此书，请重新输入");
    }
    fclose(fp);
    return head;
}
struct Book* jcisbn()//isbn简单查询
{

    struct Book* head;
    head = (struct Book*)malloc(sizeof(struct Book));
    head->next = NULL;
    FILE* fp;
    long long isbn;
    printf("请输入isbn码：");
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
            printf("书名：%s ", pre->name);
            printf("作者：%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("分类：科普类 ");
            }
            else if (pre->type == 1)
            {
                printf("分类：教育类 ");
            }
            else if (pre->type == 2)
            {
                printf("分类：小说类 ");
            }
            else if (pre->type == 3)
            {
                printf("分类：传记类 ");
            }
            else if (pre->type == 4)
            {
                printf("分类：历史类 ");
            }
            else if (pre->type == 5)
            {
                printf("分类：诗歌类 ");
            }
            printf("ISBN码为：%lld ", pre->Isbn);
            printf("出版时间：%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("状态：在库\n");
            }
            else if (pre->flag == 1)
            {
                printf("状态：已借出\n");

            }
            b++;
        }
        pre = pre->next;

    }
    if (b == 0)
    {
        printf("查无此书，请重新输入");
    }
    fclose(fp);
    return head;
};
struct Book* jcdate()//出版日期简单查询
{

    struct Book* head;
    head = (struct Book*)malloc(sizeof(struct Book));
    head->next = NULL;
    FILE* fp;
    long long date;
    printf("请输入出版日期：");
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
            printf("书名：%s ", pre->name);
            printf("作者：%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("分类：科普类 ");
            }
            else if (pre->type == 1)
            {
                printf("分类：教育类 ");
            }
            else if (pre->type == 2)
            {
                printf("分类：小说类 ");
            }
            else if (pre->type == 3)
            {
                printf("分类：传记类 ");
            }
            else if (pre->type == 4)
            {
                printf("分类：历史类 ");
            }
            else if (pre->type == 5)
            {
                printf("分类：诗歌类 ");
            }
            printf("ISBN码为：%lld ", pre->Isbn);
            printf("出版时间：%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("状态：在库\n");
            }
            else if (pre->flag == 1)
            {
                printf("状态：已借出\n");

            }
            b++;
        }
        pre = pre->next;

    }
    if (b == 0)
    {
        printf("查无此书，请重新输入");
    }
    fclose(fp);
    return head;
};
struct Book* combsearch()//组合查询
{

}


