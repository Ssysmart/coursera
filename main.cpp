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



输入为两行，每行一个字符串，共两个字符串。（请用cin.getline(s,80)录入每行字符串）（每个字符串长度都小于80）

输出
如果第一个字符串比第二个字符串小，输出一个字符"<"

如果第一个字符串比第二个字符串大，输出一个字符">"

如果两个字符串相等，输出一个字符"="




#include <iostream>
#include <string.h>
using namespace std;



int main() {

	char skr1[80]={0},skr2[80]={0};

	cin.getline(skr1,80);
	cin.getline(skr2,80);

int count1 = 0, count2 = 0;
	for(int i = 80; i>=0; i--){
		if(skr1[i] != 0){
			count1++;
		}
	}

	for(int j = 80; j>=0; j--){
			if(skr2[j] != 0){
				count2++;
			}
		}


	for(int i = 0; i < count1; i++){
		if(96<skr1[i]&&skr1[i]<123)
			skr1[i] -= 32;
	}

	for(int j = 0; j < count2; j++){
		if(96<skr2[j]&&skr2[j]<123)
			skr2[j]-=32;
	}


int test=strcmp(skr1, skr2);

if(test > 0)
	cout<<'>';
else if (test < 0)
	cout<<'<';
else
	cout << '=';

}



描述

一个以'.'结尾的简单英文句子，单词之间用空格分隔，没有缩写形式和其它特殊形式


输入

一个以'.'结尾的简单英文句子（长度不超过500），单词之间用空格分隔，没有缩写形式和其它特殊形式


输出

该句子中最长的单词。如果多于一个，则输出第一个


#include <iostream>
#include <string.h>
using namespace std;
int len = 0;

int main() {

char s[500] = {0};
int last;//用来记录最长单词最后一个字母的下标；
int maxlen =0 ; //记录最长单词长度；
int temlen = 0; //记录当前单词的长度;

cin.getline(s, 500);

for(int i = 0; s[i]!='\0'; i++){
	if(s[i] == '.'){
		if(maxlen < temlen)
		{
			maxlen = temlen;
			temlen = 0;
			last = i;
		}
		else
			break;
	}
	else if(s[i] == ' '){
		if(maxlen < temlen){
			maxlen = temlen;
			temlen = 0;
			last = i;
		}
		else
			temlen = 0;
	}
	else
	{
		temlen ++;
	}
}

for(int i = last - maxlen; i < last; i++)
	cout<<s[i];
}




描述
在main函数中， 生成一个5*5的矩阵，输入矩阵数据，并输入n，m的值。判断n，m是否在数组范围内，如果不在，则输出error；如果在范围内，则将n行和m行交换，输出交换n，m后的新矩阵。

输入
5*5矩阵的数据，以及n和m的值。

输出
如果不可交换，则输出error

如果可交换，则输出新矩阵


#include <iostream>
#include <iomanip>
using namespace std;


int main() {

int a[5][5] = {0};

   for (int i = 0; i < 5; i++){
	   for(int j = 0; j < 5; j++){
		   int num;
		   cin >> num;
		   a[i][j] = num;
	    }
     }

int n,m;

cin>> n>>m;

int interchange;


   if(n < 5 && m < 5&& n >= 0&& m >=0){
      for(int i = 0; i < 5; i++){
      interchange = a[n][i];
      a[n][i] = a[m][i];
      a[m][i] = interchange;
      }

     for(int i = 0; i < 5; i++){
    	 for(int j = 0; j < 5; j++){
    		cout << setw(4)<<a[i][j];
    	 }
    	 cout<<endl;
     }

   }
   else
	   cout << "error"<<endl;
  return 0;
}





