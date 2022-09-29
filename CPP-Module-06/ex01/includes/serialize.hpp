#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <stdint.h>
# include <iostream>

typedef struct Data
{
	int			id;
	std::string	message;
	char		favoriteChar;
}	Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
