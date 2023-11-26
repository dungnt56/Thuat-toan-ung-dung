#include <iostream>
#include <ctime>
using namespace std;
const int MAX = 50;
int a[MAX], n;


void init(int s){
	srand(time(0));
	n = s;
	for (int i = 0; i < n; i++) cout<< (a[i] = rand()) << '\t';
	cout << endl << endl;
}


void bubble_sort(int a[], int n){
	bool stop = false;
	while(!stop){
		stop = true;
		for(int i = 1; i < n; i++)
		if(a[i] < a[i - 1]){
			swap(a[i], a[i-1]);
			stop = false;
		}
	}
}

void insertion_sort(int a[], int n){
	for(int k = 1; k < n; k++){
		int z = a[k], i = k;
		while(a[i - 1] > z){
			a[i] = a[i - 1];
			i --;
		}
		a [i] = z;
	}
}

int main(){
	init(MAX);
	clock_t start = clock();
	bubble_sort(a, n);
	cout << "Thoi gian chay BUBBLE SORT = " << (clock() - start) / 100. << endl;
}
