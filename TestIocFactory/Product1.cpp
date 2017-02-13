#include "IProduct.h"
#include "IFactory.h"

class Product1: public IProduct
{
	void Do()
	{
		cout << "Product1 Do" << endl;
	}
};

REGISTER_PRODUCT(Product1);
