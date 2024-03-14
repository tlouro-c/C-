#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

class Serializer {
public:
	uintptr_t serialize(Data* ptr);
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
};

#endif
