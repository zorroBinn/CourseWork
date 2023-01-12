#pragma once
using System::String;
using System::Int32;

//Класс "Одежда"
ref class Clothes
{
private:
	bool AutoSewUp; //Показатель автопочинки одежды
	String^ Body; //Верх одежды
	String^ Pants; //Штаны
	String^ Shoes; //Обувь
	Int32 ClothesStatus; //Статус целостности одежды (0-100)

public:
	Clothes(); //Конструктор без параметров
	String^ GetBody(); //Геттер верха одежды
	void SetBody(String^ body); //Сеттер верха одежды
	String^ GetPants(); //Геттер штанов
	void SetPants(String^ pants); //Сеттер штанов
	String^ GetShoes(); //Геттер обуви
	void SetShoes(String^ shoes); //Сеттер обуви
	Int32 GetClothesStatus(); //Геттер статуса целостности одежды
	void SetClothesStatus(Int32 status); //Сеттер целостности одежды
	void SewUpClothes(); //Метод "Починка одежды"
	void TearClothes(); //Метод "Порвать одежду"
	void BuySuit(); //Метод "Купить костюм"
	void SetRegularClothes(); //Сеттер стандартной одежды
	bool GetAutoSewUp(); //Геттер показателя автопочинки одежды
	void SetAutoSewUp(bool argument); //Сеттер показателя автопочинки одежды
};

