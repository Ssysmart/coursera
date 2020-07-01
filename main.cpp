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


描述
给定一组整数，要求利用数组把这组数保存起来，再利用实现对数组中的数循环移动。假定共有n个整数，则要使前面各数顺序向后移m个位置，并使最后m各数变为最前面的m各数。

注意，不要用先输出后m个数，再输出前n-m个数的方法实现，也不要用两个数组的方式实现。

要求只用一个数组的方式实现，一定要保证在输出结果时，输出的顺序和数组中数的顺序是一致的。

输入
输入有两行：第一行包含一个正整数n和一个正整数m，第二行包含n个正整数。每两个正整数中间用一个空格分开。

输出
输出有一行：经过循环移动后数组中整数的顺序依次输出，每两个整数之间用空格分隔。


#include <iostream>
using namespace std;
int a[30] = {0};

int main() {

int n,m;
cin>>n>>m;

   for(int i = 0; i < n; i++){
	cin>>a[i];
   }

//第一种情况是数组有偶数个数的情况；


	 if(m <= n/2){
		 for(int i = 0; i < n; i++){
			 a[n+i] = a[i];
		 }
		 for(int i = n-m; i < 2*n-m; i++)
		 	 		     cout <<a[i]<<' ';
	 }
	 if(m > n/2){
		 for(int i = 0; i < n-m; i++){
			 a[n+i] = a[i];
		 }
		 for(int i = n-m; i < 2*n-m; i++){
			 cout<<a[i]<<' ';
		 }
	 }
   return 0;

}


描述
中位数定义：一组数据按从小到大的顺序依次排列，处在中间位置的一个数或最中间两个数据的平均值（如果这组数的个数为奇数，则中位数为位于中间位置的那个数；如果这组数的个数为偶数，则中位数是位于中间位置的两个数的平均值）.

给出一组无序整数，求出中位数，如果求最中间两个数的平均数，向下取整即可（不需要使用浮点数）

输入
该程序包含多组测试数据，每一组测试数据的第一行为N，代表该组测试数据包含的数据个数，1 <= N <= 15000.

接着N行为N个数据的输入，N=0时结束输入

输出
输出中位数，每一组测试数据输出一行


#include <iostream>
using namespace std;
int ind = 0;
int temp=0;//记录上个最大的数字；
int a[15000];
int n;

int main() {


while(1){
	cin >> n;
	if(n ==0)
		break;


  for(int i = 0; i < n; i++){
	 cin>>a[i];
  }

  for(int i = 0; i < n; i++){
	  for(int j = 0; j < n; j++){
		  if(a[j]<= a[i]){
			  temp = a[i];
			  a[i] = a[j];
			  a[j] = temp;
		  }
	  }
  }

  if(n%2==0){
	  cout<<(a[n/2]+a[n/2-1])/2<<endl;
  }
  if(n%2!=0){
	  cout<<a[(n-1)/2]<<endl;
  }




 }
}









描述
某校大门外长度为L的马路上有一排树，每两棵相邻的树之间的间隔都是1米。我们可以把马路看成一个数轴，马路的一端在数轴0的位置，另一端在L的位置；数轴上的每个整数点，即0，1，2，……，L，都种有一棵树。

马路上有一些区域要用来建地铁，这些区域用它们在数轴上的起始点和终止点表示。已知任一区域的起始点和终止点的坐标都是整数，区域之间可能有重合的部分。现在要把这些区域中的树（包括区域端点处的两棵树）移走。你的任务是计算将这些树都移走后，马路上还有多少棵树。

输入
输入的第一行有两个整数L（1 <= L <= 10000）和 M（1 <= M <= 100），L代表马路的长度，M代表区域的数目，L和M之间用一个空格隔开。接下来的M行每行包含两个不同的整数，用一个空格隔开，表示一个区域的起始点和终止点的坐标。

输出
输出包括一行，这一行只包含一个整数，表示马路上剩余的树的数目。


#include <iostream>
using namespace std;
int RoadLength[10001] = {0};
int count = 0;

int main() {

	int L,M;
	cin>>L>>M;

	for(int i = 0; i<=L; i++){
		RoadLength[i] = 1; //初始化所有点为1：有树；
	}
	for(int i = 0; i<M; i++){
			int a,b;
			cin>>a>>b;
			for(int j = a; j<b+1; j++){
				if(RoadLength[j] == 1)
					RoadLength[j] = 0;
			}
		}
	for(int i = 0; i<L+1; i++){
			if(RoadLength[i] == 1)
				count++;
		}

		cout << count;

}



描述
已知一个整数数组x[],其中的元素彼此都不相同。找出给定的数组中是否有一个元素满足x[i]=i的关系，数组下标从0开始。

举例而言，如果x[]={-2,-1,7,3,0,8},则x[3] = 3,因此3就是答案。

输入
第一行包含一个整数n (0 < n < 100)，表示数组中元素的个数。<br />第二行包含n个整数，依次表示数组中的元素。

输出
输出为一个整数，即满足x[i]=i的元素，若有多个元素满足，输出第一个满足的元素。若没有元素满足，则输出“N”。


#include <iostream>
using namespace std;
int list[30]={0};

int compare(int a, int b){
	if(a == b)
		return 1;
	else
		return 0;
	}


int main() {
	int n;
	cin>>n;

	for(int i = 0; i < n; i++){
		cin>>list[i];
	}

	int count = 0;
	for(int j = 0; j < n; j++){
		++count;
		int result = 0;
		result = compare(list[j], j);
		if(result == 1) {
			cout<<list[j]; break;
		}
		else
			if(count == n &&compare(list[j], j) == 0 )
				cout<<'N';
	}


return 0;
}



描述
我国有4大淡水湖。

A说：洞庭湖最大，洪泽湖最小，鄱阳湖第三。

B说：洪泽湖最大，洞庭湖最小，鄱阳湖第二，太湖第三。

C说：洪泽湖最小，洞庭湖第三。

D说：鄱阳湖最大，太湖最小，洪泽湖第二，洞庭湖第三。

已知这4个湖的大小均不相等，4个人每人仅答对一个，

请编程按照鄱阳湖、洞庭湖、太湖、洪泽湖的顺序给出他们的大小排名。


#include <iostream>
using namespace std;
int a, b, c, d;//分别代表四个湖泊



int main() {
	for(int a = 1; a < 5; a++){
		for(int b = 1; b < 5; b++){
			for(int c = 1; c < 5; c++){
				for(int d = 1; d < 5; d++){
					if((a!=b&&b!=c&&c!=d&&a!=c&&a!=d&&b!=d)&&
					((b == 1) + (d == 4) + (a == 3) == 1)&&((d == 1)+ (b == 4) + (a == 2) + (c == 3) == 1 )
					&&((d == 4)+(b == 3) == 1) && ((a == 1) + (c == 4) + (d == 2) + (b == 3) == 1) &&
					(a+b+c+d == 10) == 1){
						cout <<a<<'\n'<<b<<'\n'<<c<<'\n'<<d;
					return 0;}
				}
			}
		}
	}


return 0;
}



描述
有一个小型的报账系统，它有如下功能：

（1）统计每个人所报发票的总钱数

（2）统计每类发票的总钱数

将此系统简化为如下：假设发票类别共有A、B、C三种;一共有三个人，ID分别为1、2、3。

输入
系统输入包含三行，每行第一个数为人员ID（整型，1或2或3），第二个数为发票总张数(张数不超过100)，之后是多个发票类别（字符型，A或B或C）和相应发票金额（单进度浮点型,不超过1000.0）。

