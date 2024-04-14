void AdjustBookType(Book* head,char* name,int new_type);//设置和调整图书所属分类
void AdjustBookBTime(int old_type,int new_time);//设置和调整每类图书的借阅时间
void AdjustUserType(User* head,char* name,int new_type);//设置和调整读者所属分类
void AdjustUserTime(int old_type,int new_time);//设置和调整每类读者的借阅时间
void AddBook(Book** head,char* name,char* writer,char f_letter, int type,long long Isbn,long long p_date);//增加图书信息
void AddUser(User** head,char* name,int type,char f_letter,long long password,long long account,int num);//增加读者信息
void DeleteBook(Book** head,char* name);//删除图书信息
void DeleteUser(User** head,char* name);//删除读者信息
void ModifyBooK(Book** head,char* name,char* new_name,char* new_writer,char new_f_letter,int new_type)；//修改图书信息
void ModifyUser(User** head,char* name,char* new_name,int new_type,char new_f_letter,long long new_password,long long new_account)；//修改读者信息
void BaseInforMain()//基本信息管理
{
    int choice;
    printf("图书馆管理员系统：\n");
    printf("1.增加图书信息\n");
    printf("2.修改图书信息\n");
    printf("3.删除图书信息\n");
    printf("4.增加读者信息\n");
    printf("5.修改读者信息\n");
    printf("6.删除读者信息\n");
    printf("0.退出管理员系统");
    printf("请选择操作：");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            char book_name[100], book_writer[100], f_letter;
            int book_type;
            long long book_isbn, book_p_date;
            printf("请输入图书名称：");
            scanf("%s", book_name);
            printf("请输入图书作者：");
            scanf("%s", book_writer);
            printf("请输入图书首字母：");
            scanf(" %c", &f_letter);
            printf("请输入图书类型：");
            scanf("%d", &book_type);
            printf("请输入图书ISBN：");
            scanf("%lld", &book_isbn);
            printf("请输入图书出版日期：");
            scanf("%lld", &book_p_date);
            AddBook(&head_book, book_name, book_writer, f_letter, book_type, book_isbn, book_p_date);
            printf("图书信息添加成功！\n");
            break;
        case 2:
            char book_name_mod[100], new_book_name[100], new_book_writer[100];
            char new_f_letter;
            int new_book_type;
            printf("请输入要修改的图书名称：");
            scanf("%s", book_name_mod);
            printf("请输入新的图书名称：");
            scanf("%s", new_book_name);
            printf("请输入新的图书作者：");
            scanf("%s", new_book_writer);
            printf("请输入新的图书首字母：");
            scanf(" %c", &new_f_letter);
            printf("请输入新的图书类型：");
            scanf("%d", &new_book_type);
            ModifyBook(&head_book, book_name_mod, new_book_name, new_book_writer, new_f_letter, new_book_type);
            printf("图书信息修改成功！\n");
            break;
        case 3:
            char book_name_del[100];
            printf("请输入要删除的图书名称：");
            scanf("%s", book_name_del);
            DeleteBook(&head_book, book_name_del);
            printf("图书信息删除成功！\n");
            break;
        case 4:
            char user_name[100], f_letter_user;
            int user_type;
            long long user_password, user_account;
            int num_books;
            printf("请输入读者姓名：");
            scanf("%s", user_name);
            printf("请输入读者类型：");
            scanf("%d", &user_type);
            printf("请输入读者首字母：");
            scanf(" %c", &f_letter_user);
            printf("请输入读者密码：");
            scanf("%lld", &user_password);
            printf("请输入读者账户余额：");
            scanf("%lld", &user_account);
            printf("请输入读者可借图书数量：");
            scanf("%d", &num_books);
            AddUser(&head_user, user_name, user_type, f_letter_user, user_password, user_account, num_books);
            printf("读者信息添加成功！\n");
            break;
        case 5:
            char user_name_mod[100], new_user_name[100];
            int new_user_type;
            char new_f_letter_user;
            long long new_user_password, new_user_account;
            printf("请输入要修改的读者姓名：");
            scanf("%s", user_name_mod);
            printf("请输入新的读者姓名：");
            scanf("%s", new_user_name);
            printf("请输入新的读者类型：");
            scanf("%d", &new_user_type);
            printf("请输入新的读者首字母：");
            scanf(" %c", &new_f_letter_user);
            printf("请输入新的读者密码：");
            scanf("%lld", &new_user_password);
            printf("请输入新的读者账户余额：");
            scanf("%lld", &new_user_account);
            ModifyUser(&head_user, user_name_mod, new_user_name, new_user_type, new_f_letter_user, new_user_password, new_user_account);
            printf("读者信息修改成功！\n");
            break;
        case 6:
            char user_name_del[100];
            printf("请输入要删除的读者姓名：");
            scanf("%s", user_name_del);
            DeleteUser(&head_user, user_name_del);
            printf("读者信息删除成功！\n");
        break;
        case 0:
            return 0;
        default:
            printf("请重新选择。\n");
        
    }

}

