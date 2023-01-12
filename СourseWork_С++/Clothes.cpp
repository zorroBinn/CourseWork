#include "Clothes.h"

//Конструктор без параметров
Clothes::Clothes()
{
    SetRegularClothes();
    this->AutoSewUp = false;
}

//Геттер верха одежды
String^ Clothes::GetBody()
{
    return this->Body;
}

//Сеттер верха одежды
void Clothes::SetBody(String^ body)
{
    this->Body = body;
}

//Геттер штанов
String^ Clothes::GetPants()
{
    return this->Pants;
}

//Сеттер штанов
void Clothes::SetPants(String^ pants)
{
    this->Pants = pants;
}

//Геттер обуви
String^ Clothes::GetShoes()
{
    return this->Shoes;
}

//Сеттер обуви
void Clothes::SetShoes(String^ shoes)
{
    this->Shoes = shoes;
}

//Геттер статуса целостности одежды
Int32 Clothes::GetClothesStatus()
{
    return this->ClothesStatus;
}

//Сеттер целостности одежды
void Clothes::SetClothesStatus(Int32 status)
{
    this->ClothesStatus = status;
}

//Метод "Починка одежды"
void Clothes::SewUpClothes()
{
    if (this->ClothesStatus < 100) {
        this->ClothesStatus += 20;
        if (this->ClothesStatus > 100) {
            this->ClothesStatus = 100;
        }
    }
}

//Метод "Порвать одежду"
void Clothes::TearClothes()
{
    if (this->Pants != "Брюки") {
        this->ClothesStatus -= 5;
    }
    else {
        this->ClothesStatus -= 3;
    }
    if (this->ClothesStatus < 0) {
        this->ClothesStatus = 0;
    }
}

//Метод "Купить костюм"
void Clothes::BuySuit()
{
    this->Body = "Пиджак";
    this->Pants = "Брюки";
    this->Shoes = "Туфли";
    this->ClothesStatus = 100;
}

//Сеттер стандартной одежды
void Clothes::SetRegularClothes()
{
    this->Body = "Кофта";
    this->Pants = "Джинсы";
    this->Shoes = "Кроссовки";
    this->ClothesStatus = 100;
}

//Геттер показателя автопочинки одежды
bool Clothes::GetAutoSewUp()
{
    return this->AutoSewUp;
}

//Сеттер показателя автопочинки одежды
void Clothes::SetAutoSewUp(bool argument)
{
    this->AutoSewUp = argument;
    if (this->AutoSewUp == true) {
        this->ClothesStatus = 100;
    }
}
