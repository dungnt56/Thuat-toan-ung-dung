#include <iostream>
using namespace std;
double a, b, c, d, l = -1, r = 1, m;
double f(double x){
	return a * x * x * x + b * x * x + c * x + d;

}

int main(){
	cout << "A, B, C, D = "; cin >> a >> b >> c >> d;
	while(f(l) * f(r) >= 0){
		l = l * 2, r = r * 2;
	}
	
	while ((r - l) > 0.0000001){
		m = (r + l) / 2;
		if (f(m) == 0) break;
		if(f(m) * f(l) > 0) l = m;
		else r = m;
	}
	cout << fixed << "Nghiem la: " << m << ", f(x) = " << f(m);
}