void BookTypeMain() //图书分类管理
{
    int choice;
    printf("图书馆图书分类系统：\n");
    printf("1.设置和调整图书所属分类\n");
    printf("2.设置和调整每类图书的借阅时间\n");
    printf("0.退出图书分类系统");
    printf("请选择操作：");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            char book_name_adjust[100];
            int new_book_type_adjust;
            printf("请输入要调整类型的图书名称：");
            scanf("%s", book_name_adjust);
            printf("请输入新的图书类型：");
            scanf("%d", &new_book_type_adjust);
            AdjustBookType(head_book, book_name_adjust, new_book_type_adjust);
            printf("图书类型调整成功！\n");
            break;
        case 2:
            int old_book_type_adjust, new_book_time_adjust;
            printf("请输入要调整借阅时间的图书当前类型：");
            scanf("%d", &old_book_type_adjust);
            printf("请输入新的图书借阅时间：");
            scanf("%d", &new_book_time_adjust);
            AdjustBookBTime(old_book_type_adjust, new_book_time_adjust);
            printf("图书借阅时间调整成功！\n");
            break;
        case 0:
            return 0;
        default:
            printf("请重新选择。\n");
        
    }
}

void UserTypeMain() //读者分类管理
{
    int choice;
    printf("图书馆读者分类系统：\n");
    printf("1.设置和调整读者所属分类\n");
    printf("2.设置和调整每类读者的借阅时间\n");
    printf("0.退出读者分类系统");
    printf("请选择操作：");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            char user_name_adjust[100];
            int new_user_type_adjust;
            printf("请输入要调整类型的读者姓名：");
            scanf("%s", user_name_adjust);
            printf("请输入新的读者类型：");
            scanf("%d", &new_user_type_adjust);
            AdjustUserType(head_user, user_name_adjust, new_user_type_adjust);
            printf("读者类型调整成功！\n");
            break;
        case 2:
            int old_user_type_adjust, new_user_time_adjust;
            printf("请输入要调整借阅时间的读者当前类型：");
            scanf("%d", &old_user_type_adjust);
            printf("请输入新的读者借阅时间：");
            scanf("%d", &new_user_time_adjust);
            AdjustUserTime(old_user_type_adjust, new_user_time_adjust);
            printf("读者借阅时间调整成功！\n");
            break;
        case 0:
            return 0;
        default:
            printf("请重新选择。\n");
        
    }

}
void AdjustBookType(Book* head,char* name,int new_type)//设置和调整图书所属分类
{
    Book* current=head;// 定义一个指针current，初始化为链表头节点
    while(current!=NULL)// 遍历链表
    {
        if(strcmp(current->name,name)==0)// 如果找到名称匹配的图书
        {
            current->type=new_type;// 将图书的分类调整为新的分类
            printf("%s的类型已调整为%d",name,new_type);
            return;// 退出函数
        }
        current=current->next; // 移动到下一个节点
    }    
    printf("不存在图书%s"，name);

}
void AdjustBookBTime(int old_type,int new_time)//设置和调整每类图书的借阅时间
{
    if(old_type>=0&&old_type<6)
    {
        BookType[old_type]=new_time; // 调整对应类型的图书借阅时间
        printf("%d的借阅时长已调整为%d天"，old_type,new_time);
        return; // 退出函数
    }
    else{
        printf("不存在此类型图书\n");
    }
}
void AdjustUserType(Book* head,char* name,int new_type)//设置和调整读者所属分类
{
    User* current=head;// 定义一个指针current，初始化为链表头节点
    while(current!=NULL)// 遍历链表
    {
        if(strcmp(current->name,name)==0){
            current->type=new_type;// 将读者的分类调整为新的分类
            printf("%s的类型已调整为%d",name,new_type);
            return; // 退出函数
        }
        current=current->next;// 移动到下一个节点
    }    
    printf("不存在读者%s"，name);

}
void AdjustUserBTime(int old_type,int new_time)//设置和调整每类读者的借阅时间
{
    if(old_type>=0&&old_type<3){
        BookType[old_type]=new_time;// 调整对应类型的读者借阅时间
        printf("%d的借阅时长已调整为%d天"，old_type,new_time);
        return;// 退出函数
    }
    else{
        printf("不存在此类型读者\n");
    }

}
void AddBook(Book** head,char* name,char* writer,char f_letter, int type,long long Isbn,long long p_date)//增加图书信息
{
    Book* newBook=(Book*)malloc(sizeof(Book));// 动态分配一个新的Book节点
    newBook->name=strdup(name);// 复制name字段
    newBook->writer=strdup(writer);// 复制writer字段
    newBook->f_letter=f_letter;// 设置其他字段
    newBook->type=type;
    newBook->Isbn=Isbn;
    newBook->p_date=p_date;
    newBook->next=*head;// 将新节点插入到链表头部
    *head=newBook;
}
void DeleteBook(Book** head,char* name)//删除图书信息
{
    Book* current=*head;
    Book* prev=NULL;
    while(current!=NULL&&strcmp(current->name,name)!=0)// 遍历链表
    {
        prev=current;
        current=current->next;
        
    }
    if(current==NULL)// 如果未找到图书
    {
        printf("查无此书\n");
        return;
    }
    if(prev==NULL)// 如果要删除的节点是头节点
    {
        *head=current->next;
    }
    else // 否则，将前一个节点的next指向当前节点的下一个节点
    {
        prev->next=current->next;
    }
    free(current->name);// 释放当前节点的动态内存
    free(current->writer);
    free(current);
}
void AddUser(User** head,char* name,int type,char f_letter,long long password,long long account,int num)//增加读者信息
{
    User* newUser=(User*)malloc(sizeof(User));// 动态分配一个新的User节点
    newUser->name=strdup(name);// 复制name字段
    newUser->type=type;// 设置其他字段
    newUser->f_letter=f_letter;
    newUser->password=password;
    newUser->account=account;
    newUser->num=num;
    newUser->next=*head;// 将新节点插入到链表头部
    *head=newUser;
}
void DeleteUser(User** head,char* name)//删除读者信息
{
    User* current=*head; // 当前遍历的用户指针
    User* prev=NULL;  // 前一个用户指针
    while(current!=NULL&&strcmp(current->name,name)!=0) // 遍历链表
    {
        prev=current;// 更新前一个用户指针
        current=current->next;// 移动到下一个用户
        }
    if(current==NULL) // 如果当前用户为无
    {
        printf("查无此人\n");
        return;
    }
    if(prev==NULL) // 如果要删除的是头节点
    {
        *head=current->next; // 更新头节点为下一个用户
    }
    else{
        prev->next=current->next; // 否则将指向当前用户的下一个用户
    }
    free(current->name); // 释放当前用户的内存
    free(current->type);
    free(current);
}
void ModifyBooK(Book** head,char* name,char* new_name,char* new_writer,char new_f_letter,int new_type)//修改图书信息
{
    Book* current=*head; // 当前遍历的图书指针
    Book* prev=NULL;// 前一本图书指针
    while(current!=NULL) // 遍历链表
    {
        if(strcmp(current->name,name)==0){
            free(current->name);// 释放当前图书的内存
            free(current->writer);
            current->name=strdup(new_name);// 更新当前图书的name, writer, f_letter, type字段
            current->writer=strdup(new_writer);
            current->f_letter=new_f_letter;
            current->type=new_type;
            return;
        }
        prev=current;
        current=current->next;// 移动到下一个节点
    }
}
void ModifyUser(User** head,char* name,char* new_name,int new_type,char new_f_letter,long long new_password,long long new_account)//修改读者信息
{
    User* current=*head;// 当前遍历的用户指针
    User* prev=NULL; // 前一个用户指针
    while(current!=NULL)// 遍历链表
    {
        if(strcmp(current->name,name)==0){
            free(current->name);// 释放当前用户的内存
            free(current->type);
            current->name=strdup(new_name);
            current->f_letter=new_f_letter;
            current->type=new_type;
            current->password=new_password;
            current->account=new_account;
            return;
        }
        prev=current;
        current=current->next;// 移动到下一个节点
    }
}