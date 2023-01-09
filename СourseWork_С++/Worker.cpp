#include "Worker.h"

Worker::Worker() : Human()
{
    this->Namework = "Раздача листовок";
    this->Payment = 10;
}

Int32 Worker::GetPayment()
{
    return this->Payment;
}

void Worker::SetPayment(Int32 payment)
{

    this->Payment = payment;
}

String^ Worker::GetNamework()
{

    return this->Namework;
}

void Worker::SetNamework(String^ nameWork)
{

    this->Namework = nameWork;
}
