#pragma once
using System::Int32;

//Класс "Питание"
ref class FoodEating
{
private:
	bool AutoEating; //Показатель автоматического питания
	Int32 SatietyStatus; //Статус сытости (0-100)

public:
	FoodEating(); //Конструктор без параметров
	bool GetAutoEating(); //Геттер показателя автоматического питания
	void SetAutoEating(bool argument); //Сеттер показателя автоматического питания
	Int32 GetSatietyStatus(); //Геттер статуса сытости
	void SetSatietyStatus(Int32 argument); //Сеттер статуса сытости
	void UpSatietyStatus(Int32 argument); //Метод "Поднять статус сытости"
	void DownSatietyStatus(); //Метод "Уменьшить статус сытости"
};

