#include "MyForm.h"
#include "InfixEvaluator.h"
#include <msclr\marshal_cppstd.h>

/**
 * Author: Lauren Abrishami
 * Date: 7/7/20
 * Purpose: Creates a GUI for evaluating infix expressions.
 */

using namespace std;
using namespace Project2;
using namespace System::Windows::Forms;



void MyForm::evaluate_button_Click(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;
	try {
		String^ result;
		string user_input = context.marshal_as<std::string>(infix_expression->Text);
		InfixEvaluator eval = InfixEvaluator();
		result = gcnew String(eval.evaluate_infix(user_input).ToString());
		result_text->Clear();
		result_text->AppendText(result);
		result_text->Refresh();
	}
	catch (int ex) {
		printf("bad input. Do not include any input besides numbers, operands or parenthesis.\n");
		printf("spaces are not allowed.\n");
		result_text->Clear();
	}
	
}

int main()
{

	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Project2::MyForm form;
	Application::Run(% form);

	return 0;
};

