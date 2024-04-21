#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Book Book;

typedef struct Record Record;

typedef struct User User;

typedef struct Administrator Admin;

Book* broot;
Record* reroot;
User* uroot;
Admin* aroot;


Book* Create_Book(Book* node, char name[], char writer[], char f_letter, int type, long long Isbn, long long date, int flag);
User* Create_User(User* node, char name[], int type, char f_letter, long long password, long long account, int num);
Admin* Create_Admin(Admin* node, char name[], char f_letter, long long password, long long account);
void Load_Infor(char fileb[], char fileu[], char filea[]);
int Borrow(char uname[], long long account, char bname[], User* u_root, Book* b_root, long long date);
int Return(char uname[], long long account, char bname[], long long isbn, User* u_root, Book* b_root);
int U_Maintain(long long account, long long password, User* u_root);
void Print_Record(char name[], long long account, User* u_root);
int Search_Record(char uname[], long long account, char bname[], User* u_root);
int Count(char uname[], long long account, User* u_root);
Record* merge(Record* left, Record* right);
Record* sort(Record* head, int n);
void Sort_Record(char uname[], long long account, User* u_root);
void Writer_Search(Book* b_root);
void Book_Search(Book* b_root);
void Elastic_Search(Book* b_root);
int Search_All_Record(Book k);
int Search_Type_Record(int type);
Record* All_sort(Record* head);
int A_Maintain(long long account, long long password, Admin* a_root);
int Reset_Password(long long account);
int copyFile(char* fileRead, char* fileWrite);
void File_Cope(char* fileRead, char* fileWrite);
void AdjustBookType(Book* head, char name[], int new_type);//���ú͵���ͼ����������
void AdjustBookBTime(int old_type, int new_time);//���ú͵���ÿ��ͼ��Ľ���ʱ��
void AdjustUserType(User* head, char name[], int new_type);//���ú͵���������������
void AdjustUserBTime(int old_type, int new_time);//���ú͵���ÿ����ߵĽ���ʱ��
void AddBook(Book* head, char name[], char writer[], char f_letter, int type, long long Isbn, long long p_date);//����ͼ����Ϣ
void AddUser(User* head, char name[], int type, char f_letter, long long password, long long account);//���Ӷ�����Ϣ
void DeleteBook(Book* head, char name[]);//ɾ��ͼ����Ϣ
void DeleteUser(User* head, char name[]);//ɾ��������Ϣ
void ModifyBook(Book* head, char name[], int new_type);//�޸�ͼ����Ϣ
void ModifyUser(User* head, long long account, int new_type);//�޸Ķ�����Ϣ