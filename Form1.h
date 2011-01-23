#pragma once

class IProduct;
enum AllocationType;

namespace LeakTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			CrtSetDbgFlag();
			CreateProduct();
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Form1()
		{
			DeleteProduct();
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  sizeLabel;
	private: System::Windows::Forms::Label^  countLabel;
	private: System::Windows::Forms::TextBox^  sizeInput;
	private: System::Windows::Forms::TextBox^  countInput;
	private: System::Windows::Forms::Button^  doVirtualAlloc;
	private: System::Windows::Forms::Button^  doMalloc;
	private: System::Windows::Forms::Button^  doNew;
	private: System::Windows::Forms::CheckBox^  haveReference;
	private: System::Windows::Forms::Button^  doGCNew;





	protected: 

	protected: 

	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->sizeLabel = (gcnew System::Windows::Forms::Label());
			this->countLabel = (gcnew System::Windows::Forms::Label());
			this->sizeInput = (gcnew System::Windows::Forms::TextBox());
			this->countInput = (gcnew System::Windows::Forms::TextBox());
			this->doVirtualAlloc = (gcnew System::Windows::Forms::Button());
			this->doMalloc = (gcnew System::Windows::Forms::Button());
			this->doNew = (gcnew System::Windows::Forms::Button());
			this->haveReference = (gcnew System::Windows::Forms::CheckBox());
			this->doGCNew = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// sizeLabel
			// 
			this->sizeLabel->AutoSize = true;
			this->sizeLabel->Location = System::Drawing::Point(19, 17);
			this->sizeLabel->Name = L"sizeLabel";
			this->sizeLabel->Size = System::Drawing::Size(25, 12);
			this->sizeLabel->TabIndex = 0;
			this->sizeLabel->Text = L"size";
			// 
			// countLabel
			// 
			this->countLabel->AutoSize = true;
			this->countLabel->Location = System::Drawing::Point(11, 50);
			this->countLabel->Name = L"countLabel";
			this->countLabel->Size = System::Drawing::Size(33, 12);
			this->countLabel->TabIndex = 1;
			this->countLabel->Text = L"count";
			// 
			// sizeInput
			// 
			this->sizeInput->Location = System::Drawing::Point(55, 14);
			this->sizeInput->Name = L"sizeInput";
			this->sizeInput->Size = System::Drawing::Size(100, 19);
			this->sizeInput->TabIndex = 2;
			// 
			// countInput
			// 
			this->countInput->Location = System::Drawing::Point(55, 47);
			this->countInput->Name = L"countInput";
			this->countInput->Size = System::Drawing::Size(100, 19);
			this->countInput->TabIndex = 3;
			// 
			// doVirtualAlloc
			// 
			this->doVirtualAlloc->Location = System::Drawing::Point(176, 9);
			this->doVirtualAlloc->Name = L"doVirtualAlloc";
			this->doVirtualAlloc->Size = System::Drawing::Size(75, 23);
			this->doVirtualAlloc->TabIndex = 4;
			this->doVirtualAlloc->Text = L"VirtualAlloc";
			this->doVirtualAlloc->UseVisualStyleBackColor = true;
			this->doVirtualAlloc->Click += gcnew System::EventHandler(this, &Form1::doVirtualAlloc_Click);
			// 
			// doMalloc
			// 
			this->doMalloc->Location = System::Drawing::Point(176, 38);
			this->doMalloc->Name = L"doMalloc";
			this->doMalloc->Size = System::Drawing::Size(75, 23);
			this->doMalloc->TabIndex = 5;
			this->doMalloc->Text = L"Malloc";
			this->doMalloc->UseVisualStyleBackColor = true;
			this->doMalloc->Click += gcnew System::EventHandler(this, &Form1::doMalloc_Click);
			// 
			// doNew
			// 
			this->doNew->Location = System::Drawing::Point(176, 67);
			this->doNew->Name = L"doNew";
			this->doNew->Size = System::Drawing::Size(75, 23);
			this->doNew->TabIndex = 6;
			this->doNew->Text = L"New";
			this->doNew->UseVisualStyleBackColor = true;
			this->doNew->Click += gcnew System::EventHandler(this, &Form1::doNew_Click);
			// 
			// haveReference
			// 
			this->haveReference->AutoSize = true;
			this->haveReference->Location = System::Drawing::Point(83, 74);
			this->haveReference->Name = L"haveReference";
			this->haveReference->Size = System::Drawing::Size(72, 16);
			this->haveReference->TabIndex = 7;
			this->haveReference->Text = L"reference";
			this->haveReference->UseVisualStyleBackColor = true;
			// 
			// doGCNew
			// 
			this->doGCNew->Location = System::Drawing::Point(176, 96);
			this->doGCNew->Name = L"doGCNew";
			this->doGCNew->Size = System::Drawing::Size(75, 23);
			this->doGCNew->TabIndex = 8;
			this->doGCNew->Text = L"GCNew";
			this->doGCNew->UseVisualStyleBackColor = true;
			this->doGCNew->Click += gcnew System::EventHandler(this, &Form1::doGCNew_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(263, 126);
			this->Controls->Add(this->doGCNew);
			this->Controls->Add(this->haveReference);
			this->Controls->Add(this->doNew);
			this->Controls->Add(this->doMalloc);
			this->Controls->Add(this->doVirtualAlloc);
			this->Controls->Add(this->countInput);
			this->Controls->Add(this->sizeInput);
			this->Controls->Add(this->countLabel);
			this->Controls->Add(this->sizeLabel);
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"LeakTest";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void Form1::CrtSetDbgFlag();
		IProduct *product;
		System::Collections::Generic::List<System::Object^> ^gcobj;
		System::Void CreateProduct();
		System::Void DeleteProduct();
		bool GetParameter(int &size, int &count, bool &referred);
		System::Void allocate(AllocationType type);
		System::Void doVirtualAlloc_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void doMalloc_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void doNew_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void doGCNew_Click(System::Object^ sender, System::EventArgs^ e);
};
}

