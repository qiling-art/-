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

Book* jcbookname()//书名简单查询
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
            printf("\t作者：%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("\t分类：科普类 ");
            }
            else if (pre->type == 1)
            {
                printf("\t分类：教育类 ");
            }
            else if (pre->type == 2)
            {
                printf("\t分类：小说类 ");
            }
            else if (pre->type == 3)
            {
                printf("\t分类：传记类 ");
            }
            else if (pre->type == 4)
            {
                printf("\t分类：历史类 ");
            }
            else if (pre->type == 5)
            {
                printf("\t分类：诗歌类 ");
            }
            printf("\tISBN码为：%lld ", pre->Isbn);
            printf("\t出版时间：%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("\t状态：在库\n");
            }
            else if (pre->flag == 1)
            {
                printf("\t状态：已借出\n");

            }
            b++;
        }
        pre = pre->next;

    }
    if (b == 0)
    {
        printf("\t查无此书，请重新输入");
    }
    fclose(fp);
    return head;
};
Book* jcwriter(Book* head)//作者简单查询
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
            printf("书名：%s ", pre->name);
            printf("\t作者：%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("\t分类：科普类 ");
            }
            else if (pre->type == 1)
            {
                printf("\t分类：教育类 ");
            }
            else if (pre->type == 2)
            {
                printf("\t分类：小说类 ");
            }
            else if (pre->type == 3)
            {
                printf("\t分类：传记类 ");
            }
            else if (pre->type == 4)
            {
                printf("\t分类：历史类 ");
            }
            else if (pre->type == 5)
            {
                printf("\t分类：诗歌类 ");
            }
            printf("\tISBN码为：%lld ", pre->Isbn);
            printf("\t出版时间：%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("\t状态：在库\n");
            }
            else if (pre->flag == 1)
            {
                printf("\t状态：已借出\n");

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
Book* jctype()//类别简单查询
{
    struct Book* head;
    head = (struct Book*)malloc(sizeof(struct Book));
    head->next = NULL;
    FILE* fp;
    char booktype[100];
    char a1[] = "科普类", a2[] = "教育类", a3[] = "小说类", a4[] = "传记类", a5[] = "历史类", a6[] = "诗歌类";

    int a = -1;
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
            printf("\t作者：%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("\t分类：科普类 ");
            }
            else if (pre->type == 1)
            {
                printf("\t分类：教育类 ");
            }
            else if (pre->type == 2)
            {
                printf("\t分类：小说类 ");
            }
            else if (pre->type == 3)
            {
                printf("\t分类：传记类 ");
            }
            else if (pre->type == 4)
            {
                printf("\t分类：历史类 ");
            }
            else if (pre->type == 5)
            {
                printf("\t分类：诗歌类 ");
            }
            printf("\tISBN码为：%lld ", pre->Isbn);
            printf("\t出版时间：%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("\t状态：在库\n");
            }
            else if (pre->flag == 1)
            {
                printf("\t状态：已借出\n");

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
            printf("\t作者：%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("\t分类：科普类 ");
            }
            else if (pre->type == 1)
            {
                printf("\t分类：教育类 ");
            }
            else if (pre->type == 2)
            {
                printf("\t分类：小说类 ");
            }
            else if (pre->type == 3)
            {
                printf("\t分类：传记类 ");
            }
            else if (pre->type == 4)
            {
                printf("\t分类：历史类 ");
            }
            else if (pre->type == 5)
            {
                printf("\t分类：诗歌类 ");
            }
            printf("\tISBN码为：%lld ", pre->Isbn);
            printf("\t出版时间：%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("\t状态：在库\n");
            }
            else if (pre->flag == 1)
            {
                printf("\t状态：已借出\n");

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
            printf("\t作者：%s ", pre->writer);
            if (pre->type == 0)
            {
                printf("\t分类：科普类 ");
            }
            else if (pre->type == 1)
            {
                printf("\t分类：教育类 ");
            }
            else if (pre->type == 2)
            {
                printf("\t分类：小说类 ");
            }
            else if (pre->type == 3)
            {
                printf("\t分类：传记类 ");
            }
            else if (pre->type == 4)
            {
                printf("\t分类：历史类 ");
            }
            else if (pre->type == 5)
            {
                printf("\t分类：诗歌类 ");
            }
            printf("\tISBN码为：%lld ", pre->Isbn);
            printf("\t出版时间：%lld ", pre->p_date);
            if (pre->flag == 0)
            {
                printf("\t状态：在库\n");
            }
            else if (pre->flag == 1)
            {
                printf("\t状态：已借出\n");

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


    int flagw = 0;//判断是否写入，有输入则为1，无则为0；
    int flagt = 0;
    int flagd = 0;
    int flagf = 0;
    char p1[2] = "0";
    char p2 = '0';
    char writer[50] = "0";
    char booktype[50] = "0";
    long long date = 0;
    char fletter = '0';
    printf("请选择其中想要进行查询的几项进行输入，其余项请输入0\n");
    printf("请输入作者：");
    scanf("%s", writer);
    //printf("\n");
    getchar();
    printf("请输入类别：");
    scanf("%s", booktype);
    getchar();
    printf("请输入首字母：");
    scanf("%c", &fletter);
    //printf("\n");
    getchar();
    printf("请输入出版日期：");
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
        char a1[] = "科普类", a2[] = "教育类", a3[] = "小说类", a4[] = "传记类", a5[] = "历史类", a6[] = "诗歌类";


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
    if (flagw == 1 && flagt == 0 && flagf == 0 && flagd == 0)//开始组合判断 作者 类别
    {
        while (pre != NULL)
        {
            if (strcmp(pre->writer, writer) == 0)
            {
                printf("书名：%s ", pre->name);
                printf("\t作者：%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t分类：科普类 ");
                }
                else if (pre->type == 1)
                {
                    printf("\t分类：教育类 ");
                }
                else if (pre->type == 2)
                {
                    printf("\t分类：小说类 ");
                }
                else if (pre->type == 3)
                {
                    printf("\t分类：传记类 ");
                }
                else if (pre->type == 4)
                {
                    printf("\t分类：历史类 ");
                }
                else if (pre->type == 5)
                {
                    printf("\t分类：诗歌类 ");
                }
                printf("\tISBN码为：%lld ", pre->Isbn);
                printf("\t出版时间：%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t状态：在库\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t状态：已借出\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 0 && flagt == 1 && flagf == 0 && flagd == 0)//开始组合判断 作者 类别
    {
        while (pre != NULL)
        {
            if (pre->type == a)
            {
                printf("书名：%s ", pre->name);
                printf("\t作者：%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t分类：科普类 ");
                }
                else if (pre->type == 1)
                {
                    printf("\t分类：教育类 ");
                }
                else if (pre->type == 2)
                {
                    printf("\t分类：小说类 ");
                }
                else if (pre->type == 3)
                {
                    printf("\t分类：传记类 ");
                }
                else if (pre->type == 4)
                {
                    printf("\t分类：历史类 ");
                }
                else if (pre->type == 5)
                {
                    printf("\t分类：诗歌类 ");
                }
                printf("\tISBN码为：%lld ", pre->Isbn);
                printf("\t出版时间：%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t状态：在库\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t状态：已借出\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 0 && flagt == 0 && flagf == 1 && flagd == 0)//开始组合判断 作者 类别
    {
        while (pre != NULL)
        {
            if (pre->f_letter == fletter)
            {
                printf("书名：%s ", pre->name);
                printf("\t作者：%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t分类：科普类 ");
                }
                else if (pre->type == 1)
                {
                    printf("\t分类：教育类 ");
                }
                else if (pre->type == 2)
                {
                    printf("\t分类：小说类 ");
                }
                else if (pre->type == 3)
                {
                    printf("\t分类：传记类 ");
                }
                else if (pre->type == 4)
                {
                    printf("\t分类：历史类 ");
                }
                else if (pre->type == 5)
                {
                    printf("\t分类：诗歌类 ");
                }
                printf("\tISBN码为：%lld ", pre->Isbn);
                printf("\t出版时间：%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t状态：在库\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t状态：已借出\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 0 && flagt == 0 && flagf == 0 && flagd == 1)//开始组合判断 作者 类别
    {
        while (pre != NULL)
        {
            if (pre->p_date == date)
            {
                printf("书名：%s ", pre->name);
                printf("\t作者：%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t分类：科普类 ");
                }
                else if (pre->type == 1)
                {
                    printf("\t分类：教育类 ");
                }
                else if (pre->type == 2)
                {
                    printf("\t分类：小说类 ");
                }
                else if (pre->type == 3)
                {
                    printf("\t分类：传记类 ");
                }
                else if (pre->type == 4)
                {
                    printf("\t分类：历史类 ");
                }
                else if (pre->type == 5)
                {
                    printf("\t分类：诗歌类 ");
                }
                printf("\tISBN码为：%lld ", pre->Isbn);
                printf("\t出版时间：%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t状态：在库\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t状态：已借出\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 1 && flagt == 1 && flagf == 0 && flagd == 0)//开始组合判断 作者 类别
    {
        while (pre != NULL)
        {
            if (strcmp(pre->writer, writer) == 0 && pre->type == a)
            {
                printf("书名：%s ", pre->name);
                printf("\t作者：%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t分类：科普类 ");
                }
                else if (pre->type == 1)
                {
                    printf("\t分类：教育类 ");
                }
                else if (pre->type == 2)
                {
                    printf("\t分类：小说类 ");
                }
                else if (pre->type == 3)
                {
                    printf("\t分类：传记类 ");
                }
                else if (pre->type == 4)
                {
                    printf("\t分类：历史类 ");
                }
                else if (pre->type == 5)
                {
                    printf("\t分类：诗歌类 ");
                }
                printf("\tISBN码为：%lld ", pre->Isbn);
                printf("\t出版时间：%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t状态：在库\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t状态：已借出\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 1 && flagt == 0 && flagf == 1 && flagd == 0)//作者 首字母
    {
        /* printf("%s %s %c %lld", writer, booktype, fletter, date);*/
        while (pre != NULL)
        {
            if (strcmp(pre->writer, writer) == 0 && pre->f_letter == fletter)
            {
                printf("书名：%s ", pre->name);
                printf("\t作者：%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t分类：科普类 ");
                }
                else if (pre->type == 1)
                {
                    printf("\t分类：教育类 ");
                }
                else if (pre->type == 2)
                {
                    printf("\t分类：小说类 ");
                }
                else if (pre->type == 3)
                {
                    printf("\t分类：传记类 ");
                }
                else if (pre->type == 4)
                {
                    printf("\t分类：历史类 ");
                }
                else if (pre->type == 5)
                {
                    printf("\t分类：诗歌类 ");
                }
                printf("\tISBN码为：%lld ", pre->Isbn);
                printf("\t出版时间：%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t状态：在库\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t状态：已借出\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 1 && flagt == 0 && flagf == 0 && flagd == 1)//作者 出版日期
    {
        while (pre != NULL)
        {
            if (strcmp(pre->writer, writer) == 0 && pre->p_date == date)
            {
                printf("书名：%s ", pre->name);
                printf("\t作者：%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t分类：科普类 ");
                }
                else if (pre->type == 1)
                {
                    printf("\t分类：教育类 ");
                }
                else if (pre->type == 2)
                {
                    printf("\t分类：小说类 ");
                }
                else if (pre->type == 3)
                {
                    printf("\t分类：传记类 ");
                }
                else if (pre->type == 4)
                {
                    printf("\t分类：历史类 ");
                }
                else if (pre->type == 5)
                {
                    printf("\t分类：诗歌类 ");
                }
                printf("\tISBN码为：%lld ", pre->Isbn);
                printf("\t出版时间：%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t状态：在库\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t状态：已借出\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 0 && flagt == 1 && flagf == 1 && flagd == 0)//类别 首字母
    {
        while (pre != NULL)
        {
            if (pre->f_letter == fletter && pre->type == a)
            {
                printf("书名：%s ", pre->name);
                printf("\t作者：%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t分类：科普类 ");
                }
                else if (pre->type == 1)
                {
                    printf("\t分类：教育类 ");
                }
                else if (pre->type == 2)
                {
                    printf("\t分类：小说类 ");
                }
                else if (pre->type == 3)
                {
                    printf("\t分类：传记类 ");
                }
                else if (pre->type == 4)
                {
                    printf("\t分类：历史类 ");
                }
                else if (pre->type == 5)
                {
                    printf("\t分类：诗歌类 ");
                }
                printf("\tISBN码为：%lld ", pre->Isbn);
                printf("\t出版时间：%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t状态：在库\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t状态：已借出\n");

                }

            }
            pre = pre->next;

        }
    }
    else if (flagw == 0 && flagt == 1 && flagf == 0 && flagd == 1)//类别 出版日期
    {
        while (pre != NULL)
        {
            if ((pre->p_date) == date && pre->type == a)
            {
                printf("书名：%s ", pre->name);
                printf("\t作者：%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t分类：科普类 ");
                }
                else if (pre->type == 1)
                {
                    printf("\t分类：教育类 ");
                }
                else if (pre->type == 2)
                {
                    printf("\t分类：小说类 ");
                }
                else if (pre->type == 3)
                {
                    printf("\t分类：传记类 ");
                }
                else if (pre->type == 4)
                {
                    printf("\t分类：历史类 ");
                }
                else if (pre->type == 5)
                {
                    printf("\t分类：诗歌类 ");
                }
                printf("\tISBN码为：%lld ", pre->Isbn);
                printf("\t出版时间：%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t状态：在库\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t状态：已借出\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 0 && flagt == 0 && flagf == 1 && flagd == 1)//首字母 出版时间
    {
        while (pre != NULL)
        {
            if (pre->f_letter == fletter && pre->p_date == date)
            {
                printf("书名：%s ", pre->name);
                printf("\t作者：%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t分类：科普类 ");
                }
                else if (pre->type == 1)
                {
                    printf("\t分类：教育类 ");
                }
                else if (pre->type == 2)
                {
                    printf("\t分类：小说类 ");
                }
                else if (pre->type == 3)
                {
                    printf("\t分类：传记类 ");
                }
                else if (pre->type == 4)
                {
                    printf("\t分类：历史类 ");
                }
                else if (pre->type == 5)
                {
                    printf("\t分类：诗歌类 ");
                }
                printf("\tISBN码为：%lld ", pre->Isbn);
                printf("\t出版时间：%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t状态：在库\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t状态：已借出\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 1 && flagt == 1 && flagf == 1 && flagd == 0)// 作者 类别 首字母
    {
        while (pre != NULL)
        {
            if (strcmp(pre->writer, writer) == 0 && pre->type == a && pre->f_letter == fletter)
            {
                printf("书名：%s ", pre->name);
                printf("\t作者：%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t分类：科普类 ");
                }
                else if (pre->type == 1)
                {
                    printf("\t分类：教育类 ");
                }
                else if (pre->type == 2)
                {
                    printf("\t分类：小说类 ");
                }
                else if (pre->type == 3)
                {
                    printf("\t分类：传记类 ");
                }
                else if (pre->type == 4)
                {
                    printf("\t分类：历史类 ");
                }
                else if (pre->type == 5)
                {
                    printf("\t分类：诗歌类 ");
                }
                printf("\tISBN码为：%lld ", pre->Isbn);
                printf("\t出版时间：%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t状态：在库\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t状态：已借出\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 1 && flagt == 1 && flagf == 0 && flagd == 1)//作者 类别 出版日期
    {
        while (pre != NULL)
        {
            if (strcmp(pre->writer, writer) == 0 && pre->type == a && pre->p_date == date)
            {
                printf("书名：%s ", pre->name);
                printf("\t作者：%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t分类：科普类 ");
                }
                else if (pre->type == 1)
                {
                    printf("\t分类：教育类 ");
                }
                else if (pre->type == 2)
                {
                    printf("\t分类：小说类 ");
                }
                else if (pre->type == 3)
                {
                    printf("\t分类：传记类 ");
                }
                else if (pre->type == 4)
                {
                    printf("\t分类：历史类 ");
                }
                else if (pre->type == 5)
                {
                    printf("\t分类：诗歌类 ");
                }
                printf("\tISBN码为：%lld ", pre->Isbn);
                printf("\t出版时间：%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t状态：在库\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t状态：已借出\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 1 && flagt == 0 && flagf == 1 && flagd == 1)//作者 首字母 出版日期
    {
        while (pre != NULL)
        {


            if ((strcmp(pre->writer, writer) == 0) && (pre->p_date == date) && (pre->f_letter == fletter))
            {
                printf("书名：%s ", pre->name);
                printf("\t作者：%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t分类：科普类 ");
                }
                else if (pre->type == 1)
                {
                    printf("\t分类：教育类 ");
                }
                else if (pre->type == 2)
                {
                    printf("\t分类：小说类 ");
                }
                else if (pre->type == 3)
                {
                    printf("\t分类：传记类 ");
                }
                else if (pre->type == 4)
                {
                    printf("\t分类：历史类 ");
                }
                else if (pre->type == 5)
                {
                    printf("\t分类：诗歌类 ");
                }
                printf("\tISBN码为：%lld ", pre->Isbn);
                printf("\t出版时间：%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t状态：在库\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t状态：已借出\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 0 && flagt == 1 && flagf == 1 && flagd == 1)//类别 首字母 出版日期
    {
        while (pre != NULL)
        {
            if (pre->f_letter == fletter && pre->type == a && pre->p_date == date)
            {
                printf("书名：%s ", pre->name);
                printf("\t作者：%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t分类：科普类 ");
                }
                else if (pre->type == 1)
                {
                    printf("\t分类：教育类 ");
                }
                else if (pre->type == 2)
                {
                    printf("\t分类：小说类 ");
                }
                else if (pre->type == 3)
                {
                    printf("\t分类：传记类 ");
                }
                else if (pre->type == 4)
                {
                    printf("\t分类：历史类 ");
                }
                else if (pre->type == 5)
                {
                    printf("\t分类：诗歌类 ");
                }
                printf("\tISBN码为：%lld ", pre->Isbn);
                printf("\t出版时间：%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t状态：在库\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t状态：已借出\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    else if (flagw == 1 && flagt == 1 && flagf == 1 && flagd == 1)//作者 类别 首字母 出版日期
    {

        while (pre != NULL)
        {
            if (strcmp(pre->writer, writer) == 0 && pre->type == a && pre->f_letter == fletter && pre->p_date == date)
            {
                printf("书名：%s ", pre->name);
                printf("\t作者：%s ", pre->writer);
                if (pre->type == 0)
                {
                    printf("\t分类：科普类 ");
                }
                else if (pre->type == 1)
                {
                    printf("\t分类：教育类 ");
                }
                else if (pre->type == 2)
                {
                    printf("\t分类：小说类 ");
                }
                else if (pre->type == 3)
                {
                    printf("\t分类：传记类 ");
                }
                else if (pre->type == 4)
                {
                    printf("\t分类：历史类 ");
                }
                else if (pre->type == 5)
                {
                    printf("\t分类：诗歌类 ");
                }
                printf("\tISBN码为：%lld ", pre->Isbn);
                printf("\t出版时间：%lld ", pre->p_date);
                if (pre->flag == 0)
                {
                    printf("\t状态：在库\n");
                }
                else if (pre->flag == 1)
                {
                    printf("\t状态：已借出\n");

                }
                b++;
            }
            pre = pre->next;

        }
    }
    if (b == 0)
    {
        printf("查无此书，请重新输入");
    }

    return head;
}

int main() {

}


