#include "account.h"
#include<string.h>
#include<windows.h>  
int admin_windows1(pUSR_INFOR head_u) {
	while (1) {
		system("cls");
		printf("0. Search all\n");
		printf("1. Search by name\n");
		printf("2. Search by id\n");
		printf("3. Return\n");
		printf("Please select--------------------------------------\n");
		char tmp;
		tmp = getchar();
		while (tmp != '0'&&tmp != '1'&&tmp != '2'&&tmp != '3') {
			printf("---------------Please select from 0,1, 2, 3------------------\n");
			tmp = getchar();
		}
		while (1) {
			system("cls");
			if (tmp == '0') {
				printf("Search all,Type -1 for exit\n");
				print_list_usr(head_u);
				char s[20];
				while (scanf("%s", s) != NULL) {
					if (strcmp(s, "-1") == 0)break;


				}break;
			}
			else if (tmp == '1') {
				printf("Search by name,Type -1 for exit\n");
				char s[20];
				while (scanf("%s", s) != NULL) {
					if (strcmp(s, "-1") == 0)break;
					usr_search_by_name(head_u, s);
				}break;

			}
			else if (tmp == '2') {
				printf("Search by id,Type -1 for exit\n");
				int s = 0;
				char st[20];
				while (scanf("%s", st) != NULL) {
					if (strcmp(st, "-1") == 0)break;
					s = atoi(st);
					usr_search_by_id(head_u, s);
				}break;

			}
			else if (tmp == '3') { return 3; }
		}

	}
}
int admin_windows2(pUSR_INFOR *head_u) {
	while (1) {
		system("cls");
		printf("Add student information,press -1 to cancel\n");
		char s[20];
		char ts[20];
		int ss = 0;
		int sss = 0;
		float ssss = 0;
		printf("Please input new student's id\n");
		while (scanf("%s", s) != NULL) {

			if (strcmp(s, "-1") == 0)return 2;
			ss = atoi(s);
			pUSR_INFOR tmp = usr_search_by_id2(*head_u, ss);
			if (tmp != NULL) { printf("Id is exist!\nPlease input correct student's id\n"); continue; }
			else if (ss < 0 || ss>999999) { printf("Id is between 0-999999!\nPlease input correct student's id\n"); continue; }
			else {
				printf("Please input student's name\n");
				scanf("%s", s);
				if (strcmp(s, "-1") == 0)break;
				strcpy(ts, s);
				printf("Please input student's course id\n");
				scanf("%s", s);
				if (strcmp(s, "-1") == 0)break;
				sss = atoi(s);

				printf("Please input student's course score\n");
				scanf("%s", s);
				if (strcmp(s, "-1") == 0)break;
				ssss = atof(s);

				printf("%d %s %d %f\n", ss, ts, sss, ssss);
				list_sort_insert(head_u, ss, ts, sss, ssss);
				printf("\n-------------------------Add successfully--------------------------\n");
				Sleep(1000);
				break;

			}

		}break;

	}

}
int admin_windows3(pUSR_INFOR *head_u) {
	while (1) {
		system("cls");
		printf("Update student information,press -1 to exit\n");
		printf("Please input student's id\n");

		char s[20];
		int ss = 0;
		float sss = 0;
		while (scanf("%s", s) != NULL) {
			if (strcmp(s, "-1") == 0)return 3;
			ss = atoi(s);
			pUSR_INFOR tmp = usr_search_by_id2(*head_u, ss);
			if (tmp == NULL) { printf("No such student\n"); continue; }
			else {
				printf("Please input student's name\n previous name->%s\n", tmp->usr_name);
				scanf("%s", s);
				if (strcmp(s, "-1") == 0)break;
				strcpy(tmp->usr_name, s);
				printf("Please input student's course id\nprevious course_id->%d\n", tmp->usr_course_id);
				scanf("%s", s);
				if (strcmp(s, "-1") == 0)break;
				ss = atoi(s);
				tmp->usr_course_id = ss;
				printf("Please input student's course score\nprevious course_score->%f\n", tmp->usr_course_score);
				scanf("%s", s);
				if (strcmp(s, "-1") == 0)break;
				sss = atof(s);
				tmp->usr_course_score = sss;
				printf("%d %s %d %f\n", tmp->usr_id, tmp->usr_name, tmp->usr_course_id, tmp->usr_course_score);
				printf("\n---------------------Update successfully--------------------------\n");
				Sleep(1000);
				break;

			}
		}break;
	}

}

