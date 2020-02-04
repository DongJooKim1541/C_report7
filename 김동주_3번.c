#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 2//�����ϴ� ���� ����
#define MAX 13

void Input_data(struct data *p1, char *s);
int Isbn_judgement(struct data *p2);
int Char_to_int(char c);
void Output_data(struct data *p3, char *s);

struct data {
	char book_name[41];//�ִ� 20����
	char author[21];//�ִ� 10����
	char publisher[41];//�ִ� 20����
	char isbn_number[MAX + 1];//�ִ� 14����
};

int main() {

	struct data list[SIZE];
	int choice;
	char display[36] = { "==================================" };

	while (1) {
		printf("%s\n", display);
		printf("1. �Է�    2. ����\n");
		printf("%s\n", display);
		printf("����: ");
		scanf_s("%d", &choice);
		printf("\n");

		switch (choice) {
		case 1:
			Input_data(&list, display);
			break;
		case 2:
			Output_data(&list, display);
			break;
		}
		if (choice != 1)break;
	}
	return 0;
}

void Input_data(struct data *p1, char *s) {

	int i;
	struct data *p2;
	p2 = p1;

	for (i = 0; i < SIZE; i++) {
		printf("%s\n", s);
		printf("������: ");
		scanf_s("%s", &p1->book_name, 41);
		printf("����: ");
		scanf_s("%s", &p1->author, 21);
		printf("���ǻ��: ");
		scanf_s("%s", &p1->publisher, 41);
		do {
			printf("ISBN ��ȣ: ");
			scanf_s("%s", &p1->isbn_number, 14);
			if (Isbn_judgement(p2) == 0) {
				printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n");
			}
		} while (Isbn_judgement(p2) == 0);
		p1++;
		p2++;
	}
}

int Isbn_judgement(struct data *p2) {

	int i;
	char isbn_string[MAX + 1];
	int isbn_numbers[MAX];
	int sum = 0;

	strcpy(isbn_string, p2->isbn_number);

	for (i = 0; i < MAX; i++) {
		if (isbn_string[i] == 'NULL')break;
		isbn_numbers[i] = Char_to_int(isbn_string[i]);
	}
	for (i = 0; i < MAX; i++) {
		if (i % 2 == 1) {
			isbn_numbers[i] = isbn_numbers[i] * 3;
		}
	}

	for (i = 0; i < MAX; i++) {
		sum = sum + isbn_numbers[i];
	}

	if (sum % 10 == 0) {
		return 1;
	}
	else {
		return 0;
	}
	return 0;
}

int Char_to_int(char c) {

	int parameter;

	parameter = c - '0';

	return parameter;
}

void Output_data(struct data *p3, char *s) {
	int i;

	for (i = 0; i < SIZE; i++) {
		printf("%s\n", s);
		printf("������: ");
		printf("%s\n", p3->book_name);
		printf("����: ");
		printf("%s\n", p3->author);
		printf("���ǻ��: ");
		printf("%s\n", p3->publisher);
		printf("ISBN ��ȣ: ");
		printf("%s\n", p3->isbn_number);
		p3++;
	}
	printf("%s\n", s);
}