输出
输出包含六行，前三行为每人（按ID由小到大输出）所报发票总钱数（保留两位小数），后三行为每类发票的总钱数（保留两位小数）。


#include <iostream>
#include <iomanip>
using namespace std;
int Id;
float amountOfA1 = 0;
float amountOfB1 = 0;
float amountOfC1 = 0;
float amountOfA2 = 0;
float amountOfB2 = 0;
float amountOfC2 = 0;
float amountOfA3 = 0;
float amountOfB3 = 0;
float amountOfC3 = 0;
float total_1 = 0;
float total_2 = 0;
float total_3 = 0;

int main() {

	for(int i = 1; i<4;i++){
		cin>> Id;
		if(Id == 1){
			int n;
			cin>>n;
			for(int i = 0; i<n;i++){
				char a;
				cin>>a;
				if(a == 'A'){
					float amount;
					cin>>amount;
					amountOfA1 += amount; total_1 +=amount;
				}
				if(a == 'B'){
					float amount;
					cin>>amount;
					amountOfB1 += amount; total_1 +=amount;
				}
				if(a == 'C'){
					float amount;
					cin>>amount;
					amountOfC1 += amount; total_1 +=amount;
				}
			}
		}
		if(Id == 2){
			int n;
			cin>>n;
			for(int i = 0; i<n;i++){
			   char a;
			   cin>>a;
			   if(a == 'A'){
				  float amount;
				  cin>>amount;
				  amountOfA2 += amount; total_2 +=amount;
					}
			   if(a == 'B'){
				  float amount;
				  cin>>amount;
				  amountOfB2 += amount; total_2 +=amount;
					}
			   if(a == 'C'){
				  float amount;
				  cin>>amount;
				  amountOfC2 += amount; total_2 +=amount;
				}
		}

	}
		if(Id == 3){
			int n;
			cin>>n;
			for(int i = 0; i<n;i++){
		    char a;
		    cin>>a;
		    if(a == 'A'){
			   float amount;
			   cin>>amount;
			   amountOfA3 += amount;total_3 +=amount;
						}
		    if(a == 'B'){
			   float amount;
			   cin>>amount;
			   amountOfB3 += amount;total_3 +=amount;
						}
		    if(a == 'C'){
			   float amount;
			   cin>>amount;
			   amountOfC3 += amount;total_3 +=amount;
					}
				}
		}


  }
        float amountA, amountB, amountC;
        amountA = amountOfA1 + amountOfA2 +amountOfA3;
        amountB = amountOfB1 + amountOfB2 +amountOfB3;
        amountC = amountOfC1 + amountOfC2 +amountOfC3;
	    cout<<'1'<<' '<<setprecision(2)<<fixed<<total_1<<endl;
		cout<<'2'<<' '<<setprecision(2)<<fixed<<total_2<<endl;
		cout<<'3'<<' '<<setprecision(2)<<fixed<<total_3<<endl;
		cout<<'A'<<' ' << setprecision(2)<<fixed<< amountA <<endl;
		cout<<'B'<<' ' << setprecision(2)<<fixed<< amountB <<endl;
		cout<<'C'<<' ' << setprecision(2)<<fixed<< amountC <<endl;
	return 0;
}


描述
甲壳虫的《A day in the life》和《Tomorrow never knows》脍炙人口，如果告诉你a day in the life,真的会是tomorrow never knows?相信学了计概之后这个不会是难题，现在就来实现吧。

读入一个格式为yyyy-mm-dd的日期（即年－月－日），输出这个日期下一天的日期。可以假定输入的日期不早于1600-01-01，也不晚于2999-12-30。

输入
输入仅一行，格式为yyyy-mm-dd的日期。

输出
输出也仅一行，格式为yyyy-mm-dd的日期


#include <iostream>
#include <iomanip>
using namespace std;
int year,month,day;
int initial_month;

bool bigorsmall (int a){
	if(a == 1||a==3|| a==5||a==7||a==8||a==10||a==12){
	   return 1;
	}
	else if (a==4|| a==6||a==9||a==11)
	   return 0;
}

int main() {
    char m , n;
	cin>>year>>m>>month>>n>>day;


	bool leapyear = (year%100 == 0&&year%400 == 0)||(year % 4 == 0&&year %100!=0);
int initial_month =month;
	if(leapyear&&month == 2){
		if(day == 29){
			day =1; month =3;
		}
		if(day < 29&&month ==2){
			day+=1;}
	}
	else if(leapyear == 0&&month ==2){
		if(day ==28){
			day =1; month =3;
		}
		if(day <= 28&&month == 2){
			day+=1;}

	}


if(initial_month==month&&month!=2&&month>=1){
    if(bigorsmall(month)){
    	if(day==31&&month==12){
    	   day=1;month=1;year+=1;
    	}
    	else if(day==31){
    		day =1; month+=1;
    	}
    	else if(day < 31)
    		day +=1;
    }
    else{
    	if(day==30&&month == 12){
    		day=1;month=1;year+=1;
    	}
    	else if(day ==30){
    		day =1; month+=1;
    	}
    	else if(day < 31)
    		day +=1;
    }
}

    cout<<year<<'-'<<setw(2)<<setfill('0')<<month<<'-'<<setw(2)<<setfill('0')<<day<<endl;






	return 0;
}


描述

有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的矩阵，每个格点为一个房间，房间里可能住人，也可能空着。在第一天，有些房间里的人得了流感，以后每天，得流感的人会使其邻居传染上流感，（已经得病的不变），空房间不会传染。请输出第m天得流感的人数。


输入

第一行一个数字n，n不超过100，表示有n*n的宿舍房间。 

接下来的n行，每行n个字符，’.’表示第一天该房间住着健康的人，’#’表示该房间空着，’@’表示第一天该房间住着得流感的人。 

接下来的一行是一个整数m，m不超过100.


输出

输出第m天，得流感的人数


#include <iostream>
#include <iomanip>
using namespace std;
char room[100][100];
int  room_new[100][100] = {0};//记录新感染的人

void chuanran(int n){
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n;j++){
			if(room[i][j] == '@'&&room_new[i][j] == 1){
				if(room[i-1][j]=='.'&& i-1>=0){
					room[i-1][j] = '@';
				}
				if(room[i+1][j] == '.'&& i+1<n){
					room[i+1][j] = '@';
				}
				if(room[i][j+1] == '.'&& j+1<n){
					room[i][j+1] = '@';
				}
				if(room[i][j-1] == '.' && j-1>=0){
					room[i][j-1] = '@';
				}
				room_new[i][j] = 2;
			}
		}
	}
}

int main() {
        int n;
        cin>>n;

        for(int i = 0; i<n;i++){
	      for(int j = 0; j<n; j++){
	    	  cin>>room[i][j];
	      }
        }
        int m;
        cin>>m;
        while(m>1){
        	for(int i = 0; i<n;i++){
        		for(int j = 0; j<n;j++){
        			if(room[i][j] == '@'&&room_new[i][j] == 0){
        				room_new[i][j] = 1;
        			}
        		}
        	}
        chuanran(n);

        m--;
        }
 int sum = 0;
        for(int i = 0;i<n;i++){
        	for(int j = 0;j<n;j++){
        		if(room[i][j] == '@'){
        			sum++;
        		}
        	}
        }
        cout<<sum<<endl;

	return 0;
}

描述

