#include "NewCharacter.h"
using System::Char;

System::Void ÑourseWorkÑ::NewCharacter::checkBoxman_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->checkBoxman->Checked == true)
		this->checkBoxwoman->Checked = false;
}

System::Void ÑourseWorkÑ::NewCharacter::checkBoxwoman_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->checkBoxwoman->Checked == true)
		this->checkBoxman->Checked = false;
}

System::Void ÑourseWorkÑ::NewCharacter::createbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBoxname->Text == "" || (this->checkBoxman->Checked == false && this->checkBoxwoman->Checked == false) || this->comboBoxage->Text == "" || this->numericUpDownheight->Text == "" || this->numericUpDownweight->Text == "") {
		MessageBox::Show("Íå âñå ïîëÿ çàïîëíåíû!", "Îøèáêà!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else {
		try
		{
			StreamWriter^ f = gcnew StreamWriter("save.save", false);
			f->WriteLine(this->textBoxname->Text);
			if (this->checkBoxman->Checked == true) {
				f->WriteLine("Ì");
			}
			else {
				f->WriteLine("Æ");
			}
			f->WriteLine(this->comboBoxage->Text);
			f->WriteLine(100); //Balance
			f->WriteLine(this->numericUpDownweight->Text);
			f->WriteLine(this->numericUpDownheight->Text);
			f->WriteLine(100); //HealthStatus
			f->WriteLine(0); //InfinityHealth
			f->WriteLine("Ğàçäà÷à ëèñòîâîê");
			f->WriteLine(10); //Payment
			f->WriteLine("Êîôòà");
			f->WriteLine("Äæèíñû");
			f->WriteLine("Êğîññîâêè"); 
			f->WriteLine(100); //ClothesStatus
			f->WriteLine(0); //AutoSewUp
			f->WriteLine("Ãàğàæ"); 
			f->WriteLine("Âåëèê");
			f->WriteLine(0); //Level
			f->WriteLine(100); //SatietyStatus
			f->WriteLine(0); //AutoEating
			f->WriteLine(1); //Day
			f->Close();
			MessageBox::Show("Ïåğñîíàæ ñîçäàí!", "Ãîòîâî!", MessageBoxButtons::OK, MessageBoxIcon::None);
			this->Owner->WindowState = FormWindowState::Normal;
			this->Owner->ShowInTaskbar = true;
			this->Close();
		}
		catch (FileNotFoundException^)
		{
			MessageBox::Show("Îøèáêà ñîçäàíèÿ", "Îé!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

System::Void ÑourseWorkÑ::NewCharacter::NewCharacter_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	this->Owner->WindowState = FormWindowState::Normal;
	this->Owner->ShowInTaskbar = true;
}

System::Void ÑourseWorkÑ::NewCharacter::textBoxname_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	Char ch = e->KeyChar;
	if (ch.IsLetter(ch) || ch.IsControl(ch)) {
		return;
	}
	else {
		e->Handled = true;
	}
}
