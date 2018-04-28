
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>
#include"account.h"

void system_init(const char* config_file_name, pUSR_ACCOUNT  *pUsr_Acount, pUSR_INFOR *pUsr_Infor);
int login(pUSR_ACCOUNT  head_a, pUSR_INFOR head_u);

int std_windows(pUSR_INFOR head_u);