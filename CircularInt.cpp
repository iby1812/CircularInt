#include <vector>
#include <set>
#include <iostream>
#include <string>
#include "CircularInt.hpp"

CircularInt::CircularInt(int a, int b)
{
	if(a > b)
	{
		this->max = a;
		this->min = b;
	}
	else
	{
		this->min = a;
		this->max = b;
	}
	this->now = this->min;
}

CircularInt::CircularInt(const CircularInt& h)
{
	this->min = h.min;
	this->max = h.max;
	this->now = h.now;
}




/*CircularInt CircularInt::operator+(const CircularInt& h)
	{
		CircularInt hour{min,max};
		hour.now = this->now + h.now;

		if(hour.now > max)
		{
			hour.now = hour.now % max;
		}
		return hour;
	}

	CircularInt CircularInt::operator+(int num) {
		CircularInt hour{min,max};
		hour.now=now+num;
		while(hour.now>max){
			hour.now=hour.now-max;
		}
		return hour;
	}*/
CircularInt& CircularInt::operator/=(const int num){
	this->now = this->now / num;
	if(this->now < min)
	{
		this->now = this->now % max + max;
	}
	return *this;
}

CircularInt& CircularInt::operator-=(const int num){
	this->now = this->now - num;
	if(this->now < min)
	{
		this->now = this->now % max + max;
	}
	return *this;
}

/*CircularInt CircularInt::operator-(int num) {
		CircularInt hour{min,max};
		hour.now=num-now;
		while(hour.now<min){
			hour.now=hour.now+max;
		}
		return hour;
	}*/

/*CircularInt CircularInt::operator-() {
		CircularInt hour{min,max};
		hour.now=max-now;
		while(hour.now<min){
			hour.now=hour.now+max;
		}
		return hour;
	}*/

CircularInt& CircularInt::operator+=(const int num) {
	this->now = this->now+num;
	if(this->now > max)
	{
		this->now = this->now % max;
	}
	return *this;
}
CircularInt& CircularInt::operator+=(const CircularInt& h) {
	this->now = this->now+h.now;
	if(this->now > max)
	{
		this->now = this->now % max;
	}
	return *this;
}
CircularInt CircularInt::operator--(int){
	CircularInt temp(*this);
	operator--();
	return temp;
}
CircularInt& CircularInt::operator--(){
	now--;
	while(now<min){
		now=now+max;
	}
	return *this;
}

CircularInt CircularInt::operator++(int){
	CircularInt temp(*this);
	operator++();
	return *this;
}

CircularInt& CircularInt::operator++(){
	this->now++;
	if(this->now > 12)
	{
		this->now = this->now % max;
	}
	return *this;
}

CircularInt& CircularInt::operator=(const int num){

	this->now = num;
	return *this;
}

CircularInt& CircularInt::operator=(const CircularInt& h){
	this->now = h.now;
	return *this;

}

CircularInt& CircularInt::operator*=(const int num){
	this->now*=num;

	if(this->now > max)
	{
		this->now = this->now % max;
	}
	else {
		while(this->now < min)
		{
			this->now+=max;
		}
	}
	return *this;
}
CircularInt& CircularInt::operator*=(const CircularInt& h){
	this->now*=h.now;

	if(this->now > max)
	{
		this->now = this->now % max;
	}
	else {
		while(this->now < min)
		{
			this->now+=max;
		}
	}
	return *this;
}
vector<int> CircularInt::operator/(int num){

	vector<int> vec;
	for(int i = min; i <= max; i++)
	{
		int temp = i*num;
		if(temp > max)
		{
			temp = temp % max;
		}
		if(temp == now)
		{
			vec.push_back(i);
		}
	}
	if(vec.size() == 0)
	{
		throw string("There is no number x in {1,12} such that x*"+to_string(num)+"=10");
	}
	return vec;
}

/*CircularInt operator-(int num,const CircularInt & h) {
	CircularInt temp{h.min,h.max};
	temp.now=num-h.now;

	if(temp.now < temp.min)
	{
		temp.now = temp.now % temp.max + temp.max;
	}
	return temp;
	}*/

