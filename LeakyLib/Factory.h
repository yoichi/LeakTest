#pragma once

#include "IProduct.h"

class CFactory
{
public:
	static IProduct * createProduct();
	static void deleteProduct(IProduct *);
};