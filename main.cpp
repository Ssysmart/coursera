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

