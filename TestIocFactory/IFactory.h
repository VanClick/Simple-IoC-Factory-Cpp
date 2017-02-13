#pragma once
#include <iostream>
#include <map>
#include <string>
using namespace std;

class IProduct;

class IFactory
{
public:
	IFactory(string name);
	static void Init();
	static IProduct* Create(string name);
protected:
	virtual IProduct* Create() = 0;
private:
	string name;
	static IFactory* root;
	IFactory* next;
	static map<string, IFactory*> factoryMap;
};

#define REGISTER_PRODUCT(product) \
	class product##Factory : IFactory\
	{\
	public:\
		product##Factory(string name):IFactory(name) {}\
		virtual IProduct* Create()\
		{\
			return new product();\
		}\
	};\
	product##Factory factory(#product);