输入一个句子（一行），将句子中的每一个单词翻转后输出。


输入

只有一行，为一个字符串，不超过500个字符。单词之间以空格隔开。所谓单词指的是所有不包含空格的连续的字符。

这道题请用cin.getline输入一行后再逐个单词递归处理。

输出

翻转每一个单词后的字符串，单词之间的空格需与原文一致。


#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
char temp[500];
int count;
int b = 0;

void reverse(int start, int num,char a[]){

	if(start == num -1){
		cout << a[start];
	}
	else{
		reverse(start+1,num,a);
	    cout<<a[start];
	}

}


int main() {

	char m[500];
	cin.getline(m,500);

	int number = 0;
	for(int i = 0; m[i]!='\0';i++){
		number ++;
		}


   m[number] = ' '; m[number+1] = '\0';



	for(int i = 0; m[i]!='\0';i++){
		if(m[i]!=' '&&m[i+1]!=' '){
			temp[count] = m[i]; count++;
		}
		else if(m[i] != ' ' && m[i+1] == ' '){
			temp[count]= m[i]; count++;
			reverse(0,count,temp);
			count = 0;
		}
		else if(m[i]==' '&& m[i+1]=='\0'){
			m[i] = '\0';
		}
		else if (m[i] == ' '){
			cout<<' ';
		}
	}

	return 0;
}



所谓角谷猜想，是指对于任意一个正整数，如果是奇数，则乘3加1，如果是偶数，则除以2，得到的结果再按照上述规则重复处理，最终总能够得到1。如，假定初始整数为5，计算过程分别为16、8、4、2、1。

程序要求输入一个整数，将经过处理得到1的过程输出来。

输入
一个正整数

输出
从输入整数到1的步骤，每一步为一行，每一部中描述计算过程，假定输入为7，则输出为：

7*3+1=22

22/2=11

11*3+1=34

34/2=17

17*3+1=52

52/2=26

26/2=13

13*3+1=40

40/2=20

20/2=10

10/2=5

5*3+1=16

16/2=8

8/2=4

4/2=2

2/2=1

最后一行输出"End"，如果输入为1，直接输出"End"
	

#include <iostream>
#include <iomanip>
using namespace std;
int num[10000000];
int k =0;

void jiaogu(int n){

	if(n == 1){
	 cout<<"End"<<endl;
	}
	else if(n%2 == 0){
	 cout<<n<<'/'<<'2'<<'='<<n/2<<endl;
	 return  jiaogu(n/2);
	}
	else if(n%2 != 0){
	 cout<<n<<'*'<<'3'<<'+'<<'1'<<'='<<n*3+1<<endl;
	 return jiaogu(n*3+1);
	}

}




int main() {
	int n;
    cin>>n;

	jiaogu(n);




	return 0;
}



描述
在幼儿园中，老师安排小朋友做一个排队的游戏。首先老师精心的把数目相同的小男孩和小女孩编排在一个队列中，每个小孩按其在队列中的位置发给一个编号（编 号从0开始）。然后老师告诉小朋友们，站在前边的小男孩可以和他后边相邻的小女孩手拉手离开队列，剩余的小朋友重新站拢，再按前后相邻的小男孩小女孩手拉 手离开队列游戏，如此往复。由于教师精心的安排，恰好可以保证每两个小朋友都能手拉手离开队列，并且最后离开的两个小朋友是编号最小的和最大的两个小朋 友。（注：只有小男孩在前，小女孩在后，且他们两之间没有其他的小朋友，他们才能手拉手离开队列）。请根据老师的排队，按小女孩编号从小到大的顺序，给出 所有手拉手离开队列的小男孩和小女孩的编号对。

输入
用一个字符串代表小朋友队列。字符串中只会出现两个字符（样例输入里用的是 括号但实际数据则不一定），分别代表小男孩和小女孩，首先出现的字符代表小男孩，另一个字符代表小女孩。小孩总数不超过100

输出
按小女孩编号顺序，顺序输出手拉手离开队列的小男孩和小女孩的编号对，每行一对编号，编号之间用一个空格分隔。




#include <iostream>
#include <iomanip>
#include<cstring>
using namespace std;
char str[100]={};
char boy, girl;
int paidui(int);



int main() {

	cin>> str;
    boy = str[0];
    int n;
    n = strlen(str);

    for(int i = 0; i<n; i++){
    	if(str[i]!=boy){
    		girl = str[i];
    		break;
    	}
    }

    paidui(0);

	return 0;
}

   int paidui(int n){
	   if(str[n]== girl)
		   return n;
	   if(str[n]==' ')
		   return n;
	   int r = n+1;
	   while(str[r] != girl && str[r] != ' '){
		   r = paidui(r);
	   }
	   if(str[r]== girl){
		   cout<<n<<' '<<r<<endl;
		   return r+1;
	   }
	   else
		   return r;


   }


描述
输入一个整数矩阵，计算位于矩阵边缘的元素之和。所谓矩阵边缘的元素，就是第一行和最后一行的元素以及第一列和最后一列的元素。

输入
第一行为整数k，表示有k组数据。

每组数据有多行组成，表示一个矩阵：

第一行分别为矩阵的行数m和列数n（m < 100，n < 100），两者之间以空格分隔。

接下来输入的m行数据中，每行包含n个整数，整数之间以空格作为间隔。

输出

输出对应矩阵的边缘元素和，一个一行。

#include <iostream>
#include <iomanip>
using namespace std;
int sum = 0;
int a[101][101]= {0};


int main() {
    int n;

	cin>>n;
	int m1,m2;


	while(n>0){
		cin>>m1>>m2;



	    for(int i = 0; i<m1; i++){
		   for(int j = 0; j<m2;j++){
				cin>>a[i][j];
			    }
			}
				int *p = a[0];
		for(int i = 0; i<m1;i++){
		 if(i==0){
			 for(int j = 0; j<m2; j++){
				 sum+=*p; p++;
			 }

		 }
		 else if(i == m1-1){
			 p = a[m1-1];
			 for(int j = 0; j<m2; j++){
				 sum+= *p;p++;
			 }
		 }
		 else{
			 sum+=(a[i][0] + a[i][m2-1]);
		 }

		}
		cout<<sum<<endl;
		sum = 0;
		n--;
	}


    return 0;
}

描述
给定一个row行col列的整数数组array，要求从array[0][0]元素开始，按从左上到右下的对角线顺序遍历整个数组。


输入

输入的第一行上有两个整数，依次为row和col。

余下有row行，每行包含col个整数，构成一个二维整数数组。

（注：输入的row和col保证0 < row < 100, 0 < col < 100）

输出
按遍历顺序输出每个整数。每个整数占一行。

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int A[100][100];
    int row, col, i, j, r=0, c=0;
    cin >> row >> col;
    for (i=0; i<row; i++)
        for (j=0; j<col; j++)
            cin >> A[i][j];


   for(int j = 0; j<col;j++){
	   r = 0;
	   c = j;
	   while(r<row&&c>=0){
		   cout<<A[r++][c--]<<endl;;
	   }
   }

   for(int i = 1; i<row; i++){
	   c = col-1;
	   r = i;
	   while(c>=0&&r<=row-1){
		   cout<<A[r++][c--]<<endl;;
	   }
   }


    return 0;
}




描述
某个科室的病房分为重症和普通，只有当病人的疾病严重程度超过了入住重症病房的最低严重值，才可以安排入住重症病房。

现在要求设计一个程序，给病人安排好病房。疾病的严重程度用0到10来表示，0表示小毛病，10表示非常严重。

