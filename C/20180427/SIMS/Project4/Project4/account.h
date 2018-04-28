#include"config.h"
typedef enum role
{
	admin=1,
student 
}
USR_ROLE;
typedef struct usr_account_tag
{
    char usr_name[USR_NAME_LEN];
    char usr_pwd[USR_PWD_LEN];
	USR_ROLE usr_role;
    struct usr_account_tag *pNext_Usr_Account;
} USR_ACCOUNT, *pUSR_ACCOUNT;


typedef struct usr_infor_tag
{
	int usr_id;
	char usr_name[USR_NAME_LEN];
	int usr_course_id;
	float usr_course_score;
	struct usr_infor_ta *pNext_Usr_Infor;

}USR_INFOR, *pUSR_INFOR;


void account_insert(pUSR_ACCOUNT a, char acc_in_n[20], char acc_in_p[20], int acc_in_r);
void print_list(pUSR_ACCOUNT head);
void usr_insert(pUSR_INFOR a, int acc_in_n, char acc_in_p[20], int acc_in_r, float acc_in_rf);
void print_list_usr(pUSR_INFOR head);
void usr_search_by_name(pUSR_INFOR head, char s[20]);
void list_sort_insert(pUSR_INFOR* pphead, int i, char s[20], int ci, int cs);

