#pragma once
using System::Int32;

//Класс "Медицинская карта"
ref class MedicalCard
{
private:
	bool InfinityHealth; //Показатель бесконечного здоровья (автолечения)
	Int32 Weight; //Вес
	Int32 Height; //Рост
	Int32 HealthStatus; //Статус здоровья (0-100)

public:
	MedicalCard(); //Конструктор без параметров
	Int32 GetWeight(); //Геттер веса
	void SetWeight(Int32 weight); //Сеттер веса
	Int32 GetHeight(); //Геттер роста
	void SetHeight(Int32 height); //Сеттер роста
	Int32 GetHealthStatus(); //Геттер статуса здоровья
	void SetHealthStatus(Int32 status); //Сеттер статуса здоровья
	void DownStatus(); //Метод "Уменьшить статус здоровья"
	void UpStatus(); //Метод "Поднять статус здоровья"
	bool GetInfinityHealth(); //Геттер показателя бесконечного здоровья (автолечения)
	void SetInfinityHealth(bool argument); //Сеттер показателя бесконечного здоровья (автолечения)
};

