#include "NewCharacter.h"

System::Void СourseWorkС::NewCharacter::checkBoxman_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->checkBoxman->Checked == true)
		this->checkBoxwoman->Checked = false;
}

System::Void СourseWorkС::NewCharacter::checkBoxwoman_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->checkBoxwoman->Checked == true)
		this->checkBoxman->Checked = false;
}

System::Void СourseWorkС::NewCharacter::createbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBoxname->Text == L"" || (this->checkBoxman->Checked == false && this->checkBoxwoman->Checked == false) || this->comboBoxage->Text == L"" || this->numericUpDownheight->Text == L"" || this->numericUpDownweight->Text == L"") {
		MessageBox::Show("Не все поля заполнены!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else {
		try
		{
			StreamWriter^ f = gcnew StreamWriter("save.txt", false);
			f->WriteLine(this->textBoxname->Text);
			if (this->checkBoxman->Checked == true) {
				f->WriteLine("М");
			}
			else {
				f->WriteLine("Ж");
			}
			f->WriteLine(this->comboBoxage->Text);
			f->WriteLine(1000); //balance
			f->WriteLine(this->numericUpDownweight->Text);
			f->WriteLine(this->numericUpDownheight->Text);
			f->WriteLine(100); //healthstatus
			f->WriteLine(0); //infinityhealth
			f->WriteLine("Безработный");
			f->WriteLine(1500); //payment
			f->WriteLine("Майка");
			f->WriteLine("Трусы");
			f->WriteLine("Тапки"); 
			f->WriteLine(100); //Статус одежды
			f->WriteLine(0); //autosewup
			f->WriteLine("Гараж"); //
			f->WriteLine("Велик");
			f->WriteLine(0); //уровень
			f->WriteLine(100); //satietystatus
			f->WriteLine(0); //autoeating
			f->Close();
			MessageBox::Show("Персонаж создан!", "Готово!", MessageBoxButtons::OK, MessageBoxIcon::None);
			this->Owner->WindowState = FormWindowState::Normal;
			this->Owner->ShowInTaskbar = true;
			this->Close();
		}
		catch (FileNotFoundException^)
		{
			MessageBox::Show("Ошибка создания", "Ой!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

System::Void СourseWorkС::NewCharacter::NewCharacter_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	this->Owner->WindowState = FormWindowState::Normal;
	this->Owner->ShowInTaskbar = true;
}
