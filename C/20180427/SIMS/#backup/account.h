#include"config.h"
typedef struct usr_account_tag
{
    char usr_name[USR_NAME_LEN];
    char usr_pwd[USR_PWD_LEN];
    USR_ROLE usr_role;
    struct usr_account_tag *pNext_Usr_Account;
} USR_ACCOUNT, *pUSR_ACCOUNT;