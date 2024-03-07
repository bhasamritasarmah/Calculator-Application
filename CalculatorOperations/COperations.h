#pragma once

#define exportClass _declspec(dllexport)

class exportClass COperations
{
public:
	float add(float num1, float num2);
	float subtract(float num1, float num2);
	float multiply(float num1, float num2);
	float divide(float num1, float num2);
};

