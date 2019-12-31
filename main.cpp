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



描述
在一个长度为n(n < 1000)的整数序列中，判断是否存在某两个元素之和为k。

输入
第一行输入序列的长度n和k，用空格分开。

第二行输入序列中的n个整数，用空格分开。

输出
如果存在某两个元素的和为k，则输出yes，否则输出no。


#include <iostream>
using namespace std;

int a[1000];
int main() {
	int n, k,num;
	cin>>n>>k;

	for(int i = 0; i<n; i++){
		cin>>num;
		a[i] = num;
	}
	int index = 1;
	for(int i = 0; i<n; i++){
		for(int j = index; j<n; j++){
			if(a[i]+a[j] == k){
				cout<<"yes"<<endl;
				index = n;
				break;}
			else
				continue;
		}
		index++;
		if(index ==n)
			break;
     }

	if (index == n){
		cout<<"no"<<endl;
	}

}

//扒出一个数各个位的方法
 int n = 123456;


4

    int unitPlace = n / 1 % 10;


5

    int tenPlace = n / 10 % 10;


6

    int hundredPlace = n / 100 % 10;


7

    int thousandPlace = n / 1000 % 10;



输入
输入一行字符串（字符串中可能有空格，请用cin.getline(s,counts)方法把一行字符串输入到字符数组s中，其中counts是s的最大长度，这道题里面可以直接写80。），字符串长度小于80个字符。

输出
输出一行，依次输出a,e,i,o,u在输入字符串中出现的次数，整数之间用空格分隔。

#include <iostream>
using namespace std;

int numa = 0;
int nume = 0;
int numi = 0;
int numo = 0;
int numu = 0;


int main() {

	char s[80] = {0};
	cin.getline(s, 80);

	int i = 0;
while(s[i]!=0){
	switch(s[i])
	{
	case'a':
	    numa++;i++;break;
	case'e':
		nume++;i++;break;
	case'i':
		numi++;i++;break;
	case'o':
		numo++;i++;break;
	case'u':
		numu++;i++;break;
	default:
		i++; break;
	}
}

cout <<numa<<' '<<nume<<' '<<numi<<' '<<numo<<' '<<numu;

}



