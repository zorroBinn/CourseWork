#pragma once
using System::Int32;

//����� "�������"
ref class FoodEating
{
private:
	bool AutoEating; //���������� ��������������� �������
	Int32 SatietyStatus; //������ ������� (0-100)

public:
	FoodEating(); //����������� ��� ����������
	bool GetAutoEating(); //������ ���������� ��������������� �������
	void SetAutoEating(bool argument); //������ ���������� ��������������� �������
	Int32 GetSatietyStatus(); //������ ������� �������
	void SetSatietyStatus(Int32 argument); //������ ������� �������
	void UpSatietyStatus(Int32 argument); //����� "������� ������ �������"
	void DownSatietyStatus(); //����� "��������� ������ �������"
};

