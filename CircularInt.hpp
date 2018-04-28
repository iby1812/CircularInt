#pragma once
#include <vector>
#include <set>
#include <iostream>
#include <string>

using namespace std;

class CircularInt{
private:
	int min, max;
	int now;

public:
	CircularInt(int a, int b);
	CircularInt(const CircularInt& h);


	CircularInt& operator+=(const int);
	CircularInt& operator+=(const CircularInt& h);

	CircularInt& operator-=(const int);
	CircularInt& operator-=(const CircularInt& h);

	CircularInt& operator*=(const int);
	CircularInt& operator*=(const CircularInt& h);

	CircularInt& operator/=(const int);
	CircularInt& operator/=(const CircularInt& h);

	CircularInt operator--(int);
	CircularInt& operator--();

	CircularInt operator++(int);
	CircularInt& operator++();

	CircularInt& operator=(const int);
	CircularInt& operator=(const CircularInt& h);

	friend CircularInt operator/(const CircularInt& h, int num);
	friend CircularInt operator/(int num, const CircularInt& h);
	friend CircularInt operator/(const CircularInt& a, const CircularInt& b);

	friend int operator>=(const CircularInt& h, int num);
	friend int operator>=(int num, const CircularInt& h);
	friend int operator>=(const CircularInt& a, const CircularInt& b);

	friend int operator>(const CircularInt& h, int num);
	friend int operator>(int num, const CircularInt& h);
	friend int operator>(const CircularInt& a, const CircularInt& b);

	friend int operator<=(const CircularInt& h, int num);
	friend int operator<=(int num, const CircularInt& h);
	friend int operator<=(const CircularInt& a, const CircularInt& b);

	friend int operator<(const CircularInt& h, int num);
	friend int operator<(int num, const CircularInt& h);
	friend int operator<(const CircularInt& a, const CircularInt& b);

	friend int operator==(const CircularInt& h, int num);
	friend int operator==(int num, const CircularInt& h);
	friend int operator==(const CircularInt& a, const CircularInt& b);

	friend int operator!=(const CircularInt& h, int num);
	friend int operator!=(int num, const CircularInt& h);
	friend int operator!=(const CircularInt& a, const CircularInt& b);

	friend CircularInt operator-(const CircularInt& h);
	friend CircularInt operator-(const CircularInt& h, const int num);
	friend CircularInt operator-(const int num, const CircularInt& h);
	friend CircularInt operator-(const CircularInt& a, const CircularInt& b);

	friend CircularInt operator-=(const CircularInt& h, const int num);
	friend CircularInt operator-=(const int num, const CircularInt& h);
	friend CircularInt operator-=(const CircularInt& a, const CircularInt& b);

	friend CircularInt operator*(const CircularInt& h, const int num);
	friend CircularInt operator*(const int num, const CircularInt& h);
	friend CircularInt operator*(const CircularInt& a, const CircularInt& b);

	friend CircularInt operator+(const CircularInt& h);
	friend CircularInt operator+(const CircularInt & h, const int num);
	friend CircularInt operator+(const int num,const CircularInt & h);
	friend CircularInt operator+(const CircularInt & a,const CircularInt & b);

	friend CircularInt operator-(const CircularInt & h, const int num);
	friend CircularInt operator-(const int num,const CircularInt & h);
	friend CircularInt operator-(const CircularInt & a,const CircularInt & b);

	friend ostream& operator<<(ostream& os, const CircularInt &m);
	friend istream& operator>>(istream& os, CircularInt &m);
};

inline ostream& operator<<(ostream& os, const CircularInt &m) {
	os << m.now;
	return os;
}

inline istream& operator>>(istream& os,  CircularInt &m) {
	int n;
	os >> n;
	m.now = n;
	if(m.now>m.max){
		m.now=m.now%m.max;
	}
	while(m.now<m.min){
		m.now+=m.max;
	}
	return os;
}

inline ostream &operator<<(ostream &os, vector<int> vec) {
	string result = "";
	for(unsigned int i = 0; i < vec.size(); i++ )
	{
		result = result + to_string(vec[i]) + " ";
	}
	return os << result;
}

inline int operator==(int num, const CircularInt& h){
	if(num == h.now) return 1;
	else return 0;
}

inline int operator==(const CircularInt& a, const CircularInt& b){
	if(a.now == b.now) return 1;
	else return 0;
}

inline int operator==(const CircularInt& a, int num){
	if(a.now == num) return 1;
	else return 0;
}

inline int operator!=(int num, const CircularInt& h){
	if(num != h.now) return 1;
	else return 0;
}

inline int operator!=(const CircularInt& a, const CircularInt& b){
	if(a.now != b.now) return 1;
	else return 0;
}

inline int operator!=(const CircularInt& a, int num){
	if(a.now != num) return 1;
	else return 0;
}

inline CircularInt operator-(const CircularInt& h){
	CircularInt temp(h);
	temp.now = temp.max - temp.now;
	return temp;
}

inline CircularInt operator-(const CircularInt& h, const int num){
	CircularInt temp(h);
	temp -= num;
	return temp;
}

