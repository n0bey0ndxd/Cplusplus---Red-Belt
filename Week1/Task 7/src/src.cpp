#include <stdexcept>
#include <vector>

using namespace std;

template <typename T>
class Deque
{
private:
	vector<T> front;
	vector<T> back;
public:
	Deque() {}

	bool Empty() const
	{
		if (front.empty() && back.empty())
		{
			return true;
		}

		return false;
	}

	size_t Size() const
	{
		return front.size() + back.size();
	}

	T& operator[](size_t index)
	{
		if (index + 1u > front.size())
		{
			return back[index - front.size()];
		}
		else
		{
			return front[front.size() - 1u - index];
		}
	}

	const T& operator[](size_t index) const
	{
		if (index + 1u > front.size() )
		{
			return back[index - front.size()];
		}
		else
		{
			return front[front.size() - 1u - index];
		}
	}

	T& At(size_t index)
	{
		if (index > front.size() + back.size() - 1u)
		{
			throw out_of_range("out_of_range");
		}
		else
		{
			if (index > front.size() - 1u)
			{
				return back[index - front.size()];
			}
			else
			{
				return front[front.size() - 1u - index];
			}
		}
	}

	const T& At(size_t index) const
	{
		if (index + 1u > front.size() + back.size())
		{
			throw out_of_range("out_of_range");
		}
		else
		{
			if (index + 1u > front.size())
			{
				return back[index - front.size()];
			}
			else
			{
				return front[front.size() - 1u - index];
			}
		}

	}

	T& Front()
	{
		if (!front.empty())
		{
			return front[front.size() - 1u];
		}
		else
		{
			return back[0];
		}
	}

	const T& Front() const
	{
		if (!front.empty())
		{
			return front[front.size() - 1u];
		}
		else
		{
			return back[0];
		}

	}

	T& Back()
	{
		if (!back.empty())
		{
			return back[back.size() - 1u];
		}
		else
		{
			return front[0];
		}
	}

	const T& Back() const
	{
		if (!back.empty())
		{
			return back[back.size() - 1u];
		}
		else
		{
			return front[0];
		}
	}

	void PushFront(const T& value)
	{
		front.push_back(value);
	}

	void PushBack(const T& value)
	{
		back.push_back(value);
	}
};