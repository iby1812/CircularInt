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
		CircularInt& operator-=(const int);
		CircularInt& operator*=(const int);
		CircularInt& operator/=(const int);
		CircularInt& operator*=(const CircularInt& h);

		CircularInt operator--(int);
		CircularInt& operator--();
		CircularInt operator++(int);
		CircularInt& operator++();
		
		CircularInt& operator=(const int);

		CircularInt& operator=(const CircularInt& h);
		
		vector<int> operator/(int num);



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

		friend CircularInt operator*=(const CircularInt& h, const int num);
		friend CircularInt operator*=(const int num, const CircularInt& h);
		friend CircularInt operator*=(const CircularInt& a, const CircularInt& b);

		friend CircularInt operator+(const CircularInt& h);
		friend CircularInt operator+(const CircularInt & h, const int num);
		friend CircularInt operator+(const int num,const CircularInt & h);
		friend CircularInt operator+(const CircularInt & a,const CircularInt & b);

		friend CircularInt operator+=(const CircularInt& h, const int num);
		friend CircularInt operator+=(const int num, const CircularInt& h);
		friend CircularInt operator+=(const CircularInt& a, const CircularInt& b);

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
	int i;
	os >> i;
	m.now = i;
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
	temp *= num;
	return temp;
}
inline CircularInt operator*(const int num, const CircularInt& h){
	return operator*(h , num);
}
inline CircularInt operator*(const CircularInt& a, const CircularInt& b){
	return operator*(a , b.now);
}

inline CircularInt operator/(const CircularInt & h, const int num){
	CircularInt temp(h);
	temp /= num;
	return temp;
}
inline CircularInt operator/(const int num,const CircularInt & h){
	return h / num;
}
inline CircularInt operator/(const CircularInt & a,const CircularInt & b){
	return a / b;
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

inline CircularInt operator*=(const CircularInt& h, const int num){
	CircularInt temp(h);
	temp.now *= num;
	return temp;
}
inline CircularInt operator*=(const int num, const CircularInt& h){
	return h *= num;
}
inline CircularInt operator*=(const CircularInt& a, const CircularInt& b){
	return a *= b.now;
}

inline CircularInt operator+=(const CircularInt& h, const int num){
	CircularInt temp(h);
	temp.now += num;
	return temp;
}
inline CircularInt operator+=(const int num, const CircularInt& h){
	return h += num;
}
inline CircularInt operator+=(const CircularInt& a, const CircularInt& b){
	return a += b.now;
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
