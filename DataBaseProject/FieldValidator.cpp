#include "FieldValidator.h"

bool FieldValidator::ValidateInteger(String^ value, int size)
{
    if (String::IsNullOrWhiteSpace(value)) return false;

    value = value->Trim();

    Int64 tmp;
    if (!Int64::TryParse(value, NumberStyles::Integer,
        CultureInfo::InvariantCulture, tmp))
        return false;

    int digits = value->TrimStart(L'-', L'+')->Length;
    if (digits > size) return false;

    if (tmp < Int32::MinValue || tmp > Int32::MaxValue) return false;

    return true;
}

bool FieldValidator::ValidateBoolean(String^ value)
{
    if (String::IsNullOrWhiteSpace(value)) return false;

    value = value->Trim()->ToLowerInvariant();
    return (value == "true" || value == "1" ||
        value == "false" || value == "0");
}

bool FieldValidator::ValidateVarchar(String^ value, int size)
{
    if (value == nullptr) value = "";
    return value->Length <= size;
}

bool FieldValidator::ValidateChar(String^ value, int size)
{
    if (value == nullptr) value = "";
    return value->Length == size;
}

bool FieldValidator::ValidateDecimal(String^ value, int size, int scale)
{
    if (String::IsNullOrWhiteSpace(value)) return false;

    value = value->Trim();

    double tmp;
    if (!Double::TryParse(value, NumberStyles::Float | NumberStyles::AllowThousands,
        CultureInfo::InvariantCulture, tmp))
        return false;

    int dot = value->IndexOf('.');
    String^ intPart = (dot == -1) ? value : value->Substring(0, dot);
    String^ fracPart = (dot == -1) ? "" : value->Substring(dot + 1);

    intPart = intPart->TrimStart(L'-', L'+');

    int intLen = intPart->Length;
    int fracLen = fracPart->Length;

    return (intLen + fracLen <= size) && (fracLen <= scale);
}
