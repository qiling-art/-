#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int BookType[6] = { 30, 30, 30, 30, 30, 30 };//��������Խ��ĵ�ʱ��
int UserType[3] = { 20, 25, 30 };//��ͬ���߿��Խ��ĵ�ͼ������

typedef struct Book {
    char name[100];//����
    char writer[100];//������
    char f_letter;//ƴ������ĸ
    int type;//������࣬0 ������ 1 ������ 2 С˵�� 3 ������ 4 ��ʷ�� 5 ʫ����
    long long Isbn;//���ISBN��s
    long long p_date;//��������
    int flag;//�ж��Ȿ����û�б����
    struct Book* next;
}Book;

typedef struct Record {
    Book book;//���ĵ����������Ϣ
    long long date;//���ĵ�ʱ��
   struct Record* next;
}Record;

typedef struct User {
    char name[100];//��������
    int type;//�������� 0 ������ 1 �о��� 2 ��ʿ��
    char f_letter;//��������ƴ������ĸ
    long long password;//���ߵ�����
    long long account;//���ߵ��˺�
    int num;//�ѽ��ĵ��������
    Record* record;//���������洢��������Щ��
    struct User* next;
}User;

typedef struct Administrator {
    char name[100];//����Ա����
    char f_letter;//����Ա����ƴ������ĸ
    long long password;//����Ա����
    long long account;//����Ա�˺�
    struct Administrator* next;
}Admin;

Book* broot=NULL;
Record* reroot=NULL;
User* uroot=NULL;
Admin* aroot=NULL;
void Window();//�û�������ʾ
void Function();//ϵͳѡ��
void Window1();//ͼ�����Աϵͳ����
void Window2();//ѧ��ϵͳ����

void Function1();//ͼ�����Ա��¼
void Function2();//ѧ����¼
void Adland();

void Adxinjian();
void Adxiugai();
void Stland();
void Stxinjian();
void Stxiugai(); 
void  BaseInforMain();
int Admatch(long long account, long long password);
void DeleteUser(User* head, char name[]);//ɾ��������Ϣ
void ModifyUser(User* head, long long account, int new_type);//�޸Ķ�����Ϣ
void DeleteBook(Book* head, char name[]);//ɾ��ͼ����Ϣ
void AddUser(User* head, char name[], int type, char f_letter, long long password, long long account);//���Ӷ�����Ϣ
void AddUser(User* head, char name[], int type, char f_letter, long long password, long long account)//���Ӷ�����Ϣ
{
    User* newUser = (User*)malloc(sizeof(User));// ��̬����һ���µ�User�ڵ�
    strcpy(newUser->name, name);// ����name�ֶ�
    newUser->type = type;// ���������ֶ�
    newUser->f_letter = f_letter;
    newUser->password = password;
    newUser->account = account;
    newUser->num = 0;
    newUser->next = head;// ���½ڵ���뵽����ͷ��
    head = newUser;
}
void DeleteBook(Book* head, char name[])//ɾ��ͼ����Ϣ
{
    Book* current = head;
    Book* prev = NULL;
    while (current != NULL && strcmp(current->name, name) != 0)// ��������
    {
        prev = current;
        current = current->next;

    }
    if (current == NULL)// ���δ�ҵ�ͼ��
    {
        printf("���޴���\n");
        return;
    }
    if (prev == NULL)// ���Ҫɾ���Ľڵ���ͷ�ڵ�
    {
        head = current->next;
    }
    else // ���򣬽�ǰһ���ڵ��nextָ��ǰ�ڵ����һ���ڵ�
    {
        prev->next = current->next;
    }
}
void DeleteUser(User* head, char name[])//ɾ��������Ϣ
{
    User* current = head; // ��ǰ�������û�ָ��
    User* prev = NULL;  // ǰһ���û�ָ��
    while (current != NULL && strcmp(current->name, name) != 0) // ��������
    {
        prev = current;// ����ǰһ���û�ָ��
        current = current->next;// �ƶ�����һ���û�
    }
    if (current == NULL) // �����ǰ�û�Ϊ��
    {
        printf("���޴���\n");
        return;
    }
    if (prev == NULL) // ���Ҫɾ������ͷ�ڵ�
    {
        head = current->next; // ����ͷ�ڵ�Ϊ��һ���û�
    }
    else {
        prev->next = current->next; // ����ָ��ǰ�û�����һ���û�
    }
}
void ModifyUser(User* head, long long account, int new_type)//�޸Ķ�����Ϣ
{
    User* current = head;// ��ǰ�������û�ָ��
    User* prev = NULL; // ǰһ���û�ָ��
    while (current != NULL)// ��������
    {
        if (current->account == account) {
            current->type = new_type;
            return;
        }
        prev = current;
        current = current->next;// �ƶ�����һ���ڵ�
    }
}



