#pragma once
/**
 * Author: Lauren Abrishami
 * Date: 7/7/20
 * Purpose: header for MyForm.cpp
 */
namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ infix_expression;
	private: System::Windows::Forms::TextBox^ result_text;
	private: System::Windows::Forms::Button^ evaluate_button;
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
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(300,300);
			this->Text = L"MyForm";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label1->Text = "Enter Infix Expression:";
			this->label1->Location = System::Drawing::Point(24, 41);
			this->label1->Size = System::Drawing::Size(109, 20);
			
			
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label2->Text = "Result:";
			this->label2->Location = System::Drawing::Point(24, 70);
			this->label2->Size = System::Drawing::Size(102, 20);
			
			this->infix_expression = (gcnew System::Windows::Forms::TextBox());
			this->infix_expression->Location = System::Drawing::Point(139, 43);
			this->infix_expression->Size = System::Drawing::Size(300, 20);

			this->result_text = (gcnew System::Windows::Forms::TextBox());
			this->result_text->Location = System::Drawing::Point(139, 70);
			this->result_text->Size = System::Drawing::Size(300, 20);

			this->evaluate_button= (gcnew System::Windows::Forms::Button());
			this->evaluate_button->Click += gcnew System::EventHandler(this, &MyForm::evaluate_button_Click);
			this->evaluate_button->Location = System::Drawing::Point(206, 116);
			this->evaluate_button->Size = System::Drawing::Size(75, 23);
			this->evaluate_button->Text = "Evaluate";

			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(523, 262);
			this->Controls->Add(this->evaluate_button);
			this->Controls->Add(this->infix_expression);
			this->Controls->Add(this->result_text);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private:


		System::Void evaluate_button_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
