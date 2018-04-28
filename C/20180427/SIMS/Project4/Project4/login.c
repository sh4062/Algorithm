#include"login.h"
#include<windows.h>  

void system_init(const char* config_file_name, pUSR_ACCOUNT  *pUsr_Acount, pUSR_INFOR *pUsr_Infor) {
	printf("-----------------------------------Init--------------------------------------");
	Sleep(1000);
	FILE *fpconf = fopen(config_file_name, "r");
	if (fpconf == NULL) {
		perror("fpconf");
	}

	char accountSQL[40];
	int account = 0;
	char usrSQL[40];
	int usr = 0;
	fscanf(fpconf, "%s", accountSQL);
	fscanf(fpconf, "%d", &account);
	fscanf(fpconf, "%s", usrSQL);
	fscanf(fpconf, "%d", &usr);
	fclose(fpconf);
	printf("\nDataBase Dir: \n%s \n %s\n", accountSQL, usrSQL);
	FILE *fpa = fopen(accountSQL, "r");
	if (fpa == NULL) {
		perror("fpa");
	}
	pUSR_ACCOUNT a_tmp = (pUSR_ACCOUNT)calloc(1, sizeof(USR_ACCOUNT));
	//由于一定有管理员账户的存在 所以不用管头节点为空
	fscanf(fpa, "%s %s %d", a_tmp->usr_name, a_tmp->usr_pwd, &a_tmp->usr_role);
	*pUsr_Acount = a_tmp;
	for (int i = 1; i < account; i++) {
		char acc_in_n[20];
		char acc_in_p[20];
		int acc_in_r;

		fscanf(fpa, "%s %s %d", acc_in_n, acc_in_p, &acc_in_r);

		account_insert(*pUsr_Acount, acc_in_n, acc_in_p, acc_in_r);

	}

	fclose(fpa);

	FILE *fpu = fopen(usrSQL, "r");
	if (fpu == NULL) {
		perror("fpu");
	}
	//fflush(fpu);
	pUSR_INFOR u_tmp = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));
	fscanf(fpu, "%d %s %d %f", &u_tmp->usr_id, u_tmp->usr_name, &u_tmp->usr_course_id, &u_tmp->usr_course_score);
	if (u_tmp->usr_id == NULL) {
		printf("\n-----------------------------Empty Database---------------------------\n");
		return;
	}
	*pUsr_Infor = u_tmp;
	for (int i = 1; i < usr; i++) {
		int usr_in_id;
		char usr_in_name[20];
		int usr_in_course;
		float usr_in_score;

		fscanf(fpu, "%d %s %d %f", &usr_in_id, usr_in_name, &usr_in_course, &usr_in_score);

		usr_insert(*pUsr_Infor, usr_in_id, usr_in_name, usr_in_course, usr_in_score);

	}
	fclose(fpu);
	return;
}

void write_database(char*conf , pUSR_ACCOUNT  pUsr_Acount, pUSR_INFOR pUsr_Infor) {
	printf("-----------------------------------Update Database--------------------------------------");
	int a = acc_count(pUsr_Acount);
	int u = usr_count(pUsr_Infor);
	FILE *fpconf = fopen(conf, "r+");
	if (fpconf == NULL) {
		perror("fpconf");
	}

	char accountSQL[40];
	int account = 0;
	char usrSQL[40];
	int usr = 0;
	fscanf(fpconf, "%s", accountSQL);
	fscanf(fpconf, "%d", &account);
	fscanf(fpconf, "%s", usrSQL);
	fscanf(fpconf, "%d", &usr);
	fseek(fpconf,0,SEEK_SET);
	fprintf(fpconf, "%s\n", accountSQL);
	fprintf(fpconf, "%d\n", a);
	fprintf(fpconf, "%s\n", usrSQL);
	fprintf(fpconf, "%d", u);

	fclose(fpconf);
	printf("\nDataBase Dir: \n%s \n %s\n", accountSQL, usrSQL);
	//FILE *fpa = fopen("./database/test", "w+");
	FILE *fpa = fopen(accountSQL, "w+");
	if (fpa == NULL) {
		perror("fpa");
	}
	pUSR_ACCOUNT tmp = pUsr_Acount;
	for (int i = 0; i < a; i++) {

		fprintf(fpa, "%s %s %d\n", tmp->usr_name, tmp->usr_pwd, tmp->usr_role);

		tmp = tmp->pNext_Usr_Account;

	}

	fclose(fpa);
	
	//FILE *fpu = fopen("./database/test", "r+");
		FILE *fpu = fopen(usrSQL, "w+");
	if (fpu == NULL) {
		perror("fpu");
	}
	//fseek(fpu, 0, SEEK_END);
	pUSR_INFOR u_tmp = pUsr_Infor;
	for (int i = 0; i < u; i++) {

		fprintf(fpu, "%d %s %d %f\n", u_tmp->usr_id, u_tmp->usr_name, u_tmp->usr_course_id, u_tmp->usr_course_score);
		u_tmp = u_tmp->pNext_Usr_Infor;
	}
	fclose(fpu);
	return;



}