输入
第一行输入病人的个数m(m < 50)，以及安排住入重症病房的最低严重值a

紧接着m行，每行表示病人编号（三个位，用0补齐）及其疾病的严重程度（浮点数，1位小数）。

每个病人的疾病严重程度都不一样。

输出
要求按照病人的严重程度输出住在重症病房里的病人的编号

注意：

如果当前所有病人的严重程度并不满足住在重症病房里，则输出“None.”（不包括引号）

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int id[101]= {0};
float s[101] = {0};

int main()
{

int *p1 = id;
float *p2 = s;
int num = 0;
float n;int m;
  cin>>m>>n;//m是总的样本数，n是最低严重值；

  for(int i = 0; i<m; i++){
	  int ID;float state;
	  cin>>ID>>state;
	  if(state >n){
		  *p1 =ID;
		  *p2 = state;
		  p1++;p2++;
		  num++;
	  }
  }

  p1=id;p2 =s;

    if(num == 0){
  	  cout<<"None."<<endl;
    }
    else{
  	  for(int i = 0; i<num;i++){
  		 for(int j = 0; j<num-1-i;j++){
  			 if(s[j] < s[j+1]){
  				 float temp1;
  				 temp1 = s[j];
  				 s[j] = s[j+1];
  				 s[j+1] = temp1;
  				 int temp2;
  				 temp2 = id[j];
  				 id[j] = id[j+1];
  				 id[j+1] = temp2;

  			 }
  		 }
  	  }
    }
  if(num != 0){
    for(int i =0; i<num;i++){
   	   cout<<setfill('0')<<setw(3)<<id[i]<<' '<<fixed<<setprecision(1)<<s[i]<<endl;
      }
  }



    return 0;
}

描述
脱氧核糖核酸（DNA）由两条互补的碱基链以双螺旋的方式结合而成。而构成DNA的碱基共有4种，分别为腺瞟呤（A）、鸟嘌呤（G）、胸腺嘧啶（T）和胞嘧啶（C）。我们知道，在两条互补碱基链的对应位置上，腺瞟呤总是和胸腺嘧啶配对，鸟嘌呤总是和胞嘧啶配对。你的任务就是根据一条单链上的碱基序列，给出对应的互补链上的碱基序列。

输入
第一行是一个正整数n，表明共有n条要求解的碱基链。

以下共有n行，每行用一个字符串表示一条碱基链。这个字符串只含有大写字母A、T、G、C，分别表示腺瞟呤、胸腺嘧啶、鸟嘌呤和胞嘧啶。每条碱基链的长度都不超过255。

输出
共有n行，每行为一个只含有大写字母A、T、G、C的字符串。分别为与输入的各碱基链互补的碱基链。


#include <cstring>
#include <iomanip>
using namespace std;
char a[1000][256] = {};



int main()
{
  int n;
  cin>>n;
  cin.get();


  char (*p)[256] = a;

  for(int i = 0; i<n; i++){
	  cin>>*p;
	  p++;
  }

 p = a;

 for(int i = 0; i<n;i++){
	 int j = 0;
	 while(p[i][j] != '\0'){
		 if(p[i][j] == 'A'){
			 p[i][j] = 'T';
		 }
		 else if(p[i][j] == 'T'){
			 p[i][j] = 'A';
		 }
		 else if (p[i][j] == 'G'){
			 p[i][j] = 'C';
		 }
		 else{
			 p[i][j] = 'G';
		 }
		 j++;
	 }
 }
 p=a;
 for(int i = 0; i<n;i++){
	 cout<<*p++<<endl;
 }

    return 0;
}


描述
输入一串长度不超过500个符号的字符串，输出在串中出现第2多的英语字母(大小写字母认为相同)和次数（如果串中有其它符号，则忽略不考虑）。如果有多个字母的次数都是第2多，则按串中字母出现的顺序输出第1个。

例 ab&dcAab&c9defgb

这里，a 和 b都出现3次，c和d都出现2次，e、f 和 g 各出现1次，其中的符号&和9均忽略不考虑。因此，出现第2多的应该是 c 和 d，但是 d 开始出现的位置在 c 的前面，因此，输出为

D+d:2

(假定在字符串中，次数第2多的字母总存在)

输入
一个字符串

输出
大写字母+小写字母:个数
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
char a[500] = {};
struct str{
	char alpha[26]={'A', 'B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	int count[26] ={0};
};



int main()
{

	str string;
	cin.getline(a,500);

	for(int i = 0; a[i]!='\0';i++){
		if((97<=a[i]&&a[i]<=122)||(a[i]>=65&&a[i]<=90)){
			for(int j = 0; j<25;j++){
				if(toupper(a[i]) == string.alpha[j]){
					string.count[j] +=1;
				}
			}
		}
		else
			continue;
	}


	int index = 0;
	int Max = 0;



    	for(int j = 0; j<26;j++){
    		if(string.count[j]>Max){
    			Max = string.count[j];
    			index = j;
    		}
    	}//得到当前数组的最大的那个数

        int id[26] = {0};
    	bool second = 0;
    	char secondMax[26] ={};
    	int h = 0;
    	while(Max>=0){
    		Max--;
    		for(int k = 0; k<26;k++){
    		if(string.count[k] == Max){
    			secondMax[h] = string.alpha[k];
    			id[h] = k;
    			second =1;
    			h++;
    		}
    	 }
    		if(second == 1)
    			break;
    	}


    	for(int i=0; a[i]!='\0';i++){
    		for(int j = 0; j<26;j++){
    			if(toupper(a[i]) == secondMax[j]){
    				index = id[j];
    				second = 0;
    			    break;
    			}
    		}
    		if(second == 0){
    			break;
    		}
    	}

    cout<<string.alpha[index]<<'+'<<char (tolower(string.alpha[index]))<<':'<<string.count[index]<<endl;

    return 0;
}


描述
在一个学生信息处理程序中，要求实现一个代表学生的类，并且所有成员变量都应该是私有的。

（注：评测系统无法自动判断变量是否私有。我们会在结束之后统一对作业进行检查，请同学们严格按照题目要求完成，否则可能会影响作业成绩。）

输入
姓名，年龄，学号，第一学年平均成绩，第二学年平均成绩，第三学年平均成绩，第四学年平均成绩。

其中姓名、学号为字符串，不含空格和逗号；年龄为正整数；成绩为非负整数。

各部分内容之间均用单个英文逗号","隔开，无多余空格。

输出
一行，按顺序输出：姓名，年龄，学号，四年平均成绩（向下取整）。

各部分内容之间均用单个英文逗号","隔开，无多余空格。

#include<iostream>
#include<cstring>
using namespace std;

//评测系统
class student{
private:
	char name[20];
	char Id[20];
	int Age;
	int grade;
	int A,B,C,D;
public:
	int averagescore();
	void basicinfo();
	void getinfo();
};
int student::averagescore(){
	return ((A+B+C+D)/4);
}
void student::getinfo(){
	char a,b,c;
	cin.getline(name,20,',');
	cin>>Age>>a;
	cin.getline(Id,20,',');
	cin>>A>>a>>B>>b>>C>>c>>D;

}
void student:: basicinfo(){
	cout<<name<<','<<Age<<','<<Id<<','<<averagescore();
}

int main()
{

student r;
r.getinfo();
r.basicinfo();



	return 0;
}


#include <iostream>
using namespace std;
class Base {
public:
    int k;
    Base(int n):k(n) { }
};
class Big {
public:
    int v; Base b;
// 在此处补充你的代码
    Big(int n):v(n),b(n){}

