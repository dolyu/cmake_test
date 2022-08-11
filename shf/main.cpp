// CMakeProject2.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include "test.h"
//#include "boost/thread.hpp"
#include "boost/filesystem.hpp"
using namespace std;
// using namespace boost::filesystem;
// #include <filesystem>
int main()
{
	int a = 1;
	a = 2;

	cout << "Hello CMake." << a << endl;

	string str = "c:/vfcompat.dll";
	const char* path = str.c_str();
	cout << path;
	if(boost::filesystem::exists(path))
			cout << str + "은 이미 존재하는 디렉토리입니다.\n";
	else{
			cout << str + "은 존재하지 않는 디렉토리입니다.\n";
	}
	//boost::this_thread::sleep(boost::posix_time::milliseconds(30));
       

	return 0;
}
