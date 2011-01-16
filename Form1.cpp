#include "stdafx.h"
#include "Form1.h"
#include "Factory.h"
#ifdef _DEBUG
#include <crtdbg.h>
#endif

namespace LeakTest {
	System::Void Form1::CrtSetDbgFlag()
	{
#ifdef _DEBUG
		int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
		tmpFlag |= _CRTDBG_LEAK_CHECK_DF;
		_CrtSetDbgFlag(tmpFlag);
#endif
	}

	System::Void Form1::CreateProduct()
	{
		product = CFactory::createProduct();
	}

	System::Void Form1::DeleteProduct()
	{
		CFactory::deleteProduct(product);
	}

	System::Void Form1::allocate(AllocationType type)
	{
		int size, count;
		try
		{
			size= int::Parse(this->sizeInput->Text);
		}
		catch (Exception^)
		{
			MessageBox::Show("Invalid size");
			return;
		}
		try
		{
			count = int::Parse(this->countInput->Text);
		}
		catch (Exception^)
		{
			MessageBox::Show("Invalid count");
			return;
		}
		bool referred = this->haveReference->Checked;
		product->Create(type, size, count, referred);
	}

	System::Void Form1::doVirtualAlloc_Click(System::Object^ /*sender*/, System::EventArgs^ /*e*/)
	{
		allocate(AllocationType_VirtualAlloc);
	}

	System::Void Form1::doMalloc_Click(System::Object^ /*sender*/, System::EventArgs^ /*e*/)
	{
		allocate(AllocationType_Malloc);
	}

	System::Void Form1::doNew_Click(System::Object^ /*sender*/, System::EventArgs^ /*e*/)
	{
		allocate(AllocationType_New);
	}
}