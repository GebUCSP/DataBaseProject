#pragma once

using namespace System;

public ref class FieldValidator {
public:
	static bool ValidateInteger(String^ value, int size);
	static bool ValidateBoolean(String^ value);;
	static bool ValidateVarchar(String^ value, int size);
	static bool ValidateChar(String^ value, int size);
	static bool ValidateDecimal(String^ value, int size, int scale);
};

