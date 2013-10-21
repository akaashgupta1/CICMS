#pragma once
#include "stdafx.h"
#include<Windows.h>
#using<System.dll>
#using <mscorlib.dll>


using namespace System;
using namespace System;
using namespace System::Diagnostics;
using namespace System::ComponentModel;

namespace test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	public: System::Windows::Forms::PictureBox^  View;
	private: System::Windows::Forms::Button^  button3;
	public: 
	private: 


	protected: 


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->View = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->View))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(24, 144);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(170, 37);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Launch CICMS";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(24, 231);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(170, 38);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Quit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// View
			// 
			this->View->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"View.BackgroundImage")));
			this->View->ErrorImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"View.ErrorImage")));
			this->View->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"View.InitialImage")));
			this->View->Location = System::Drawing::Point(12, 35);
			this->View->Name = L"View";
			this->View->Size = System::Drawing::Size(215, 103);
			this->View->TabIndex = 2;
			this->View->TabStop = false;
			this->View->UseWaitCursor = true;
			this->View->WaitOnLoad = true;
			this->View->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(24, 188);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(170, 37);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Visit SOC Website";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(236, 293);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->View);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"CICMS Launcher ";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->View))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 system("\"CICMS.exe\"");
			 }
	private: System::Void Loading_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {exit(0);
			 }
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {Process::Start("http://www.comp.nus.edu.sg");

		 }
};
}

