#include "Game.h"

System::Void �ourseWork�::Game::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxworker->Visible = false;
	this->groupBoxclothes->Visible = false;
	this->groupBoxmd->Visible = false;
	this->groupBoxrealty->Visible = false;
	this->groupBoxhuman->Visible = true;
	this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
}

System::Void �ourseWork�::Game::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxhuman->Visible = false;
	this->groupBoxworker->Visible = false;
	this->groupBoxclothes->Visible = false;
	this->groupBoxrealty->Visible = false;
	this->groupBoxmd->Visible = true;
}

System::Void �ourseWork�::Game::���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxhuman->Visible = false;
	this->groupBoxworker->Visible = false;
	this->groupBoxmd->Visible = false;
	this->groupBoxclothes->Visible = false;
	this->groupBoxrealty->Visible = true;
	this->realtyhouse->Text = realty->GetHousing();
	this->realtycar->Text = realty->GetVehicle();
}

System::Void �ourseWork�::Game::������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxhuman->Visible = false;
	this->groupBoxclothes->Visible = false;
	this->groupBoxmd->Visible = false;
	this->groupBoxrealty->Visible = false;
	this->groupBoxworker->Visible = true;
	this->workername->Text = worker->GetName();
	this->Namework->Text = worker->GetNamework();
	this->payment->Text = Convert::ToString(worker->GetPayment());
}

System::Void �ourseWork�::Game::������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxhuman->Visible = false;
	this->groupBoxworker->Visible = false;
	this->groupBoxmd->Visible = false;
	this->groupBoxrealty->Visible = false;
	this->groupBoxclothes->Visible = true;
	this->dataGridViewclothes->Rows[0]->Cells[1]->Value = clothes->GetBody();
	this->dataGridViewclothes->Rows[1]->Cells[1]->Value = clothes->GetPants();
	this->dataGridViewclothes->Rows[2]->Cells[1]->Value = clothes->GetShoes();
	this->dataGridViewclothes->Rows[3]->Cells[1]->Value = clothes->GetClothesStatus();
}

System::Void �ourseWork�::Game::checkBoxhouse_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->checkBoxhouse->Checked == true) {
		this->comboBoxrealtyhouse->Visible = true;
		this->buybutton->Visible = true;
		this->checkBoxcar->Checked = false;
		this->comboBoxrealtycar->Visible = false;
	}
	else if (this->checkBoxhouse->Checked == false && this->checkBoxcar->Checked == true) {
		this->comboBoxrealtyhouse->Visible = false;
	}
	else {
		this->buybutton->Visible = false;
		this->comboBoxrealtycar->Visible = false;
	}
}

System::Void �ourseWork�::Game::checkBoxcar_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->checkBoxcar->Checked == true) {
		this->buybutton->Visible = true;
		this->checkBoxhouse->Checked = false;
		this->comboBoxrealtyhouse->Visible = false;
		this->comboBoxrealtycar->Visible = true;
	}
	else if (this->checkBoxcar->Checked == false && this->checkBoxhouse->Checked == true) {
		this->comboBoxrealtycar->Visible = false;
	}
	else {
		this->buybutton->Visible = false;
		this->comboBoxrealtycar->Visible = false;
	}
}

System::Void �ourseWork�::Game::Game_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	System::Windows::Forms::DialogResult result = MessageBox::Show("�� ������, ��� ������ �����?", "��������!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
	if (result == System::Windows::Forms::DialogResult::Yes) {
		if (worker->GetAge() != 0) {
			StreamWriter^ f = gcnew StreamWriter("save.txt", false);
			f->WriteLine(worker->GetName());
			f->WriteLine(worker->GetSex());
			f->WriteLine(worker->GetAge());
			f->WriteLine(worker->GetMoneybalance());
			f->WriteLine(medcard->GetWeight());
			f->WriteLine(medcard->GetHeight());
			f->WriteLine(worker->GetNamework());
			f->WriteLine(worker->GetPayment());
			f->WriteLine(clothes->GetBody());
			f->WriteLine(clothes->GetPants());
			f->WriteLine(clothes->GetShoes());
			f->WriteLine(realty->GetHousing());
			f->WriteLine(realty->GetVehicle());
			f->WriteLine(worker->GetLevel());
			f->Close();
		}
		this->Owner->WindowState = FormWindowState::Normal;
		this->Owner->ShowInTaskbar = true;
		return;
	}
	else {
		e->Cancel = true;
	}
}

