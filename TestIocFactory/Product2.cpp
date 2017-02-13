#include "IFactory.h"
#include "IProduct.h"

class Product2: public IProduct
{
	void Do()
	{
		cout << "Product2 Do" << endl;
	}
};

REGISTER_PRODUCT(Product2);
