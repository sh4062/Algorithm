#include"login.h"
void account_insert(pUSR_ACCOUNT a, char acc_in_n[20],char acc_in_p[20],int acc_in_r)
{
	pUSR_ACCOUNT p_new = (pUSR_ACCOUNT)malloc(sizeof(USR_ACCOUNT));
	strcpy(p_new->usr_name, acc_in_n);
	strcpy(p_new->usr_pwd, acc_in_p);
	p_new->usr_role = acc_in_r;
	        
	p_new->pNext_Usr_Account = NULL;         /*将新元素next置为空*/
	
		while ((a)->pNext_Usr_Account != NULL)  /*最终让temp指向尾结点*/
		{
			(a) = (a)->pNext_Usr_Account;
		}
		(a)->pNext_Usr_Account = p_new;     /*将尾结点temp的next设为p_new,即将p_new设为尾结点*/

	}
void print_list(pUSR_ACCOUNT head)
{
	pUSR_ACCOUNT elem = head;
	while (elem != NULL)
	{
		printf("%s %s %d\n", elem->usr_name, elem->usr_pwd, elem->usr_role);
		elem = elem->pNext_Usr_Account;
	}
	printf("\n");
}
int search_account(pUSR_ACCOUNT head,char *s)
{
	pUSR_ACCOUNT elem = head;
	while (elem != NULL)
	{
		if (strcmp(elem->usr_name, s) == 0) {
			return 1;
		}
		elem = elem->pNext_Usr_Account;
	}
	printf("No such account\n");
	return 0;
	
}
int search_account_p(pUSR_ACCOUNT head, char *s)
{
	pUSR_ACCOUNT elem = head;
	while (elem != NULL)
	{
		if (strcmp(elem->usr_pwd, s) == 0) {
			if (elem->usr_role == 1)
				return 1; else if (elem->usr_role == 2)return 2;
		}
		elem = elem->pNext_Usr_Account;
	}
	printf("Password is wrong\n");
	return 0;

}

void usr_insert(pUSR_INFOR a, int acc_in_n, char acc_in_p[20], int acc_in_r,float acc_in_rf) {
	pUSR_INFOR p_new = (pUSR_INFOR)malloc(sizeof(USR_INFOR));
	p_new->usr_id = acc_in_n;
	strcpy(p_new->usr_name, acc_in_p);
	p_new->usr_course_id = acc_in_r;
	p_new->usr_course_score = acc_in_rf;

	p_new->pNext_Usr_Infor = NULL;         /*将新元素next置为空*/

	while ((a)->pNext_Usr_Infor != NULL)  /*最终让temp指向尾结点*/
	{
		(a) = (a)->pNext_Usr_Infor;
	}
	(a)->pNext_Usr_Infor = p_new;     /*将尾结点temp的next设为p_new,即将p_new设为尾结点*/
}

void print_list_usr(pUSR_INFOR head)
{
	pUSR_INFOR elem = head;
	while (elem != NULL)
	{
		printf("%d %s %d %f\n", elem->usr_id, elem->usr_name, elem->usr_course_id, elem->usr_course_score);
		elem = elem->pNext_Usr_Infor;
	}
	printf("\n");
}

void usr_search_by_name(pUSR_INFOR head,char s[20])
{
	pUSR_INFOR elem = head;
	while (elem != NULL)
	{
		if (strcmp(elem->usr_name, s) == 0) {
			printf("%d %s %d %f\n", elem->usr_id, elem->usr_name, elem->usr_course_id, elem->usr_course_score);
			return;
		}
		
		elem = elem->pNext_Usr_Infor;
	}
	printf("No such thing\n");
}

void usr_search_by_id(pUSR_INFOR head, int s)
{
	pUSR_INFOR elem = head;
	while (elem != NULL)
	{
		if (elem->usr_id  == s) {
			printf("%d %s %d %f\n", elem->usr_id, elem->usr_name, elem->usr_course_id, elem->usr_course_score);
			return ;
		}

		elem = elem->pNext_Usr_Infor;
	}
	printf("No such thing\n");
	return;
}


pUSR_INFOR usr_search_by_id2(pUSR_INFOR head, int s)
{
	pUSR_INFOR elem = head;
	while (elem != NULL)
	{
		if (elem->usr_id == s) {
			return elem;
		}

		elem = elem->pNext_Usr_Infor;
	}

	return NULL;
}

