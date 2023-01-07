#include "NewCharacter.h"

System::Void �ourseWork�::NewCharacter::checkBoxman_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->checkBoxman->Checked == true)
		this->checkBoxwoman->Checked = false;
}

System::Void �ourseWork�::NewCharacter::checkBoxwoman_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->checkBoxwoman->Checked == true)
		this->checkBoxman->Checked = false;
}

System::Void �ourseWork�::NewCharacter::createbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBoxname->Text == L"" || (this->checkBoxman->Checked == false && this->checkBoxwoman->Checked == false) || this->comboBoxage->Text == L"" || this->numericUpDownheight->Text == L"" || this->numericUpDownweight->Text == L"") {
		MessageBox::Show("�� ��� ���� ���������!", "������!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else {
		try
		{
			StreamWriter^ f = gcnew StreamWriter("save.save", false);
			f->WriteLine(this->textBoxname->Text);
			if (this->checkBoxman->Checked == true) {
				f->WriteLine("�");
			}
			else {
				f->WriteLine("�");
			}
			f->WriteLine(this->comboBoxage->Text);
			f->WriteLine(1000); //Balance
			f->WriteLine(this->numericUpDownweight->Text);
			f->WriteLine(this->numericUpDownheight->Text);
			f->WriteLine(100); //HealthStatus
			f->WriteLine(0); //InfinityHealth
			f->WriteLine("�����������");
			f->WriteLine(1500); //Payment
			f->WriteLine("�����");
			f->WriteLine("������");
			f->WriteLine("���������"); 
			f->WriteLine(100); //ClothesStatus
			f->WriteLine(0); //AutoSewUp
			f->WriteLine("�����"); 
			f->WriteLine("�����");
			f->WriteLine(0); //Level
			f->WriteLine(100); //SatietyStatus
			f->WriteLine(0); //AutoEating
			f->WriteLine(1); //Day
			f->Close();
			MessageBox::Show("�������� ������!", "������!", MessageBoxButtons::OK, MessageBoxIcon::None);
			this->Owner->WindowState = FormWindowState::Normal;
			this->Owner->ShowInTaskbar = true;
			this->Close();
		}
		catch (FileNotFoundException^)
		{
			MessageBox::Show("������ ��������", "��!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

System::Void �ourseWork�::NewCharacter::NewCharacter_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	this->Owner->WindowState = FormWindowState::Normal;
	this->Owner->ShowInTaskbar = true;
}
