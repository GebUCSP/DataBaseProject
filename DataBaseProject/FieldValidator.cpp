#include "FieldValidator.h"

bool FieldValidator::ValidateInteger(String^ value, int size) {
	// si se inestar un valor como 9999999999 se convierte en el max permitido 2147483647
}
bool FieldValidator::ValidateBoolean(String^ value) {
	// cualquier numero distinto de cero se considera true
	// 'False' como cadena se debería evaluar como TRUE
	value = value->ToLower();
	return (value == "true" || value == "false" || value == "1" || value == "0");
}
bool FieldValidator::ValidateVarchar(String^ value, int size) {
	// 'Hola' , '123', ''
	return value->Length <= size;
}
bool FieldValidator::ValidateChar(String^ value, int size) {
	// Char rellena con espacios hasta la longitud definida
	return value->Length == size;
}
bool FieldValidator::ValidateDecimal(String^ value, int size, int scale) {
	// 3.14, -10.5, 42  , 0
	double result;
	if (!Double::TryParse(value, result))
		return 0;

	array<String^>^ arr = value->Split('.');
	int IntPart = arr[0]->TrimStart('-')->Length;
	int DecPart;
	if (arr->Length > 1)
		DecPart = arr[1]->Length;
	else  DecPart = 0;

	return (IntPart + DecPart <= size && DecPart <= scale);
}