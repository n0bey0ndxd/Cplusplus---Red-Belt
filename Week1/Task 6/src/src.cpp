#include "test_runner.h"

#include <vector>

using namespace std;

template <typename T>
class Table
{
public:
	Table(size_t _i, size_t _j) : i(_i), j(_j) 
	{
	    Resize(i, j);
	}
	Table() : i(0), j(0) {}

	void Resize(size_t new_i, size_t new_j)
	{
		i = new_i;
		j = new_j;
		values.resize(i);
		for (auto& i : values)
		{
			i.resize(j);
		}
	}

	
	const vector<T>& operator[](size_t index) const
	{
		return values[index];
	}

	
	vector<T>& operator[](size_t index)
	{
		return values[index];
	}

	pair<size_t, size_t> Size() const
	{
		if (!values.empty() && !values[0].empty())
		{
			return { values.size(), values[0].size() };
		}
		return { 0, 0 };
	}
	
private:
	size_t i, j;
	vector<vector<T>> values;
};

void TestTable() {
	Table<int> t(1, 1);
	ASSERT_EQUAL(t.Size().first, 1u);
	ASSERT_EQUAL(t.Size().second, 1u);
	t[0][0] = 42;
	ASSERT_EQUAL(t[0][0], 42);
	t.Resize(3, 4);
	ASSERT_EQUAL(t.Size().first, 3u);
	ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestTable);
	return 0;
}