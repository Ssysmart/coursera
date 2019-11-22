#include <iostream>
#include<iomanip>
using namespace std;
int a[100];
int b[100]; //1-18
int c[100]; //19-35
int d[100]; //36-60
int e[100]; //60>
double s = 0.00;//1-18的个数
double v = 0.00;//19 - 35的个数
double f = 0.00;//36 - 60的个数
double g = 0.00;//60》 的个数


int main() {
	double n;
	cin >> n;


	for(int i = 0; i < n; i++) {
		int m;
		cin >> m;
		a[i] = m;
	}


	for(int i = 0; i< n; i++) {
		if (a[i] <= 18)
			{b[i] = a[i];
		    s++;}
		else if(19 <= a[i]&&a[i] <= 35){
			c[i] = a[i];
		    v++;}
		else if(36 <= a[i]&&a[i] <= 60)
			{d[i] = a[i];
			f++;}
		else
		    {
		    g++;
		    }
	}

	double q = n*1.00;

	double bPercentage = s/q*100;
	double cPercentage = v/q*100;
	double dPercentage = f/q*100;
	double ePercentage = g/q*100;

	cout.setf(ios::fixed);
	cout.precision(2);
	   cout <<"1-18:"<<" "<< bPercentage<< "%" << endl;
	   cout << "19-35:"<<" "<< cPercentage << "%"<<endl;
	   cout << "36-60:"<<" "<< dPercentage << "%"<<endl;
	   cout << "60-:"<<" "<< ePercentage << "%"<<endl;
	    	return 0;


    	}


