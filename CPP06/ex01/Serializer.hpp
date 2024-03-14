#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <cstdint>

struct Data
{
	char	*name;
	char	*instructions;
	int		numEntries;
};

class Serializer {
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
};

#endif