    Big (Big &a):v(a.v),b(a.b.k){
    }
};
//这里用初始化列表是因为如果 b = a.b的话默认a2的b 是一个生成对象但是a2的b应该还没有生成所以用初始化列表

int main() {
    Big a1(5); Big a2 = a1;
    cout << a1.v << "," << a1.b.k << endl;
    cout << a2.v << "," << a2.b.k << endl;
    return 0;
}

魔兽世界 备战 
#include <iostream>
#include <iomanip>
#include<cstring>
#include <stdio.h>
using namespace std;//魔兽世界备战：：什么乱七八糟的
//五个类

class Charactor {
public:
    char name[7];//dragon ninja iceman lion wolf
    //函数名不是指针但是作为参数有贬为指针，但是他不能像指针那样赋值
    int borntime;
    int Charactor_life;
    Charactor(const char* a, int b, int c,int &d) {
        strcpy_s(name, a);
        Charactor_life = b;
        d-=b;
        borntime = c;
      
    }
};
//2个结构体red和blue


bool whether_stop(int a, int* b) {
    for (int i = 0; i < 5; i++) {
        if (a >= * b++) { return 1; }//继续制造
    }
    return 0;
}

struct s_life {
    char species[5][7] = { "dragon","ninja","iceman","lion","wolf" };//输入时的顺序
    int species_life[5];
};

int num_of_charactor(char(*a)[7], char(*b)[7], int array[]) {
    for (int i = 0; i < 5; i++) {
        if (**a == **(b + i)) { array[i] += 1; return array[i]; }       
    }
    
}//匹配到对象就加1

void Jump_or_not(char(*a)[7], int b, int* c, int& d) {
    if (b < *c) {
        //如果生命值小于此物种
        for (int i = 0; i < 5; i++) {
            if (d == 4) { 
                if (b >= * c) { break; }
                else{ c -= 4; d = 0; a -= 4; }
            }
            else {
                if (b >= *c) { break; }
                else { d++; c++; a++; }
            }
        }
    }
}
int main() {
   

    int num_of_case;
    cin >> num_of_case;
    int case_n = 0;
    while (num_of_case > 0) {
        char red[5][7] = { "iceman","lion","wolf","ninja","dragon" };
        int red_life[5] = { 0 };
        int red_num_of_charactor[5] = { 0 };
        //这里是关系到输出顺序
        char blue[5][7] = { "lion","dragon","ninja","iceman","wolf" };
        int blue_life[5] = { 0 };
        int blue_num_of_charactor[5] = { 0 };

        int red_ID = 0, blue_ID = 0;
        int borntime = 0;
        int life;
        int red_total_life;
        int blue_total_life;//大本营的生命值


    s_life object;

    //循环次数

    cin >> life; red_total_life = life; blue_total_life = life;

    for (int i = 0; i < 5; i++) {
        cin >> object.species_life[i];//录入每种物种的生命值
    }
    
    char(*c1)[7] = red;
    char(*c2)[7] = blue;

 
   
;    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if(**(c1+i)==**(object.species+j)) {
                red_life[i] = object.species_life[j];
            }
        }
    }
    //犯了个错误，*号应该是只有指针指向一个元素的时候加*号是可以提取该元素的否则只是升级降级的作用；
    

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (**(object.species + j) == **(c2 + i)) {
                blue_life[i] = object.species_life[j];
            }
        }
    }

    //把输出顺序调好

     bool red_finish_or_not = 0;bool blue_finish_or_not = 0;
     int red_i = 0, blue_i = 0;
     printf("Case:%u\n", ++case_n);
        while (1) {
            int record = 0;//记录红蓝双方有没有生成士兵。
            if (whether_stop(red_total_life, object.species_life) == 0 && red_finish_or_not == 0) { cout << setw(3) << setfill('0') << borntime << ' ' << "red headquarter stops making warriors" << endl; red_finish_or_not = 1; }
            if (whether_stop(red_total_life, object.species_life)) {
                Jump_or_not(c1, red_total_life, &red_life[red_i], (red_i));
                c1 = &red[red_i];
                Charactor* pred = new Charactor(*c1, red_life[red_i], borntime, red_total_life);
                printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
                    pred->borntime, "red", pred->name, ++red_ID, pred->Charactor_life, num_of_charactor(c1, red, red_num_of_charactor), pred->name, "red");
                if (**(c1++) == 'd') { c1 = red; }
                delete pred;
                record += 1;
                if (red_i < 4) { red_i++; }
                else { red_i = 0; }
            }

            if (whether_stop(blue_total_life, object.species_life) == 0 && blue_finish_or_not == 0) { cout << setw(3) << setfill('0') << borntime << ' ' << "blue headquarter stops making warriors" << endl; blue_finish_or_not = 1; }
            if (whether_stop(blue_total_life, object.species_life)) {
                Jump_or_not(c2, blue_total_life, &blue_life[blue_i], (blue_i));
                c2 = &blue[blue_i];
                Charactor* pblue = new Charactor(*c2, blue_life[blue_i], borntime, blue_total_life);
                printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
                    pblue->borntime, "blue", pblue->name, ++blue_ID, pblue->Charactor_life, num_of_charactor(c2, blue, blue_num_of_charactor), pblue->name, "blue");
                if (**(c2 ++) == 'w') { c2 = blue; }
                delete pblue;
                record += 1;
                if (blue_i < 4) { blue_i++; }
                else { blue_i = 0; }
            }

            if (record == 0) { break; }
            borntime++;
            
        }
        num_of_case--;
    }

    return 0;
}


描述
写一个MyString 类，使得下面程序的输出结果是：

1. abcd-efgh-abcd-

2. abcd-

3.

4. abcd-efgh-

5. efgh-

6. c

7. abcd-

8. ijAl-

9. ijAl-mnop

10. qrst-abcd-

11. abcd-qrst-abcd- uvw xyz

about

big

me

take

abcd

qrst-abcd-

要求：MyString类必须是从C++的标准类string类派生而来。提示1：如果将程序中所有 "MyString" 用"string" 替换，那么题目的程序中除了最后两条语句编译无法通过外，其他语句都没有问题，而且输出和前面给的结果吻合。也就是说，MyString类对 string类的功能扩充只体现在最后两条语句上面。提示2: string类有一个成员函数 string substr(int start,int length); 能够求从 start位置开始，长度为length的子串

程序：


#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
// 在此处补充你的代码
class MyString {
	char* sValue;
public:
	MyString() { sValue = NULL; }
	MyString(const char* a) {
		int n = strlen(a);
		sValue = new char[n + 1];
		int i;
		for (i = 0; i < n; i++) {
			sValue[i] = a[i];
		}
		sValue[i] = '\0';
	}

