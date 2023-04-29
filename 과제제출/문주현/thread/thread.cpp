#include <iostream>
#include <thread>

void Thr1(int num){
	std::cout << "Thr1 : " << num << std::endl;
}
void Thr2(int num){
	std::cout << "Thr2 : " << num << std::endl;
}

main(){
	for(int i=1;i < 11;++i){
		
		std::thread th1(Thr1, i);
		std::thread th2(Thr2, i);
		th1.join();
		th2.join();
	}
  return 0;
}
