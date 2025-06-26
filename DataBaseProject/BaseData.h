#pragma once

using namespace System;

public ref class BaseData abstract{
public:
	virtual void FromString(String^ valueStr) abstract;
	virtual int GetSize() abstract;
};