	MyString operator+(MyString a) {
		MyString m;
		m.sValue = new char[(strlen(sValue) + strlen(a.sValue) + 1)];
		strcpy(m.sValue, sValue);
		strcat(m.sValue, a.sValue);
		return m;
	}
	friend ostream& operator<<(ostream& a, const MyString& b);
	char& operator[](int a) { return sValue[a]; }
	MyString(string a) {
		if (sValue)
			delete[]sValue;
		else {
			sValue = new char[(strlen(a.c_str()))];
			strcpy(sValue, a.c_str());
		}

	}
	MyString operator+=(const char* a) {
		int n;
		n = strlen(a) + strlen(sValue);
		char* p = new char[n + 1];
		strcpy(p, sValue);
		strcat(p, a);
		delete[]sValue;
		sValue = p;
		return *this;
	}
	friend MyString operator+(const char*, MyString&);
	MyString operator+(const char* a) {
		char* p = new char[strlen(a) + strlen(sValue) + 1];
		strcpy(p, sValue);
		strcat(p, a);
		if (sValue) { delete[]sValue; }
		sValue = p;
		return *this;
	}
	bool operator<(MyString& a) {
		int i = strcmp(sValue, a.sValue);
		if (i < 0) {
			return 1;
		}
		else
			return 0;
	}
	bool operator==(MyString& a) {
		int i = strcmp(sValue, a.sValue);
		if (i == 0) {
			return 1;
		}
		else
			return 0;
	}
	bool operator>(MyString& a) {
		int i = strcmp(sValue, a.sValue);
		if (i > 0) {
			return 1;
		}
		else
			return 0;
	}


    MyString operator()(int i, int j) {
        MyString res;
        res.sValue = new char[j];
        int start=i;
        int idx = 0;
        for (idx=0; idx < j; idx++)
            res.sValue[idx] = sValue[start++];
        res.sValue[idx] = '\0';
        return res;
    }
};
MyString operator+(const char* a, MyString& b) {
	MyString p;
	p.sValue = new char[strlen(a) + strlen(b.sValue) + 1];
	strcpy(p.sValue, a);
	strcat(p.sValue, b.sValue);
	return p;
}
ostream& operator<<(ostream& a, const MyString& b) {
	if (b.sValue == NULL)
		return a;
	else {
		a << b.sValue;
		return a;
	}
}
int CompareString(const void* e1, const void* e2) {
	MyString* s1 = (MyString*)e1;
	MyString* s2 = (MyString*)e2;
	if (*s1 < *s2) return -1;
	else if (*s1 == *s2) return 0;
	else if (*s1 > * s2) return 1;
}
int main() {
	MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
	MyString SArray[4] = { "big","me","about","take" };
	cout << "1. " << s1 << s2 << s3 << s4 << endl;
	s4 = s3; s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1; s1 = "ijkl-";
	s1[2] = 'A';
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray, 4, sizeof(MyString), CompareString);
	for( int i = 0;i < 4;++i )
	        cout << SArray[i] << endl;
	//输出s1从下标0开始长度为4的子串
	    cout << s1(0,4) << endl;
	    //输出s1从下标为5开始长度为10的子串
	    cout << s1(5,10) << endl;
	return 0;
}

编程题＃2： 魔兽世界之二：装备

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。 

红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。 

有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。

双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。 

不同的武士有不同的特点。

dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。

ninjia可以拥有两件武器。编号为n的ninjia降生时即获得编号为 n%3 和 (n+1)%3的武器。

iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。

lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。

wolf没特点。

请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。

武士在刚降生的时候有一个生命值。 

在每个整点，双方的司令部中各有一个武士降生。 

红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。 

蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。 

制造武士需要生命元。 

制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。 

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。

一共有两种事件，其对应的输出样例如下： 

1) 武士降生 

输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter

表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。(为简单起见，不考虑单词的复数形式)注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

如果造出的是dragon，那么还要输出一行，例：

It has a arrow,and it's morale is 23.34

表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）

如果造出的是ninjia，那么还要输出一行，例：

It has a bomb and a arrow

表示该ninjia降生时得到了bomb和arrow。

如果造出的是iceman，那么还要输出一行，例：

It has a sword

表示该iceman降生时得到了sword。

如果造出的是lion，那么还要输出一行，例：

It's loyalty is 24

表示该lion降生时的忠诚度是24。

2) 司令部停止制造武士

输出样例： 010 red headquarter stops making warriors

表示在 10点整，红方司令部停止制造武士

输出事件时： 

首先按时间顺序输出； 

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。


输入

第一行是一个整数,代表测试数据组数。

每组测试数据共两行。 

第一行，一个整数M。其含义为： 每个司令部一开始都有M个生命元( 1 <= M <= 10000) 

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000


输出

对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。

对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始 

接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。


//魔兽世界World of Warcraft
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include<cstring>
using namespace std;

class Charactor {
protected:
	string name;
	int borntime;
	int charactor_life;
public:
	Charactor(const string, int, int);
	~Charactor() {};
	const char* return_name() {
		return (name.c_str());
	}
	int return_borntime() {
		return borntime;
	}
	int return_charactor_life() {
		return charactor_life;
	}
};

struct s_life {
	string species[5] = { "dragon","ninja","iceman","lion","wolf" };
	int species_life[5] = { 0 };
};

class blueHeadquarter;
class  redHeadquarter {
	static int red_ID;
	static float red_Headquarter_life;//大本营生命值
	static int red_life[5];
	static int red_num_of_charactor[5];

public:
	redHeadquarter() {};
	~redHeadquarter() {};
	static string red[5];
	static void assign_life(int a, int b) {
		red_life[a] = b;
	}
	friend class Charactor;
	friend void c_in(redHeadquarter&, blueHeadquarter&, s_life&);
	friend void rearrange_order(int, s_life);
	float return_red_Headquarter_life() {
		return red_Headquarter_life;
	}
	int* return_red_life(int a) {
		return &red_life[a];
	}
	void red_manufacturing(int a) {
		red_Headquarter_life -= red_life[a];
	}
	int& return_red_ID() {
		return red_ID;
	}
	int* return_red_num_of_charactor() {
		return red_num_of_charactor;
	}
	friend class dragon;
	friend class lion;
	friend void details(string, bool);
	friend void reset();
};
int redHeadquarter::red_ID = 0;
int redHeadquarter::red_life[5] = { 0 };
int redHeadquarter::red_num_of_charactor[5] = { 0 };
string redHeadquarter::red[5] = { "iceman", "lion", "wolf", "ninja", "dragon" };
float redHeadquarter::red_Headquarter_life = 0;

class blueHeadquarter {
	static int blue_ID;
	static float blue_Headquarter_life;//大本营生命值
	static int blue_life[5];
	static int blue_num_of_charactor[5];
public:
	blueHeadquarter() {};
	~blueHeadquarter() {};
	static string blue[5];
	static void assign_life(int a, int b) {
		blue_life[a] = b;
	}
	friend class Charactor;
	friend void c_in(redHeadquarter&, blueHeadquarter&, s_life&);
	friend void rearrange_order(int, s_life);
	float return_blue_Headquarter_life() {
		return blue_Headquarter_life;
	}
	int* return_blue_life(int a) {
		return &blue_life[a];
	}
	void blue_manufacturing(int a) {
		blue_Headquarter_life -= blue_life[a];
	}
	int& return_blue_ID() {
		return blue_ID;
	}
	int* return_blue_num_of_charactor() {
		return blue_num_of_charactor;
	}
	friend class dragon;
	friend class lion;
	friend void details(string, bool);
	friend void reset();

};
int blueHeadquarter::blue_num_of_charactor[5] = { 0 };
int blueHeadquarter::blue_ID = 0;
float blueHeadquarter::blue_Headquarter_life = 0;
int blueHeadquarter::blue_life[5] = { 0 };
string blueHeadquarter::blue[5] = { "lion","dragon","ninja","iceman","wolf" };

