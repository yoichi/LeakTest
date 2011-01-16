#pragma once

enum AllocationType
{
	AllocationType_VirtualAlloc,
	AllocationType_Malloc,
	AllocationType_New
};

class IProduct
{
public:
	virtual ~IProduct() {}

	virtual void Create(AllocationType type, int size, int count, bool referred) = 0;
};
