#include"pch.h"
#include"par_ptr_tree.h"
int main(void) {
	ParPtrTree p1(11);
	p1.UNION(3, 1);
	p1.UNION(4, 1);
	p1.UNION(5, 1);
	p1.UNION(6, 2);
	p1.UNION(1, 0);
	p1.UNION(2, 0);
	p1.UNION(8, 7);
	p1.UNION(9, 7);
	p1.UNION(10, 7);
	cout << boolalpha << p1.differ(9, 8);
	p1.print();
	return 0;
}