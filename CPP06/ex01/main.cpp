#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		D1;
	uintptr_t	serializedObject;
	Data		*deserializedObjectPtr;

	D1.name = "Database";
	D1.instructions = "Run Database";
	D1.numEntries = 2;

	serializedObject = Serializer::serialize(&D1);
	deserializedObjectPtr = Serializer::deserialize(serializedObject);

	deserializedObjectPtr->instructions = ":o";
	
	std::cout << deserializedObjectPtr->instructions << std::endl;
	std::cout << D1.instructions << std::endl;

	std::cout << &D1 << std::endl;
	std::cout << deserializedObjectPtr << std::endl;
	return (0);
}
