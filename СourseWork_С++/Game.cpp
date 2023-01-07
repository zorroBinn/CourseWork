#include "Game.h"

System::Void �ourseWork�::Game::DataInitialization()
{
	if (File::Exists("save.save") == true) {
		try
		{
			StreamReader^ f = File::OpenText("save.save");
			worker->SetName(f->ReadLine());
			worker->SetSex(f->ReadLine());
			worker->SetAge(Convert::ToInt32(f->ReadLine()));
			worker->SetMoneyBalance(Convert::ToInt32(f->ReadLine()));
			worker->GetMedCard()->SetWeight(Convert::ToInt32(f->ReadLine()));
			worker->GetMedCard()->SetHeight(Convert::ToInt32(f->ReadLine()));
			worker->GetMedCard()->SetHealthStatus(Convert::ToInt32(f->ReadLine()));
			if (f->ReadLine() == "0") {
				worker->GetMedCard()->SetInfinityHealth(false);
			}
			else {
				worker->GetMedCard()->SetInfinityHealth(true);
				this->autohealthbutton->BackColor = System::Drawing::Color::LimeGreen;
			}
			worker->SetNamework(f->ReadLine());
			worker->SetPayment(Convert::ToInt32(f->ReadLine()));
			worker->GetClothes()->SetBody(f->ReadLine());
			worker->GetClothes()->SetPants(f->ReadLine());
			worker->GetClothes()->SetShoes(f->ReadLine());
			worker->GetClothes()->SetClothesStatus(Convert::ToInt32(f->ReadLine()));
			if (f->ReadLine() == "0") {
				worker->GetClothes()->SetAutoSewUp(false);
			}
			else {
				worker->GetClothes()->SetAutoSewUp(true);
				this->autosewupbutton->BackColor = System::Drawing::Color::LimeGreen;
			}
			worker->GetRealty()->SetHousing(f->ReadLine());
			worker->GetRealty()->SetVehicle(f->ReadLine());
			worker->SetLevel(Convert::ToInt32(f->ReadLine()));
			worker->GetFood()->SetSatietyStatus(Convert::ToInt32(f->ReadLine()));
			if (f->ReadLine() == "0") {
				worker->GetFood()->SetAutoEating(false);
			}
			else {
				worker->GetFood()->SetAutoEating(true);
				this->autoeatbutton->BackColor = System::Drawing::Color::LimeGreen;
			}
			Day = Convert::ToInt32(f->ReadLine());
			f->Close();

			SatietyUpdating();
			MoneyBalanceUpdating();
			HealthUpdating();
			if (worker->GetClothes()->GetPants() == "�����") {
				this->buttonsewup->Text = "�������� ������(10$)";
			}
			this->infoname->Text = worker->GetName();
			this->infoday->Text = Convert::ToString(Day);
			this->dataGridViewclothes->Rows->Add();
			this->dataGridViewclothes->Rows->Add();
			this->dataGridViewclothes->Rows->Add();
			this->dataGridViewclothes->Rows->Add();
			this->dataGridViewclothes->Rows[0]->Cells[0]->Value = L"����";
			this->dataGridViewclothes->Rows[1]->Cells[0]->Value = L"�����";
			this->dataGridViewclothes->Rows[2]->Cells[0]->Value = L"�����";
			this->dataGridViewclothes->Rows[3]->Cells[0]->Value = L"��������� ������";
			this->dataGridViewclothes->Rows[0]->Cells[1]->Value = worker->GetClothes()->GetBody();
			this->dataGridViewclothes->Rows[1]->Cells[1]->Value = worker->GetClothes()->GetPants();
			this->dataGridViewclothes->Rows[2]->Cells[1]->Value = worker->GetClothes()->GetShoes();
			this->dataGridViewclothes->Rows[3]->Cells[1]->Value = worker->GetClothes()->GetClothesStatus();
			this->humanname->Text = worker->GetName();
			this->humansex->Text = worker->GetSex();
			this->humanage->Text = Convert::ToString(worker->GetAge());
			if (worker->GetClothes()->GetShoes() == "�����") {
				this->buysuitbutton->Visible = false;
			}
			this->mdname->Text = worker->GetName();
			this->mdweight->Text = Convert::ToString(worker->GetMedCard()->GetWeight());
			this->mdheight->Text = Convert::ToString(worker->GetMedCard()->GetHeight());
			Double IMT = (worker->GetMedCard()->GetWeight() + 0.0) / (worker->GetMedCard()->GetHeight() * worker->GetMedCard()->GetHeight() / 10000);
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
			this->realtyhouse->Text = worker->GetRealty()->GetHousing();
			this->realtycar->Text = worker->GetRealty()->GetVehicle();
			this->workername->Text = worker->GetName();
			this->Namework->Text = worker->GetNamework();
			this->payment->Text = Convert::ToString(worker->GetPayment());
		}
		catch (Exception^)
		{
			MessageBox::Show("�� �������� ��������� ����������!", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			if (File::Exists("save.save") == true) {
				File::Delete("save.save");
			}
			this->Owner->WindowState = FormWindowState::Normal;
			this->Owner->ShowInTaskbar = true;
			this->Close();
		}
	}
}

System::Void �ourseWork�::Game::MoneyBalanceUpdating()
{
	this->infomoneybalance->Text = Convert::ToString(worker->GetMoneybalance());
	this->humanbalance->Text = Convert::ToString(worker->GetMoneybalance());
}

System::Void �ourseWork�::Game::SatietyUpdating()
{
	this->infosatietypercent->Text = Convert::ToString(worker->GetFood()->GetSatietyStatus());
	this->satiety->Text = Convert::ToString(worker->GetFood()->GetSatietyStatus());
}

System::Void �ourseWork�::Game::HealthUpdating()
{
	this->infohealthpercent->Text = Convert::ToString(worker->GetMedCard()->GetHealthStatus());
	this->health->Text = Convert::ToString(worker->GetMedCard()->GetHealthStatus());
}

System::Void �ourseWork�::Game::LevelUp()
{
	worker->LevelUp();
	this->Namework->Text = worker->GetNamework();
	this->payment->Text = Convert::ToString(worker->GetPayment());
}

System::Void �ourseWork�::Game::GameSave()
{
	try
	{
		StreamWriter^ f = gcnew StreamWriter("save.save", false);
		f->WriteLine(worker->GetName());
		f->WriteLine(worker->GetSex());
		f->WriteLine(worker->GetAge());
		f->WriteLine(worker->GetMoneybalance());
		f->WriteLine(worker->GetMedCard()->GetWeight());
		f->WriteLine(worker->GetMedCard()->GetHeight());
		f->WriteLine(worker->GetMedCard()->GetHealthStatus());
		if (worker->GetMedCard()->GetInfinityHealth() == true) {
			f->WriteLine(1);
		}
		else {
			f->WriteLine(0);
		}
		f->WriteLine(worker->GetNamework());
		f->WriteLine(worker->GetPayment());
		f->WriteLine(worker->GetClothes()->GetBody());
		f->WriteLine(worker->GetClothes()->GetPants());
		f->WriteLine(worker->GetClothes()->GetShoes());
		f->WriteLine(worker->GetClothes()->GetClothesStatus());
		if (worker->GetClothes()->GetAutoSewUp() == true) {
			f->WriteLine(1);
		}
		else {
			f->WriteLine(0);
		}
		f->WriteLine(worker->GetRealty()->GetHousing());
		f->WriteLine(worker->GetRealty()->GetVehicle());
		f->WriteLine(worker->GetLevel());
		f->WriteLine(worker->GetFood()->GetSatietyStatus());
		if (worker->GetFood()->GetAutoEating() == true) {
			f->WriteLine(1);
		}
		else {
			f->WriteLine(0);
		}
		f->WriteLine(Day);
		f->Close();
	}
	catch (Exception^)
	{
		MessageBox::Show("�� ������� �������� ����������!", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void �ourseWork�::Game::GameLoss()
{
	bool lossrate = false;
	while (lossrate == false) {
		if (worker->GetClothes()->GetClothesStatus() == 0 && worker->GetClothes()->GetPants() == "�����" && worker->GetMoneybalance() < 10) {
			MessageBox::Show("��� ������ ��������� � ��� �� ������� ����� ��� ��������!\n���� ���������� ������ ������.", "��!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			worker->GetClothes()->SetRegularClothes();
			this->dataGridViewclothes->Rows[0]->Cells[1]->Value = worker->GetClothes()->GetBody();
			this->dataGridViewclothes->Rows[1]->Cells[1]->Value = worker->GetClothes()->GetPants();
			this->dataGridViewclothes->Rows[2]->Cells[1]->Value = worker->GetClothes()->GetShoes();
			this->dataGridViewclothes->Rows[3]->Cells[1]->Value = worker->GetClothes()->GetClothesStatus();
			this->buysuitbutton->Visible = true;
		}
		if (worker->GetClothes()->GetClothesStatus() == 0 && worker->GetClothes()->GetPants() != "�����" && worker->GetMoneybalance() < 5) {
			lossrate = true;
			MessageBox::Show("���� ��������!\n������� ���������: ������������� �������� ������", "����� ����...", MessageBoxButtons::OK, MessageBoxIcon::Information);
			break;
		}
		if (worker->GetFood()->GetSatietyStatus() == 0 && worker->GetMoneybalance() < 5) {
			lossrate = true;
			MessageBox::Show("���� ��������!\n������� ���������: ������������� ������� �����", "����� ����...", MessageBoxButtons::OK, MessageBoxIcon::Information);
			break;
		}
		if (worker->GetMedCard()->GetHealthStatus() == 0 && worker->GetMoneybalance() < 10) {
			lossrate = true;
			MessageBox::Show("���� ��������!\n������� ���������: ������������� �������", "����� ����...", MessageBoxButtons::OK, MessageBoxIcon::Information);
			break;
		}
		break;
	}
	if (lossrate == true) {
		MessageBox::Show("���������:\n����������� ����: " + Day, "���� ��������", MessageBoxButtons::OK, MessageBoxIcon::Information);
		GameSave();
		this->Owner->WindowState = FormWindowState::Normal;
		this->Owner->ShowInTaskbar = true;
	}
}

System::Void �ourseWork�::Game::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxworker->Visible = false;
	this->groupBoxfood->Visible = false;
	this->groupBoxclothes->Visible = false;
	this->groupBoxmd->Visible = false;
	this->groupBoxrealty->Visible = false;
	this->groupBoxhuman->Visible = true;
}

System::Void �ourseWork�::Game::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxhuman->Visible = false;
	this->groupBoxfood->Visible = false;
	this->groupBoxworker->Visible = false;
	this->groupBoxclothes->Visible = false;
	this->groupBoxrealty->Visible = false;
	this->groupBoxmd->Visible = true;
}

System::Void �ourseWork�::Game::���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxhuman->Visible = false;
	this->groupBoxfood->Visible = false;
	this->groupBoxworker->Visible = false;
	this->groupBoxmd->Visible = false;
	this->groupBoxclothes->Visible = false;
	this->groupBoxrealty->Visible = true;
}

System::Void �ourseWork�::Game::������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxhuman->Visible = false;
	this->groupBoxfood->Visible = false;
	this->groupBoxclothes->Visible = false;
	this->groupBoxmd->Visible = false;
	this->groupBoxrealty->Visible = false;
	this->groupBoxworker->Visible = true;
}

System::Void �ourseWork�::Game::������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxhuman->Visible = false;
	this->groupBoxfood->Visible = false;
	this->groupBoxworker->Visible = false;
	this->groupBoxmd->Visible = false;
	this->groupBoxrealty->Visible = false;
	this->groupBoxclothes->Visible = true;
}