int login(pUSR_ACCOUNT  head_a, pUSR_INFOR head_u) {
	printf("-----------------Login to Student Information Management System--------------------\n");
	printf("name:");
	char t[20];
	char tp[20];
	char tt;
	int nlen = 0;
	while (((tt = getchar()) != '\n'))
	{
		if (tt == '\b') {
			nlen--;
			if (nlen < 0) { nlen = 0; continue; }
		}
		else nlen++;
		if (nlen >= 20)return 0;
		if (nlen >= 1)
			t[nlen - 1] = tt;

	}
	t[nlen] = '\0';
	//printf("%s\n", t);
	int acc_val = search_account(head_a, t);
	if (acc_val == 0) return 0;

	printf("password:");
	int plen = 0;
	while (((tt = getch()) != '\r'))
	{
		if (tt == '\b')
		{
			plen--;
			if (plen >= 0)
				printf("\b \b");
			else { plen = 0; continue; }


		}
		else {
			printf("*");
			plen++;
		}

		if (plen > 20) {
			printf("\nPassword is wrong\n");
			return 0;
		}
		if (plen >= 1)
			tp[plen - 1] = tt;
	}
	tp[plen] = '\0';
	//printf("%s", tp);
	//printf("%d", plen);
	int pwd_val = search_account_p(head_a, tp);
	if (pwd_val == 0) return 0;
	else return pwd_val;
}
int admin_windows(pUSR_INFOR *head_u, pUSR_ACCOUNT *head_a, char*conf) {
	while (1) {
		system("cls");
		printf("1. Search Student Information\n");
		printf("2. Add Student Information\n");
		printf("3. Update Student Information\n");
		printf("4. Delete Student Information\n");
		printf("5. Add User Account\n");
		printf("6. Update User Account\n");
		printf("7. Delete User Account\n");
		printf("8. Search User Account\n");
		printf("9. Exit\n");
		char tmp;
		tmp = getchar();
		while (tmp != '1'&&tmp != '2'&&tmp != '3'&&tmp != '4'&&tmp != '5'&&tmp != '6'&&tmp != '7'&&tmp != '8'&&tmp != '9')
		{
			printf("\n---------------Please select from 1, 2, 3, 4, 5, 6, 7, 8, 9------------------\n");
			tmp = getchar();
			fflush(stdin);
		}

		if (tmp == '1') {
			while (1) {
				int res1 = admin_windows1(*head_u);
				if (res1 == 3)break;
			}

		}
		else if (tmp == '2') {
			while (1) {
				int res2 = admin_windows2(head_u);
				if (res2 == 2)break;
			}

		}
		else if (tmp == '3') {
			while (1) {
				int res3 = admin_windows3(head_u);
				if (res3 == 3)break;
			}
		}
		else if (tmp == '4') {
			while (1) {
				int res4 = admin_windows4(head_u);
				if (res4 == 4)break;
			}
		}
		else if (tmp == '5') {
			while (1) {
				int res5 = admin_windows5(head_a);
				if (res5 == 5)break;
			}
		}
		else if (tmp == '6') {
			while (1) {
				int res6 = admin_windows6(head_a);
				if (res6 == 6)break;
			}
		}
		else if (tmp == '7') {
			while (1) {
				int res7 = admin_windows7(head_a);
				if (res7 == 7)break;
			}
		}
		else if (tmp == '8') {
			while (1) {
				int res1 = admin_windows8(*head_a);
				if (res1 == 2)break;
			}
		}
		else if (tmp == '9') { write_database(conf,*head_a,*head_u); return 9; }
		write_database(conf, *head_a, *head_u);
	}



}
int std_windows(pUSR_INFOR head_u) {
	while (1) {
		system("cls");
		printf("1. Search by name\n");
		printf("2. Search by id\n");
		printf("3. Return\n");
		printf("Please select--------------------------------------\n");
		char tmp;
		tmp = getchar();
		while (tmp != '1'&&tmp != '2'&&tmp != '3') {
			printf("---------------Please select from 1, 2, 3------------------\n");
			tmp = getchar();
		}
		while (1) {
			if (tmp == '1') {

				printf("Search by name,Type -1 for exit\n");
				char s[20];
				while (scanf("%20s", s) != NULL) {
					if (strcmp(s, "-1") == 0)break;
					usr_search_by_name(head_u, s);
				}break; system("cls");

			}
			else if (tmp == '2') {
				printf("Search by id,Type -1 for exit\n");
				int s = 0;
				char st[20];
				while (scanf("%s20", st) != NULL) {
					if (strcmp(st, "-1") == 0)break;
					s = atoi(st);
					usr_search_by_id(head_u, s);
				}break; system("cls");

			}
			else if (tmp == '3') { return 3; }
		}

	}
}