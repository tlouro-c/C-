#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T, typename Container=std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	typedef typename Container::iterator iterator;
	iterator begin() {
        return std::stack<T, Container>::c.begin();
    }

    iterator end() {
        return std::stack<T, Container>::c.end();
    }
};

#endif
