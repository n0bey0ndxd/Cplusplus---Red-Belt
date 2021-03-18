#include <algorithm>

using namespace std;

template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred)
{
    ForwardIterator result = find_if(first, last, pred);

    for (ForwardIterator curr = result; curr != last; curr++)
    {
        if (pred(*curr) && *result < *curr && curr != result)
        {
            result = curr;
        }
    }

    return result;
}