#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 5
#define SIZE 10

void show_menu();
void find_gcd();
void binary();
int get_random();
int rgcd(int, int);
void play_2d_array();
void insert_array(int num[][5]);
void print_array(int num[][5]);
int find_row_max(int* p);
int find_row_average(int* p);
int find_total_max(int num[][5]);
int find_total_average(int num[][5]);
int integer_to_binary(int integer);


int main(void)
{
	int sel;
	srand(time(NULL));

	while (1)
	{
		show_menu();
		scanf("%d", &sel);

		if (sel == 1)
			find_gcd();
		if (sel == 2)
			play_2d_array();
		if (sel == 3)
			binary();
		if (sel == 4)
			break;
		else
			continue;

	}
	return 0;
}

void show_menu(void)
{
	printf("1. 최대 공약수 구하기\n");
	printf("2. 2차원 배열\n");
	printf("3. 2진수 변환\n");
	printf("4. 끝내기\n");
	printf("메뉴를 선택하시오:");
}

void find_gcd()
{
	int a, b;
	printf("\n최대 공약수 구하기 문제입니다. \n");
	a = get_random();
	b = get_random();
	printf("%d와 %d의 최대공약수는 %d 입니다. \n", a, b, rgcd(a, b));

}

int get_random()
{
	return (rand() % 100 + 1);
}

int rgcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return rgcd(y, (x % y));
}

void play_2d_array()
{
	int num[ROW][COL];
	int i;

	insert_array(num);

	printf("\n\n3x5 배열에 랜덤하게 할당된 배열 원소 입니다. \n");
	print_array(num);

	printf("\n각 행별 최대 값 및 평균입니다. \n");
	for (i = 0; i < ROW; i++)
		printf("[%d]행 최대값: %4d, 평균: %4d\n", i, find_row_max(num[i]), find_row_average(num[i]));

	printf("\n배열 전체 원소에 대한 최대값 및 평균입니다. \n");
	printf("최대값: %4d, 평균: %4d \n\n", find_total_max(num), find_total_average(num));
}

void insert_array(int num[][5])
{
	int i, r;
	int* p;
	p = &num[0][0];

	for (i = 0; i < ROW; i++)
		for (r = 0; r < COL; r++)
		{
			*p = get_random();
			p++;
		}
}

void print_array(int num[][5])
{

	int i, r;
	int* p;
	p = &num[0][0];

	for (i = 0; i < ROW; i++)
		for (r = 0; r < COL; r++)
		{
			printf("%3d ", *p);
			p++;
			if (r == 4)
				printf("\n");
		}
}

int find_row_max(int* p)
{
	int r, max, compare = *p;

	for (r = 1; r < COL; r++)
	{
		if (compare < *(p + r))
			compare = *(p + r);
	}
	max = compare;
	return max;
}

int find_row_average(int* p)
{
	int average, r, total = 0;

	for (r = 0; r < COL; r++)
	{
		total = total + *(p + r);
	}
	average = total / 5;

	return average;
}

int find_total_max(int num[][5])
{
	int a, b, c, max;
	int(*p)[5] = num;

	a = find_row_max(p);
	b = find_row_max(p+1);
	c = find_row_max(p+2);

	if (a > b && a > c)
	{
		max = a;
		return max;
	}
	else if (b > c && b > a)
	{
		max = b;
		return max;
	}
	else if (c > b && c > a)
	{
		max = c;
		return max;
	}
}

int find_total_average(int num[][5])
{
	int a, b, c, average;
	int(*p)[5] = num;

	a = find_row_average(p);
	b = find_row_average(p + 1);
	c = find_row_average(p + 2);

	average = (a + b + c) / 3;

	return average;
}

void binary()
{
	int* pi;
	pi = (int*)malloc(sizeof(int));
	*pi = get_random();

	printf("2진수 변환 계산기입니다.\n");
	printf("10진수 %d를 2진수로 변환한 결과:",*pi);
	integer_to_binary(*pi);
	printf("\n");

	free(pi);
}

int integer_to_binary(int integer)
{
	if (integer == 1)
		printf("");
	else
	{
		integer_to_binary(integer / 2);
	}

	if (integer != 1)
	{
		printf("%d", integer % 2);
	}
}