#pragma once
#include "Clothes.h"
#include "MedicalCard.h"
#include "Realty.h"
#include "FoodEating.h"
using System::String;
using System::Int32;

//Класс "Человек"
ref class Human
{
protected:
	Int32 Age; //Возраст
	Int32 Moneybalance; //Баланс
	String^ Name; //Имя
	String^ Sex; //Пол
	Int32 Level; //Уровень
	MedicalCard^ MedCard; //Медицинская карта человека
	Realty^ realty; //Имущество человека
	Clothes^ clothes; //Одежда человека
	FoodEating^ food; //Питание человека

public:
	Human(); //Конструктор без параметров
	Int32 GetAge(); //Геттер возраста
	void SetAge(Int32 age); //Сеттер возраста
	Int32 GetMoneybalance(); //Геттер баланса
	void SetMoneyBalance(Int32 moneybalance); //Сеттер баланса
	String^ GetName(); //Геттер имени
	void SetName(String^ name); //Сеттер имени
	String^ GetSex(); //Геттер пола
	void SetSex(String^ sex); //Сеттер пола
	Int32 GetLevel(); //Геттер уровня
	void SetLevel(Int32 level); //Сеттер уровня
	void LevelUp(); //Метод "Повышение уровня"
	void ChangeMoney(Int32 money); //Метод "Изменить баланс денег"
	MedicalCard^ GetMedCard(); //Геттер медицинской карты
	Realty^ GetRealty(); //Геттер имущества
	Clothes^ GetClothes(); //Геттер одежды
	FoodEating^ GetFood(); //Геттер питания
};

