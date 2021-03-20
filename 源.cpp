//ployd
#include<iostream>
using namespace std;
#define Vmax 10
int main() {
	int a[Vmax][Vmax] = {0}, i, j, k;
	int V, E, x, y, z;
	cout << "输入点的个数和边的个数：";
	cin >> V >> E;
	cout << "输入两个点和他们的距离：" << endl;
	for (i = 0; i < E; i++) {
		cin >> x >> y >> z;
		a[x][y] = z;
	}
	for (i = 1; i < V+1; i++) {
		for (j = 1; j < V+1; j++) {
			if (a[i][j] == 0 && i != j)
				a[i][j] = 100000;
		}
	}
	for (k = 1; k < V + 1; k++) {
		for (i = 1; i < V + 1; i++) {
			for (j = 1; j < V + 1; j++) {
				if (a[i][k] + a[k][j] < a[i][j]) {
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}
	for (i = 1; i < V + 1; i++) {
		for (j = 1; j < V + 1; j++) {
			cout << a[i][j] << " ";
			if (j == V) {
				cout << endl;
			}
		}
	}
	return 0;
}
/*测试用例
6 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
结果
0 2 5 4
9 0 3 4
6 8 0 1
5 7 10 0*/






//dijkstra
#include<iostream>
using namespace std;
#define Infinity 10000
#define moreInfinity 100000
#define matrixSize 10
bool isEmpty(int arr[],int V) {
	int i;
	for (i = 1; i < V + 1; i++) {
		if (arr[i] == 0) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int V, E;
	int i, j;
	int x, y, z;
	int a[matrixSize][matrixSize], A[matrixSize];
	int min = moreInfinity, k, minn = moreInfinity;
	int v[matrixSize] = { 0 };
	cout << "输入点的个数和边的个数：";
	cin >> V >> E;
	cout << "输入两个点和他们的距离：" << endl;
	for (i = 0; i < V + 1; i++) {
		A[i] = 10000;
		for (j = 0; j < V + 1; j++) {
			a[i][j] = 10000;
		}
	}
	for (i = 0; i < E; i++) {
		cin >> x >> y >> z;
		a[x][y] = z;
	}
	for (i = 2; i < V + 1; i++) {
		if (a[1][i] != 10000) {
			A[i] = a[1][i];
		}
	}
	A[1] = 0;
	v[1] = 1;
	while(!isEmpty(v,V)) {
		min = moreInfinity;
		for (j = 1; j < V + 1; j++) {//找到最小点位置
			if (A[j] < min && A[j] != 10000 && v[j] != 1) {
				min = A[j];
				k = j;
			}
		}
		v[k] = 1;
		for (j = 1; j < V + 1; j++) {//更新一排数组
			if (a[k][j] != 10000) {
				if (min + a[k][j] < A[j]) {
					A[j] = min + a[k][j];
				}
			}
		}	
	}
	for (i = 1; i < V + 1; i++) {
		cout << A[i] << " ";
	}
	return 0;
}

//测试用例1
/*8 11
1 2 1
2 4 2
3 1 2
4 3 1
5 4 2
4 6 8
6 5 2
5 7 2
7 6 3
7 8 3
8 6 2*/
//结果1
//0 1 4 3 13 11 15 18


//测试用例2
/*6 9
1 2 1
1 3 12
2 3 9
2 4 3
4 3 4
3 5 5
4 5 13
5 6 4
4 6 15*/
//结果2
//0 1 8 4 13 17