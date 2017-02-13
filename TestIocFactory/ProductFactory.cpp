#include "IProduct.h"
#include "IFactory.h"

IFactory* IFactory::root = NULL;
map<string, IFactory*> IFactory::factoryMap;

IFactory::IFactory(string name)
{
	this->next = root;
	root = this;
	this->name = name;
}

void IFactory::Init()
{
	IFactory* curr = root;
	while (curr != NULL)
	{
		factoryMap[curr->name] = curr;
		curr = curr->next;
	}
}

IProduct* IFactory::Create(string name)
{
	IFactory* factory = factoryMap[name];
	if (factory != NULL)
	{
		return factory->Create();
	}
	return NULL;
}
