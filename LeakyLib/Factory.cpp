#include "Factory.h"
#include "Product.h"

IProduct *CFactory::createProduct()
{
	return new CProduct;
}

void CFactory::deleteProduct(IProduct *product)
{
	delete product;
}