void list_sort_insert(pUSR_INFOR* pphead, int i,char s[20],int ci,float cs)
{
	pUSR_INFOR pnew = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));//会把申请的空间全部赋值为0
	pUSR_INFOR pcur = *pphead;
	pUSR_INFOR ppre = *pphead;
	pnew->usr_id = i;
	strcpy(pnew->usr_name,s);
	pnew->usr_course_id = ci;
	pnew->usr_course_score = cs;
	if (NULL == *pphead)//如果链表为空，新结点即是头，又是尾
	{
		*pphead = pnew;
		
	}
	else if (i<pcur->usr_id)//新节点插入到头部
	{
		pnew->pNext_Usr_Infor = pcur;//把原有链表头，赋值给新结点的next
		*pphead = pnew;//新结点变为头结点
	}
	else {
		while (pcur)//插入到中间
		{
			if (pcur->usr_id>i)
			{
				pnew->pNext_Usr_Infor = pcur;
				ppre->pNext_Usr_Infor = pnew;
				return;
			}
			ppre = pcur;
			
			pcur = pcur->pNext_Usr_Infor;
		}
		
		ppre->pNext_Usr_Infor = pnew;
		
	}
}

void u_deletell(pUSR_INFOR* pphead, int delnum) {
	pUSR_INFOR pcur = *pphead;
	pUSR_INFOR ppre = *pphead;
	if (!pcur)//masm编译器空指针无法访问内存不崩溃
	{
		printf("list is empty\n");
	}
	else if (pcur->usr_id == delnum)//删除的是头部
	{
		*pphead = pcur->pNext_Usr_Infor;//头指针就指向下一个节点
		free(pcur);
		pcur = NULL;

	}
	else {
		while (pcur)//删除中间，
		{
			if (pcur->usr_id == delnum)
			{
				ppre->pNext_Usr_Infor = pcur->pNext_Usr_Infor;
				break;
			}
			ppre = pcur;
			pcur = pcur->pNext_Usr_Infor;
		}
		
		if (NULL == pcur)//free空指针不会崩溃
		{
			printf("delnum is not in the list\n");
		}
		else {
			free(pcur);
		}
	}

}

void a_list_sort_insert(pUSR_ACCOUNT* pphead, char i[20], char s[20], int ci)
{
	pUSR_ACCOUNT pnew = (pUSR_ACCOUNT)calloc(1, sizeof(USR_ACCOUNT));//会把申请的空间全部赋值为0
	pUSR_ACCOUNT pcur = *pphead;
	pUSR_ACCOUNT ppre = *pphead;
	
	strcpy(pnew->usr_name, i);
	strcpy(pnew->usr_pwd, s);
	pnew->usr_role = ci;
	if (NULL == *pphead)//如果链表为空，新结点即是头，又是尾
	{
		*pphead = pnew;

	}
	else if (strcmp(i,pcur->usr_name)<0)//新节点插入到头部
	{
		pnew->pNext_Usr_Account = pcur;//把原有链表头，赋值给新结点的next
		*pphead = pnew;//新结点变为头结点
	}
	else {
		while (pcur)//插入到中间
		{
			if (strcmp(pcur->usr_name,i)>0)
			{
				pnew->pNext_Usr_Account = pcur;
				ppre->pNext_Usr_Account = pnew;
				return;
			}
			ppre = pcur;
		
			pcur = pcur->pNext_Usr_Account;

		}
		
		ppre->pNext_Usr_Account = pnew;
		

	}
}pUSR_ACCOUNT acc_search_by_name(pUSR_ACCOUNT head, int s)
{
	pUSR_ACCOUNT elem = head;
	while (elem != NULL)
	{
		if (strcmp(elem->usr_name,s)==0) {
			return elem;
		}

		elem = elem->pNext_Usr_Account;
	}

	return NULL;
}

void a_deletell(pUSR_ACCOUNT* pphead, char i[20]){
	pUSR_ACCOUNT pcur = *pphead;
	pUSR_ACCOUNT ppre = *pphead;
	if (!pcur)//masm编译器空指针无法访问内存不崩溃
	{
		printf("list is empty\n");
	}
	else if (strcmp(pcur->usr_name, i)==0)//删除的是头部
	{
		*pphead = pcur->pNext_Usr_Account;//头指针就指向下一个节点
		free(pcur);
		pcur = NULL;

	}
	else {
		while (pcur)//删除中间，
		{
			if ((strcmp(pcur->usr_name, i) == 0))
			{
				ppre->pNext_Usr_Account = pcur->pNext_Usr_Account;
				break;
			}
			ppre = pcur;
			pcur = pcur->pNext_Usr_Account;
		}

		if (NULL == pcur)//free空指针不会崩溃
		{
			printf("delnum is not in the list\n");
		}
		else {
			free(pcur);
		}
	}

}

int acc_count(pUSR_ACCOUNT head)
{
	int res = 0;
	pUSR_ACCOUNT elem = head;
	while (elem != NULL)
	{
		res++;
		
		elem = elem->pNext_Usr_Account;
	}

	return res;
}

int usr_count(pUSR_INFOR head)
{
	pUSR_INFOR elem = head;
	int res = 0;
	while (elem != NULL)
	{
		res++;
		elem = elem->pNext_Usr_Infor;
	}
	return res;
}