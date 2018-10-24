
#include"arena.h"

int main(void) {

	leveldb::Arena arena;
	//auto rtn = arena.Allocate(3000);
	//auto rtn1 = arena.Allocate(200);
	auto rtn2 = arena.Allocate(4);
	arena.AllocateAligned(300);
	size_t rtn4 = arena.MemoryUsage();
	return 0;
}

