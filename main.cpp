#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue> 
#include <locale.h>
#include<time.h>
using namespace std;
void BFSD(int** G, int* DIST, int num, int n) {
	queue <int> q;
	int i;
	q.push(num);
	DIST[num] = 0;
	while (!q.empty()) {
		num = q.front();
		q.pop();
		printf("%d ", num);
		for (i = 0; i < n; i++) {
			if (DIST[i] == -1 && G[num][i] == 1) {
				q.push(i);
				DIST[i] = DIST[num]+1;
			}
			
		}
	}
}
int main(void) {
	setlocale(LC_ALL, "Rus");
	int** a;
	int N;
	printf("Введите N: ");
	scanf("%d", &N);
	a = (int**)malloc(N * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		int* b = (int*)malloc(N * sizeof(int));
		for (int j = 0; j < N; j++) {
			b[j] = 0;
		}
		a[i] = b;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				int num = rand() % 2;
				a[i][j] = num;
				a[j][i] = num;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	int len = N;
	int* visits = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		visits[i] = -1;
	}
	printf("Введите вершину: ");
	scanf("%d", &N);
	BFSD(a, visits, N, len); 
	printf("\n");
	printf( "Расстояния от вершины ");
	printf("%d",N);
	printf(" до: ");
	printf("\n");
	
	for (int i = 0; i < len; i++) {
		printf("%d ", i);
		printf("-->");
		printf("%d ", visits[i]);
		printf("\n");
	}
}

