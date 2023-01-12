#pragma once
using System::String;
using System::Int32;

//Класс "Имущество"
ref class Realty
{
private:
	String^ Housing; //Недвижимость
	String^ Vehicle; //Транспортное средство

public:
	Realty(); //Конструктор без параметров
	String^ GetHousing(); //Геттер недвижимости
	void SetHousing(String^ housing); //Сеттер недвижимости
	String^ GetVehicle(); //Геттер транспортного средства
	void SetVehicle(String^ vehicle); //Сеттер транспортного средства
};