System::Void �ourseWork�::Game::buysuitbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMoneybalance() >= 1000) {
		clothes->BuySuit();
		clothes->SetClothesStatus(100);
		this->dataGridViewclothes->Rows[0]->Cells[1]->Value = clothes->GetBody();
		this->dataGridViewclothes->Rows[1]->Cells[1]->Value = clothes->GetPants();
		this->dataGridViewclothes->Rows[2]->Cells[1]->Value = clothes->GetShoes();
		this->dataGridViewclothes->Rows[3]->Cells[1]->Value = clothes->GetClothesStatus();
		this->buysuitbutton->Visible = false;
		worker->ChangeMoney(-1000);
		this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
		this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
	}
	else {
		MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void �ourseWork�::Game::buttonsewup_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMoneybalance() >= 5) {
		if (clothes->GetClothesStatus() < 100) {
			clothes->SewUpClothes();
			this->dataGridViewclothes->Rows[3]->Cells[1]->Value = clothes->GetClothesStatus();
			worker->ChangeMoney(-5);
			this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
			this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
		}
		else {
			MessageBox::Show("������ ��� ���������!", "�����?", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	else {
		MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void �ourseWork�::Game::workingbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (medcard->GetHealthStatus() > 0 && clothes->GetClothesStatus() > 0) {
		worker->ChangeMoney(worker->GetPayment());
		this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
		this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
		clothes->TearClothes();
		medcard->DownStatus();
		this->infohealthpercent->Text = Convert::ToString(medcard->GetHealthStatus());
		this->health->Text = Convert::ToString(medcard->GetHealthStatus());
		this->dataGridViewclothes->Rows[3]->Cells[1]->Value = clothes->GetClothesStatus();
		if (worker->GetMoneybalance() > 100000000 && worker->GetLevel() < 4) {
			if (worker->GetNamework() != "������") {
				MessageBox::Show("� ����������!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			worker->SetNamework("������");
			worker->SetPayment(900000);
			worker->LevelUp();
			this->Namework->Text = worker->GetNamework();
			this->payment->Text = Convert::ToString(worker->GetPayment());
		}
		if (worker->GetMoneybalance() > 10000000 && worker->GetLevel() < 3) {
			if (worker->GetNamework() != "���������") {
				MessageBox::Show("� ����������!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			worker->SetNamework("���������");
			worker->SetPayment(185000);
			worker->LevelUp();
			this->Namework->Text = worker->GetNamework();
			this->payment->Text = Convert::ToString(worker->GetPayment());
		}
		if (worker->GetMoneybalance() > 1000000 && worker->GetLevel() < 2) {
			if (worker->GetNamework() != "����� ������") {
				MessageBox::Show("� ����������!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			worker->SetNamework("����� ������");
			worker->SetPayment(70000);
			worker->LevelUp();
			this->Namework->Text = worker->GetNamework();
			this->payment->Text = Convert::ToString(worker->GetPayment());
		}
		if (worker->GetMoneybalance() > 100000 && worker->GetLevel() < 1) {
			if (worker->GetNamework() != "������") {
				MessageBox::Show("� ����������!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			worker->SetNamework("������");
			worker->SetPayment(13000);
			worker->LevelUp();
			this->Namework->Text = worker->GetNamework();
			this->payment->Text = Convert::ToString(worker->GetPayment());
		}
	}
	else {
		MessageBox::Show("������ �� �� ������ ��������!\n��������� ��������� ��������\n��� ��������� ������.", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void �ourseWork�::Game::healthbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMoneybalance() >= 10) {
		if (medcard->GetHealthStatus() < 100) {
			medcard->UpStatus();
			worker->ChangeMoney(-10);
			this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
			this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
			this->infohealthpercent->Text = Convert::ToString(medcard->GetHealthStatus());
			this->health->Text = Convert::ToString(medcard->GetHealthStatus());
		}
		else {
			MessageBox::Show("�� ��� �������!", "����� ? ", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	else {
		MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void �ourseWork�::Game::buybutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->checkBoxhouse->Checked == true) {
		if (this->comboBoxrealtyhouse->Text == "��������(3 000 000)") {
			if (worker->GetMoneybalance() >= 3000000) {
				realty->SetHousing(this->comboBoxrealtyhouse->Text);
				worker->ChangeMoney(-3000000);
				this->realtyhouse->Text = realty->GetHousing();
				this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
				this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
			}
			else {
				MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		if (this->comboBoxrealtyhouse->Text == "�������(7 000 000)") {
			if (worker->GetMoneybalance() >= 7000000) {
				realty->SetHousing(this->comboBoxrealtyhouse->Text);
				worker->ChangeMoney(-7000000);
				this->realtyhouse->Text = realty->GetHousing();
				this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
				this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
			}
			else {
				MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		if (this->comboBoxrealtyhouse->Text == "�����(20 000 000)") {
			if (worker->GetMoneybalance() >= 20000000) {
				realty->SetHousing(this->comboBoxrealtyhouse->Text);
				worker->ChangeMoney(-20000000);
				this->realtyhouse->Text = realty->GetHousing();
				this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
				this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
			}
			else {
				MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	}
	else {
		if (this->comboBoxrealtycar->Text == "��������(200 000)") {
			if (worker->GetMoneybalance() >= 200000) {
				realty->SetVehicle(this->comboBoxrealtycar->Text);
				worker->ChangeMoney(-200000);
				this->realtycar->Text = realty->GetVehicle();
				this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
				this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
			}
			else {
				MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		if (this->comboBoxrealtycar->Text == "����������(600 000)") {
			if (worker->GetMoneybalance() >= 600000) {
				realty->SetVehicle(this->comboBoxrealtycar->Text);
				worker->ChangeMoney(-600000);
				this->realtycar->Text = realty->GetVehicle();
				this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
				this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
			}
			else {
				MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		if (this->comboBoxrealtycar->Text == "�����(9 000 000)") {
			if (worker->GetMoneybalance() >= 9000000) {
				realty->SetVehicle(this->comboBoxrealtycar->Text);
				worker->ChangeMoney(-9000000);
				this->realtycar->Text = realty->GetVehicle();
				this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
				this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
			}
			else {
				MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	}
}

System::Void �ourseWork�::Game::DataInitialization()
{
	if (File::Exists("save.txt") == true) {
		try
		{
			StreamReader^ f = File::OpenText("save.txt");
			worker->SetName(f->ReadLine());
			worker->SetSex(f->ReadLine());
			worker->SetAge(Convert::ToInt32(f->ReadLine()));
			worker->SetMoneyBalance(Convert::ToInt32(f->ReadLine()));
			medcard->SetWeight(Convert::ToInt32(f->ReadLine()));
			medcard->SetHeight(Convert::ToInt32(f->ReadLine()));
			worker->SetNamework(f->ReadLine());
			worker->SetPayment(Convert::ToInt32(f->ReadLine()));
			clothes->SetBody(f->ReadLine());
			clothes->SetPants(f->ReadLine());
			clothes->SetShoes(f->ReadLine());
			realty->SetHousing(f->ReadLine());
			realty->SetVehicle(f->ReadLine());
			worker->SetLevel(Convert::ToInt32(f->ReadLine()));
			f->Close();

			this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
			this->infoname->Text = worker->GetName();
			this->infohealthpercent->Text = Convert::ToString(medcard->GetHealthStatus());
			this->dataGridViewclothes->Rows->Add();
			this->dataGridViewclothes->Rows->Add();
			this->dataGridViewclothes->Rows->Add();
			this->dataGridViewclothes->Rows->Add();
			this->dataGridViewclothes->Rows[0]->Cells[0]->Value = L"����";
			this->dataGridViewclothes->Rows[1]->Cells[0]->Value = L"�����";
			this->dataGridViewclothes->Rows[2]->Cells[0]->Value = L"�����";
			this->dataGridViewclothes->Rows[3]->Cells[0]->Value = L"��������� ������";
			this->humanname->Text = worker->GetName();
			this->humansex->Text = worker->GetSex();
			this->humanage->Text = Convert::ToString(worker->GetAge());
			if (clothes->GetShoes() == "�����") {
				this->buysuitbutton->Visible = false;
			}
			this->mdname->Text = worker->GetName();
			this->mdweight->Text = Convert::ToString(medcard->GetWeight());
			this->mdheight->Text = Convert::ToString(medcard->GetHeight());
			Double IMT = (medcard->GetWeight() + 0.0) / (medcard->GetHeight() * medcard->GetHeight() / 10000);
			this->imt->Text = Convert::ToString(IMT);
			if (IMT < 18.5) {
				this->imtcomment->Text = "���� �����";
			}
			else if (IMT > 26.0) {
				this->imtcomment->Text = "���� �����";
			}
			else {
				this->imtcomment->Text = "�����";
			}
			
		}
		catch (Exception^)
		{
			MessageBox::Show("������ �������� �����!", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->Close();
		}
	}
}

System::Void �ourseWork�::Game::boostersbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->groupBoxboosters->Visible == false) {
		this->groupBoxboosters->Visible = true;
	}
	else {
		this->groupBoxboosters->Visible = false;
	}
}
