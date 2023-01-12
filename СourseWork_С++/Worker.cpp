#include "Worker.h"

//Конструктор без параметров
Worker::Worker() : Human()
{
    this->Namework = "Раздача листовок";
    this->Payment = 10;
}

//Геттер оплаты
Int32 Worker::GetPayment()
{
    return this->Payment;
}

//Сеттер оплаты
void Worker::SetPayment(Int32 payment)
{

    this->Payment = payment;
}

//Геттер наименования работы
String^ Worker::GetNamework()
{

    return this->Namework;
}

//Сеттер наименования работы
void Worker::SetNamework(String^ nameWork)
{

    this->Namework = nameWork;
}
