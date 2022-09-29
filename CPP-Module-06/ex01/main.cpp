#include "serialize.hpp"

int main(void)
{
	Data		dataStruct;

	dataStruct.id = 0;
	dataStruct.message = "Hi I'm the french messager";
	dataStruct.favoriteChar = 't';

	uintptr_t raw = serialize(&dataStruct);
	std::cout << "Raw: " << raw << std::endl;
	Data* ptr = deserialize(raw);

	std::cout << "ID: " << ptr->id << std::endl;
	std::cout << "Message: " << ptr->message << std::endl;
	std::cout << "Favorite Char: " << ptr->favoriteChar << std::endl;
	return 0;
}
