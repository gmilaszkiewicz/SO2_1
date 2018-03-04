#include <iostream>
#include <thread>
#include <time.h>
#include <Windows.h>

using namespace std;

const int num_threads = 3;
const int iloscCykli = 2;

void call_from_thread(int tid) {
	cout << "Filozof " << tid <<" zasiadl do stolu." <<endl;
	for (int i = 0; i < iloscCykli; i++)
	{
		cout << "Filozof " << tid << " je." << endl;
		int czasJedzenia = rand() % 500;
		Sleep(czasJedzenia);	
		cout << "Filozof " << tid << " filozofuje." << endl;
		int czasFilozofowania = rand() % 500;
		Sleep(czasFilozofowania);
	}
}


int main(){ 
	thread t[num_threads];

	for (int i = 0; i < num_threads; i++)
	{
		t[i] = thread(call_from_thread, i);
	}
	
	cout << "main" << endl;
	for (int i = 0; i < num_threads; i++)
	{
		t[i].join();
	}

	system("pause");
	return 0;
}