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

