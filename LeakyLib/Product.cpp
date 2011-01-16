#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif
#include "Product.h"
#include <windows.h>

CProduct::~CProduct()
{
	for (std::vector<void*>::iterator it = container_[AllocationType_VirtualAlloc].begin(); it != container_[AllocationType_VirtualAlloc].end(); it++)
	{
		VirtualFree(*it, 0, MEM_RELEASE);
	}
	for (std::vector<void*>::iterator it = container_[AllocationType_Malloc].begin(); it != container_[AllocationType_Malloc].end(); it++)
	{
		free(*it);
	}
	for (std::vector<void*>::iterator it = container_[AllocationType_New].begin(); it != container_[AllocationType_New].end(); it++)
	{
		char *ptr = static_cast<char*>(*it);
		delete [] ptr;
	}
}

void CProduct::Create(AllocationType type, int size, int count, bool referred)
{
	switch (type) {
	case AllocationType_VirtualAlloc:
		for (int i = 0; i < count; i++)
		{
			void *ptr = VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE);
			memset(ptr, 0xed, size);
			if (referred)
			{
				container_[AllocationType_VirtualAlloc].push_back(ptr);
			}
		}
		break;
	case AllocationType_Malloc:
		for (int i = 0; i < count; i++)
		{
			void *ptr = malloc(size);
			memset(ptr, 0xee, size);
			if (referred)
			{
				container_[AllocationType_Malloc].push_back(ptr);
			}
		}
		break;
	case AllocationType_New:
		for (int i = 0; i < count; i++)
		{
			char *ptr = new char[size];
			memset(ptr, 0xef, size);
			if (referred)
			{
				container_[AllocationType_New].push_back(static_cast<void*>(ptr));
			}
		}
		break;
	default:
		// not reached
		return;
	}
}