void reset() {
	for (int i = 0; i < 5; i++) {
		redHeadquarter::red_num_of_charactor[i] = 0;
		blueHeadquarter::blue_num_of_charactor[i] = 0;
	}
	redHeadquarter::red_ID = 0;
	blueHeadquarter::blue_ID = 0;

}



Charactor::Charactor(const string name_, int life, int time) {
	name = name_;
	borntime = time;
	charactor_life = life;
}
bool Whether_stop(int a, const int* b) {
	float tmp; redHeadquarter r; blueHeadquarter blue;
	if (a == 1)
		tmp = r.return_red_Headquarter_life();
	else
		tmp = blue.return_blue_Headquarter_life();
	for (int i = 0; i < 5; i++) {
		if (tmp >= *b++)
			return true;
	}
	return false;
}

void c_in(redHeadquarter& a, blueHeadquarter& b, s_life& c) {
	float life;
	cin >> life;
	b.blue_Headquarter_life = life;
	a.red_Headquarter_life = life;
	for (int i = 0; i < 5; i++) {
		cin >> c.species_life[i];
	}
}

void rearrange_order(int a, s_life b) {
	if (a) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (strcmp((&b.species[j])->c_str(), (&redHeadquarter::red[i])->c_str()) == 0)
					redHeadquarter::assign_life(i, b.species_life[j]);
			}
		}
	}
	else {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (strcmp((&b.species[j])->c_str(), (&blueHeadquarter::blue[i])->c_str()) == 0)
					blueHeadquarter::assign_life(i, b.species_life[j]);
			}
		}
	}
}
void Jump_or_not(string* a, float b, int* c, int& d) {
	if (b < *c) {
		for (int i = 0; i < 5; i++) {
			if (d == 4) {
				if (b >= *c)
					break;
				else { c -= 4; d = 0; a -= 4; }
			}
			else {
				if (b >= *c)
					break;
				else { d++; c++; a++; }
			}
		}
	}
}
int num_of_charactor(string a, string* b, int array[]) {
	for (int i = 0; i < 5; i++) {
		if (strcmp(a.c_str(), (b[i]).c_str()) == 0) {
			array[i] += 1;
			return array[i];
		}
	}
}

class weapon {
	static string wuqi[3];
public:
	weapon() {
	}
	friend void c_out(string s);
};
string weapon::wuqi[3] = { "sword","bomb","arrow" };
class dragon :public weapon {
	static int weapon_d;
	static float morale;
public:
	dragon(int, float);
	friend void c_out(string);
};
int dragon::weapon_d = 0;
float dragon::morale = 0;
dragon::dragon(int n, float m) {
	weapon_d = n % 3;
	morale = m / redHeadquarter::red_life[4];//友元类访问静态私有成员
}


class ninja :public weapon {
	static int weapon_x;
	static int weapon_y;
public:
	ninja(int);
	friend void c_out(string);
};
int ninja::weapon_x = 0;
int ninja::weapon_y = 0;
ninja::ninja(int n) {
	weapon_x = n % 3;
	weapon_y = (n + 1) % 3;
}
class iceman :public weapon {
	static int weapon;
public:
	iceman(int);
	friend void c_out(string);
};
int iceman::weapon = 0;
iceman::iceman(int n) {
	weapon = n % 3;
}
class lion :public weapon {
	static int loyalty;
public:
	lion(string);
	friend void c_out(string);
};
int lion::loyalty = 0;
lion::lion(string h) {
	if (!strcmp(h.c_str(), "red"))
		loyalty = (int)redHeadquarter::red_Headquarter_life;
	else
		loyalty = (int)blueHeadquarter::blue_Headquarter_life;
}
class wolf :public weapon {

};
void c_out(string);
void details(string s, bool b) {
	if (!strcmp(s.c_str(), "dragon")) {
		if (b == 1)
			dragon d(redHeadquarter::red_ID, redHeadquarter::red_Headquarter_life);//有元函数可以访问静态私有成员
		else
			dragon d(blueHeadquarter::blue_ID, blueHeadquarter::blue_Headquarter_life);
		c_out("dragon");
	}
	else if (!strcmp(s.c_str(), "ninja")) {
		if (b == 1)
			ninja n(redHeadquarter::red_ID);
		else
			ninja n(blueHeadquarter::blue_ID);
		c_out("ninja");
	}
	else if (!strcmp(s.c_str(), "iceman")) {
		if (b == 1)
			iceman i(redHeadquarter::red_ID);
		else
			iceman i(blueHeadquarter::blue_ID);
		c_out("iceman");
	}
	else if (!strcmp(s.c_str(), "lion")) {
		if (b == 1)
			lion l("red");
		else
			lion l("blue");
		c_out("lion");
	}
}
void c_out(string s) {
	if (!strcmp(s.c_str(), "dragon")) {
		printf("It has a %s and it's morale is %.2f\n", weapon::wuqi[dragon::weapon_d].c_str(), dragon::morale);
	}
	else if (!strcmp(s.c_str(), "ninja")) {
		printf("It has a %s and a %s\n", weapon::wuqi[ninja::weapon_x].c_str(), weapon::wuqi[ninja::weapon_y].c_str());
	}
	else if (!strcmp(s.c_str(), "iceman")) {
		printf("It has a %s\n", weapon::wuqi[iceman::weapon].c_str());
	}
	else if (!strcmp(s.c_str(), "lion")) {
		printf("It's loyalty is %d\n", lion::loyalty);
	}
}
int main() {

	int num_of_case;
	cin >> num_of_case;
	int case_n = 0;
	while (num_of_case > 0) {
		s_life object; int borntime = 0, red_i = 0, blue_i = 0; bool red_flag = 0, blue_flag = 0;
		redHeadquarter red;
		blueHeadquarter blue;
		reset();
		string* c1 = red.red;
		string* c2 = blue.blue;

		c_in(red, blue, object);
		rearrange_order(1, object);
		rearrange_order(0, object);
		printf("Case:%u\n", ++case_n);


		while (1) {
			int record = 0;
			if ((!Whether_stop(1, object.species_life) && !red_flag)) {
				cout << setw(3) << setfill('0') << borntime << ' ' << "red headquarter stops making warriors" << endl;
				red_flag = 1;
			}
			if (Whether_stop(1, object.species_life)) {
				Jump_or_not(redHeadquarter::red, red.return_red_Headquarter_life(), red.return_red_life(red_i), red_i);
				Charactor* pred = new Charactor(redHeadquarter::red[red_i], *red.return_red_life(red_i), borntime);
				red.red_manufacturing(red_i);
				printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
					pred->return_borntime(), "red", pred->return_name(), ++red.return_red_ID(), pred->return_charactor_life(),
					num_of_charactor(red.red[red_i], red.red, red.return_red_num_of_charactor()), pred->return_name(), "red");
				details(redHeadquarter::red[red_i], 1);
				if (strcmp((*c1).c_str(), "dragon"))
					c1 = red.red;
				delete pred;
				record += 1;
				if (red_i < 4)
					red_i++;
				else
					red_i = 0;
			}
			if ((!Whether_stop(0, object.species_life)) && !blue_flag) {
				cout << setw(3) << setfill('0') << borntime << ' ' << "blue headquarter stops making warriors" << endl;
				blue_flag = 1;
			}
			if (Whether_stop(0, object.species_life)) {
				Jump_or_not(blueHeadquarter::blue, blue.return_blue_Headquarter_life(), blue.return_blue_life(blue_i), blue_i);
				Charactor* pblue = new Charactor(blueHeadquarter::blue[blue_i], *blue.return_blue_life(blue_i), borntime);
				blue.blue_manufacturing(blue_i);
				printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
					pblue->return_borntime(), "blue", pblue->return_name(), ++blue.return_blue_ID(), pblue->return_charactor_life(),
					num_of_charactor(blue.blue[blue_i], blue.blue, blue.return_blue_num_of_charactor()), pblue->return_name(), "blue");
				details(blueHeadquarter::blue[blue_i], 0);
				if (strcmp((*c2).c_str(), "Wolf"))
					c2 = blue.blue;
				delete pblue;
				record += 1;
				if (blue_i < 4) {
					blue_i++;
				}
				else
					blue_i = 0;
			}
			if (record == 0)
				break;
			borntime++;

		}
		num_of_case--;

	}
	return 0;
}


