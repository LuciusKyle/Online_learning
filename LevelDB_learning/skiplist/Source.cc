
#include"skiplist.h"



struct Comparator {
	int operator()(const int& a, const int& b) const {
		if (a < b) {
			return -1;
		}
		else if (a > b) {
			return +1;
		}
		else {
			return 0;
		}
	}
};


int main(void)
{
	leveldb::Arena arena;
	Comparator cmp;
	leveldb::SkipList<int, Comparator> skiplist(cmp, &arena);

	skiplist.Insert(1);
	skiplist.Insert(2);
	skiplist.Insert(3);
	skiplist.Insert(4);
	skiplist.Insert(5);

	leveldb::SkipList<int, Comparator>::Iterator iter(&skiplist);
	bool result = iter.Valid();

	return 0;
}


