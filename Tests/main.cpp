#include <gtest/gtest.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]){
	srand(time(NULL));
	cout << rand() << endl;
	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
	return 0;
}
