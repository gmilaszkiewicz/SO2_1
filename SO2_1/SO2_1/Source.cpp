#include <iostream>
#include <thread>

using namespace std;

void call_from_thread(int tid) {
	cout << "watek: " << tid << endl;
}


int main() {
	thread t[5];

	for (int i = 0; i < 5; i++)
	{
		t[i] = thread(call_from_thread, i);
	}

	cout << "main" << endl;

	for (int i = 0; i < 5; i++)
	{
		t[i].join();
	}

	system("pause");
	return 0;
}