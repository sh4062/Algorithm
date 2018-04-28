#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "config.h"
#include "login.h"
#include<windows.h>  

int main(int arg, char **argv)
{
	argv[1] = "./database/configure";
	pUSR_ACCOUNT  head_a = NULL;
	pUSR_INFOR head_u = NULL;
	//printf("%s", argv[1]);
	system_init(argv[1], &head_a, &head_u);
	//print_list(head_a);
	//print_list_usr(head_u);
	system("cls");
	while(1){
		system("cls");
	int init = login(head_a,head_u);
	while (init < 1) {
		init = login(head_a, head_u);
	}
	system("cls");
	Sleep(500);
	while(1){
		system("cls");
	printf("Login successfully\n Wellcome to the student information management system\n");
	if (init == 1) {
		int res1 = admin_windows(&head_u,&head_a,argv[1]);
		if (res1 == 9)break;
	}
	else if (init == 2) {
		int res2 = std_windows(head_u);
			if (res2 == 3)break;
	}
	}
	}
	system("pause");

}