System::Void �ourseWork�::Game::���toolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->groupBoxfood->Visible = true;
	this->groupBoxrealty->Visible = false;
	this->groupBoxhuman->Visible = false;
	this->groupBoxworker->Visible = false;
	this->groupBoxmd->Visible = false;
	this->groupBoxclothes->Visible = false;
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
			GameSave();
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
	if (worker->GetMoneybalance() >= 5000) {
		worker->GetClothes()->BuySuit();
		this->dataGridViewclothes->Rows[0]->Cells[1]->Value = worker->GetClothes()->GetBody();
		this->dataGridViewclothes->Rows[1]->Cells[1]->Value = worker->GetClothes()->GetPants();
		this->dataGridViewclothes->Rows[2]->Cells[1]->Value = worker->GetClothes()->GetShoes();
		this->dataGridViewclothes->Rows[3]->Cells[1]->Value = worker->GetClothes()->GetClothesStatus();
		this->buysuitbutton->Visible = false;
		worker->ChangeMoney(-5000);
		MoneyBalanceUpdating();
		GameLoss();
	}
	else {
		MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void �ourseWork�::Game::buttonsewup_Click(System::Object^ sender, System::EventArgs^ e)
{
	if ((worker->GetMoneybalance() >= 5 && worker->GetClothes()->GetPants() != "�����") || (worker->GetMoneybalance() >= 10 && worker->GetClothes()->GetPants() == "�����")) {
		if (worker->GetClothes()->GetClothesStatus() < 100) {
			worker->GetClothes()->SewUpClothes();
			this->dataGridViewclothes->Rows[3]->Cells[1]->Value = worker->GetClothes()->GetClothesStatus();
			if (worker->GetClothes()->GetPants() != "�����") {
				worker->ChangeMoney(-5);
			}
			else {
				worker->ChangeMoney(-10);
			}
			MoneyBalanceUpdating();
			GameLoss();
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
	GameLoss();
	if (worker->GetMedCard()->GetHealthStatus() > 0 && worker->GetClothes()->GetClothesStatus() > 0 && worker->GetFood()->GetSatietyStatus() > 0) {
		worker->ChangeMoney(worker->GetPayment());
		MoneyBalanceUpdating();
		Day++;
		this->infoday->Text = Convert::ToString(Day);
		if (worker->GetClothes()->GetAutoSewUp() != true) {
			worker->GetClothes()->TearClothes();
			this->dataGridViewclothes->Rows[3]->Cells[1]->Value = worker->GetClothes()->GetClothesStatus();
		}
		if (worker->GetMedCard()->GetInfinityHealth() != true) {
			worker->GetMedCard()->DownStatus();
			HealthUpdating();
		}
		if (worker->GetFood()->GetAutoEating() != true) {
			worker->GetFood()->DownSatietyStatus();
			SatietyUpdating();
		}
		if (worker->GetMoneybalance() > 100000000 && worker->GetLevel() < 4) {
			MessageBox::Show("� ����������!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			worker->SetNamework("������");
			worker->SetPayment(900000);
			LevelUp();
		}
		if (worker->GetMoneybalance() > 10000000 && worker->GetLevel() < 3) {
			MessageBox::Show("� ����������!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			worker->SetNamework("���������");
			worker->SetPayment(185000);
			LevelUp();
		}
		if (worker->GetMoneybalance() > 1000000 && worker->GetLevel() < 2) {
			MessageBox::Show("� ����������!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			worker->SetNamework("����� ������");
			worker->SetPayment(70000);
			LevelUp();
		}
		if (worker->GetMoneybalance() > 100000 && worker->GetLevel() < 1) {
			MessageBox::Show("� ����������!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			worker->SetNamework("������");
			worker->SetPayment(13000);
			LevelUp();
		}
	}
	else {
		MessageBox::Show("������ �� �� ������ ��������!\n��������� ��������� ��������,\n ��������� ������ ��� �������", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void �ourseWork�::Game::healthbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMoneybalance() >= 10) {
		if (worker->GetMedCard()->GetHealthStatus() < 100) {
			worker->GetMedCard()->UpStatus();
			worker->ChangeMoney(-10);
			MoneyBalanceUpdating();
			HealthUpdating();
			GameLoss();
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
				worker->GetRealty()->SetHousing(this->comboBoxrealtyhouse->Text);
				worker->ChangeMoney(-3000000);
				this->realtyhouse->Text = worker->GetRealty()->GetHousing();
				MoneyBalanceUpdating();
			}
			else {
				MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		if (this->comboBoxrealtyhouse->Text == "�������(7 000 000)") {
			if (worker->GetMoneybalance() >= 7000000) {
				worker->GetRealty()->SetHousing(this->comboBoxrealtyhouse->Text);
				worker->ChangeMoney(-7000000);
				this->realtyhouse->Text = worker->GetRealty()->GetHousing();
				MoneyBalanceUpdating();
			}
			else {
				MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		if (this->comboBoxrealtyhouse->Text == "�����(20 000 000)") {
			if (worker->GetMoneybalance() >= 20000000) {
				worker->GetRealty()->SetHousing(this->comboBoxrealtyhouse->Text);
				worker->ChangeMoney(-20000000);
				this->realtyhouse->Text = worker->GetRealty()->GetHousing();
				MoneyBalanceUpdating();
			}
			else {
				MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	}
	else {
		if (this->comboBoxrealtycar->Text == "��������(200 000)") {
			if (worker->GetMoneybalance() >= 200000) {
				worker->GetRealty()->SetVehicle(this->comboBoxrealtycar->Text);
				worker->ChangeMoney(-200000);
				this->realtycar->Text = worker->GetRealty()->GetVehicle();
				MoneyBalanceUpdating();
			}
			else {
				MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		if (this->comboBoxrealtycar->Text == "����������(600 000)") {
			if (worker->GetMoneybalance() >= 600000) {
				worker->GetRealty()->SetVehicle(this->comboBoxrealtycar->Text);
				worker->ChangeMoney(-600000);
				this->realtycar->Text = worker->GetRealty()->GetVehicle();
				MoneyBalanceUpdating();
			}
			else {
				MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
		if (this->comboBoxrealtycar->Text == "�����(9 000 000)") {
			if (worker->GetMoneybalance() >= 9000000) {
				worker->GetRealty()->SetVehicle(this->comboBoxrealtycar->Text);
				worker->ChangeMoney(-9000000);
				this->realtycar->Text = worker->GetRealty()->GetVehicle();
				MoneyBalanceUpdating();
			}
			else {
				MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}
	}
	GameLoss();
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

System::Void �ourseWork�::Game::onefoodbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMoneybalance() >= 5) {
		if (worker->GetFood()->GetSatietyStatus() < 100) {
			worker->GetFood()->UpSatietyStatus(10);
			SatietyUpdating();
			worker->ChangeMoney(-5);
			MoneyBalanceUpdating();
			GameLoss();
		}
		else {
			MessageBox::Show("�� ��������� �����!", "�����?", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	else {
		MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void �ourseWork�::Game::twofoodbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMoneybalance() >= 20) {
		if (worker->GetFood()->GetSatietyStatus() < 100) {
			worker->GetFood()->UpSatietyStatus(25);
			SatietyUpdating();
			worker->ChangeMoney(-20);
			MoneyBalanceUpdating();
			GameLoss();
		}
		else {
			MessageBox::Show("�� ��������� �����!", "�����?", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	else {
		MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void �ourseWork�::Game::threebutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMoneybalance() >= 100) {
		if(worker->GetFood()->GetSatietyStatus() < 100) {
			worker->GetFood()->UpSatietyStatus(100);
			SatietyUpdating();
			worker->ChangeMoney(-100);
			MoneyBalanceUpdating();
			GameLoss();
		}
		else {
			MessageBox::Show("�� ��������� �����!", "�����?", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	else {
		MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void �ourseWork�::Game::autoeatbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetFood()->GetAutoEating() == false) {
		if (worker->GetMoneybalance() >= 500000) {
			System::Windows::Forms::DialogResult result = MessageBox::Show("�������������� ����������� ������� ��������� ��� ������ �� ������������ � ��������� ������ ���������. ��� �������� ������ ����� ��������!", "������ ���������� ���������?", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
			if (result == System::Windows::Forms::DialogResult::Yes) {
				this->autoeatbutton->BackColor = System::Drawing::Color::LimeGreen;
				worker->GetFood()->SetAutoEating(true);
				worker->ChangeMoney(-500000);
				SatietyUpdating();
				MoneyBalanceUpdating();
				GameLoss();
			}
		}
		else {
			MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
}

System::Void �ourseWork�::Game::autosewupbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetClothes()->GetAutoSewUp() == false) {
		if (worker->GetMoneybalance() >= 1000000) {
			System::Windows::Forms::DialogResult result = MessageBox::Show("�������������� ������� ������ ��������� ��� ������ �� ������������ � ��������� ������ ������ ���������. ��� �������� ������ ����� ��������!", "������ ���������� ����������� ������?", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
			if (result == System::Windows::Forms::DialogResult::Yes) {
				this->autosewupbutton->BackColor = System::Drawing::Color::LimeGreen;
				worker->GetClothes()->SetAutoSewUp(true);
				this->dataGridViewclothes->Rows[3]->Cells[1]->Value = worker->GetClothes()->GetClothesStatus();
				worker->ChangeMoney(-1000000);
				MoneyBalanceUpdating();
				GameLoss();
			}
		}
		else {
			MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
}

System::Void �ourseWork�::Game::autohealthbutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (worker->GetMedCard()->GetInfinityHealth() == false) {
		if (worker->GetMoneybalance() >= 1500000) {
			System::Windows::Forms::DialogResult result = MessageBox::Show("�������������� ������� ��������� ��� ������ �� ������������ � ��������� �������� ������ ���������. ��� �������� ������ ����� ��������!", "������ ���������� �����������?", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
			if (result == System::Windows::Forms::DialogResult::Yes) {
				this->autohealthbutton->BackColor = System::Drawing::Color::LimeGreen;
				worker->GetMedCard()->SetInfinityHealth(true);
				worker->ChangeMoney(-1500000);
				MoneyBalanceUpdating();
				HealthUpdating();
				GameLoss();
			}
		}
		else {
			MessageBox::Show("������������ �����!", "���!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
}
