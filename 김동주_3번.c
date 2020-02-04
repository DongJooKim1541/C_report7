#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 2//소유하는 도서 개수
#define MAX 13

void Input_data(struct data *p1, char *s);
int Isbn_judgement(struct data *p2);
int Char_to_int(char c);
void Output_data(struct data *p3, char *s);

struct data {
	char book_name[41];//최대 20글자
	char author[21];//최대 10글자
	char publisher[41];//최대 20글자
	char isbn_number[MAX + 1];//최대 14글자
};

int main() {

	struct data list[SIZE];
	int choice;
	char display[36] = { "==================================" };

	while (1) {
		printf("%s\n", display);
		printf("1. 입력    2. 종료\n");
		printf("%s\n", display);
		printf("선택: ");
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
		printf("도서명: ");
		scanf_s("%s", &p1->book_name, 41);
		printf("저자: ");
		scanf_s("%s", &p1->author, 21);
		printf("출판사명: ");
		scanf_s("%s", &p1->publisher, 41);
		do {
			printf("ISBN 번호: ");
			scanf_s("%s", &p1->isbn_number, 14);
			if (Isbn_judgement(p2) == 0) {
				printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
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
		printf("도서명: ");
		printf("%s\n", p3->book_name);
		printf("저자: ");
		printf("%s\n", p3->author);
		printf("출판사명: ");
		printf("%s\n", p3->publisher);
		printf("ISBN 번호: ");
		printf("%s\n", p3->isbn_number);
		p3++;
	}
	printf("%s\n", s);
}