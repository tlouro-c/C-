#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <list>
# include <ctime>
# include <iomanip>
# include <cstdlib>

typedef std::vector< std::pair<int, int> > PairsVector;
typedef std::deque< std::pair<int, int> > PairsDeque;
typedef std::list< std::pair<int, int> > PairsList;

template <typename It>
It	myNext(It iterator, int	x = 1)
{
	std::advance(iterator, x);
	return (iterator);
}

template <typename It>
It	myPrev(It iterator, int	x = 1)
{
	std::advance(iterator, -x);
	return (iterator);
}

template <typename T>
double timeSinceInUs(T start, T end)
{
	return (double(end - start) / CLOCKS_PER_SEC * 1000000);
}

template <typename C1, typename C2>
void	fillContainers(C1& container1, C2& container2,
			int argc, char** argv)
{
	char *rest = NULL;

	for (int i = 1; i < argc; i++) {
		long	result = std::strtol(argv[i], &rest, 10);
		if (result <= 0 || result > INT_MAX || *rest)
			throw ("error: bad input...");
		container1.push_back(static_cast<int>(result));
		container2.push_back(static_cast<int>(result));
	}
}

template <typename It>
void	printContainer(const It& begin, const It& end, const char* preText)
{
	std::cout << preText;
	for (It it = begin; it != end; std::advance(it, 1)) {
			std::cout << ' ' << *it;
	}
	std::cout << std::endl;
}

template <typename Iter>  //* This one sorts each pair
void	SortPairs(Iter begin, Iter end)
{
	std::size_t size = std::distance(begin, end);

	bool	leftOver = size % 2 != 0;
	end = leftOver ? myPrev(end) : end;
	for (Iter it = begin; it != end; std::advance(it, 2)) {
		if (*it > *(myNext(it)))
			std::swap(*it, *(myNext(it)));
	}
}

template<typename PairsContainer, typename OriginalContainer>
PairsContainer	ConvertToPairs(OriginalContainer& toSort)
{
	PairsContainer	Pairs;
	
	while (toSort.size() > 1)
	{
		Pairs.push_back(std::make_pair(*toSort.begin(), *myNext(toSort.begin())));
		toSort.erase(toSort.begin());
		toSort.erase(toSort.begin());
	}
	return (Pairs);
}

template<typename PairsContainer, typename OriginalContainer>
void	generateChains(PairsContainer& pairs, OriginalContainer& mainChain,
			OriginalContainer& pendElements)
{
	bool leftOver = mainChain.size() == 1;
	int	tmp(0);
	if (leftOver) {
		tmp = mainChain.front();
		mainChain.clear();
	}

	for (typename PairsContainer::iterator it = pairs.begin();
		it != pairs.end(); it++) {
			pendElements.push_back(it->first);
			mainChain.push_back(it->second);
	}
	if (leftOver) {
		pendElements.push_back(tmp); }
}

template<typename T, typename Iter, typename Container>
Iter	binaryInsertion(T& value, const Iter& begin, const Iter& end,
			Container& mainChain)
{
	std::size_t size = std::distance(begin, end);
	if (size <= 1) {
		return (value > *begin) ? myNext(begin) : begin;
	}
	Iter mid = myNext(begin, size / 2);
	if (value < *mid)
		return binaryInsertion(value, begin, mid, mainChain);
	else
		return binaryInsertion(value, mid, end, mainChain);
}

template<typename T>
void	insertPendIntoMain(T& pendElements, T& mainChain)
{
	typename T::iterator position;
	while (pendElements.size() > 0) {
		position = binaryInsertion(pendElements.front(),
			mainChain.begin(), mainChain.end() , mainChain);
		mainChain.insert(position, pendElements.front());
		pendElements.erase(pendElements.begin());
	}
}

template <typename ContainerType, typename It>
void	merge(const It& begin, const It& mid,
			const It& end)
{
	ContainerType	temp;
	It left = begin;
	It right = mid;

	while (left != mid && right != end)
	{
		if (left->second < right->second) {
			temp.push_back(*left);
			left++;
		}
		else {
			temp.push_back(*right);
			right++;
		}
	}
	while (left != mid) {
		temp.push_back(*left);
		left++;
	}
	while (right != end) {
		temp.push_back(*right);
		right++;
	}

	std::copy(temp.begin(), temp.end(), begin);
}

template <typename ContainerType, typename It>
void	mergeSort(const It& begin,
			const It& end)
{
	std::size_t size = std::distance(begin, end);
	if (size <= 1)
		return ;
	
	It mid = myNext(begin, size / 2);

	mergeSort<ContainerType, It>(begin, mid);
	mergeSort<ContainerType, It>(mid, end);

	merge<ContainerType, It>(begin, mid, end);
}
template <typename Container, typename PairContainer>
void	fordJohnsonSort(Container& toSort)
{
	Container&		mainChain = toSort;
	Container		pendElements;
	PairContainer	pairs;

	SortPairs(toSort.begin(), toSort.end());
	pairs = ConvertToPairs<PairContainer, Container >(toSort);
	mergeSort<PairContainer, typename PairContainer::iterator>(pairs.begin(), pairs.end());
	generateChains(pairs, mainChain, pendElements);
	insertPendIntoMain(pendElements, mainChain);
}

#endif
