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
			StreamWriter^ f = gcnew StreamWriter("save.txt", false);
			f->WriteLine(this->textBoxname->Text);
			if (this->checkBoxman->Checked == true) {
				f->WriteLine("�");
			}
			else {
				f->WriteLine("�");
			}
			f->WriteLine(this->comboBoxage->Text);
			f->WriteLine(1000); //balance
			f->WriteLine(this->numericUpDownweight->Text);
			f->WriteLine(this->numericUpDownheight->Text);
			f->WriteLine(100); //healthstatus
			f->WriteLine(0); //infinityhealth
			f->WriteLine("�����������");
			f->WriteLine(1500); //payment
			f->WriteLine("�����");
			f->WriteLine("�����");
			f->WriteLine("�����"); 
			f->WriteLine(100); //������ ������
			f->WriteLine(0); //autosewup
			f->WriteLine("�����"); //
			f->WriteLine("�����");
			f->WriteLine(0); //�������
			f->WriteLine(100); //satietystatus
			f->WriteLine(0); //autoeating
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
