#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>

typedef std::vector< std::pair<int, int> > PairsVector;
typedef std::list< std::pair<int, int> > PairsList;
typedef std::vector<int>::iterator vectorIter;

template <typename Iter>  //* This one sorts each pair
void	SortPairs(Iter begin, Iter end)
{
	std::size_t size = std::distance(begin, end);
	if (size < 2)
		return ;

	bool	leftOver = size % 2 != 0;
	for (Iter it = begin; it != end - leftOver; it += 2) {
		if (*it > *(it + 1))
			std::swap(*it, *(it + 1));
	}
}
template<typename PairsContainer, typename OriginalContainer>
PairsContainer	ConvertToPairs(OriginalContainer& toSort)
{
	PairsContainer	Pairs;
	bool leftOver = toSort.size() % 2 != 0;
	for (typename OriginalContainer::iterator it = toSort.begin();
		it != toSort.end() - leftOver; it += 2) {
			Pairs.push_back(std::make_pair(*it, *(it + 1)));
	}
	return (Pairs);
}

#endif