int Admatch(long long m, long long a)//ƥ�����ݿ��е��˺�����
{
    FILE* fp;
    int n = 0, i = 0;
    long long zhanghao;
    long long  password;

    if ((fp = fopen("Adland.txt", "r")) == NULL)
    {
        system("cls");
        printf("\n ��δ�����û�!���½��˻�");
        _getch();
        system("cls");
        Function1();
    }
    else
    {
        for (; !feof(fp);)
        {
            fscanf(fp, "%lld %lld", &zhanghao, &password);
            if (m == zhanghao)
            {
                if (a == password)
                    return 1;
                else
                {
                    return -1;
                }
            }
        }
        fclose(fp); // �ر��ļ�
        return 0;
    }
}

void Window()
{
    printf("\n\n\t    ��ӭʹ��ͼ�����ϵͳ\n\n");
    printf("**********************************************");
    printf("\n\n\t\t��ѡ��ϵͳ\n\n");
    printf("\n\n\t\t1.ͼ�����Աϵͳ\n\n");
    printf("\n\n\t\t2.ѧ��ϵͳ\n\n");
    printf("\n\n\t\t3.�˳�ϵͳ\n\n");
    printf("\n\n\t    �밴��ѡ�񣬻س�ȷ��\n");
    printf("**********************************************\n");
    return;
 }
