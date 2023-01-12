#pragma once
using System::String;
using System::Int32;

//����� "������"
ref class Clothes
{
private:
	bool AutoSewUp; //���������� ����������� ������
	String^ Body; //���� ������
	String^ Pants; //�����
	String^ Shoes; //�����
	Int32 ClothesStatus; //������ ����������� ������ (0-100)

public:
	Clothes(); //����������� ��� ����������
	String^ GetBody(); //������ ����� ������
	void SetBody(String^ body); //������ ����� ������
	String^ GetPants(); //������ ������
	void SetPants(String^ pants); //������ ������
	String^ GetShoes(); //������ �����
	void SetShoes(String^ shoes); //������ �����
	Int32 GetClothesStatus(); //������ ������� ����������� ������
	void SetClothesStatus(Int32 status); //������ ����������� ������
	void SewUpClothes(); //����� "������� ������"
	void TearClothes(); //����� "������� ������"
	void BuySuit(); //����� "������ ������"
	void SetRegularClothes(); //������ ����������� ������
	bool GetAutoSewUp(); //������ ���������� ����������� ������
	void SetAutoSewUp(bool argument); //������ ���������� ����������� ������
};

