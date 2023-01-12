#pragma once
#include "Human.h"
using System::String;
using System::Int32;

//Класс "Работник" - наследуется от класса "Человек"
ref class Worker : public Human 
{
private:
	String^ Namework; //Наименование работы
	Int32 Payment; //Оплата

public:
	Worker(); //Конструктор без параметров
	Int32 GetPayment(); //Геттер оплаты
	void SetPayment(Int32 payment); //Сеттер оплаты
	String^ GetNamework(); //Геттер наименования работы
	void SetNamework(String^ namework); //Сеттер наименования работы
};