void Window1()
{
    printf("\n\n\t    ��ӭʹ��ͼ�����Ա��¼ϵͳ\n\n");
    printf("**********************************************");
    printf("\n\n\t\t1.��¼ϵͳ\n\n");
    printf("\n\n\t\t2.�����˺�\n\n");
    printf("\n\n\t\t3.�޸�����\n\n");
    printf("\n\n\t\t4.�˳�ϵͳ\n\n");
    printf("\n\n\t    �밴��ѡ�񣬻س�ȷ��\n");
    printf("**********************************************\n");
    return;
}
void Window2()
{
    printf("\n\n\t    ��ӭʹ��ѧ��ϵͳ\n\n");
    printf("**********************************************");
    printf("\n\n\t\t1.��¼ϵͳ\n\n");
    printf("\n\n\t\t2.�����˺�\n\n");
    printf("\n\n\t\t3.�޸�����\n\n");
    printf("\n\n\t\t4.�˳�ϵͳ\n\n");
    printf("\n\n\t    �밴��ѡ�񣬻س�ȷ��\n");
    printf("**********************************************\n");
    return;
}
void Function1()
{
    char choose;
    system("cls");
    Window1();
    scanf(" %c", &choose);
    switch (choose)//���ܺ���
    {
    case'1':
        Adland();
        break;
    case'2':
        Adxinjian();
        break;
    case'3':
        Adxiugai();
        break;
    case'4':
        system("cls");
        _getch();
        exit(0);
        system("cls");
        break;
    }

}
void Function2()
{
    char choose;
    system("cls");
    Window2();
    scanf(" %c", &choose);
    switch (choose)//���ܺ���
    {
    case'1':
        Stland();
        break;
    case'2':
        Stxinjian();
        break;
    case'3':
        Stxiugai();
        break;
    case'4':
        system("cls");
        _getch();
        exit(0);
        system("cls");
        break;
    }
}
void Function()//�û����ܺ���
{
   char choose;
        Window();
        scanf(" %c", &choose);
        switch (choose)//���ܺ���
        {
        case'1':
           Function1();
            break;
        case'2':
            Function2();
            break;
       
        case'3':
            system("cls");
            _getch();
            exit(0);
            system("cls");
            break;
        }
    
}
void Adland()
{

    long long  zhanghao;
    long long password;
    int i = 2, j, k, n;
    char hit = 0;
    system("cls");
    do
    {
        printf("\n�������˺�:\n");
        scanf("%lld", &zhanghao);
        printf("ȷ�������밲�س������������밴ECS");
        hit = _getch();//��ͣ����i���պ������һ��ָ��
        for (; hit != 13 && hit != 27;)//��ֻ֤����CR��ESC�����˳�ѭ��,���������ַ����ã���ͣ���򣬰�'CR'������
        {
            hit = _getch();
        }
    } while (hit == 27);
    printf("\n����������:\n");
    scanf("%lld", &password);
    i = Admatch(zhanghao, password);
    if (i == 1)
    {
        printf("��½�ɹ�!�����������");
        _getch();
        BaseInforMain();
        
    }
    else
    {
        if (i == -1)
        {
            printf("�������!");
            _getch();
            Adland();
        }
        if (i == 0)
            printf("�����ڴ��û�");
        _getch();
        system("cls");
        
    }
}
void Adxinjian()
{

}
void Adxiugai()
{

}
void Stland()
{

}
void Stxinjian()
{

}
void Stxiugai()
{

}
void BaseInforMain()
{
    int choice;
    printf("ͼ��ݹ���Աϵͳ��\n");
    printf("1.����ͼ����Ϣ\n");
    printf("2.�޸�ͼ����Ϣ\n");
    printf("3.ɾ��ͼ����Ϣ\n");
    printf("4.���Ӷ�����Ϣ\n");
    printf("5.�޸Ķ�����Ϣ\n");
    printf("6.ɾ��������Ϣ\n");
    printf("0.�˳�����Աϵͳ\n");
    printf("��ѡ�������");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        char book_name[100], book_writer[100];
        char f_letter;
        int book_type;
        long long book_isbn, book_p_date;
        printf("������ͼ�����ƣ�");
        scanf("%s", book_name);
        printf("������ͼ�����ߣ�");
        scanf("%s", book_writer);
        printf("������ͼ������ĸ��");
        scanf(" %c", &f_letter);
        printf("������ͼ�����ͣ�");
        scanf("%d", &book_type);
        printf("������ͼ��ISBN��");
        scanf("%lld", &book_isbn);
        printf("������ͼ��������ڣ�");
        scanf("%lld", &book_p_date);
        AddBook(&broot, book_name, book_writer, f_letter, book_type, book_isbn, book_p_date);
        printf("ͼ����Ϣ��ӳɹ���\n");
        break;
    case 2:
        char book_name_mod[100], new_book_name[100], new_book_writer[100];
        char new_f_letter;
        int new_book_type;
        printf("������Ҫ�޸ĵ�ͼ�����ƣ�");
        scanf("%s", book_name_mod);
        printf("�������µ�ͼ�����ͣ�");
        scanf("%d", &new_book_type);
        ModifyBook(&broot, book_name_mod, new_book_type);
        printf("ͼ����Ϣ�޸ĳɹ���\n");
        break;
    case 3:
        char book_name_del[100];
        printf("������Ҫɾ����ͼ�����ƣ�");
        scanf("%s", book_name_del);
        DeleteBook(&broot, book_name_del);
        printf("ͼ����Ϣɾ���ɹ���\n");
        break;
    case 4:
        char user_name[100], f_letter_user;
        int user_type;
        long long user_password, user_account;
        int num_books;
        printf("���������������");
        scanf("%s", user_name);
        printf("������������ͣ�");
        scanf("%d", &user_type);
        printf("�������������ĸ��");
        scanf(" %c", &f_letter_user);
        printf("������������룺");
        scanf("%lld", &user_password);
        long long t = rand() % 10000000000;
        user_account = t;
        AddUser(&uroot, user_name, user_type, f_letter_user, user_password, user_account);
        printf("������Ϣ��ӳɹ���\n");
        break;
    case 5:
        long long account;
        int new_user_type;
        printf("�����뽫Ҫ�޸ĵ��û��˻�:");
        scanf("%lld", &account);
        printf("�������޸ĺ������:");
        scanf("%d", &new_user_type);
        ModifyUser(uroot, account, new_user_type);
        printf("������Ϣ�޸ĳɹ���\n");
        break;
    case 6:
        char user_name_del[100];
        printf("������Ҫɾ���Ķ���������");
        scanf("%s", user_name_del);
        DeleteUser(&uroot, user_name_del);
        printf("������Ϣɾ���ɹ���\n");
        break;
    case 0:
        return 0;
    default:
        printf("������ѡ��\n");

    }

}
int main()
{
    system("color 4E");
    Function();
    system("pause");
    	return 0;
}