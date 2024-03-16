#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

typedef unsigned int uint;

class Span {
public:
	Span(uint maxSize);
	~Span();
	Span(const Span& other);
	Span& operator=(const Span& other);

private:
	std::vector<int>	classVector;
	uint				_maxSize;
	Span();
};

#endif
