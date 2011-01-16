#include "IProduct.h"
#include <vector>

class CProduct : public IProduct
{
private:
	std::vector<void*> container_[3];
public:
	~CProduct();
	virtual void Create(AllocationType type, int size, int count, bool referred);
};
