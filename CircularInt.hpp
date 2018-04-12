


#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;


struct CircularInt{


	int min;
	int max;
	int now;

	friend CircularInt operator-(int num,const CircularInt & h);
	// constructor getting two numbers that will be the range

	CircularInt(int a,int b){
		if(a>b){
			max=a;
			min=b;
		}
		else{
			min=a;
			max=b;
		}
		now=min;
	}

	//copy constructor

	CircularInt(const CircularInt& h){
		min=h.min;
		max=h.max;
		now=h.now;
	}

	//overload operator + by adding another class object

	CircularInt operator+(const CircularInt& h) {
		CircularInt hour{min,max};
		hour.now=now+h.now;
		while(hour.now>max){
			hour.now=hour.now-max;
		}
		return hour;
	}

	//overload operator + by adding number

	CircularInt operator+(int num) {
		CircularInt hour{min,max};
		hour.now=now+num;
		while(hour.now>max){
			hour.now=hour.now-max;
		}
		return hour;
	}

	//overload operator - by decreasing number

	CircularInt operator-(int num) {
		CircularInt hour{min,max};
		hour.now=num-now;
		while(hour.now<min){
			hour.now=hour.now+max;
		}
		return hour;
	}

	//overload operator - by decreasing max range number

	CircularInt operator-() {
		CircularInt hour{min,max};
		hour.now=max-now;
		while(hour.now<min){
			hour.now=hour.now+max;
		}
		return hour;
	}


	//overload operator += by adding number and return the current class object

	CircularInt& operator+=(int num) {
		now=now+num;
		while(now>max){
			now=now-max;
		}
		return *this;
	}

	CircularInt operator--(int){
		CircularInt temp(*this);
		operator--();
		return temp;
	}
	CircularInt& operator--(){
		now--;
		while(now<min){
			now=now+max;
		}
		return *this;
	}

	CircularInt operator++(int){
		CircularInt temp(*this);
		operator++();
		return *this;
	}

	CircularInt& operator++(){
		now++;
		while(now>max){
			now=now-max;
		}
		return *this;
	}

	CircularInt operator*=(int num){
		now*=num;
		while(now>max){
			now-=max;
		}
		return *this;
	}


	string operator/(int num){
		string s;
		for(int i=min;i<=max;i++){
			int temp = i*num;
			while(temp > max){
				temp -= max;
			}
			if(temp == now){
				string tmp = to_string(i);
				s+=tmp+" ";
			}
		}

		if(s.length()==0){
			throw string("There is no number x in {1,12} such that x*"+to_string(num)+"=10");
			exit(1);
		}
		return s;
	}
};

CircularInt operator-(int num,const CircularInt & h) {
	CircularInt temp{h.min,h.max};
	temp.now=num-h.now;
	while(temp.now<temp.min){
		temp.now+=temp.max;
	}
	return temp;
		}
//overload operator << print class object number

std::ostream &operator<<(std::ostream &os, CircularInt const &m) {
	return os << m.now;
}



