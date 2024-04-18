#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>
//jc 为简单查询 zc为组合查询 mc为模糊查询 
typedef struct Book {
    char * name;//书名 
    char * writer;//作者名
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


