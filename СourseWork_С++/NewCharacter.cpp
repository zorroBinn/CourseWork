#include "NewCharacter.h"

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
	if (this->textBoxname->Text == L"" || (this->checkBoxman->Checked == false && this->checkBoxwoman->Checked == false) || this->comboBoxage->Text == L"" || this->numericUpDownheight->Text == L"" || this->numericUpDownweight->Text == L"") {
		MessageBox::Show("Íå âñå ïîëÿ çàïîëíåíû!", "Îøèáêà!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else {
		try
		{
			StreamWriter^ f = gcnew StreamWriter("save.txt", false);
			f->WriteLine(this->textBoxname->Text);
			if (this->checkBoxman->Checked == true) {
				f->WriteLine("Ì");
			}
			else {
				f->WriteLine("Æ");
			}
			f->WriteLine(this->comboBoxage->Text);
			f->WriteLine(1000);
			f->WriteLine(this->numericUpDownweight->Text);
			f->WriteLine(this->numericUpDownheight->Text);
			f->WriteLine("Áåçðàáîòíûé");
			f->WriteLine(1500);
			f->WriteLine("Ìàéêà");
			f->WriteLine("Òðóñû");
			f->WriteLine("Òàïêè");
			f->WriteLine("Ãàðàæ");
			f->WriteLine("Âåëèê");
			f->WriteLine(0);
			f->Close();
			MessageBox::Show("Ïåðñîíàæ ñîçäàí!", "Ãîòîâî!", MessageBoxButtons::OK, MessageBoxIcon::None);
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
