#pragma once
#include "Human.h"
#include "Clothes.h"
#include "MedicalCard.h"
#include "Realty.h"
#include "worker.h"

namespace �ourseWork� {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// ������ ��� Game
	/// </summary>
	public ref class Game : public System::Windows::Forms::Form
	{
		MedicalCard^ medcard;
		Clothes^ clothes;
		Realty^ realty;
		Worker^ worker;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ parametr;
	private: System::Windows::Forms::PictureBox^ picturebox;
	private: System::Windows::Forms::Label^ imtcomment;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cloth;

	public:
		Game(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			worker = gcnew Worker();
			medcard = gcnew MedicalCard();
			realty = gcnew Realty();
			clothes = gcnew Clothes();
			DataInitialization();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menu;
	protected:

	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ ������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������ToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ Infobox;
	private: System::Windows::Forms::Label^ infohealth;
	private: System::Windows::Forms::Label^ infobalance;
	private: System::Windows::Forms::Label^ infoname;



	private: System::Windows::Forms::GroupBox^ groupBoxhuman;
	private: System::Windows::Forms::Label^ humanbalance;
	private: System::Windows::Forms::Label^ labelhumanbalance;
	private: System::Windows::Forms::Label^ humanage;

	private: System::Windows::Forms::Label^ labelhumanage;
	private: System::Windows::Forms::Label^ humansex;
	private: System::Windows::Forms::Label^ labelhumansex;
	private: System::Windows::Forms::Label^ humanname;
	private: System::Windows::Forms::Label^ labelhumanname;
	private: System::Windows::Forms::Label^ labelmyhuman;
	private: System::Windows::Forms::GroupBox^ groupBoxworker;
	private: System::Windows::Forms::Label^ payment;




	private: System::Windows::Forms::Label^ labelpayment;
	private: System::Windows::Forms::Label^ Namework;


	private: System::Windows::Forms::Label^ labelNamework;
	private: System::Windows::Forms::Label^ workername;


	private: System::Windows::Forms::Label^ labelworkerhumanname;
	private: System::Windows::Forms::Label^ labelworker;
	private: System::Windows::Forms::Button^ workingbutton;
	private: System::Windows::Forms::Label^ infopercent;

	private: System::Windows::Forms::GroupBox^ groupBoxmd;

	private: System::Windows::Forms::Label^ labelmdpercent;
	private: System::Windows::Forms::Label^ health;
	private: System::Windows::Forms::Label^ labelhealth;
	private: System::Windows::Forms::Label^ imt;
	private: System::Windows::Forms::Label^ labelimt;
	private: System::Windows::Forms::Button^ healthbutton;


	private: System::Windows::Forms::Label^ mdheight;
	private: System::Windows::Forms::Label^ labelmdheight;
	private: System::Windows::Forms::Label^ mdweight;
	private: System::Windows::Forms::Label^ labelmdweight;
	private: System::Windows::Forms::Label^ mdname;
	private: System::Windows::Forms::Label^ labelmdname;
	private: System::Windows::Forms::Label^ labelmedicalcard;
	private: System::Windows::Forms::GroupBox^ groupBoxrealty;

	private: System::Windows::Forms::Button^ buybutton;

	private: System::Windows::Forms::Label^ labelrealtybuy;










	private: System::Windows::Forms::Label^ realtycar;

	private: System::Windows::Forms::Label^ labelrealtycar;
	private: System::Windows::Forms::Label^ realtyhouse;


	private: System::Windows::Forms::Label^ labelrealtyhouse;

	private: System::Windows::Forms::Label^ labelrealty;
	private: System::Windows::Forms::ComboBox^ comboBoxrealtycar;
	private: System::Windows::Forms::CheckBox^ checkBoxcar;
	private: System::Windows::Forms::CheckBox^ checkBoxhouse;
	private: System::Windows::Forms::ComboBox^ comboBoxrealtyhouse;
	private: System::Windows::Forms::Label^ infohealthpercent;
	private: System::Windows::Forms::Label^ infomoneybalance;
	private: System::Windows::Forms::GroupBox^ groupBoxclothes;
	private: System::Windows::Forms::DataGridView^ dataGridViewclothes;


	private: System::Windows::Forms::Button^ buttonsewup;
	private: System::Windows::Forms::Label^ labelclothes;
	private: System::Windows::Forms::Button^ buysuitbutton;







	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Game::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Infobox = (gcnew System::Windows::Forms::GroupBox());
			this->infomoneybalance = (gcnew System::Windows::Forms::Label());
			this->infohealthpercent = (gcnew System::Windows::Forms::Label());
			this->infopercent = (gcnew System::Windows::Forms::Label());
			this->infohealth = (gcnew System::Windows::Forms::Label());
			this->infobalance = (gcnew System::Windows::Forms::Label());
			this->infoname = (gcnew System::Windows::Forms::Label());
			this->picturebox = (gcnew System::Windows::Forms::PictureBox());
			this->groupBoxhuman = (gcnew System::Windows::Forms::GroupBox());
			this->humanbalance = (gcnew System::Windows::Forms::Label());
			this->labelhumanbalance = (gcnew System::Windows::Forms::Label());
			this->humanage = (gcnew System::Windows::Forms::Label());
			this->labelhumanage = (gcnew System::Windows::Forms::Label());
			this->humansex = (gcnew System::Windows::Forms::Label());
			this->labelhumansex = (gcnew System::Windows::Forms::Label());
			this->humanname = (gcnew System::Windows::Forms::Label());
			this->labelhumanname = (gcnew System::Windows::Forms::Label());
			this->labelmyhuman = (gcnew System::Windows::Forms::Label());
			this->groupBoxworker = (gcnew System::Windows::Forms::GroupBox());
			this->workingbutton = (gcnew System::Windows::Forms::Button());
			this->payment = (gcnew System::Windows::Forms::Label());
			this->labelpayment = (gcnew System::Windows::Forms::Label());
			this->Namework = (gcnew System::Windows::Forms::Label());
			this->labelNamework = (gcnew System::Windows::Forms::Label());
			this->workername = (gcnew System::Windows::Forms::Label());
			this->labelworkerhumanname = (gcnew System::Windows::Forms::Label());
			this->labelworker = (gcnew System::Windows::Forms::Label());
			this->groupBoxmd = (gcnew System::Windows::Forms::GroupBox());
			this->labelmdpercent = (gcnew System::Windows::Forms::Label());
			this->health = (gcnew System::Windows::Forms::Label());
			this->labelhealth = (gcnew System::Windows::Forms::Label());
			this->imt = (gcnew System::Windows::Forms::Label());
			this->labelimt = (gcnew System::Windows::Forms::Label());
			this->healthbutton = (gcnew System::Windows::Forms::Button());
			this->mdheight = (gcnew System::Windows::Forms::Label());
			this->labelmdheight = (gcnew System::Windows::Forms::Label());
			this->mdweight = (gcnew System::Windows::Forms::Label());
			this->labelmdweight = (gcnew System::Windows::Forms::Label());
			this->mdname = (gcnew System::Windows::Forms::Label());
			this->labelmdname = (gcnew System::Windows::Forms::Label());
			this->labelmedicalcard = (gcnew System::Windows::Forms::Label());
			this->groupBoxclothes = (gcnew System::Windows::Forms::GroupBox());
			this->buysuitbutton = (gcnew System::Windows::Forms::Button());
			this->dataGridViewclothes = (gcnew System::Windows::Forms::DataGridView());
			this->parametr = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cloth = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonsewup = (gcnew System::Windows::Forms::Button());
			this->labelclothes = (gcnew System::Windows::Forms::Label());
			this->groupBoxrealty = (gcnew System::Windows::Forms::GroupBox());
			this->comboBoxrealtycar = (gcnew System::Windows::Forms::ComboBox());
			this->checkBoxcar = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxhouse = (gcnew System::Windows::Forms::CheckBox());
			this->comboBoxrealtyhouse = (gcnew System::Windows::Forms::ComboBox());
			this->buybutton = (gcnew System::Windows::Forms::Button());
			this->labelrealtybuy = (gcnew System::Windows::Forms::Label());
			this->realtycar = (gcnew System::Windows::Forms::Label());
			this->labelrealtycar = (gcnew System::Windows::Forms::Label());
			this->realtyhouse = (gcnew System::Windows::Forms::Label());
			this->labelrealtyhouse = (gcnew System::Windows::Forms::Label());
			this->labelrealty = (gcnew System::Windows::Forms::Label());
			this->imtcomment = (gcnew System::Windows::Forms::Label());
			this->menu->SuspendLayout();
			this->Infobox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox))->BeginInit();
			this->groupBoxhuman->SuspendLayout();
			this->groupBoxworker->SuspendLayout();
			this->groupBoxmd->SuspendLayout();
			this->groupBoxclothes->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewclothes))->BeginInit();
			this->groupBoxrealty->SuspendLayout();
			this->SuspendLayout();
			// 
			// menu
			// 
			this->menu->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->menu->AutoSize = false;
			this->menu->BackColor = System::Drawing::Color::Goldenrod;
			this->menu->Dock = System::Windows::Forms::DockStyle::None;
			this->menu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->������ToolStripMenuItem,
					this->���������ToolStripMenuItem, this->��������ToolStripMenuItem, this->��������ToolStripMenuItem, this->������ToolStripMenuItem
			});
			this->menu->Location = System::Drawing::Point(54, 446);
			this->menu->Name = L"menu";
			this->menu->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menu->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->menu->Size = System::Drawing::Size(630, 70);
			this->menu->TabIndex = 0;
			this->menu->Text = L"����";
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->AutoSize = false;
			this->������ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 14));
			this->������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"������ToolStripMenuItem.Image")));
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(125, 76);
			this->������ToolStripMenuItem->Text = L"������";
			this->������ToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->������ToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Game::������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->AutoSize = false;
			this->���������ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 14));
			this->���������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"���������ToolStripMenuItem.Image")));
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(125, 76);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->���������ToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Game::���������ToolStripMenuItem_Click);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->AutoSize = false;
			this->��������ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 14));
			this->��������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"��������ToolStripMenuItem.Image")));
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(125, 76);
			this->��������ToolStripMenuItem->Text = L"��������";
			this->��������ToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->��������ToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Game::��������ToolStripMenuItem_Click);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->AutoSize = false;
			this->��������ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 14));
			this->��������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"��������ToolStripMenuItem.Image")));
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(125, 76);
			this->��������ToolStripMenuItem->Text = L"��������";
			this->��������ToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->��������ToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Game::��������ToolStripMenuItem_Click);
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->AutoSize = false;
			this->������ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 14));
			this->������ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"������ToolStripMenuItem.Image")));
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(125, 76);
			this->������ToolStripMenuItem->Text = L"������";
			this->������ToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->������ToolStripMenuItem->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Game::������ToolStripMenuItem_Click);
			// 
			// Infobox
			// 
			this->Infobox->BackColor = System::Drawing::SystemColors::Info;
			this->Infobox->Controls->Add(this->infomoneybalance);
			this->Infobox->Controls->Add(this->infohealthpercent);
			this->Infobox->Controls->Add(this->infopercent);
			this->Infobox->Controls->Add(this->infohealth);
			this->Infobox->Controls->Add(this->infobalance);
			this->Infobox->Controls->Add(this->infoname);
			this->Infobox->Controls->Add(this->picturebox);
			this->Infobox->Location = System::Drawing::Point(560, 2);
			this->Infobox->Margin = System::Windows::Forms::Padding(2);
			this->Infobox->Name = L"Infobox";
			this->Infobox->Padding = System::Windows::Forms::Padding(2);
			this->Infobox->Size = System::Drawing::Size(194, 75);
			this->Infobox->TabIndex = 1;
			this->Infobox->TabStop = false;
			// 
			// infomoneybalance
			// 
			this->infomoneybalance->AutoSize = true;
			this->infomoneybalance->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->infomoneybalance->Location = System::Drawing::Point(5, 34);
			this->infomoneybalance->Name = L"infomoneybalance";
			this->infomoneybalance->Size = System::Drawing::Size(56, 19);
			this->infomoneybalance->TabIndex = 20;
			this->infomoneybalance->Text = L"������";
			// 
			// infohealthpercent
			// 
			this->infohealthpercent->AutoSize = true;
			this->infohealthpercent->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->infohealthpercent->Location = System::Drawing::Point(68, 56);
			this->infohealthpercent->Name = L"infohealthpercent";
			this->infohealthpercent->Size = System::Drawing::Size(32, 17);
			this->infohealthpercent->TabIndex = 19;
			this->infohealthpercent->Text = L"100";
			// 
			// infopercent
			// 
			this->infopercent->AutoSize = true;
			this->infopercent->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->infopercent->Location = System::Drawing::Point(101, 56);
			this->infopercent->Name = L"infopercent";
			this->infopercent->Size = System::Drawing::Size(23, 17);
			this->infopercent->TabIndex = 18;
			this->infopercent->Text = L"%";
			// 
			// infohealth
			// 
			this->infohealth->AutoSize = true;
			this->infohealth->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->infohealth->Location = System::Drawing::Point(-3, 56);
			this->infohealth->Name = L"infohealth";
			this->infohealth->Size = System::Drawing::Size(72, 17);
			this->infohealth->TabIndex = 2;
			this->infohealth->Text = L"��������";
			// 
			// infobalance
			// 
			this->infobalance->AutoSize = true;
			this->infobalance->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->infobalance->Location = System::Drawing::Point(-3, 17);
			this->infobalance->Name = L"infobalance";
			this->infobalance->Size = System::Drawing::Size(56, 17);
			this->infobalance->TabIndex = 2;
			this->infobalance->Text = L"������";
			// 
			// infoname
			// 
			this->infoname->AutoSize = true;
			this->infoname->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->infoname->Location = System::Drawing::Point(-3, 0);
			this->infoname->Name = L"infoname";
			this->infoname->Size = System::Drawing::Size(38, 17);
			this->infoname->TabIndex = 1;
			this->infoname->Text = L"���";
			// 
			// picturebox
			// 
			this->picturebox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picturebox.Image")));
			this->picturebox->Location = System::Drawing::Point(130, 0);
			this->picturebox->Name = L"picturebox";
			this->picturebox->Size = System::Drawing::Size(64, 75);
			this->picturebox->TabIndex = 0;
			this->picturebox->TabStop = false;
			// 
			// groupBoxhuman
			// 
			this->groupBoxhuman->BackColor = System::Drawing::Color::NavajoWhite;
			this->groupBoxhuman->Controls->Add(this->humanbalance);
			this->groupBoxhuman->Controls->Add(this->labelhumanbalance);
			this->groupBoxhuman->Controls->Add(this->humanage);
			this->groupBoxhuman->Controls->Add(this->labelhumanage);
			this->groupBoxhuman->Controls->Add(this->humansex);
			this->groupBoxhuman->Controls->Add(this->labelhumansex);
			this->groupBoxhuman->Controls->Add(this->humanname);
			this->groupBoxhuman->Controls->Add(this->labelhumanname);
			this->groupBoxhuman->Controls->Add(this->labelmyhuman);
			this->groupBoxhuman->Location = System::Drawing::Point(241, 82);
			this->groupBoxhuman->Name = L"groupBoxhuman";
			this->groupBoxhuman->Size = System::Drawing::Size(259, 361);
			this->groupBoxhuman->TabIndex = 3;
			this->groupBoxhuman->TabStop = false;
			this->groupBoxhuman->Visible = false;
			// 
			// humanbalance
			// 
			this->humanbalance->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->humanbalance->AutoSize = true;
			this->humanbalance->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->humanbalance->Location = System::Drawing::Point(107, 172);
			this->humanbalance->Name = L"humanbalance";
			this->humanbalance->Size = System::Drawing::Size(74, 17);
			this->humanbalance->TabIndex = 10;
			this->humanbalance->Text = L"������";
			this->humanbalance->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelhumanbalance
			// 
			this->labelhumanbalance->AutoSize = true;
			this->labelhumanbalance->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelhumanbalance->Location = System::Drawing::Point(6, 172);
			this->labelhumanbalance->Name = L"labelhumanbalance";
			this->labelhumanbalance->Size = System::Drawing::Size(56, 17);
			this->labelhumanbalance->TabIndex = 9;
			this->labelhumanbalance->Text = L"������";
			// 
			// humanage
			// 
			this->humanage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->humanage->AutoSize = true;
			this->humanage->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->humanage->Location = System::Drawing::Point(107, 135);
			this->humanage->Name = L"humanage";
			this->humanage->Size = System::Drawing::Size(39, 17);
			this->humanage->TabIndex = 8;
			this->humanage->Text = L"���";
			this->humanage->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelhumanage
			// 
			this->labelhumanage->AutoSize = true;
			this->labelhumanage->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelhumanage->Location = System::Drawing::Point(6, 135);
			this->labelhumanage->Name = L"labelhumanage";
			this->labelhumanage->Size = System::Drawing::Size(63, 17);
			this->labelhumanage->TabIndex = 7;
			this->labelhumanage->Text = L"�������";
			// 
			// humansex
			// 
			this->humansex->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->humansex->AutoSize = true;
			this->humansex->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->humansex->Location = System::Drawing::Point(107, 99);
			this->humansex->Name = L"humansex";
			this->humansex->Size = System::Drawing::Size(42, 17);
			this->humansex->TabIndex = 6;
			this->humansex->Text = L"���";
			this->humansex->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelhumansex
			// 
			this->labelhumansex->AutoSize = true;
			this->labelhumansex->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelhumansex->Location = System::Drawing::Point(6, 99);
			this->labelhumansex->Name = L"labelhumansex";
			this->labelhumansex->Size = System::Drawing::Size(36, 17);
			this->labelhumansex->TabIndex = 5;
			this->labelhumansex->Text = L"���";
			// 
			// humanname
			// 
			this->humanname->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->humanname->AutoSize = true;
			this->humanname->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->humanname->Location = System::Drawing::Point(107, 61);
			this->humanname->Name = L"humanname";
			this->humanname->Size = System::Drawing::Size(46, 17);
			this->humanname->TabIndex = 4;
			this->humanname->Text = L"���";
			this->humanname->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelhumanname
			// 
			this->labelhumanname->AutoSize = true;
			this->labelhumanname->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelhumanname->Location = System::Drawing::Point(6, 61);
			this->labelhumanname->Name = L"labelhumanname";
			this->labelhumanname->Size = System::Drawing::Size(38, 17);
			this->labelhumanname->TabIndex = 3;
			this->labelhumanname->Text = L"���";
			// 
			// labelmyhuman
			// 
			this->labelmyhuman->AutoSize = true;
			this->labelmyhuman->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelmyhuman->Location = System::Drawing::Point(63, 16);
			this->labelmyhuman->Name = L"labelmyhuman";
			this->labelmyhuman->Size = System::Drawing::Size(137, 22);
			this->labelmyhuman->TabIndex = 2;
			this->labelmyhuman->Text = L"��� ��������";
			// 
			// groupBoxworker
			// 
			this->groupBoxworker->BackColor = System::Drawing::Color::NavajoWhite;
			this->groupBoxworker->Controls->Add(this->workingbutton);
			this->groupBoxworker->Controls->Add(this->payment);
			this->groupBoxworker->Controls->Add(this->labelpayment);
			this->groupBoxworker->Controls->Add(this->Namework);
			this->groupBoxworker->Controls->Add(this->labelNamework);
			this->groupBoxworker->Controls->Add(this->workername);
			this->groupBoxworker->Controls->Add(this->labelworkerhumanname);
			this->groupBoxworker->Controls->Add(this->labelworker);
			this->groupBoxworker->Location = System::Drawing::Point(241, 82);
			this->groupBoxworker->Name = L"groupBoxworker";
			this->groupBoxworker->Size = System::Drawing::Size(259, 361);
			this->groupBoxworker->TabIndex = 11;
			this->groupBoxworker->TabStop = false;
			this->groupBoxworker->Visible = false;
			// 
			// workingbutton
			// 
			this->workingbutton->BackColor = System::Drawing::Color::Goldenrod;
			this->workingbutton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->workingbutton->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->workingbutton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->workingbutton->Location = System::Drawing::Point(76, 275);
			this->workingbutton->Name = L"workingbutton";
			this->workingbutton->Size = System::Drawing::Size(107, 52);
			this->workingbutton->TabIndex = 12;
			this->workingbutton->Text = L"��������";
			this->workingbutton->UseVisualStyleBackColor = false;
			this->workingbutton->Click += gcnew System::EventHandler(this, &Game::workingbutton_Click);
			// 
			// payment
			// 
			this->payment->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->payment->AutoSize = true;
			this->payment->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->payment->Location = System::Drawing::Point(107, 135);
			this->payment->Name = L"payment";
			this->payment->Size = System::Drawing::Size(73, 17);
			this->payment->TabIndex = 8;
			this->payment->Text = L"������";
			this->payment->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelpayment
			// 
			this->labelpayment->AutoSize = true;
			this->labelpayment->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelpayment->Location = System::Drawing::Point(6, 135);
			this->labelpayment->Name = L"labelpayment";
			this->labelpayment->Size = System::Drawing::Size(59, 17);
			this->labelpayment->TabIndex = 7;
			this->labelpayment->Text = L"������";
			// 
			// Namework
			// 
			this->Namework->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Namework->AutoSize = true;
			this->Namework->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Namework->Location = System::Drawing::Point(107, 99);
			this->Namework->Name = L"Namework";
			this->Namework->Size = System::Drawing::Size(68, 17);
			this->Namework->TabIndex = 6;
			this->Namework->Text = L"������";
			this->Namework->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelNamework
			// 
			this->labelNamework->AutoSize = true;
			this->labelNamework->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelNamework->Location = System::Drawing::Point(6, 99);
			this->labelNamework->Name = L"labelNamework";
			this->labelNamework->Size = System::Drawing::Size(55, 17);
			this->labelNamework->TabIndex = 5;
			this->labelNamework->Text = L"������";
			// 
			// workername
			// 
			this->workername->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->workername->AutoSize = true;
			this->workername->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->workername->Location = System::Drawing::Point(107, 61);
			this->workername->Name = L"workername";
			this->workername->Size = System::Drawing::Size(46, 17);
			this->workername->TabIndex = 4;
			this->workername->Text = L"���";
			this->workername->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelworkerhumanname
			// 
			this->labelworkerhumanname->AutoSize = true;
			this->labelworkerhumanname->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelworkerhumanname->Location = System::Drawing::Point(6, 61);
			this->labelworkerhumanname->Name = L"labelworkerhumanname";
			this->labelworkerhumanname->Size = System::Drawing::Size(38, 17);
			this->labelworkerhumanname->TabIndex = 3;
			this->labelworkerhumanname->Text = L"���";
			// 
			// labelworker
			// 
			this->labelworker->AutoSize = true;
			this->labelworker->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelworker->Location = System::Drawing::Point(46, 16);
			this->labelworker->Name = L"labelworker";
			this->labelworker->Size = System::Drawing::Size(170, 22);
			this->labelworker->TabIndex = 2;
			this->labelworker->Text = L"������� ��������";
			// 
			// groupBoxmd
			// 
			this->groupBoxmd->BackColor = System::Drawing::Color::NavajoWhite;
			this->groupBoxmd->Controls->Add(this->imtcomment);
			this->groupBoxmd->Controls->Add(this->labelmdpercent);
			this->groupBoxmd->Controls->Add(this->health);
			this->groupBoxmd->Controls->Add(this->labelhealth);
			this->groupBoxmd->Controls->Add(this->imt);
			this->groupBoxmd->Controls->Add(this->labelimt);
			this->groupBoxmd->Controls->Add(this->healthbutton);
			this->groupBoxmd->Controls->Add(this->mdheight);
			this->groupBoxmd->Controls->Add(this->labelmdheight);
			this->groupBoxmd->Controls->Add(this->mdweight);
			this->groupBoxmd->Controls->Add(this->labelmdweight);
			this->groupBoxmd->Controls->Add(this->mdname);
			this->groupBoxmd->Controls->Add(this->labelmdname);
			this->groupBoxmd->Controls->Add(this->labelmedicalcard);
			this->groupBoxmd->Location = System::Drawing::Point(241, 82);
			this->groupBoxmd->Name = L"groupBoxmd";
			this->groupBoxmd->Size = System::Drawing::Size(259, 361);
			this->groupBoxmd->TabIndex = 12;
			this->groupBoxmd->TabStop = false;
			this->groupBoxmd->Visible = false;
			// 
			// labelmdpercent
			// 
			this->labelmdpercent->AutoSize = true;
			this->labelmdpercent->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelmdpercent->Location = System::Drawing::Point(136, 221);
			this->labelmdpercent->Name = L"labelmdpercent";
			this->labelmdpercent->Size = System::Drawing::Size(23, 17);
			this->labelmdpercent->TabIndex = 17;
			this->labelmdpercent->Text = L"%";
			// 
			// health
			// 
			this->health->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->health->AutoSize = true;
			this->health->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->health->Location = System::Drawing::Point(107, 221);
			this->health->Name = L"health";
			this->health->Size = System::Drawing::Size(32, 17);
			this->health->TabIndex = 16;
			this->health->Text = L"100";
			this->health->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelhealth
			// 
			this->labelhealth->AutoSize = true;
			this->labelhealth->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelhealth->Location = System::Drawing::Point(6, 221);
			this->labelhealth->Name = L"labelhealth";
			this->labelhealth->Size = System::Drawing::Size(72, 17);
			this->labelhealth->TabIndex = 15;
			this->labelhealth->Text = L"��������";
			// 
			// imt
			// 
			this->imt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->imt->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->imt->Location = System::Drawing::Point(107, 177);
			this->imt->Name = L"imt";
			this->imt->Size = System::Drawing::Size(45, 17);
			this->imt->TabIndex = 14;
			this->imt->Text = L"���";
			this->imt->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelimt
			// 
			this->labelimt->AutoSize = true;
			this->labelimt->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelimt->Location = System::Drawing::Point(6, 177);
			this->labelimt->Name = L"labelimt";
			this->labelimt->Size = System::Drawing::Size(45, 17);
			this->labelimt->TabIndex = 13;
			this->labelimt->Text = L"���";
			// 
			// healthbutton
			// 
			this->healthbutton->BackColor = System::Drawing::Color::Goldenrod;
			this->healthbutton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->healthbutton->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->healthbutton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->healthbutton->Location = System::Drawing::Point(65, 275);
			this->healthbutton->Name = L"healthbutton";
			this->healthbutton->Size = System::Drawing::Size(124, 52);
			this->healthbutton->TabIndex = 12;
			this->healthbutton->Text = L"��������(10$)";
			this->healthbutton->UseVisualStyleBackColor = false;
			this->healthbutton->Click += gcnew System::EventHandler(this, &Game::healthbutton_Click);
			// 
			// mdheight
			// 
			this->mdheight->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->mdheight->AutoSize = true;
			this->mdheight->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->mdheight->Location = System::Drawing::Point(107, 135);
			this->mdheight->Name = L"mdheight";
			this->mdheight->Size = System::Drawing::Size(50, 17);
			this->mdheight->TabIndex = 8;
			this->mdheight->Text = L"����";
			this->mdheight->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelmdheight
			// 
			this->labelmdheight->AutoSize = true;
			this->labelmdheight->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelmdheight->Location = System::Drawing::Point(6, 135);
			this->labelmdheight->Name = L"labelmdheight";
			this->labelmdheight->Size = System::Drawing::Size(40, 17);
			this->labelmdheight->TabIndex = 7;
			this->labelmdheight->Text = L"����";
			// 
			// mdweight
			// 
			this->mdweight->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->mdweight->AutoSize = true;
			this->mdweight->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->mdweight->Location = System::Drawing::Point(107, 99);
			this->mdweight->Name = L"mdweight";
			this->mdweight->Size = System::Drawing::Size(40, 17);
			this->mdweight->TabIndex = 6;
			this->mdweight->Text = L"���";
			this->mdweight->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelmdweight
			// 
			this->labelmdweight->AutoSize = true;
			this->labelmdweight->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelmdweight->Location = System::Drawing::Point(6, 99);
			this->labelmdweight->Name = L"labelmdweight";
			this->labelmdweight->Size = System::Drawing::Size(34, 17);
			this->labelmdweight->TabIndex = 5;
			this->labelmdweight->Text = L"���";
			// 
			// mdname
			// 
			this->mdname->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->mdname->AutoSize = true;
			this->mdname->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->mdname->Location = System::Drawing::Point(107, 61);
			this->mdname->Name = L"mdname";
			this->mdname->Size = System::Drawing::Size(46, 17);
			this->mdname->TabIndex = 4;
			this->mdname->Text = L"���";
			this->mdname->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelmdname
			// 
			this->labelmdname->AutoSize = true;
			this->labelmdname->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelmdname->Location = System::Drawing::Point(6, 61);
			this->labelmdname->Name = L"labelmdname";
			this->labelmdname->Size = System::Drawing::Size(38, 17);
			this->labelmdname->TabIndex = 3;
			this->labelmdname->Text = L"���";
			// 
			// labelmedicalcard
			// 
			this->labelmedicalcard->AutoSize = true;
			this->labelmedicalcard->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelmedicalcard->Location = System::Drawing::Point(33, 16);
			this->labelmedicalcard->Name = L"labelmedicalcard";
			this->labelmedicalcard->Size = System::Drawing::Size(186, 22);
			this->labelmedicalcard->TabIndex = 2;
			this->labelmedicalcard->Text = L"����������� �����";
			// 
			// groupBoxclothes
			// 
			this->groupBoxclothes->BackColor = System::Drawing::Color::NavajoWhite;
			this->groupBoxclothes->Controls->Add(this->buysuitbutton);
			this->groupBoxclothes->Controls->Add(this->dataGridViewclothes);
			this->groupBoxclothes->Controls->Add(this->buttonsewup);
			this->groupBoxclothes->Controls->Add(this->labelclothes);
			this->groupBoxclothes->Location = System::Drawing::Point(241, 82);
			this->groupBoxclothes->Name = L"groupBoxclothes";
			this->groupBoxclothes->Size = System::Drawing::Size(259, 361);
			this->groupBoxclothes->TabIndex = 13;
			this->groupBoxclothes->TabStop = false;
			this->groupBoxclothes->Visible = false;
			// 
			// buysuitbutton
			// 
			this->buysuitbutton->BackColor = System::Drawing::Color::Goldenrod;
			this->buysuitbutton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buysuitbutton->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buysuitbutton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->buysuitbutton->Location = System::Drawing::Point(55, 226);
			this->buysuitbutton->Name = L"buysuitbutton";
			this->buysuitbutton->Size = System::Drawing::Size(145, 43);
			this->buysuitbutton->TabIndex = 14;
			this->buysuitbutton->Text = L"������ ������(1000$)";
			this->buysuitbutton->UseVisualStyleBackColor = false;
			this->buysuitbutton->Click += gcnew System::EventHandler(this, &Game::buysuitbutton_Click);
			// 
			// dataGridViewclothes
			// 
			this->dataGridViewclothes->AllowUserToAddRows = false;
			this->dataGridViewclothes->AllowUserToDeleteRows = false;
			this->dataGridViewclothes->AllowUserToResizeColumns = false;
			this->dataGridViewclothes->AllowUserToResizeRows = false;
			this->dataGridViewclothes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewclothes->BackgroundColor = System::Drawing::Color::NavajoWhite;
			this->dataGridViewclothes->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle5->BackColor = System::Drawing::Color::Cornsilk;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewclothes->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle5;
			this->dataGridViewclothes->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewclothes->ColumnHeadersVisible = false;
			this->dataGridViewclothes->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->parametr,
					this->cloth
			});
			dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle8->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle8->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle8->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle8->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle8->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewclothes->DefaultCellStyle = dataGridViewCellStyle8;
			this->dataGridViewclothes->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->dataGridViewclothes->Location = System::Drawing::Point(6, 83);
			this->dataGridViewclothes->Name = L"dataGridViewclothes";
			this->dataGridViewclothes->ReadOnly = true;
			this->dataGridViewclothes->RowHeadersVisible = false;
			this->dataGridViewclothes->Size = System::Drawing::Size(247, 137);
			this->dataGridViewclothes->TabIndex = 13;
			// 
			// parametr
			// 
			dataGridViewCellStyle6->BackColor = System::Drawing::Color::White;
			this->parametr->DefaultCellStyle = dataGridViewCellStyle6;
			this->parametr->Frozen = true;
			this->parametr->HeaderText = L"��������";
			this->parametr->MaxInputLength = 30;
			this->parametr->Name = L"parametr";
			this->parametr->ReadOnly = true;
			this->parametr->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->parametr->Width = 124;
			// 
			// cloth
			// 
			dataGridViewCellStyle7->BackColor = System::Drawing::Color::White;
			this->cloth->DefaultCellStyle = dataGridViewCellStyle7;
			this->cloth->Frozen = true;
			this->cloth->HeaderText = L"������";
			this->cloth->MaxInputLength = 30;
			this->cloth->Name = L"cloth";
			this->cloth->ReadOnly = true;
			this->cloth->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->cloth->Width = 124;
			// 
			// buttonsewup
			// 
			this->buttonsewup->BackColor = System::Drawing::Color::Goldenrod;
			this->buttonsewup->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonsewup->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonsewup->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->buttonsewup->Location = System::Drawing::Point(65, 275);
			this->buttonsewup->Name = L"buttonsewup";
			this->buttonsewup->Size = System::Drawing::Size(124, 52);
			this->buttonsewup->TabIndex = 12;
			this->buttonsewup->Text = L"�������� ������(5$)";
			this->buttonsewup->UseVisualStyleBackColor = false;
			this->buttonsewup->Click += gcnew System::EventHandler(this, &Game::buttonsewup_Click);
			// 
			// labelclothes
			// 
			this->labelclothes->AutoSize = true;
			this->labelclothes->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelclothes->Location = System::Drawing::Point(95, 16);
			this->labelclothes->Name = L"labelclothes";
			this->labelclothes->Size = System::Drawing::Size(77, 22);
			this->labelclothes->TabIndex = 2;
			this->labelclothes->Text = L"������";
			// 
			// groupBoxrealty
			// 
			this->groupBoxrealty->BackColor = System::Drawing::Color::NavajoWhite;
			this->groupBoxrealty->Controls->Add(this->comboBoxrealtycar);
			this->groupBoxrealty->Controls->Add(this->checkBoxcar);
			this->groupBoxrealty->Controls->Add(this->checkBoxhouse);
			this->groupBoxrealty->Controls->Add(this->comboBoxrealtyhouse);
			this->groupBoxrealty->Controls->Add(this->buybutton);
			this->groupBoxrealty->Controls->Add(this->labelrealtybuy);
			this->groupBoxrealty->Controls->Add(this->realtycar);
			this->groupBoxrealty->Controls->Add(this->labelrealtycar);
			this->groupBoxrealty->Controls->Add(this->realtyhouse);
			this->groupBoxrealty->Controls->Add(this->labelrealtyhouse);
			this->groupBoxrealty->Controls->Add(this->labelrealty);
			this->groupBoxrealty->Location = System::Drawing::Point(241, 82);
			this->groupBoxrealty->Name = L"groupBoxrealty";
			this->groupBoxrealty->Size = System::Drawing::Size(259, 361);
			this->groupBoxrealty->TabIndex = 12;
			this->groupBoxrealty->TabStop = false;
			this->groupBoxrealty->Visible = false;
			// 
			// comboBoxrealtycar
			// 
			this->comboBoxrealtycar->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxrealtycar->FormattingEnabled = true;
			this->comboBoxrealtycar->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"��������(200 000)", L"����������(600 000)",
					L"�����(9 000 000)"
			});
			this->comboBoxrealtycar->Location = System::Drawing::Point(18, 226);
			this->comboBoxrealtycar->Name = L"comboBoxrealtycar";
			this->comboBoxrealtycar->Size = System::Drawing::Size(222, 21);
			this->comboBoxrealtycar->TabIndex = 16;
			this->comboBoxrealtycar->Visible = false;
			// 
			// checkBoxcar
			// 
			this->checkBoxcar->AutoSize = true;
			this->checkBoxcar->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBoxcar->Location = System::Drawing::Point(149, 172);
			this->checkBoxcar->Name = L"checkBoxcar";
			this->checkBoxcar->Size = System::Drawing::Size(91, 21);
			this->checkBoxcar->TabIndex = 15;
			this->checkBoxcar->Text = L"���������";
			this->checkBoxcar->UseVisualStyleBackColor = true;
			this->checkBoxcar->CheckedChanged += gcnew System::EventHandler(this, &Game::checkBoxcar_CheckedChanged);
			// 
			// checkBoxhouse
			// 
			this->checkBoxhouse->AutoSize = true;
			this->checkBoxhouse->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBoxhouse->Location = System::Drawing::Point(18, 172);
			this->checkBoxhouse->Name = L"checkBoxhouse";
			this->checkBoxhouse->Size = System::Drawing::Size(68, 21);
			this->checkBoxhouse->TabIndex = 14;
			this->checkBoxhouse->Text = L"�����";
			this->checkBoxhouse->UseVisualStyleBackColor = true;
			this->checkBoxhouse->CheckedChanged += gcnew System::EventHandler(this, &Game::checkBoxhouse_CheckedChanged);
			// 
			// comboBoxrealtyhouse
			// 
			this->comboBoxrealtyhouse->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxrealtyhouse->FormattingEnabled = true;
			this->comboBoxrealtyhouse->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"��������(3 000 000)", L"�������(7 000 000)",
					L"�����(20 000 000)"
			});
			this->comboBoxrealtyhouse->Location = System::Drawing::Point(18, 226);
			this->comboBoxrealtyhouse->Name = L"comboBoxrealtyhouse";
			this->comboBoxrealtyhouse->Size = System::Drawing::Size(222, 21);
			this->comboBoxrealtyhouse->TabIndex = 13;
			this->comboBoxrealtyhouse->Visible = false;
			// 
			// buybutton
			// 
			this->buybutton->BackColor = System::Drawing::Color::Goldenrod;
			this->buybutton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buybutton->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buybutton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->buybutton->Location = System::Drawing::Point(66, 284);
			this->buybutton->Name = L"buybutton";
			this->buybutton->Size = System::Drawing::Size(124, 52);
			this->buybutton->TabIndex = 12;
			this->buybutton->Text = L"������";
			this->buybutton->UseVisualStyleBackColor = false;
			this->buybutton->Visible = false;
			this->buybutton->Click += gcnew System::EventHandler(this, &Game::buybutton_Click);
			// 
			// labelrealtybuy
			// 
			this->labelrealtybuy->AutoSize = true;
			this->labelrealtybuy->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelrealtybuy->Location = System::Drawing::Point(77, 142);
			this->labelrealtybuy->Name = L"labelrealtybuy";
			this->labelrealtybuy->Size = System::Drawing::Size(105, 17);
			this->labelrealtybuy->TabIndex = 7;
			this->labelrealtybuy->Text = L"������ �����";
			// 
			// realtycar
			// 
			this->realtycar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->realtycar->AutoSize = true;
			this->realtycar->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->realtycar->Location = System::Drawing::Point(107, 99);
			this->realtycar->Name = L"realtycar";
			this->realtycar->Size = System::Drawing::Size(122, 17);
			this->realtycar->TabIndex = 6;
			this->realtycar->Text = L"����������";
			this->realtycar->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelrealtycar
			// 
			this->labelrealtycar->AutoSize = true;
			this->labelrealtycar->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelrealtycar->Location = System::Drawing::Point(6, 99);
			this->labelrealtycar->Name = L"labelrealtycar";
			this->labelrealtycar->Size = System::Drawing::Size(81, 17);
			this->labelrealtycar->TabIndex = 5;
			this->labelrealtycar->Text = L"���������";
			// 
			// realtyhouse
			// 
			this->realtyhouse->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->realtyhouse->AutoSize = true;
			this->realtyhouse->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->realtyhouse->Location = System::Drawing::Point(107, 61);
			this->realtyhouse->Name = L"realtyhouse";
			this->realtyhouse->Size = System::Drawing::Size(65, 17);
			this->realtyhouse->TabIndex = 4;
			this->realtyhouse->Text = L"���ܨ";
			this->realtyhouse->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelrealtyhouse
			// 
			this->labelrealtyhouse->AutoSize = true;
			this->labelrealtyhouse->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelrealtyhouse->Location = System::Drawing::Point(6, 61);
			this->labelrealtyhouse->Name = L"labelrealtyhouse";
			this->labelrealtyhouse->Size = System::Drawing::Size(55, 17);
			this->labelrealtyhouse->TabIndex = 3;
			this->labelrealtyhouse->Text = L"�����";
			// 
			// labelrealty
			// 
			this->labelrealty->AutoSize = true;
			this->labelrealty->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelrealty->Location = System::Drawing::Point(72, 16);
			this->labelrealty->Name = L"labelrealty";
			this->labelrealty->Size = System::Drawing::Size(108, 22);
			this->labelrealty->TabIndex = 2;
			this->labelrealty->Text = L"���������";
			// 
			// imtcomment
			// 
			this->imtcomment->AutoSize = true;
			this->imtcomment->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->imtcomment->Location = System::Drawing::Point(155, 177);
			this->imtcomment->Name = L"imtcomment";
			this->imtcomment->Size = System::Drawing::Size(53, 17);
			this->imtcomment->TabIndex = 18;
			this->imtcomment->Text = L"�����";
			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(755, 525);
			this->Controls->Add(this->groupBoxclothes);
			this->Controls->Add(this->groupBoxmd);
			this->Controls->Add(this->groupBoxrealty);
			this->Controls->Add(this->groupBoxworker);
			this->Controls->Add(this->groupBoxhuman);
			this->Controls->Add(this->Infobox);
			this->Controls->Add(this->menu);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menu;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(771, 564);
			this->MinimumSize = System::Drawing::Size(771, 564);
			this->Name = L"Game";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"������� ����";
			this->TopMost = true;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Game::Game_FormClosing);
			this->menu->ResumeLayout(false);
			this->menu->PerformLayout();
			this->Infobox->ResumeLayout(false);
			this->Infobox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox))->EndInit();
			this->groupBoxhuman->ResumeLayout(false);
			this->groupBoxhuman->PerformLayout();
			this->groupBoxworker->ResumeLayout(false);
			this->groupBoxworker->PerformLayout();
			this->groupBoxmd->ResumeLayout(false);
			this->groupBoxmd->PerformLayout();
			this->groupBoxclothes->ResumeLayout(false);
			this->groupBoxclothes->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewclothes))->EndInit();
			this->groupBoxrealty->ResumeLayout(false);
			this->groupBoxrealty->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBoxhouse_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBoxcar_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Game_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void buysuitbutton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonsewup_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void workingbutton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void healthbutton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buybutton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DataInitialization();
	};
}