给定n个字符串（从1开始编号），每个字符串中的字符位置从0开始编号，长度为1-500，现有如下若干操作：

copy N X L：取出第N个字符串第X个字符开始的长度为L的字符串。

add S1 S2：判断S1，S2是否为0-99999之间的整数，若是则将其转化为整数做加法，若不是，则作字符串加法，返回的值为一字符串。

find S N：在第N个字符串中从左开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。

rfind S N：在第N个字符串中从右开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。

insert S N X：在第N个字符串的第X个字符位置中插入S字符串。

reset S N：将第N个字符串变为S。

print N：打印输出第N个字符串。

printall：打印输出所有字符串。

over：结束操作。

其中N，X，L可由find与rfind操作表达式构成，S，S1，S2可由copy与add操作表达式构成。

输入

第一行为一个整数n（n在1-20之间）

接下来n行为n个字符串，字符串不包含空格及操作命令等。

接下来若干行为一系列操作，直到over结束。

输出

根据操作提示输出对应字符串。

#include <iostream>
#include <string>
#include<stdlib.h>
#include<cstdlib>

using namespace std;
string str[22];
string Myreset();
void getString(string&);
void getInt(int&);
string Mycopy();
string MyAdd();
int MyRfind();
int Myfind();
void Getstring(string&, int&);
string MyInsert() {
	string s;
	int n, x;
	getString(s);
	getInt(n);
	getInt(x);
	return(str[n].insert(x, s));

}
void Myitoa(int m, char* const str, int& i) {
	if (m >= 0 && m <= 9) {
		str[i++] = (char)(m + 48);
	}
	else {
		Myitoa(m / 10, str, i);
		str[i++] = (char)(m % 10 + 48);
	}
}
int Myatoi(const char* str) {
	if (str == NULL) {
		return -1;
	}
	else {
		return (int)*str - 48;
	}
}
void getInt(int& n) {
	string s;
	cin >> s;
	if (s == "find") {
		n = Myfind();
	}
	else if (s == "rfind") {
		n = MyRfind();
	}
	else
		n = Myatoi(s.c_str());
}
int Myfind() {
	string s;
	getString(s);
	int n;
	getInt(n);
	int value;
	value = str[n].find(s.c_str());
	if (value == string::npos)
		return s.length();
	else
		return value;
}
int MyRfind() {
	string s;
	getString(s);
	int n;
	getInt(n);
	int value = str[n].rfind(s.c_str());
	if (value == string::npos)
		return s.length();
	else
		return value;
}
void getString(string& s) {
	string Instruct;
	cin >> Instruct;
	if (Instruct == "copy") {
		s = Mycopy();
	}
	else if (Instruct == "add") {
		s = MyAdd();
	}
	else
		s = Instruct;
}

string MyAdd() {
	string s1, s2;
	int m = -1, n = -1;
	Getstring(s1, m);
	Getstring(s2, n);
	if (m == -1 || n == -1) {
		return(s1 + s2);
	}
	else {
		m += n;
		char str[7];
		int i = 0;
		Myitoa(m, str, i);
		str[i] = '\0';
		return (string)str;
	}
}


void Getstring(string& s, int& m) {
	getString(s);
	unsigned int i = 0;
	for (m = 0; i < s.length(); i++) {
		if ( s.at(i) >= '0' && s.at(i) <= '9') {
			m = m * 10 + s.at(i) - '0';
		}
		else
			break;
	}
	if (i != s.length()  || m>99999) {
		m = -1;
	}
}
string Mycopy() {
	int n, x, l;
	getInt(n);
	getInt(x);
	getInt(l);
	return(str[n].substr(x, l));
}
string Myreset() {
	string s;
	int n;
	getString(s);
	getInt(n);
	return (str[n].assign(s));

}
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> str[i];
	}
	string instruct;
	while (cin >> instruct) {
		if (instruct == "over")
			break;
		switch (instruct.at(1)) {
		case('n'):
			MyInsert(); break;
		case ('e'):
			Myreset(); break;
		case('r'):if (instruct == "print") {
			int n;
			cin >> n;
			cout << str[n] << endl;
		}
				 else {
			for (int i = 1; i <= N; i++) {
				cout << str[i] << endl;
			}
		}
		default:
			;
		}

	}




	return 0;
}

描述

为了迎接08年的奥运会，让大家更加了解各种格斗运动，facer新开了一家热血格斗场。格斗场实行会员制，但是新来的会员不需要交入会费，而只要同一名老会员打一场表演赛，证明自己的实力。

我们假设格斗的实力可以用一个正整数表示，成为实力值。另外，每个人都有一个唯一的id，也是一个正整数。为了使得比赛更好看，每一个新队员都会选择与他实力最为接近的人比赛，即比赛双方的实力值之差的绝对值越小越好，如果有两个人的实力值与他差别相同，则他会选择比他弱的那个（显然，虐人必被虐好）。

不幸的是，Facer一不小心把比赛记录弄丢了，但是他还保留着会员的注册记录。现在请你帮facer恢复比赛纪录，按照时间顺序依次输出每场比赛双方的id。


输入

第一行一个数n(0 < n <=100000)，表示格斗场新来的会员数（不包括facer）。以后n行每一行两个数，按照入会的时间给出会员的id和实力值。一开始，facer就算是会员，id为1，实力值1000000000。输入保证两人的实力值不同。


输出

N行，每行两个数，为每场比赛双方的id，新手的id写在前面。

#include <iostream>
#include <string>
#include<map>
using namespace std;

int main() {
	int newer;
	cin >> newer;
	typedef map<int, int> mem;

	mem huiyuan;
	mem::iterator myself;
	mem::iterator duishou_1;
	mem::iterator duishou_2;
	mem::iterator result;
	huiyuan.insert(mem::value_type(1000000000,1));
	for (; newer > 0; newer--) {
		int new_id, new_power,ind;
		cin >> new_id >> new_power;
		myself = huiyuan.insert(make_pair(new_power, new_id)).first;
		duishou_1 = myself; duishou_2 = myself; result = myself;
		if (++result == huiyuan.end()) {
			result = duishou_1--;
		}
		else if (--result == huiyuan.begin()) {
			result++;
		}
		else if (result != huiyuan.begin() && result != huiyuan.end()) {
			--duishou_1; ++duishou_2;
			if (abs(duishou_1->first - myself->first) < abs(duishou_2->first - myself->first))
				result = duishou_1;
			else if (abs(duishou_1->first - myself->first) > abs(duishou_2->first - myself->first)) { result = duishou_2; }
			if (abs(duishou_1->first - myself->first) == abs(duishou_2->first - myself->first))
				result = duishou_1;
		}
		cout << new_id << " " << result->second << endl;
		
	}


	return 0;
}
