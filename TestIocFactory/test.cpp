#include "IFactory.h"
#include "IProduct.h"

class Test1
{
public:
	void Test()
	{
		cout << "Test1" << endl;

		IFactory::Init();

		IProduct* product1 = IFactory::Create("Product1");
		if (product1 != NULL)
		{
			product1->Do();
		}

		IProduct* product2 = IFactory::Create("Product2");
		if (product2 != NULL)
		{
			product2->Do();
		}

		char end = getchar();
	}
};

int main()
{
	Test1* test1 = new Test1();
	test1->Test();
}
