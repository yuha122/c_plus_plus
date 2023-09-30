//-------레퍼런스------
//Reference: 참조
//특정 변수에 대한 별명을 추가로 만들어 다른 이름으로도 접근 가능하도록 하는 개념
//레퍼런스 변수 선언 원형: 저장할 변수의 자료형& 참조자이름(새로운 이름) = 저장할 변수이름;
//포인터와 비슷하게 다른 이름으로 변수에 접근할 수 있지만
//포인터는 새로운 메모리 공간을 필요로 하고 그 공간에 변수의 주소를 저장한다면
//레퍼런스는 새로운 메모리 공간이 할당되지 않음(그저 같은 메모리 공간을 공유)
//그렇기 때문에 선언할 떄 반드시 초기화 해줘야 함
//상수 형태 값이 아닌 변수 값으로만 초기화 가능
//포인터와 달리 레퍼런스의 대상을 프로그램 중간에 바꿀 수 없음
//&는 선언이 끝난 변수 앞에 사용되면 주소를 나타내주지만 선언할 떄 사용되면 그 변수가 레퍼런스임을 알려줌
//레퍼런스는 주로 함수에 인수를 전달할 때 사용
//함수가 레퍼런스를 인수로 전달 받으면, 레퍼런스가 참조하고 있는 실제 변수의 값을 함수 내에서 변경(조작)할 수 있음
//마치 포인터가 하듯이!

#include <iostream>
#include <string>

void Swap(int& ref1, int& ref2){
    int tmp = ref1;
    ref1 = ref2;
    ref2 = tmp;
}
int main(){

    /*레퍼런스 변수 사용
    int num;
    int& ref = num;
    int* ptr = &num;
    ref = 5;

    std::cout << "num의 값: " << num << std::endl;
    std::cout << "ref로 확인하는 num의 값: " << ref << std::endl;
    
    std::cout << "num의 주소: " << &num << std::endl;
    std::cout << "ref의 주소: " << &ref << std::endl;
    std::cout << "ptr의 주소: " << &ptr << std::endl;*/

    /*레퍼런스 선언과 동시에 반드시 초기화 햐아 함
    int num1, num2;
    int& ref = num1;*/

    /*레퍼런스의 대상을 바꾸는 것이 불가능한 것을 확인하기
    int num1 = 1, num2 = 2;
    int& ref = num1;
    std::cout << "변경 전 ref의 값: " << ref << std::endl;
    std::cout << "변경 전 ref의 주소: " << &ref << std::endl;
    ref = num2;
    //이건 사실 num1 = num2와 같은 의미임. ref가 num2를 지칭하는 게 아니라 num1, ref 공간에 num2의 값이 복사되는 것
    std::cout << "변경 후 ref의 값: " << ref << std::endl;
    std::cout << "변경 후 ref의 주소: " << &ref << std::endl;*/

    /*문제1
    int num;
    int& ref = num;
    std::cout << "입력: ";
    std::cin >> ref;
    std::cout << "출력: " << num << std::endl;*/

    /*레퍼런스를 함수 인자로 전달하기*/
    int num1 = 10, num2 = 20;
    std::cout << "변경 전의 num1 값은 " << num1 << "이고 num2 값은 " << num2 << std::endl;
    Swap(num1, num2);
    std::cout << "변경 후의 num1 값은 " << num1 << "이고 num2 값은 " << num2 << std::endl;
    
    return 0;
}