int admin_windows4(pUSR_INFOR *head_u) {
	while (1) {
		system("cls");
		printf("Delete student information,press -1 to exit\n");
		printf("Please input student's id\n");
		char s[20];
		int ss = 0;
		float sss = 0;
		while (scanf("%s", s) != NULL) {
			printf("Please input correct information\n");
			if (strcmp(s, "-1") == 0)return 4;
			ss = atoi(s);
			pUSR_INFOR tmp = usr_search_by_id2(*head_u, ss);
			if (tmp == NULL) { printf("No such student\n"); continue; }
			else {
				printf("Delete %d %s %d %f\n", tmp->usr_id, tmp->usr_name, tmp->usr_course_id, tmp->usr_course_score);
				u_deletell(head_u, ss);
				printf("\n---------------------Delete successfully--------------------------\n");
				Sleep(1000);
				break;

			}
		}break;


	}

}
int admin_windows5(pUSR_ACCOUNT *head_a) {

	while (1) {
		system("cls");
		printf("Add account information,press -1 to cancel\n");
		char s[20];
		char ts[20];
		char tsp[20];
		int ss = 0;
		printf("Please input new account's name\n");
		while (scanf("%20s", s) != NULL) {
			if (strcmp(s, "-1") == 0)return 5;
			int a = search_account(*head_a, s);
			if (a == 1) { printf("Account is exist!\nPlease input correct account's name\n"); continue; }
			else {
				strcpy(ts, s);
				printf("Please input account's password\n");	
				scanf("%s", s);
				if (strcmp(s, "-1") == 0)break;
				strcpy(tsp, s);
				printf("Please input account's authority\n");
				scanf("%s", s);
				ss = atoi(s);
				if (ss != 1 && ss != 2) {
					printf("Please input right authority\n");
					Sleep(1000);
					break;
				}
				printf("%s %s %d\n", ts, tsp, ss);
				a_list_sort_insert(head_a, ts, tsp, ss);
				printf("\n-------------------------Add successfully--------------------------\n");
				Sleep(1000);
				break;

			}

		}break;

	}

}
int admin_windows6(pUSR_ACCOUNT *head_a) {
	while (1) {
		system("cls");
		printf("Update account information,press -1 to exit\n");
		printf("Please input account's name\n");

		char s[20];
		char ts[20];
		char tsp[20];
		int ss = 0;
		while (scanf("%s", s) != NULL) {
			if (strcmp(s, "-1") == 0)return 6;
			strcpy(ts, s);
			pUSR_ACCOUNT tmp = acc_search_by_name(*head_a, ts);
			if (tmp == NULL) { printf("No such account\n"); continue; }
			else {
				printf("Please input student's password\n previous password->%s\n", tmp->usr_pwd);
				scanf("%s", s);
				strcpy(tmp->usr_pwd, s);
				printf("Please input student's role id\nprevious role->%d\n", tmp->usr_role);
				scanf("%s", s);
				ss = atoi(s);
				tmp->usr_role = ss;
				printf("\n---------------------Update successfully--------------------------\n");
				Sleep(1000);
				break;

			}
		}break;
	}

}
int admin_windows7(pUSR_ACCOUNT *head_a) {
	while (1) {
		system("cls");
		printf("Delete account information\n");
		char s[20];
		char ts[20];
		char tsp[20];
		int ss = 0;
		while (scanf("%s", s) != NULL) {
			if (strcmp(s, "-1") == 0)return 7;
			strcpy(ts, s);
			pUSR_ACCOUNT tmp = acc_search_by_name(*head_a, ts);

			if (tmp == NULL) { printf("No such account\n"); continue; }
			else {
				printf("Delete %s %s %d \n", tmp->usr_name, tmp->usr_pwd, tmp->usr_role);
				a_deletell(head_a, ts);
				printf("\n---------------------Delete successfully--------------------------\n");
				Sleep(1000);
				break;

			}break;


		}

	}
}

int admin_windows8(pUSR_ACCOUNT head_u) {
	while (1) {
		system("cls");
		printf("0. Search all\n");
		printf("1. Search by name\n");
		printf("2. Return\n");
		printf("Please select--------------------------------------\n");
		char tmp;
		tmp = getchar();
		while (tmp != '0'&&tmp != '1'&&tmp != '2') {
			printf("---------------Please select from 0,1, 2------------------\n");
			tmp = getchar();
		}
		while (1) {
			system("cls");
			if (tmp == '0') {
				printf("Search all,Type -1 for exit\n");
				print_list(head_u);
				char s[20];
				while (scanf("%s", s) != NULL) {
					if (strcmp(s, "-1") == 0)break;


				}break;
			}
			else if (tmp == '1') {
				printf("Search by name 1 for exist, 0 for not exist,Type -1 for exit\n");
				char s[20];
				while (scanf("%s", s) != NULL) {
					if (strcmp(s, "-1") == 0)break;
					printf("%d", search_account(head_u, s));
				}break;

			}

			else if (tmp == '2') { return 2; }
		}

	}
}