// Clinic :

#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define CLEAR system("cls")
#define WAIT _sleep(1300)

#define R  "\033[0;31m"
#define B  "\033[0;34m"
#define W  "\033[0;37m"
#define C  "\033[0;36m"
#define P  "\033[0;35m"
#define G  "\033[0;32m"
#define Y  "\033[0;33m"

enum daycolor { white, red, blue };

struct calendar {
	int day = 0;
	int month = 0;
	int weekday;
	int start;
	int end;
	char doctor[10][13];
	daycolor main_color;
	daycolor sub_color = white;
	char reason[30];
};

struct visit {
	float start;
	float end;
	char id[12];
};

struct doctor_day {
	visit vis[24];
	int i_v = 0;
};

struct doctor {
	char name[20];
	char lastname[20];
	char codemeli[12];
	char email[30];
	char id[12];
	int payment = 0;
	struct doctor_day dday[93];
	int cost;
	int wallet;
};

struct patient {
	char name[20];
	char lastname[20];
	char codemeli[12];
	char email[30];
	char id[12];
	int wallet;
	char prescription[10][300];
};

void hash(char* pass)
{
	for (int i = 0; i < strlen(pass); i++)
	{
		pass[i] = pass[i] + 20;
	}
}

void hashback(char* pass)
{
	for (int i = 0; i < strlen(pass); i++)
	{
		pass[i] = pass[i] - 20;
	}
}



void passw(char* pass, char* user)
{
	printf(P);
	int i = 0, j;
	char c;
	while (true)
	{
		j = 0;
		CLEAR;
		printf("USERNAME : %s\n", user);
		printf("PASSWORD : ");
		while (pass[j] > 0)
		{
			printf("*");
			j++;
		}
		c = getch();
		if (c == 13)
		{
			pass[i] = '\0';
			break;
		}
		else if (c == ' ')
		{
			continue;
		}
		else if (c == 8 && i > 0)
		{
			i--;
			pass[i] = NULL;
		}
		else if (c != 8)
		{
			pass[i] = c;
			printf("%c", pass[i]);
			i++;
			_sleep(200);
		}
	}
	return;
}


float sum(float a, float b)
{
	a += 0.004;
	b += 0.004;
	int c = (int)a;
	int d = (int)b;

	int f = ((a - c) * 100);
	int g = ((b - d) * 100);

	int h = (f + g) / 60;
	float j = (f + g) % 60;
	float s = (j / 100);

	float r = c + d + h + s;

	return r;

}

int arr[20], arr2[93], arr3[20];
int arry[20], arry2[93], arry3[20];

int pcancelvisit(struct doctor doc[20], int a, int b, int c, int i_p, struct patient pat[20])
{

	int i = 0;
	for (int v = 0; v < 20; v++)
	{
		if (doc[arry[c]].dday[arry2[b]].vis[v].start > 0 && doc[arry[c]].dday[arry2[b]].vis[v].id[0] > 0 && strcmp(doc[arry[c]].dday[arry2[b]].vis[v].id, pat[i_p].id) == 0)
		{
			if (i == a)
			{
				printf(B);
			}
			else
			{
				printf(W);
			}
			arry3[i] = v;
			i++;
			printf("( %.2f - %.2f )\n", doc[arry[c]].dday[arry2[b]].vis[v].start, doc[arry[c]].dday[arry2[b]].vis[v].end);
		}

	}
	printf(W);

	return i;
}
int pcanceldday(struct doctor doc[20], int a, int b, struct calendar cal[93], int i_p, struct patient pat[20])
{
	int c = 0, i = 0;
	for (int d = 0; d < 93; d++)
	{
		c = 0;
		for (int v = 0; v < 20; v++)
		{
			if (doc[arry[b]].dday[d].vis[v].start > 0 && doc[arry[b]].dday[d].vis[v].id[0] > 0 && strcmp(doc[arry[b]].dday[d].vis[v].id, pat[i_p].id) == 0)
			{
				if (a == i)
				{
					printf(B);
				}
				else
				{
					printf(W);
				}
				if (c == 0)
				{
					arry2[i] = d;
					i++;
					if (cal[d].month == 0)
						printf("%d / %d \n", 12, cal[d].day);
					else
						printf("%d / %d \n", cal[d].month, cal[d].day);
					c++;
					break;
				}
			}
		}
	}

	printf(W);

	return i;
}

int pcanceldoctor(struct doctor doc[20], int a, int i_p, struct patient pat[20])
{
	int c = 0, k = 0, j = 0;
	for (int i = 0; i < 20; i++)
	{
		c = 0;
		for (int d = 0; d < 93; d++)
		{
			for (int v = 0; v < 20; v++)
			{
				if (doc[i].dday[d].vis[v].start > 0 && doc[i].dday[d].vis[v].id[0] > 0 && strcmp(doc[i].dday[d].vis[v].id, pat[i_p].id) == 0)
				{
					if (j == a)
					{
						printf(B);
					}
					else
					{
						printf(W);
					}
					if (c == 0)
					{
						arry[j] = i;
						j++;
						printf("Dr.%s-%s\n", doc[i].name, doc[i].lastname);
						c++;
						k++;
						break;
					}

				}


			}

			if (c > 0)
				break;
		}
	}
	if (k == 0)
	{
		printf("THERE IS NO DOCTOR .");
		WAIT;
	}
	printf(W);
	return j;
}


int printvisit(struct doctor doc[20], int a, int b, int c)
{

	int i = 0;
	for (int v = 0; v < 20; v++)
	{
		if (doc[arr[c]].dday[arr2[b]].vis[v].start > 0 && doc[arr[c]].dday[arr2[b]].vis[v].id[0] < 0)
		{
			if (i == a)
			{
				printf(B);
			}
			else
			{
				printf(W);
			}
			arr3[i] = v;
			i++;
			printf("( %.2f - %.2f )\n", doc[arr[c]].dday[arr2[b]].vis[v].start, doc[arr[c]].dday[arr2[b]].vis[v].end);
		}

	}
	printf(W);

	return i;
}

int printdday(struct doctor doc[20], int a, int b, struct calendar cal[93])
{
	int c = 0, i = 0;
	for (int d = 0; d < 93; d++)
	{
		c = 0;
		for (int v = 0; v < 20; v++)
		{
			if (doc[arr[b]].dday[d].vis[v].start > 0 && doc[arr[b]].dday[d].vis[v].id[0] < 0)
			{
				if (a == i)
				{
					printf(B);
				}
				else
				{
					printf(W);
				}
				if (c == 0)
				{
					arr2[i] = d;
					i++;
					if (cal[d].month == 0)
						printf("%d / %d \n", 12, cal[d].day);
					else
						printf("%d / %d \n", cal[d].month, cal[d].day);
					c++;
					break;
				}
			}
		}
	}

	printf(W);

	return i;
}

int printdoctor(struct doctor doc[20], int a)
{
	int c = 0, k = 0, j = 0;
	for (int i = 0; i < 20; i++)
	{
		c = 0;
		for (int d = 0; d < 93; d++)
		{
			for (int v = 0; v < 20; v++)
			{
				if (doc[i].dday[d].vis[v].start > 0 && doc[i].dday[d].vis[v].id[0] < 0)
				{
					if (j == a)
					{
						printf(B);
					}
					else
					{
						printf(W);
					}
					if (c == 0)
					{
						arr[j] = i;
						j++;
						printf("Dr.%s-%s\n", doc[i].name, doc[i].lastname);
						c++;
						k++;
						break;
					}

				}


			}

			if (c > 0)
				break;
		}
	}
	if (k == 0)
	{
		printf("THERE IS NO DOCTOR .");
		WAIT;
	}
	printf(W);
	return j;
}

int check(struct calendar cal, char username[12])
{
	for (int i = 0; i < 10; i++)
	{
		if (cal.doctor[i][3] > 0)
		{
			if (i == 9)
			{
				return 13;
			}
			continue;
		}
		else
		{
			int i2 = 0, flag = 0;
			while (cal.doctor[i2][3] > 0)
			{
				if (strcmp(cal.doctor[i2], username) == 0)
				{
					flag = 1;
					break;
				}
				i2++;
			}
			if (flag)
			{
				return -(i2 + 1);
				break;
			}
			else
			{
				return i2 + 1;
				break;
			}
		}
	}
}

