#include "serialize.hpp"

uintptr_t	serialize(Data* ptr)
{
	uintptr_t ret;

	ret = reinterpret_cast<uintptr_t>(ptr);
	return ret;
}

Data *deserialize(uintptr_t raw)
{
	Data *ret;

	ret = reinterpret_cast<Data*>(raw);
	return (ret);
}
