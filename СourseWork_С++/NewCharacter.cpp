#include "NewCharacter.h"
using System::Char;

//����� ���� (�) �� ������
System::Void �ourseWork�::NewCharacter::checkBoxman_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->checkBoxman->Checked == true)
		this->checkBoxwoman->Checked = false;
}

//����� ���� (�) �� ������
System::Void �ourseWork�::NewCharacter::checkBoxwoman_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->checkBoxwoman->Checked == true)
		this->checkBoxman->Checked = false;
}

//������������ ����� ���������� �� ������
System::Void �ourseWork�::NewCharacter::createbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->textBoxname->Text == "" || (this->checkBoxman->Checked == false && this->checkBoxwoman->Checked == false) || this->comboBoxage->Text == "" || this->numericUpDownheight->Text == "" || this->numericUpDownweight->Text == "") {
		MessageBox::Show("�� ��� ���� ���������!", "������!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else {
		try
		{
			StreamWriter^ f = gcnew StreamWriter("save.save", false);
			//
			//� ����� sava.save ��������� �������� ���������� �� ���������
			//
			f->WriteLine(this->textBoxname->Text); //���
			//���
			if (this->checkBoxman->Checked == true) {
				f->WriteLine("�");
			}
			else {
				f->WriteLine("�");
			}
			f->WriteLine(this->comboBoxage->Text); //�������
			f->WriteLine(100); //Balance
			f->WriteLine(this->numericUpDownweight->Text); //���
			f->WriteLine(this->numericUpDownheight->Text); //����
			f->WriteLine(100); //HealthStatus
			f->WriteLine(0); //InfinityHealth
			f->WriteLine("������� ��������"); //������������ ������
			f->WriteLine(10); //Payment
			f->WriteLine("�����"); //���� ������
			f->WriteLine("������"); //�����
			f->WriteLine("���������"); //�����
			f->WriteLine(100); //ClothesStatus
			f->WriteLine(0); //AutoSewUp
			f->WriteLine("�����"); //������������
			f->WriteLine("�����"); //������������ ��������
			f->WriteLine(0); //Level
			f->WriteLine(100); //SatietyStatus
			f->WriteLine(0); //AutoEating
			f->WriteLine(1); //Day
			f->Close();
			MessageBox::Show("�������� ������!", "������!", MessageBoxButtons::OK, MessageBoxIcon::None);
			this->Close();
		}
		catch (FileNotFoundException^)
		{
			MessageBox::Show("������ ��������", "��!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

//������� � ����� �������� ���� ��� �������� ������ �����
System::Void �ourseWork�::NewCharacter::NewCharacter_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	this->Owner->WindowState = FormWindowState::Normal;
	this->Owner->ShowInTaskbar = true;
}

//������ �� ���� � ��������� ���� ����� ���������
System::Void �ourseWork�::NewCharacter::textBoxname_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	Char ch = e->KeyChar;
	if (ch.IsLetter(ch) || ch.IsControl(ch)) {
		return;
	}
	else {
		e->Handled = true;
	}
}