inline CircularInt operator-(const int num, const CircularInt& h){
	return -(h - num);
}
inline CircularInt operator-(const CircularInt& a, const CircularInt& b){
	return a - b.now;
}

inline CircularInt operator+(const int num, const CircularInt& h){
	return h + num;
}

inline CircularInt operator+(const CircularInt & h, const int num){
	CircularInt temp(h);
	temp += num;
	return temp;
}

inline CircularInt operator+(const CircularInt & a,const CircularInt & b){
	return a + b.now;
}

inline CircularInt operator*(const CircularInt& h, const int num){
	CircularInt temp(h);
	temp.now = temp.now*num;
	while(temp.now > temp.max)
		{
			temp.now-=temp.max;
		}
		while(temp.now < temp.min)
		{
			temp.now+=temp.max;
		}
	return temp;
}
inline CircularInt operator*(const int num, const CircularInt& h){
	CircularInt temp(h);
		temp.now = temp.now*num;
		while(temp.now > temp.max)
			{
				temp.now-=temp.max;
			}
			while(temp.now < temp.min)
			{
				temp.now+=temp.max;
			}
		return temp;
}
inline CircularInt operator*(const CircularInt& a, const CircularInt& b){
	CircularInt temp(a);
		temp.now = temp.now*b.now;
		while(temp.now > temp.max)
			{
				temp.now-=temp.max;
			}
			while(temp.now < temp.min)
			{
				temp.now+=temp.max;
			}
		return temp;
}
inline int operator>(const CircularInt& h, int num){
	if(h.now > num) return 1;
	else return 0;
}
inline int operator>(int num, const CircularInt& h){
	if(num > h.now) return 1;
	else return 0;
}
inline int operator>(const CircularInt& a, const CircularInt& b){
	if(a.now > b.now) return 1;
	else return 0;
}

inline int operator<(const CircularInt& h, int num){
	if(h.now < num) return 1;
	else return 0;
}
inline int operator<(int num, const CircularInt& h){
	if(num < h.now) return 1;
	else return 0;
}
inline int operator<(const CircularInt& a, const CircularInt& b){
	if(a.now < b.now) return 1;
	else return 0;
}

inline int operator<=(const CircularInt& h, int num){
	if(h.now <= num) return 1;
	else return 0;
}
inline int operator<=(int num, const CircularInt& h){
	if(num <= h.now) return 1;
	else return 0;
}
inline int operator<=(const CircularInt& a, const CircularInt& b){
	if(a.now <= b.now) return 1;
	else return 0;
}

inline int operator>=(const CircularInt& h, int num){
	if(h.now >= num) return 1;
	else return 0;
}
inline int operator>=(int num, const CircularInt& h){
	if(num >= h.now) return 1;
	else return 0;
}
inline int operator>=(const CircularInt& a, const CircularInt& b){
	if(a.now >= b.now) return 1;
	else return 0;
}

inline CircularInt operator-=(const CircularInt& h, const int num){
	CircularInt temp(h);
	temp.now -= num;
	return temp;
}
inline CircularInt operator-=(const int num, const CircularInt& h){
	return h -= num;
}
inline CircularInt operator-=(const CircularInt& a, const CircularInt& b){
	return a -= b.now;
}

inline CircularInt operator/(const CircularInt& h, int num){


	CircularInt a(h);
	int count=0;
	for(int i = a.min; i <= a.max; i++)
	{
		int temp = i*num;
		while(temp>a.max){
			temp-=a.max;
		}

		while(temp<a.min){
			temp+=a.max;
		}

		if(temp == h.now)
		{
			count++;
			a.now=i;
		}
	}
	if(count == 0)
	{
		throw string("There is no number x in {"+to_string(a.min)+ ","+ to_string(a.max)+"} such that x*" + to_string(num)+"="+to_string(h.now));
	}
	return a;
}

inline CircularInt operator/(int num,const CircularInt& h){

	CircularInt a(h);
	int count=0;
	for(int i = a.min; i <= a.max; i++)
	{
		int temp = i*h.now;
		while(temp>a.max){
			temp-=a.max;
		}

		while(temp<a.min){
			temp+=a.max;
		}

		if(temp == num)
		{
			count++;
			a.now=i;
		}
	}
	if(count == 0)
	{
		throw string("There is no number x in {"+to_string(a.min)+ ","+ to_string(a.max)+"} such that x*" + to_string(num)+"="+to_string(h.now));
	}
	return a;
}
inline CircularInt operator/(const CircularInt& h, const CircularInt& b){

	CircularInt a(h);
	int count=0;
	for(int i = a.min; i <= a.max; i++)
	{
		int temp = i*b.now;
		while(temp>a.max){
			temp-=a.max;
		}

		while(temp<a.min){
			temp+=a.max;
		}

		if(temp == h.now)
		{
			count++;
			a.now=i;
		}
	}
	if(count == 0)
	{
		throw string("There is no number x in {"+to_string(a.min)+ ","+ to_string(a.max)+"} such that x*" + to_string(b.now)+"="+to_string(h.now));
	}
	return a;
}