void printc(struct calendar cal[100])
{
	CLEAR;
	printf(W);
	printf("SAT|SUN|MON|TUE|WED|THU|FRI\n");
	printf("---------------------------\n");
	int j1, i2 = 0, j2 = 0, n = 0;
	for (j1 = 0; j1 < cal[0].weekday; j1++)
	{
		printf("    ");
	}
	for (int i1 = 0; i1 < 15; i1++)
	{
		for (j1; j1 < 7; j1++)
		{
			if (cal[(i2 * 7) + j2].day > 0)
			{
				if (cal[(i2 * 7) + j2].sub_color == blue)
				{
					printf(B);
					cal[(i2 * 7) + j2].sub_color = white;
				}
				else
				{
					switch (cal[(i2 * 7) + j2].main_color)
					{
					case 0:
						printf(W);
						break;
					case 1:
						printf(R);
					}
				}
				printf("%3d|", cal[(i2 * 7) + j2].day);
				j2 = (j2 + 1) % 7;
				n++;
				i2 = (n) / 7;
			}
		}
		printf("\n");
		j1 = 0;
	}
	printf(W);
	return;
}

int main()
{
	int flag1 = 0;
	int i_doc = 0;
	int i_pat = 0;
	int i_cal = 0;
	struct doctor doc[20];
	struct patient pat[20];
	struct calendar cal[93];
	FILE* fcal;
	FILE* fdoc;
	FILE* fpat;
	FILE* fdata;
	fdoc = fopen("Doctors.txt", "r");
	if (fdoc != NULL)
	{
		while (true)
		{
			fread(&doc[i_doc], sizeof(doc[i_doc]), 1, fdoc);
			i_doc++;
			if (feof(fdoc))
				break;
		}
	}
	if (i_doc > 0)
	{
		i_doc--;
	}
	for (int i = 0; i < i_doc; i++)
	{
		hashback(doc[i].codemeli);
	}
	fpat = fopen("Patients.txt", "r");
	if (fpat != NULL)
	{
		while (true)
		{
			fread(&pat[i_pat], sizeof(pat[i_pat]), 1, fpat);
			i_pat++;
			if (feof(fpat))
				break;
		}
	}
	if (i_pat > 0)
	{
		i_pat--;
	}
	for (int i = 0; i < i_pat; i++)
	{
		hashback(pat[i].codemeli);
	}
	fcal = fopen("Calendar.bin", "rb");
	if (fcal != NULL)
	{
		flag1 = 1;
		while (true)
		{
			fread(&cal[i_cal], sizeof(cal[i_cal]), 1, fcal);
			i_cal++;
			if (feof(fcal))
				break;
		}
	}
	if (i_cal > 0)
	{
		i_cal--;
	}
	int calendar_length;
	int month_start[3];
	int month_length[3];
	int year, month, day;
	int firstyear, firstmonth, firstday;
	fdata = fopen("Data.txt", "r");
	if (fdata != NULL)
	{
		fread(&firstyear, sizeof(firstyear), 1, fdata);
		fread(&firstmonth, sizeof(firstmonth), 1, fdata);
		fread(&firstday, sizeof(firstday), 1, fdata);
		for (int i10 = 0; i10 < 3; i10++)
		{
			fread(&month_length[i10], sizeof(month_length[i10]), 1, fdata);

		}
		fread(&calendar_length, sizeof(calendar_length), 1, fdata);
		for (int i11 = 0; i11 < 3; i11++)
		{
			fread(&month_start[i11], sizeof(month_start[i11]), 1, fdata);
		}
		fclose(fdata);
	}
	char firstweekday[20];
	while (true)
	{
		CLEAR;
		printf(C);
		printf("PLEASE ENTER THE DATE : ");
		scanf("%4d%2d%2d", &year, &month, &day);
		if (flag1 == 0)
		{
			printf("WEEKDAY : ");
			scanf("%s", firstweekday);
			firstday = day;
			firstmonth = month;
			firstyear = year;
			for (int i1 = 0; i1 < 3; i1++)
			{
				switch ((month + i1) % 12)
				{
				case 1:case 2:case 3:case 4:case 5:case 6:
					month_length[i1] = 31;
					break;
				case 7: case 8: case 9: case 10: case 11:
					month_length[i1] = 30;
					break;
				case 0:
					month_length[i1] = 29;
					break;
				}
			}
			calendar_length = month_length[0] + month_length[1] + month_length[2];
			month_start[0] = 0;
			month_start[1] = month_length[0];
			month_start[2] = month_length[0] + month_length[1];
			fdata = fopen("Data.txt", "w");
			if (fdata == NULL)
			{
				printf("ERROR IN OPENING FILE !");
				return 0;
			}
			fwrite(&year, sizeof(year), 1, fdata);
			fwrite(&month, sizeof(month), 1, fdata);
			fwrite(&day, sizeof(day), 1, fdata);
			for (int i8 = 0; i8 < 3; i8++)
			{
				fwrite(&month_length[i8], sizeof(month_length[i8]), 1, fdata);

			}
			fwrite(&calendar_length, sizeof(calendar_length), 1, fdata);
			for (int i9 = 0; i9 < 3; i9++)
			{
				fwrite(&month_start[i9], sizeof(month_start[i9]), 1, fdata);
			}
			fclose(fdata);
			if (strcmp(firstweekday, "SATURDAY") == 0 || strcmp(firstweekday, "SAT") == 0)
			{
				cal[0].weekday = 0;
				break;
			}
			else if (strcmp(firstweekday, "SUNDAY") == 0 || strcmp(firstweekday, "SUN") == 0)
			{
				cal[0].weekday = 1;
				break;
			}
			else if (strcmp(firstweekday, "MONDAY") == 0 || strcmp(firstweekday, "MON") == 0)
			{
				cal[0].weekday = 2;
				break;
			}
			else if (strcmp(firstweekday, "TUESDAY") == 0 || strcmp(firstweekday, "TUE") == 0)
			{
				cal[0].weekday = 3;
				break;
			}
			else if (strcmp(firstweekday, "WEDNESDAY") == 0 || strcmp(firstweekday, "WED") == 0)
			{
				cal[0].weekday = 4;
				break;
			}
			else if (strcmp(firstweekday, "THURSDAY") == 0 || strcmp(firstweekday, "THU") == 0)
			{
				cal[0].weekday = 5;
				break;
			}
			else if (strcmp(firstweekday, "FRIDAY") == 0 || strcmp(firstweekday, "FRI") == 0)
			{
				cal[0].weekday = 6;
				break;
			}
			else
			{
				printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
				WAIT;
			}
		}
		else
		{
			break;
		}
	}

	CLEAR;
	int f;
	f = 0;
	if (month == 0 || year > firstyear)
		f = 12;
	for (int i = 0; i < i_doc; i++)
	{
		if (month + f > firstmonth + 1 && doc[i].payment == 0)
		{
			printf(R);
			printf("Dr.%s %s was removed due to non-payment of rent\n", doc[i].name, doc[i].lastname);
			WAIT;
			WAIT;
			for (int j = i; j < i_doc; j++)
			{
				doc[j] = doc[j + 1];
			}
			i_doc--;
			i--;

		}
	}
	CLEAR;

	for (int i = 0; i < i_doc; i++)
	{
		hash(doc[i].codemeli);
	}
	fdoc = fopen("Doctors.txt", "w");
	if (fdoc == NULL)
	{
		printf(R);
		printf("ERROR IN OPENING FILE !");
		return 0;
	}
	for (int i19 = 0; i19 < i_doc; i19++)
	{
		fwrite(&doc[i19], sizeof(doc[i19]), 1, fdoc);
	}
	fclose(fdoc);
	for (int i = 0; i < i_doc; i++)
	{
		hashback(doc[i].codemeli);
	}

	while (true)
	{
		// MENU :

	menu:
		CLEAR;
		printf(G);
		printf("1. SIGN IN\n");
		printf(W);
		printf("2. FORGOT PASSWORD\n");
		printf(R);
		printf("3. EXIT\n");
		printf(W);
		char input1[30];
		scanf("%s", input1);
		if (strcmp(input1, "1") == 0)
		{
			while (true)
			{
				// SIGN IN :

			sign_in:
				CLEAR;
				printf(P);
				char username[20], password[20];
				printf("USERNAME : ");
				scanf("%s", username);
				strcpy(password, "面面面面面面");
				printf("PASSWORD : ");
				passw(password, username);
				if (strcmp(username, "Admin") == 0 && strcmp(password, "Admin") == 0)
				{
					// ADMIN : 

				admin:
					while (true)
					{
						CLEAR;
						printf(C);
						printf("1. ADD DOCTOR\n");
						printf("2. ADD PATIENT\n");
						printf("3. MONTHLY SCHEDULE\n");
						printf("4. VISITS SCHEDULE\n");
						printf(R);
						printf("5. BACK\n");
						char input2[30];
						scanf("%s", input2);
						if (strcmp(input2, "1") == 0)
						{
							// ADD DOCTOR : 

							CLEAR;

							char name_d[100], lastname_d[100];
							printf(P);
							printf("NAME : ");
							scanf("%s", name_d);
							printf("\nLAST NAME : ");
							scanf("%s", lastname_d);
							int i2 = 0;
							while (i2 < i_doc)
							{
								if (strcmp(name_d, doc[i2].name) == 0 && strcmp(lastname_d, doc[i2].lastname) == 0)
								{
									printf(Y);
									printf("\nTHIS DOCTOR HAS ALREADY BEEN ADDED !");
									WAIT;
									goto admin;
								}
								i2++;
							}
							printf(P);
							strcpy(doc[i_doc].name, name_d);
							strcpy(doc[i_doc].lastname, lastname_d);
							printf("\nCODE : ");
							scanf("%s", doc[i_doc].codemeli);
							printf("\nEMAIL : ");
							scanf("%s", doc[i_doc].email);
							strcpy(doc[i_doc].id, "1001401");
							int a1, a2, a3;
							char b_d[4];
							a1 = i_doc % 10;
							a2 = (i_doc / 10) % 10;
							a3 = (i_doc / 100) % 10;
							b_d[0] = (char)a3 + 48;
							b_d[1] = (char)a2 + 48;
							b_d[2] = (char)a1 + 48;
							b_d[3] = '\0';
							strcat(doc[i_doc].id, b_d);
							doc[i_doc].wallet = 10;
							printf("\nYOUR WALLET CREDIT : %d $", doc[i_doc].wallet);
							printf("\nYOUR ID : %s", doc[i_doc].id);
							WAIT;
							WAIT;
							for (int i = 0; i < i_doc + 1; i++)
							{
								hash(doc[i].codemeli);
							}
							fdoc = fopen("Doctors.txt", "a");
							if (fdoc == NULL)
							{
								printf(R);
								printf("ERROR IN OPENING FILE !");
								return 0;
							}
							fwrite(&doc[i_doc], sizeof(doc[i_doc]), 1, fdoc);
							fclose(fdoc);
							for (int i = 0; i < i_doc + 1; i++)
							{
								hashback(doc[i].codemeli);
							}
							i_doc++;
						}
						else if (strcmp(input2, "2") == 0)
						{
							// ADD PATIENT 

							CLEAR;
							printf(P);
							int i3 = 0;
							char name_p[100], lastname_p[100];
							printf("NAME : ");
							scanf("%s", name_p);
							printf("\nLAST NAME : ");
							scanf("%s", lastname_p);
							while (i3 < i_pat)
							{
								if (strcmp(name_p, pat[i3].name) == 0 && strcmp(lastname_p, pat[i3].lastname) == 0)
								{
									printf(Y);
									printf("\nTHIS PATIENT HAS ALREADY BEEN ADDED !");
									WAIT;
									goto admin;
								}
								i3++;
							}
							printf(P);
							strcpy(pat[i_pat].name, name_p);
							strcpy(pat[i_pat].lastname, lastname_p);
							printf("\nCODE : ");
							scanf("%s", pat[i_pat].codemeli);
							printf("\nEMAIL : ");
							scanf("%s", pat[i_pat].email);
							strcpy(pat[i_pat].id, "1121401");
							int a4, a5, a6;
							char b_p[4];
							a4 = i_pat % 10;
							a5 = (i_pat / 10) % 10;
							a6 = (i_pat / 100) % 10;
							b_p[0] = (char)a6 + 48;
							b_p[1] = (char)a5 + 48;
							b_p[2] = (char)a4 + 48;
							b_p[3] = '\0';
							strcat(pat[i_pat].id, b_p);
							pat[i_pat].wallet = 500;
							printf("\nYOUR WALLET CREDIT : %d $", pat[i_pat].wallet);
							printf("\nYOUR ID : %s", pat[i_pat].id);
							WAIT;
							WAIT;
							for (int i = 0; i < i_pat + 1; i++)
							{
								hash(pat[i].codemeli);
							}
							fpat = fopen("Patients.txt", "a");
							if (fpat == NULL)
							{
								printf(R);
								printf("ERROR IN OPENING FILE !");
								return 0;
							}
							fwrite(&pat[i_pat], sizeof(pat[i_pat]), 1, fpat);
							fclose(fpat);
							for (int i = 0; i < i_pat; i++)
							{
								hashback(pat[i].codemeli);
							}
							for (int i = 0; i < i_pat + 1; i++)
							{
								hashback(pat[i].codemeli);
							}
							i_pat++;
						}
						else if (strcmp(input2, "3") == 0)
						{
							// MONTHLY SCHEDULE :

							for (int i4 = 0; i4 < 3; i4++)
							{
								for (int i5 = 0; i5 < month_length[i4]; i5++)
								{
									cal[i5 + month_start[i4]].day = i5 + 1;
									cal[i5 + month_start[i4]].month = ((month + i4) % 12);
								}
								for (int t13 = 0; t13 < month_length[i4]; t13++)
								{
									cal[t13 + month_start[i4]].weekday = ((t13 + month_start[i4] + cal[0].weekday) % 7);
								}
								for (int t13 = 0; t13 < month_length[i4]; t13++)
								{
									if (cal[t13 + month_start[i4]].weekday == 6)
									{
										cal[t13 + month_start[i4]].main_color = red;
									}
									else
									{
										cal[t13 + month_start[i4]].main_color = white;
									}
								}
								for (int t17 = 0; t17 < month_length[i4]; t17++)
								{
									cal[t17 + month_start[i4]].start = 8;
									if (cal[t17 + month_start[i4]].weekday < 5)
									{
										cal[t17 + month_start[i4]].end = 21;
									}
									if (cal[t17 + month_start[i4]].weekday == 5)
									{
										cal[t17 + month_start[i4]].end = 13;
									}
								}
								int t1, ij = 13, flag2 = 0;
								while (true)
								{
									printc(cal);
									t1 = getch();
									switch (t1)
									{
									case 72: // UP :
										if (ij - 7 >= 0)
											ij -= 7;
										cal[ij].sub_color = blue;
										break;
									case 80: // DOWN :
										if (ij + 7 < calendar_length)
											ij += 7;
										cal[ij].sub_color = blue;
										break;
									case 75: // LEFT :
										if (ij - 1 >= 0)
											ij--;
										cal[ij].sub_color = blue;
										break;
									case 77: // RIGHT :
										if (ij + 1 < calendar_length)
											ij++;
										cal[ij].sub_color = blue;
										break;
									case 13: // ENTER :
										if (cal[ij].main_color == white)
										{
											printf(P);
											cal[ij].main_color = red;
											printf("\n\nREASON : ");
											scanf("%s", cal[ij].reason);
										}
										else if (cal[ij].main_color == red && cal[ij].weekday != 6)
										{
											cal[ij].main_color = white;
											strcpy(cal[ij].reason, "\0");
										}
										break;
									case 32: // SPACE :
										flag2 = 1;
										break;
									}
									if (flag2 == 1)
									{
										flag2 = 0;
										break;
									}
								}
							}
							printf(W);
							fcal = fopen("Calendar.bin", "wb");
							if (fcal == NULL)
							{
								printf(R);
								printf("ERROR IN OPENING FILE !");
								return 0;
							}
							for (int i6 = 0; i6 < calendar_length; i6++)
							{
								fwrite(&cal[i6], sizeof(cal[i6]), 1, fcal);
								i_cal++;
							}
							fclose(fcal);
						}
						else if (strcmp(input2, "4") == 0)
						{
							// VISITS SCHEDULE :

							while (true)
							{
								CLEAR;
								printf(C);
								printf("1. ALL\n");
								printf("2. CHOOSE DOCTOR\n");
								printf(R);
								printf("3. BACK\n");
								char input3[100];
								scanf("%s", input3);
								if (strcmp(input3, "1") == 0)
								{
									// ALL :

									CLEAR;
									int c3 = 0;
									for (int i = 0; i < 20; i++)
									{
										for (int d = 0; d < 93; d++)
										{
											for (int v = 0; v < 20; v++)
											{
												if (doc[i].dday[d].vis[v].id[0] > 0)
												{
													printf("Dr.%s-%s : %s ( %.2f - %.2f )\n", doc[i].name, doc[i].lastname, doc[i].dday[d].vis[v].id, doc[i].dday[d].vis[v].start, doc[i].dday[d].vis[v].end);
													c3++;
												}
											}
										}
									}
									if (c3 == 0)
									{
										printf(R);
										printf("THERE IS NO APOINTMENT .");
										WAIT;
									}
									else
									{
										WAIT;
										WAIT;
										WAIT;
										WAIT;
									}
								}
								else if (strcmp(input3, "2") == 0)
								{
									// CHOOSE DOCTOR :


									int i40 = 0;
									while (true)
									{
										CLEAR;
										printdoctor(doc, i40);
										switch (getch())
										{
										case 72: // UP :
											if (i40 > 0)
												i40--;
											break;
										case 80: // DOWN :
											if (i40 < i_doc - 1)
												i40++;
											break;
										case 32: // SPACE :
											goto admin;
											break;
										case 13: // ENTER :
											while (true)
											{
												CLEAR;
												for (int d = 0; d < 93; d++)
												{
													for (int v = 0; v < 20; v++)
													{
														if (doc[i40].dday[d].vis[v].id[0] > 0)
														{
															printf("%s : ( %.2f - %.2f )\n", doc[i40].dday[d].vis[v].id, doc[i40].dday[d].vis[v].start, doc[i40].dday[d].vis[v].end);
														}
													}
												}
												printf(Y);
												printf("PRESS SPACE T0 GO BACK .\n");
												printf(W);
												if (getch() == 32)
												{
													break;
												}
											}
											break;
										}
									}
								}
								else if (strcmp(input3, "3") == 0)
								{
									// BACK :

									goto admin;
								}
								else
								{
									// INVALID ANSWER :

									printf(R);
									printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
									WAIT;
								}
							}
						}
						else if (strcmp(input2, "5") == 0)
						{
							// BACK :

							goto menu;
						}
						else
						{
							// INVALID ANSWER :

							printf(R);
							printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
							WAIT;
						}
					}
				}
				else
				{
					int i_p = 0;
					int i_d = 0;
					int flag3 = 0;
					for (int i7 = 0; i7 < i_doc; i7++)
					{
						if (strcmp(doc[i7].id, username) == 0 && strcmp(doc[i7].codemeli, password) == 0)
						{
							flag3 = 1;
							i_d = i7;
							break;
						}
					}
					for (int i8 = 0; i8 < i_pat; i8++)
					{
						if (strcmp(username, pat[i8].id) == 0 && strcmp(password, pat[i8].codemeli) == 0)
						{
							flag3 = 2;
							i_p = i8;
							break;
						}
					}
					if (flag3 == 1)
					{
						// DOCTORS' PAGE :

					doctor_page:
						while (true)
						{
							CLEAR;
							printf(C);
							printf("1. DETERMINING THE SHIFTS\n");
							printf("2. RESERVED VISITS\n");
							printf("3. PATIENT PRESCRIPTION\n");
							printf("4. RENT PAYMENT\n");
							printf("5. VISIRS PAYMENT\n");
							printf(R);
							printf("6. BACK\n");
							char input4[30];
							scanf("%s", input4);
							if (strcmp(input4, "1") == 0)
							{
								// DETERMINING THE SHIFTS :

								while (true)
								{
									CLEAR;
									printf(C);
									printf("1. SET FOR A DAY\n");
									printf("2. RECURRING DAYS IN THE MONTH\n");
									printf(R);
									printf("3. BACK\n");
									char input5[30];
									scanf("%s", input5);
									if (strcmp(input5, "1") == 0)
									{
										// SET FOR A DAY :

										int t2, ij = 13, flag4 = 0;
										while (true)
										{
											printc(cal);
											t2 = getch();
											switch (t2)
											{
											case 72: // UP :
												if (ij - 7 >= 0)
													ij -= 7;
												cal[ij].sub_color = blue;
												break;
											case 80: // DOWN :
												if (ij + 7 < calendar_length)
													ij += 7;
												cal[ij].sub_color = blue;
												break;
											case 75: // LEFT :
												if (ij - 1 >= 0)
													ij--;
												cal[ij].sub_color = blue;
												break;
											case 77: // RIGHT :
												if (ij + 1 < calendar_length)
													ij++;
												cal[ij].sub_color = blue;
												break;
											case 13: // ENTER :

												if (cal[ij].main_color == red)
												{
													printf(R);
													printf("THIS DAY , THE CLINIC IS CLOSED !");
													WAIT;
												}
												else
												{
													for (int i10 = 0; i10 < 10; i10++)
													{
														if (cal[ij].doctor[i10][0] > 0)
														{
															if (i10 == 9)
															{
																printf(R);
																printf("THE CLINIC IS FULL !");
																WAIT;
															}
															continue;
														}
														else
														{
															int i11 = 0, flag5 = 0;
															while (cal[ij].doctor[i11][3] > 0)
															{
																if (strcmp(cal[ij].doctor[i11], username) == 0)
																{
																	flag5 = 1;
																	break;
																}
																i11++;
															}
															if (flag5)
															{
																strcpy(cal[ij].doctor[i11], "面面面面面面");
																int i18 = doc[i_d].dday[ij].i_v;
																while (doc[i_d].dday[ij].vis[i18].start > 0)
																{
																	doc[i_d].dday[ij].vis[i18].start = -13;
																	doc[i_d].dday[ij].vis[i18].end = -13;
																	i18++;
																}
																printf(Y);
																printf("YOUR BOOKING WAS CANCELLED .");
																WAIT;
																break;
															}
															else
															{
																float checkin, checkout;
																float t9;
																int flag7 = 0;
																while (true)
																{
																	CLEAR;
																	printc(cal);
																	printf(C);
																	printf("ENTER YOUR CHECK-IN AND CHECK-OUT TIMES : ");
																	scanf("%f - %f", &checkin, &checkout);
																	if (checkin >= cal[ij].start && checkin < cal[ij].end)
																		if (checkout > cal[ij].start && checkout <= cal[ij].end)
																			if (checkin < checkout)
																			{
																				while (true)
																				{
																					CLEAR;
																					printc(cal);
																					printf(C);
																					printf("CHOOSE YOUR TURN DURATION .\n");
																					printf("1. 60 min\n");
																					printf("2. 90 min\n");
																					printf("3. 120 min\n");
																					printf("4. 150 min\n");
																					char input9[30];
																					scanf("%s", input9);

																					if (strcmp(input9, "1") == 0)
																					{
																						t9 = 1;
																						flag7 = 1;
																						break;
																					}
																					else if (strcmp(input9, "2") == 0)
																					{
																						t9 = 1.30;
																						flag7 = 1;
																						break;
																					}
																					else if (strcmp(input9, "3") == 0)
																					{
																						t9 = 2;
																						flag7 = 1;
																						break;
																					}
																					else if (strcmp(input9, "4") == 0)
																					{
																						t9 = 2.30;
																						flag7 = 1;
																						break;
																					}
																					else
																					{
																						printf(R);
																						printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
																						WAIT;
																					}
																				}
																			}
																	if (flag7)
																	{
																		break;
																	}
																	else
																	{
																		printf(R);
																		printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
																		WAIT;
																	}
																}
																float t10 = checkin;
																int i18 = doc[i_d].dday[ij].i_v;
																strcpy(cal[ij].doctor[i10], username);
																while (sum(t10, t9) <= checkout)
																{
																	doc[i_d].dday[ij].vis[i18].start = t10;
																	doc[i_d].dday[ij].vis[i18].end = sum(t10, t9);
																	i18++;
																	t10 = sum(t10, t9);
																}
																printf(G);
																printf("THIS DAY WAS SUCCESSFULLY BOOKED .");
																WAIT;
																break;
															}
														}
													}
												}
												for (int i = 0; i < i_doc; i++)
												{
													hash(doc[i].codemeli);
												}
												fdoc = fopen("Doctors.txt", "w");
												if (fdoc == NULL)
												{
													printf(R);
													printf("ERROR IN OPENING FILE !");
													return 0;
												}
												for (int i19 = 0; i19 < i_doc; i19++)
												{
													fwrite(&doc[i19], sizeof(doc[i19]), 1, fdoc);
												}
												fclose(fdoc);
												for (int i = 0; i < i_doc; i++)
												{
													hashback(doc[i].codemeli);
												}
												fcal = fopen("Calendar.bin", "wb");
												if (fcal == NULL)
												{
													printf(R);
													printf("ERROR IN OPENING FILE !");
													return 0;
												}
												for (int i12 = 0; i12 < calendar_length; i12++)
												{
													fwrite(&cal[i12], sizeof(cal[i12]), 1, fcal);
												}
												fclose(fcal);
												break;
											case 32: // SPACE :
												flag4 = 1;
												break;
											}
											if (flag4 == 1)
											{
												flag4 = 0;
												break;
											}
										}
									}
									else if (strcmp(input5, "2") == 0)
									{
										// RECURRING DAYS IN THE MONTH :


										struct calendar t3[31];
										int t4 = month - firstmonth;
										if (t4 < 0)
											t4 = t4 + 12;
										int flag6;
										for (int i13 = 0; i13 < month_length[t4]; i13++)
										{
											t3[i13] = cal[i13 + month_start[t4]];
										}
										while (true)
										{
											CLEAR;
											printc(t3);
											printf(C);
											printf("ON WHICH DAYS OF THE WEEK CAN YOU ATTEND THE CLINIC ?\n");
											char input7[30];
											scanf("%s", input7);
											if (strcmp(input7, "SATURDAY") == 0 || strcmp(input7, "SAT") == 0)
											{
												flag6 = 0;
												break;
											}
											else if (strcmp(input7, "SUNDAY") == 0 || strcmp(input7, "SUN") == 0)
											{
												flag6 = 1;
												break;
											}
											else if (strcmp(input7, "MONDAY") == 0 || strcmp(input7, "MON") == 0)
											{
												flag6 = 2;
												break;
											}
											else if (strcmp(input7, "TUESDAY") == 0 || strcmp(input7, "TUE") == 0)
											{
												flag6 = 3;
												break;
											}
											else if (strcmp(input7, "WEDNESDAY") == 0 || strcmp(input7, "WED") == 0)
											{
												flag6 = 4;
												break;
											}
											else if (strcmp(input7, "THURSDAY") == 0 || strcmp(input7, "THU") == 0)
											{
												flag6 = 5;
												break;
											}
											else if (strcmp(input7, "FRIDAY") == 0 || strcmp(input7, "FRI") == 0)
											{
												flag6 = 6;
												printf(R);
												printf("THESE DAYS , THE CLINIC IS CLOSED .");
												WAIT;
												goto doctor_page;
												break;
											}
											else
											{
												printf(R);
												printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
												WAIT;
											}
										}
										struct calendar t5[5];
										int i15 = 0, c1 = 0, t7[5];
										for (int i14 = 0; i14 < month_length[t4]; i14++)
										{
											if (t3[i14].weekday == flag6)
											{
												t5[i15] = t3[i14];
												t7[i15] = i14;
												i15++;
												if (t3[i14].main_color == red)
													c1++;
											}
										}
										float checkin2, checkout2;
										float t11;
										int flag8 = 0;
										while (true)
										{
											CLEAR;
											printc(t3);
											printf(C);
											printf("ENTER YOUER CHECK-IN AND CHECK-OUT TIMES : ");
											scanf("%f - %f", &checkin2, &checkout2);
											if (checkin2 >= t5[0].start && checkin2 < t5[0].end)
												if (checkout2 > t5[0].start && checkout2 <= t5[0].end)
													if (checkin2 < checkout2)
													{
														while (true)
														{
															CLEAR;

															printc(t3);
															printf(C);
															printf("CHOOSE YOUR TURN DURATION .\n");
															printf("1. 60 min\n");
															printf("2. 90 min\n");
															printf("3. 120 min\n");
															printf("4. 150 min\n");
															char input10[30];
															scanf("%s", input10);

															if (strcmp(input10, "1") == 0)
															{
																t11 = 1;
																flag8 = 1;
																break;
															}
															else if (strcmp(input10, "2") == 0)
															{
																t11 = 1.30;
																flag8 = 1;
																break;
															}
															else if (strcmp(input10, "3") == 0)
															{
																t11 = 2;
																flag8 = 1;
																break;
															}
															else if (strcmp(input10, "4") == 0)
															{
																t11 = 2.30;
																flag8 = 1;
																break;
															}
															else
															{
																printf(R);
																printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
																WAIT;
															}
														}
													}
											if (flag8)
											{
												break;
											}
											else
											{
												printf(R);
												printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
												WAIT;
											}
										}
										printf(W);
										int i16 = 0;
										switch (c1)
										{
										case 0:
											CLEAR;
											while (t5[i16].day > 0)
											{
												int t6 = check(t5[i16], username);
												if (t6 > 0)
												{
													strcpy(cal[t7[i16] + month_start[t4]].doctor[t6 - 1], username);
													float t12 = checkin2;
													int i20 = doc[i_d].dday[t7[i16] + month_start[t4]].i_v;
													while (sum(t12, t11) <= checkout2)
													{
														doc[i_d].dday[t7[i16] + month_start[t4]].vis[i20].start = t12;
														doc[i_d].dday[t7[i16] + month_start[t4]].vis[i20].end = sum(t12, t11);
														i20++;
														t12 = sum(t12, t11);
													}
													printf(G);
													printf("%d : WAS SUCCESSFULLY BOOKED .\n", cal[t7[i16] + month_start[t4]].day);
													WAIT;
												}
												else if (t6 == 13)
												{
													printf(R);
													printf("%d : THE CLINIC IS FULL .\n", cal[t7[i16] + month_start[t4]].day);
													WAIT;
												}
												else if (t6 < 0)
												{
													printf(Y);
													printf("%d : YOU HAVE ALREADY BOOKED TISE DAY .\n", cal[t7[i16] + month_start[t4]].day);
													WAIT;
												}
												i16++;
											}

											break;
										case 1: case 2: case 3:

											while (true)
											{
												CLEAR;
												printf(C);
												printf("THE CLINIC IS CLOSED ON SOME DAYS .\n");
												printf("WOULD YOU LIKE TO BOOK OTHER DAYS OF YOUR CHOICE ?\n");
												printf("1. YES\n");
												printf("2. NO\n");
												char input8[30];
												scanf("%s", input8);
												if (strcmp(input8, "1") == 0)
												{
													// YES :

													printc(t3);
													int i17 = 0;
													while (t5[i17].weekday >= 0)
													{
														int t8 = check(t5[i17], username);
														if (t5[i17].main_color != red)
														{
															if (t8 > 0)
															{
																strcpy(cal[t7[i17] + month_start[t4]].doctor[t8 - 1], username);
																float t12 = checkin2;
																int i20 = doc[i_d].dday[t7[i16] + month_start[t4]].i_v;
																while (sum(t12, t11) <= checkout2)
																{
																	doc[i_d].dday[t7[i17] + month_start[t4]].vis[i20].start = t12;
																	doc[i_d].dday[t7[i17] + month_start[t4]].vis[i20].end = sum(t12, t11);
																	i20++;
																	t12 = sum(t12, t11);
																}
																printf(G);
																printf("%d : WAS SUCCESSFULLY BOOKED .\n", cal[t7[i17] + month_start[t4]].day);
																WAIT;
															}
															else if (t8 == 13)
															{
																printf(R);
																printf("%d : THE CLINIC IS FULL .\n", cal[t7[i17] + month_start[t4]].day);
																WAIT;
															}
															else if (t8 < 0)
															{
																printf(Y);
																printf("%d : YOU HAVE ALREADY BOOKED TISE DAY .\n", cal[t7[i17] + month_start[t4]].day);
																WAIT;
															}
														}
														i17++;
													}

													break;
												}
												else if (strcmp(input8, "2") == 0)
												{
													// NO : 

													break;
												}
												else
												{
													// INVALID ANSWER : 

													printf(R);
													printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
													WAIT;
												}
											}

											break;
										case 4: case 5:
											printf(R);
											printf("THESE DAYS , THE CLINIC IS CLOSED !");
											WAIT;
											break;
										}
										for (int i = 0; i < i_doc; i++)
										{
											hash(doc[i].codemeli);
										}
										fdoc = fopen("Doctors.txt", "w");
										if (fdoc == NULL)
										{
											printf(R);
											printf("ERROR IN OPENING FILE !");
											return 0;
										}
										for (int i19 = 0; i19 < i_doc; i19++)
										{
											fwrite(&doc[i19], sizeof(doc[i19]), 1, fdoc);
										}
										fclose(fdoc);
										for (int i = 0; i < i_doc; i++)
										{
											hashback(doc[i].codemeli);
										}
										fcal = fopen("Calendar.bin", "wb");
										if (fcal == NULL)
										{
											printf(R);
											printf("ERROR IN OPENING FILE !");
											return 0;
										}
										for (int i12 = 0; i12 < calendar_length; i12++)
										{
											fwrite(&cal[i12], sizeof(cal[i12]), 1, fcal);
										}
										fclose(fcal);
									}
									else if (strcmp(input5, "3") == 0)
									{
										// BACK :

										goto doctor_page;
									}
									else
									{
										// INVALID ANSWER :

										printf(R);
										printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
										WAIT;
									}
								}
							}
							else if (strcmp(input4, "2") == 0)
							{
								// RESERVED VISITS :


								while (true)
								{
									CLEAR;
									int c4 = 0;
									for (int i24 = 0; i24 < 7; i24++)
									{
										switch (cal[day + i24 - 1].weekday)
										{
										case 0:
											printf("SAT : ");
											break;
										case 1:
											printf("SUN : ");
											break;
										case 2:
											printf("MON : ");
											break;
										case 3:
											printf("TUE : ");
											break;
										case 4:
											printf("WED : ");
											break;
										case 5:
											printf("THU : ");
											break;
										case 6:
											printf("FRI : ");
											break;
										}
										for (int i25 = 0; i25 < 20; i25++)
										{
											if (doc[i_d].dday[day + i24 - 1].vis[i25].id[0] > 0)
											{
												printf("( %.2f - %.2f ) ", doc[i_d].dday[day + i24 - 1].vis[i25].start, doc[i_d].dday[day + i24 - 1].vis[i25].end);
												c4++;
											}
										}

										printf("\n");
									}
									if (c4 == 0)
									{
										printf(R);
										printf("YOU HAVE NO VISITORS THIS WEEK .");
										WAIT;
										WAIT;
										break;
									}
									printf("\n");
									printf(C);
									printf("DO YOU WANT TO SEE YOUR PATIENT INFORMATION ?\n");
									printf("1. YES\n");
									printf("2. NO\n");
									char input12[30];
									scanf("%s", input12);
									if (strcmp(input12, "1") == 0)
									{
										// YES :

										while (true)
										{
											int c2 = 0;
											CLEAR;
											for (int i26 = 0; i26 < 7; i26++)
											{
												switch (cal[day + i26 - 1].weekday)
												{
												case 0:
													printf("SAT : ");
													break;
												case 1:
													printf("SUN : ");
													break;
												case 2:
													printf("MON : ");
													break;
												case 3:
													printf("TUE : ");
													break;
												case 4:
													printf("WED : ");
													break;
												case 5:
													printf("THU : ");
													break;
												case 6:
													printf("FRI : ");
													break;
												}
												for (int i27 = 0; i27 < 20; i27++)
												{
													if (doc[i_d].dday[day + i26 - 1].vis[i27].id[0] > 0)
													{
														printf("( %.2f - %.2f ) ", doc[i_d].dday[day + i26 - 1].vis[i27].start, doc[i_d].dday[day + i26 - 1].vis[i27].end);
														c2++;
													}
												}
												printf("\n");
											}
											if (c2 == 0)
											{
												printf(R);
												printf("YOU HAVE NO VISITORS THIS WEEK .");
												WAIT;
												break;
											}
											else
												printf("\n");
											printf(C);
											printf("ENTER THE DAY OF YOUR CHOICE : ");
											int t13;
											char input13[30];
											scanf("%s", input13);
											if ((strcmp(input13, "SAT") == 0) || (strcmp(input13, "SUN") == 0) || (strcmp(input13, "MON") == 0) || (strcmp(input13, "TUE") == 0) || (strcmp(input13, "WED") == 0) || (strcmp(input13, "THU") == 0) || (strcmp(input13, "FRI") == 0))
											{
												if (strcmp(input13, "SAT") == 0)
												{
													t13 = 0;
												}
												else if (strcmp(input13, "SUN") == 0)
												{
													t13 = 1;
												}
												else if (strcmp(input13, "MON") == 0)
												{
													t13 = 2;
												}
												else if (strcmp(input13, "TUE") == 0)
												{
													t13 = 3;
												}
												else if (strcmp(input13, "WED") == 0)
												{
													t13 = 4;
												}
												else if (strcmp(input13, "THU") == 0)
												{
													t13 = 5;
												}
												else if (strcmp(input13, "FRI") == 0)
												{
													t13 = 6;
												}
												int t14;
												for (int i30 = 0; i30 < 7; i30++)
												{
													if (t13 == cal[day + i30 - 1].weekday)
													{
														t14 = day + i30 - 1;
														break;
													}
												}
												while (true)
												{

													CLEAR;
													switch (cal[t14].weekday)
													{
													case 0:
														printf("SAT : ");
														break;
													case 1:
														printf("SUN : ");
														break;
													case 2:
														printf("MON : ");
														break;
													case 3:
														printf("TUE : ");
														break;
													case 4:
														printf("WED : ");
														break;
													case 5:
														printf("THU : ");
														break;
													case 6:
														printf("FRI : ");
														break;
													}
													for (int i29 = 0; i29 < 20; i29++)
													{
														if (doc[i_d].dday[t14].vis[i29].id[0] > 0)
														{
															printf("( %.2f - %.2f ) ", doc[i_d].dday[t14].vis[i29].start, doc[i_d].dday[t14].vis[i29].end);
														}
													}
													printf("\n");

													int flag10 = 0;
													printf("\n");
													printf(C);
													printf("ENTER YOUR TIME PERIOD YOU WANT : ");
													float s, e;
													char t15[20];
													scanf("%f - %f", &s, &e);
													for (int i29 = 0; i29 < 20; i29++)
													{
														if (doc[i_d].dday[t14].vis[i29].id[0] > 0)
														{
															if ((s == doc[i_d].dday[t14].vis[i29].start) && (e == doc[i_d].dday[t14].vis[i29].end))
															{
																strcpy(t15, doc[i_d].dday[t14].vis[i29].id);
																for (int i31 = 0; i31 < i_pat; i31++)
																{
																	if (strcmp(t15, pat[i31].id) == 0)
																	{
																		CLEAR;
																		printf(Y);
																		printf("NAME : %s\n", pat[i31].name);
																		printf("LAST NAME : %s\n", pat[i31].lastname);
																		printf("CODE : %s\n", pat[i31].codemeli);
																		printf("EMAIL : %s\n", pat[i31].email);
																		printf("ID : %s\n", pat[i31].id);
																		flag10 = 1;
																		WAIT;
																		WAIT;
																		WAIT;
																	}
																}
															}
														}
													}

													if (flag10)
														goto doctor_page;
												}
											}
											else
											{
												// INVALID ANSWER :

												printf(R);
												printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
												WAIT;
											}
										}
									}
									else if (strcmp(input12, "2") == 0)
									{
										// NO ;

										goto doctor_page;
									}
									else
									{
										// INVALID ANSWER :

										printf(R);
										printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
										WAIT;
									}
								}
							}
							else if (strcmp(input4, "3") == 0)
							{
								// PATIENT PRESCRIPTION :

								int ar[20];
								int ii = 0;
								int i34 = 0;
								int i35 = 0;
								int i37 = 0;
								while (true)
								{
									CLEAR;
									i35 = 0;
									ii = 0;
									while (true)
									{
										if (doc[i_d].dday[day - 1].vis[i35].id[0] > 0)
										{
											if (ii == i34)
											{
												printf(B);
											}
											else
											{
												printf(W);
											}
											ar[ii] = i35;
											printf("%s : ( %.2f - %.2f )\n", doc[i_d].dday[day - 1].vis[ar[ii]].id, doc[i_d].dday[day - 1].vis[ar[ii]].start, doc[i_d].dday[day - 1].vis[ar[ii]].end);
											ii++;
										}
										if (i35 == 19)
										{
											break;
										}
										i35++;
									}
									if (ii == 0)
									{
										printf(R);
										printf("THERE IS NO APOINTMENT .");
										WAIT;
										break;
									}
									switch (getch())
									{
									case 72:
										if (i34 > 0)
											i34--;
										break;
									case 80:
										if (i34 < ii - 1)
											i34++;
										break;
									case 13:
										for (i37; i37 < 20; i37++)
										{
											if (strcmp(pat[i37].id, doc[i_d].dday[day - 1].vis[ar[i34]].id) == 0)
												break;
										}
										while (true)
										{
											int flag11 = 0;
											if (pat[i37].wallet - doc[i_d].cost > 0)
											{
												CLEAR;
												printf(C);
												printf("%s : ( %.2f - %.2f )\n", doc[i_d].dday[day - 1].vis[ar[i34]].id, doc[i_d].dday[day - 1].vis[ar[i34]].start, doc[i_d].dday[day - 1].vis[ar[i34]].end);
												printf("PRESCRIPTION : ");
												for (int i36 = 0; i36 < 10; i36++)
												{
													if (pat[i37].prescription[i36][0] < 0)
													{
														fgets(pat[i37].prescription[i36], 130, stdin);
														doc[i_d].wallet = doc[i_d].wallet + (doc[i_d].cost);
														flag11 = 1;
														for (int i = 0; i < i_pat; i++)
														{
															hash(pat[i].codemeli);
														}
														fpat = fopen("Patients.txt", "w");
														if (fpat == NULL)
														{
															printf(R);
															printf("ERROR IN OPENING FILE !");
															return 0;
														}
														for (int i39 = 0; i39 < i_pat; i39++)
														{
															fwrite(&pat[i39], sizeof(pat[i39]), 1, fpat);
														}
														fclose(fpat);
														for (int i = 0; i < i_pat; i++)
														{
															hashback(pat[i].codemeli);
														}
														break;
													}
												}
												if (flag11 == 1)
												{
													break;
												}
												else
												{
													printf(R);
													printf("PRESCRIPTIONS IS FULL !");
													WAIT;
												}
											}
											else
											{
												printf(R);
												printf("YOUR PATIENT ACCOUNT WALLET IS INSUFFICIENT !");
												WAIT;
												break;
											}
										}
										break;
									case 32:
										goto doctor_page;
										break;
									}
								}
							}
							else if (strcmp(input4, "4") == 0)
							{
								// RENT PAYMENT :

								while (true)
								{
									CLEAR;
									printf(C);
									printf("1. EXTENSION\n");
									printf("2. PAYMENT\n");
									printf(R);
									printf("3. BACK\n");
									char input14[30];
									scanf("%s", input14);
									if (strcmp(input14, "1") == 0)
									{
										// EXTENSION :

										CLEAR;
										if (doc[i_d].payment == 0)
										{
											int f;
											f = 0;
											if (year > firstyear || month == 0)
												f = 12;
											if (month + f > firstmonth + 1)
											{
												if (doc[i_d].wallet - (month_length[month + f - firstmonth - 1] * 20) > 0)
												{
													printf(G);
													doc[i_d].wallet = doc[i_d].wallet - (month_length[month + f - firstmonth - 1] * 20);
													doc[i_d].payment = 2;
													printf("PAYMENT WAS SUCCESSFULL .");
													WAIT;
													for (int i = 0; i < i_doc; i++)
													{
														hash(doc[i].codemeli);
													}
													fdoc = fopen("Doctors.txt", "w");
													if (fdoc == NULL)
													{
														printf(R);
														printf("ERROR IN OPENING FILE !");
														return 0;
													}
													for (int i39 = 0; i39 < i_doc; i39++)
													{
														fwrite(&doc[i39], sizeof(doc[i39]), 1, fdoc);
													}
													fclose(fdoc);
													for (int i = 0; i < i_doc; i++)
													{
														hashback(doc[i].codemeli);
													}
												}
												else
												{
													printf(R);
													printf("INSUFFICIENT INVENTORY !");
													WAIT;
												}
											}
											else
											{
												printf(R);
												printf("YOU CANTNNOT IN THIS MONTH !");
												WAIT;
											}
										}
										else
										{
											printf(R);
											printf("YOU CANTNNOT IN THIS MONTH !");
											WAIT;
										}
									}
									else if (strcmp(input14, "2") == 0)
									{
										// PAYMENT :

										CLEAR;
										if (doc[i_d].payment == 0)
										{
											int f;
											f = 0;
											if (year > firstyear || month == 0)
												f = 12;
											if (month > firstmonth)
											{
												int t18 = month - firstmonth;
												if (t18 < 0)
												{
													t18 = t18 + 12;
												}
												if (doc[i_d].wallet - (month_length[t18 - 1] * 10) > 0)
												{
													printf(G);
													doc[i_d].wallet = doc[i_d].wallet - (month_length[t18 - 1] * 10);
													doc[i_d].payment = 1;
													printf("PAYMENT WAS SUCCESSFULL .");
													WAIT;
													for (int i = 0; i < i_doc; i++)
													{
														hash(doc[i].codemeli);
													}
													fdoc = fopen("Doctors.txt", "w");
													if (fdoc == NULL)
													{
														printf(R);
														printf("ERROR IN OPENING FILE !");
														return 0;
													}
													for (int i39 = 0; i39 < i_doc; i39++)
													{
														fwrite(&doc[i39], sizeof(doc[i39]), 1, fdoc);
													}
													fclose(fdoc);
													for (int i = 0; i < i_doc; i++)
													{
														hashback(doc[i].codemeli);
													}
												}
												else
												{
													printf(R);
													printf("INSUFFICIENT INVENTORY !");
													WAIT;
												}
											}
											else
											{
												printf(R);
												printf("YOU CANTNNOT IN THIS MONTH !");
												WAIT;
											}
										}
										else if (doc[i_d].payment == 1)
										{
											int f;
											f = 0;
											if (year > firstyear || month == 0)
												f = 12;
											if (month + f > firstmonth + 1)
											{
												int t18 = month - firstmonth;
												if (t18 < 0)
												{
													t18 = t18 + 12;
												}
												if (doc[i_d].wallet - (month_length[t18 - 1] * 10) > 0)
												{
													printf(G);
													doc[i_d].wallet = doc[i_d].wallet - (month_length[t18 - 1] * 10);
													doc[i_d].payment = 1;
													printf("PAYMENT WAS SUCCESSFULL .");
													WAIT;
													for (int i = 0; i < i_doc; i++)
													{
														hash(doc[i].codemeli);
													}
													fdoc = fopen("Doctors.txt", "w");
													if (fdoc == NULL)
													{
														printf(R);
														printf("ERROR IN OPENING FILE !");
														return 0;
													}
													for (int i39 = 0; i39 < i_doc; i39++)
													{
														fwrite(&doc[i39], sizeof(doc[i39]), 1, fdoc);
													}
													fclose(fdoc);
													for (int i = 0; i < i_doc; i++)
													{
														hashback(doc[i].codemeli);
													}
												}
												else
												{
													printf(R);
													printf("INSUFFICIENT INVENTORY !");
													WAIT;
												}
											}
											else
											{
												printf(R);
												printf("YOU CANTNNOT IN THIS MONTH !");
												WAIT;
											}
										}

									}
									else if (strcmp(input14, "3") == 0)
									{
										// BACK :

										goto doctor_page;
									}
									else
									{
										// INVALID ANSWER :

										printf(R);
										printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
										WAIT;
									}
								}
							}
							else if (strcmp(input4, "5") == 0)
							{
								// VISIRS PAYMENT :

								int cost;
								while (true)
								{
									CLEAR;
									printf(C);
									printf("COST OF YOUR VISIT : ");
									scanf("%d", &cost);
									if (cost < 50 && cost > 10)
									{
										doc[i_d].cost = cost;
										break;
									}
									else
									{
										printf(R);
										printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
										WAIT;
									}
								}
							}
							else if (strcmp(input4, "6") == 0)
							{
								// BACK :

								goto menu;
							}
							else
							{
								// INVALID ANSWER :

								printf(R);
								printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
								WAIT;
							}
						}
					}
					else if (flag3 == 2)
					{
						// PATIENTS' PAGE :

					patient_page:
						while (true)
						{
							CLEAR;
							printf(C);
							printf("1. BOOK AN APPOINTMENT\n");
							printf("2. CANCEL AN APOINTMENT\n");
							printf("3. ALL APOINTMENTS\n");
							printf("4. PRESCRIPTIONS\n");
							printf(R);
							printf("5. BACK\n");
							char input11[30];
							scanf("%s", input11);
							if (strcmp(input11, "1") == 0)
							{
								// BOOK AN APOINTMENT :

								int l1;
								int i21 = 0;
								while (true)
								{
									CLEAR;
									l1 = printdoctor(doc, i21);
									switch (getch())
									{
									case 72: // UP :
										if (i21 > 0)
											i21--;
										break;
									case 80: // DOWN :
										if (i21 < l1 - 1)
											i21++;
										break;
									case 32: // SPACE :
										goto patient_page;
										break;
									case 13: // ENTER :
										int i22 = 0;
										int l2;
										while (true)
										{
											CLEAR;
											l2 = printdday(doc, i22, i21, cal);
											switch (getch())
											{
											case 72: // UP :
												if (i22 > 0)
													i22--;
												break;
											case 80: // DOWN :
												if (i22 < l2 - 1)
													i22++;
												break;
											case 32: // SPACE :
												goto patient_page;
												break;
											case 13: // ENTER :
												int l3;
												int i23 = 0;
												while (true)
												{
													CLEAR;
													l3 = printvisit(doc, i23, i22, i21);
													switch (getch())
													{
													case 72: // UP :
														if (i23 > 0)
															i23--;
														break;
													case 80: // DOWN :
														if (i23 < l3 - 1)
															i23++;
														break;
													case 32: // SPACE :
														goto patient_page;
														break;
													case 13: // ENTER :


														if (pat[i_p].wallet - (doc[i21].cost * 1.1) > 0)
														{
															printf(G);
															strcpy(doc[i21].dday[arr2[i22]].vis[arr3[i23]].id, pat[i_p].id);
															pat[i_p].wallet = pat[i_p].wallet - (doc[i21].cost * 1.1);
															printf("YOUR APOINTMENT HAS BEEN SUCCESSFULLY BOOKED .");
															for (int i = 0; i < i_doc; i++)
															{
																hash(doc[i].codemeli);
															}
															fdoc = fopen("Doctors.txt", "w");
															if (fdoc == NULL)
															{
																printf(R);
																printf("ERROR IN OPENING FILE !");
																return 0;
															}
															for (int i19 = 0; i19 < i_doc; i19++)
															{
																fwrite(&doc[i19], sizeof(doc[i19]), 1, fdoc);
															}
															fclose(fdoc);
															for (int i = 0; i < i_doc; i++)
															{
																hashback(doc[i].codemeli);
															}
														}
														else
														{
															printf(R);
															printf("INSUFFICIENT INVENTORY");
														}
														WAIT;
														break;
													}
												}

												break;

											}
										}
										break;
									}
								}
							}
							else if (strcmp(input11, "2") == 0)
							{
								// CANCEL AN APOINTMENT :

								int i41 = 0;
								int l4 = 0;
								while (true)
								{
									CLEAR;
									l4 = pcanceldoctor(doc, i41, i_p, pat);
									switch (getch())
									{
									case 72: // UP :
										if (i41 > 0)
											i41--;
										break;
									case 80: // DOWN :
										if (i41 < l4 - 1)
											i41++;
										break;
									case 32: // SPACE :
										goto patient_page;
										break;
									case 13:

										int i43 = 0;
										int l5 = 0;
										while (true)
										{
											CLEAR;
											l5 = pcanceldday(doc, i43, i41, cal, i_p, pat);
											switch (getch())
											{
											case 72: // UP :
												if (i43 > 0)
													i43--;
												break;
											case 80: // DOWN :
												if (i43 < l5 - 1)
													i43++;
												break;
											case 32: // SPACE :
												goto patient_page;
												break;
											case 13:
												int i45 = 0;
												int l6 = 0;
												while (true)
												{
													CLEAR;
													l6 = pcancelvisit(doc, i45, i43, i41, i_p, pat);
													switch (getch())
													{
													case 72: // UP :
														if (i45 > 0)
															i45--;
														break;
													case 80: // DOWN :
														if (i45 < l6 - 1)
															i45++;
														break;
													case 32: // SPACE :
														goto patient_page;
														break;
													case 13:
														if (strcmp(doc[i41].dday[arry2[i43]].vis[arry3[i45]].id, pat[i_p].id) == 0)
														{
															printf(Y);
															strcpy(doc[i41].dday[arry2[i43]].vis[arry3[i45]].id, "面面面面面面");
															pat[i_p].wallet = pat[i_p].wallet + ((doc[i41].cost) * 0.5);
															printf("YOUR APOINTMENT WAS CANCELLED .\n");
															WAIT;
															for (int i = 0; i < i_doc; i++)
															{
																hash(doc[i].codemeli);
															}
															fdoc = fopen("Doctors.txt", "w");
															if (fdoc == NULL)
															{
																printf(R);
																printf("ERROR IN OPENING FILE !");
																return 0;
															}
															for (int i19 = 0; i19 < i_doc; i19++)
															{
																fwrite(&doc[i19], sizeof(doc[i19]), 1, fdoc);
															}
															fclose(fdoc);
															for (int i = 0; i < i_doc; i++)
															{
																hashback(doc[i].codemeli);
															}
														}
														break;
													}
												}
												break;
											}
										}
										break;
									}
								}
							}
							else if (strcmp(input11, "3") == 0)
							{
								// ALL APOINTMENTS :

								int a[20], a2[93], a3[20];
								int i49 = 0;
								int i50 = 0;
								while (true)
								{
									CLEAR;
									i50 = 0;
									for (int i = 0; i < 20; i++)
									{
										for (int d = 0; d < 93; d++)
										{
											for (int v = 0; v < 20; v++)
											{
												if (doc[i].dday[d].vis[v].id[0] > 0)
												{
													if (strcmp(doc[i].dday[d].vis[v].id, pat[i_p].id) == 0)
													{
														if (i50 == i49)
														{
															printf(B);
														}
														else
														{
															printf(W);
														}
														a[i50] = i;
														a2[i50] = d;
														a3[i50] = v;
														if (cal[a2[i50]].month == 0)
															printf("Dr.%s-%s: (%d / %d)(%.2f - %.2f)\n", doc[a[i50]].name, doc[a[i50]].lastname, 12, cal[a2[i50]].day, doc[a[i50]].dday[a2[i50]].vis[a3[i50]].start, doc[a[i50]].dday[a2[i50]].vis[a3[i50]].end);
														else
															printf("Dr.%s-%s: (%d / %d)(%.2f - %.2f)\n", doc[a[i50]].name, doc[a[i50]].lastname, cal[a2[i50]].month, cal[a2[i50]].day, doc[a[i50]].dday[a2[i50]].vis[a3[i50]].start, doc[a[i50]].dday[a2[i50]].vis[a3[i50]].end);
														i50++;
														printf(W);
													}
												}
											}
										}
									}
									switch (getch())
									{
									case 72: // UP :
										if (i49 > 0)
											i49--;
										break;
									case 80: // DOWN :
										if (i49 < i50 - 1)
											i49++;
										break;
									case 32: // SPACE :
										goto patient_page;
										break;
									case 13:

										printf(Y);
										CLEAR;
										printf("NAME : %s\n", doc[a[i49]].name);
										printf("LASTNAME : %s\n", doc[a[i49]].lastname);
										printf("EMAIL : %s\n", doc[a[i49]].email);
										WAIT;
										WAIT;
										WAIT;
										break;
									}
								}
							}
							else if (strcmp(input11, "4") == 0)
							{
								// PRESCRIPTIONS :

								CLEAR;
								int c = 0;
								for (int i52 = 0; i52 < 10; i52++)
								{
									if (pat[i_p].prescription[i52][0] > 0)
									{
										c++;
										printf(Y);
										printf("%s", pat[i_p].prescription[i52]);
										printf("\n");
										printf("--------------------------------------------------------------------");
										printf("\n");
										WAIT;
										WAIT;
									}
								}
								if (c == 0)
								{
									CLEAR;
									printf(R);
									printf("THERE IS NO PRESCRIPTION .");
									WAIT;
								}
							}
							else if (strcmp(input11, "5") == 0)
							{
								// BACK :

								goto menu;
							}
							else
							{
								// INVALID ANSWER :

								printf(R);
								printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
								WAIT;
							}
						}
					}
					else
					{
						// INVALID ANSWER :

						printf(R);
						printf("\n");
						printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
						WAIT;
						while (true)
						{
							CLEAR;
							printf(G);
							printf("1. TRY AGAIN\n");
							printf(R);
							printf("2. BACK\n");
							char input6[30];
							scanf("%s", input6);
							if (strcmp(input6, "1") == 0)
							{
								// TRY AGAIN :

								goto sign_in;
							}
							else if (strcmp(input6, "2") == 0)
							{
								// BACK :

								goto menu;
							}
							else
							{
								printf(R);
								printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
								WAIT;
							}
						}
					}
				}
			}
		}
		else if (strcmp(input1, "2") == 0)
		{
			// FORGOT PASSWORD :

			CLEAR;
			printf(P);
			int flag9 = 1;
			char t16[20], t17[100];
			printf("ID : ");
			scanf("%s", t16);
			printf("EMAIL : ");
			scanf("%s", t17);
			for (int i53 = 0; i53 < i_doc; i53++)
			{
				if (strcmp(t16, doc[i53].id) == 0 && strcmp(t17, doc[i53].email) == 0)
				{
					printf(Y);
					printf("YOUR PASSWORD IS : %s", doc[i53].codemeli);
					WAIT;
					flag9 = 0;
				}
			}
			for (int i53 = 0; i53 < i_doc; i53++)
			{
				if (strcmp(t16, pat[i53].id) == 0 && strcmp(t17, pat[i53].email) == 0)
				{
					printf(Y);
					printf("YOUR PASSWORD IS : %s", pat[i53].codemeli);
					WAIT;
					flag9 = 0;
				}
			}
			if (flag9)
			{
				printf(R);
				printf("YOU DO NOT HAVE AN ACCOUNT !\n");
				WAIT;
			}
		}
		else if (strcmp(input1, "3") == 0)
		{
			// EXIT :

			return 0;
		}
		else
		{
			// INVALID ANSWER :

			printf(R);
			printf("INVALID ANSWER ! PLEASE TRY AGAIN .");
			WAIT;
		}

	}

	return 0;
}

/*-----END-----*/
