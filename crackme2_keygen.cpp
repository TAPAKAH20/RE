
#include <iostream>

//for a long time thought that password is a string. not a number
//int pass_hash(char* pass) {
//	int c = 0xa;
//	int a = 0;
//	char b = 0;
//	for (int i = 0; pass[i] != '\0'; i++) {
//		b = pass[i] - 0x30;
//		a *= c;
//		a += b;
//	}
//
//	return a ^ 0x1234;
//}


int login_hash(char* login) {
	int uedi = 0;
	for (int i = 0; login[i] != '\0'; i++) {
		if (login[i] >= 0x5a) {
			login[i] -= 0x20;
		}
		else if (login[i] < 0x41) {
			return NULL;
		}
		uedi += (int)login[i];
	}

	return uedi ^ 0x5678;
}

int main()
{

	..printf("%d\n", pass_hash((char*)"10"));
	char login[256];
	int pass;
	scanf_s("%s", login, 256);

	
	

	int log_res = login_hash(login);

	printf("%d\n", log_res);



	pass = (log_res ) ^ 0x1234;
	printf("Pass: %d", pass);
	return 0;
}

