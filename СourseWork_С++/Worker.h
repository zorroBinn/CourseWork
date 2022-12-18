#pragma once
#include "Human.h"
using System::String;
using System::Int32;

ref class Worker : public Human 
{
private:
	String^ Namework;
	Int32 Payment;

public:
	Worker();
	Int32 GetPayment();
	void SetPayment(Int32 payment);
	String^ GetNamework();
	void SetNamework(String^ namework);
};

