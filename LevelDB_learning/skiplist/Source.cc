
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

	for (int i = 0; i < 0xffff; ++i) {
		if (i == 0xfff) {
			int temp = 0;
		}
		skiplist.Insert(i);
	}

	leveldb::SkipList<int, Comparator>::Iterator iter(&skiplist);
	iter.Seek(4);
	bool result = iter.Valid();


	return 0;
}

