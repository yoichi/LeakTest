#include "stdafx.h"
#include "Form1.h"
#include "Factory.h"
#ifdef _DEBUG
#include <crtdbg.h>
#endif

namespace LeakTest {
	ref class ManagedObject
	{
	private:
		array<char> ^data_;
	public:
		ManagedObject(int size)
		{
			data_ = gcnew array<char>(size);
			Array::Clear(data_, 0, size);
		}
	};

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
		gcobj = gcnew System::Collections::Generic::List<System::Object^>();
		product = CFactory::createProduct();
	}

	System::Void Form1::DeleteProduct()
	{
		CFactory::deleteProduct(product);
	}

	bool Form1::GetParameter(int &size, int &count, bool &referred)
	{
		try
		{
			size= int::Parse(this->sizeInput->Text);
			if (size <= 0)
			{
				MessageBox::Show("Zero or negative size");
				return false;
			}
		}
		catch (Exception^)
		{
			MessageBox::Show("Invalid size");
			return false;
		}
		try
		{
			count = int::Parse(this->countInput->Text);
			if (count <= 0)
			{
				MessageBox::Show("Zero or negative count");
				return false;
			}
		}
		catch (Exception^)
		{
			MessageBox::Show("Invalid count");
			return false;
		}
		referred = this->haveReference->Checked;
		return true;
	}

	System::Void Form1::allocate(AllocationType type)
	{
		int size, count;
		bool referred;
		if (GetParameter(size, count, referred))
		{
			product->Create(type, size, count, referred);
		}
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

	System::Void Form1::doGCNew_Click(System::Object^ /*sender*/, System::EventArgs^ /*e*/)
	{
		int size, count;
		bool referred;
		if (GetParameter(size, count, referred))
		{
			for (int i = 0; i < count; i++)
			{
				ManagedObject ^obj = gcnew ManagedObject(size);
				if (referred)
				{
					gcobj->Add(obj);
				}
			}
		}
	}
}