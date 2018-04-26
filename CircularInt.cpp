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


CircularInt& CircularInt::operator/=(const int num){
	now = now / num;
	while(now > max)
		{
			now-=max;
		}
		while(now < min)
		{
			now+=max;
		}
	return *this;
}
CircularInt& CircularInt::operator/=(const CircularInt& h){
	now = now / h.now;
	while(now > max)
		{
			now-=max;
		}
		while(now < min)
		{
			now+=max;
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

CircularInt& CircularInt::operator-=(const CircularInt& h){
	this->now = this->now - h.now;
	if(this->now < min)
	{
		this->now = this->now % max + max;
	}
	return *this;
}

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
	return temp;
}

CircularInt& CircularInt::operator++(){
	now++;
	if(now > max)
	{
		now =now % max;
	}
	return *this;
}

CircularInt& CircularInt::operator=(const int num){

	now = num;
	if(now > max)
	{
		now =now % max;
	}
	while(now<min){
		now+=max;
	}
	return *this;
}

CircularInt& CircularInt::operator=(const CircularInt& h){
	now = h.now;
	if(now > max)
	{
		now =now % max;
	}
	while(now<min){
		now+=max;
	}
	return *this;

}

CircularInt& CircularInt::operator*=(const int num){
	now*=num;

	while(now > max)
	{
		now-=max;
	}
	while(now < min)
	{
		now+=max;
	}

	return *this;
}
CircularInt& CircularInt::operator*=(const CircularInt& h){
	now*=h.now;

	while(now > max)
	{
		now-=max;
	}
	while(now < min)
	{
		now+=max;
	}

	return *this;
}
vector<int> CircularInt::operator/(const int num){


	vector<int> vec;
	for(int i = min; i <= max; i++)
	{
		int temp = i*num;
		if(temp > max)
		{
			temp = temp % max;
		}
		if(temp<min){
			while(temp<min){
				temp+=max;
			}
		}
		if(temp == now)
		{
			vec.push_back(i);
		}
	}
	if(vec.size() == 0)
	{
		throw string("There is no number x in {1 , 12} such that x*" + to_string(num)+"=10");
	}
	return vec;
}

vector<int> CircularInt::operator/(const CircularInt& h){

	vector<int> vec;
	for(int i = min; i <= max; i++)
	{
		int temp = i*h.now;
		if(temp > max)
		{
			temp = temp % max;
		}
		if(temp<min){
			while(temp<min){
				temp+=max;
			}
		}
		if(temp == now)
		{
			vec.push_back(i);
		}
	}
	if(vec.size() == 0)
	{
		throw string("There is no number x in {1 , 12} such that x*" + to_string(h.now)+"=+10");
	}
	return vec;
}


