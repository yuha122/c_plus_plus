//------함수 오버로딩------
//오버로드 = 과적
//동일한 이름을 가진 함수를 여러 개 정의해서 사용하는 개념(C언어-동일한 이름의 함수가 오직 한 개만 존재)
//함수를 호출할 때는 함수 이름과 매개 변수에 대한 정보가 모두 일치해야 함
//함수 오버로딩을 사용할 떄는 매개 변수의 타입이나 개수를 다르게 정의해야 구분해서 사용 가능
//함수 오버로딩과 디폴트 매개 변수는 함께 사용할 수 있으나
//디폴트 매개 변수로 인해 함수를 호출할 때 함수 구분이 불가능할 수도 있기 때문에 중복되는 상황이 발생하지 않도록 주의해야 함
//함수 이름이 같지만 반환 값이 다르다고 해서 함수 오버로딩을 사용하는 것은 불가능함


//------namespace------
//같은 이름의 식별자(변수나 함수)를 상황(namespace이름)에 따라 구분해서 사용할 수 있게 하는 개념
//namespace 정의하는 방법:
//  namespace 이름공간이름{
//       식별자;
//  }
//이름공간 안에 접근할 때는 ::(범위 지정 연산자) 사용
//ex)이름공간 이름::식별자
//   ACompany::TextPrint();
//이름공간 안에 있는 함수를 선언과 정의로 구분할 때는
//정의 부분에 반환형 이름광간이름::함수이름(매개변수) 형식으로 진행하는 것이 좋음


//------using------
//이름공간 이름을 생략할 수 있게 해주는 개념
//1. 식별자 지정 using 원형: using 이름공간이름::이름공간이름을생략해서사용하고자하는식별자;
//그 식별자를 사용할 때만 이름공간이름을 생략할 수 있음
//2. 이름공간 지정 using 원형: using namespace 생략하고자하는 이름광간;
//using으로 이름공간을 생략했을 때 중복되는 식별자가 없는지 주의해야 함
//이름공간 지정보다는 식별자 지정을 사용하는 편이 더 안전


//------범위 지정 연산자(::)------
//범위지정연산자를 사용하면 특정 이름공간에 속하지 않은 전역 변수나 함수에 접근 가능
//전역 변수 및 함수에 접근하는 방법: 접근하고자 하는 변수 및 함수 앞에 :: 붙여주면 됨
//ex) ::TextPrint();
//ex) ::num;
//변수나 함수 이름이 중복되지 않더라도 그 변수나 함수나 전역임을 알리는 역할을 하기도 함


#include <iostream>
#include <string>

using namespace std;





/*함수 오버로딩 기본에서 쓰인 함수
void Add(int n1, int n2){
    std::cout << "더한 값: " << n1 + n2 << std::endl;
}

void Add(int n1, int n2, int n3 = 30){
    std::cout << "더한 값: " << n1 + n2 + n3 << std::endl;
}
void Add(double n1, double n2){
    std::cout << "더한 값: " << n1 + n2 << std::endl;
}*/

/*반환값이 다를 때 매개 변수가 동일한 함수 오버로딩이 가능할까?
int Sub(int n1, int n2){
    return n1 - n2;
}

int Sub(int n1, int n2){
    return n2 - n1;
}*/

/*문제1 함수-유하
void Switch(int* n1, int* n2){
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void Switch(double* n1, double* n2){
    double tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void Switch(char* n1, char* n2){
    char tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}*/

/*문제1 함수-쌤
//C++에서는 C와 달리 포인터가 아닌 레퍼런스를 이용하여 call-by-reference가 가능!!
void Swap(int& ref1, int& ref2){
    int tmp = ref1;
    ref1 = ref2;
    ref2 = tmp;
}

void Swap(double& ref1, double& ref2){
    double tmp = ref1;
    ref1 = ref2;
    ref2 = tmp;
}

void Swap(char& ref1, char& ref2){
    char tmp = ref1;
    ref1 = ref2;
    ref2 = tmp;
}*/

/*이름공간 안의 함수 선언과 정의 따로하기
namespace ACompany {
    void TextPrint();
}

namespace BCompany {
    void TextPrint();
}*/


/*using으로 namespace이름 생략하기 & 범위 지정 연산자
namespace CCompany{
    int data1 = 11;
    int data2 = 22;

    void Data1Print(){
        std::cout << "data1: " << data1 << std::endl;
    }

    void Data2Print(){
        std::cout << "data2: " << data2 << std::endl;
    }

    void TextPrint(){
        std::cout << "C Function!" << std::endl;
    }
}

void TextPrint(){
    std::cout << "Global Function!" << std::endl;
}

int num;*/

/*문제2 namespace
namespace chulsoo{
    int age;
    double height;
    double weight;
    void info();
}

namespace minsoo{
    int age;
    double height;
    double weight;
    void info();
}

namespace yeonghee{
    int age;
    double height;
    double weight;
    void info();
}*/


int main(){
    
    /*함수 오버로딩 기본
    Add(10, 20);
    Add(10, 20, 30);
    Add(11.1, 22.2);*/

    /*반환값이 다를 때 매개 변수가 동일한 함수 오버로딩이 가능할까?
    Sub(10, 20);
    Sub(20, 10);
    //정답: 불가능*/
    
    /*문제1-유하 풀이(포인터 사용)
    int choice, n1, n2;
    double d1, d2;
    char ch1, ch2;
    std::cout << "----------데이터 바꾸기----------" << std::endl;
    std::cout << "1. 정수" << std::endl;
    std::cout << "2. 실수" << std::endl;
    std::cout << "3. 문자" << std::endl;
    std::cout << "입력: ";
    std::cin >> choice;
    switch(choice){
        case 1:
            std::cout << "두 정수 입력: ";
            std::cin >> n1 >> n2;
            Switch(&n1, &n2);
            std::cout << "출력: " << n1 << ' ' << n2 << std::endl;
            break;
        case 2:
            std::cout << "두 실수 입력: ";
            std::cin >> d1 >> d2;
            Switch(&d1, &d2);
            std::cout << "출력: " << d1 << ' ' << d2 << std::endl;
            break;
        case 3:
            std::cout << "두 문자 입력: ";
            std::cin >> ch1 >> ch2;
            Switch(&ch1, &ch2);
            std::cout << "출력: " << ch1 << ' ' << ch2 << std::endl;
            break;
    }*/

    /*문제1-쌤 풀이(레퍼런스를 인자, 매개변수로 사용)
    int select, num1, num2;
    double d1, d2;
    char ch1, ch2;
    std::cout << "----------데이터 바꾸기----------" << std::endl;
    std::cout << "1. 정수" << std::endl;
    std::cout << "2. 실수" << std::endl;
    std::cout << "3. 문자" << std::endl;
    std::cout << "입력: ";
    std::cin >> select;
    switch(select){
        case 1:
            std::cout << "두 정수 입력: ";
            std::cin >> num1 >> num2;
            Swap(num1, num2);
            std::cout << "출력: " << num1 << ' ' << num2 << std::endl;
            break;
        case 2:
            std::cout << "두 실수 입력: ";
            std::cin >> d1 >> d2;
            Swap(d1, d2);
            std::cout << "출력: " << d1 << ' ' << d2 << std::endl;
            break;
        case 3:
            std::cout << "두 문자 입력: ";
            std::cin >> ch1 >> ch2;
            Swap(ch1, ch2);
            std::cout << "출력: " << ch1 << ' ' << ch2 << std::endl;
            break;
    }*/

    /*namespace 사용하기
    ACompany::TextPrint();
    BCompany::TextPrint();*/

    /*이름공간의 이름 생략하기
    //1. 식별자 지정 using
    using CCompany::Data1Print;
    Data1Print();
    //2. 이름공간 지정 using
    using namespace CCompany;
    Data2Print();
    //TextPrint();
    //CCompany안의 TextPrint()인지, 전역함수 TextPrint()인지 알 수 없음*/

    /*볌위 지정 연산자 사용
    //전역 함수 TextPrint()에 접근하는 방법
    ::TextPrint();

    //전역 변수 접근하는 방법
    int num = 4;
    std::cout << "num의 값: " << ::num << std::endl;*/

    /*namespace 문제2
        cout << "철수의 정보 입력" << endl;
    cout << "나이: ";
    cin >> chulsoo::age;
    cout << "키: ";
    cin >> chulsoo::height;
    cout << "몸무게: ";
    cin >> chulsoo::weight;
    cout << endl;

    cout << "민수의 정보 입력" << endl;
    cout << "나이: ";
    cin >> minsoo::age;
    cout << "키: ";
    cin >> minsoo::height;
    cout << "몸무게: ";
    cin >> minsoo::weight;
    cout << endl;

    cout << "영희의 정보 입력" << endl;
    cout << "나이: ";
    cin >> yeonghee::age;
    cout << "키: ";
    cin >> yeonghee::height;
    cout << "몸무게: ";
    cin >> yeonghee::weight;
    cout << endl;

    cout.setf(ios::fixed);
    cout.precision(2);
    chulsoo::info();
    cout << endl;
    minsoo::info();
    cout << endl;
    yeonghee::info();
    cout << endl;*/

    

    return 0;
}

/*이름공간 함수 정의
void ACompany::TextPrint(){
        std::cout << "A Function!" << std::endl;
}

void BCompany::TextPrint(){
        std::cout << "B Function!" << std::endl;
}*/

/*문제2 함수 정의
void chulsoo::info(){
    cout << "철수의 정보" << endl;
    cout << "나이: " << age << endl;
    cout << "키: " << height << endl;
    cout << "몸무게: " << weight << endl;
    cout << "BMI: " << weight / ((height / 100) * (height / 100)) << endl;
}

void minsoo::info(){
    cout << "민수의 정보" << endl;
    cout << "나이: " << age << endl;
    cout << "키: " << height << endl;
    cout << "몸무게: " << weight << endl;
    cout << "BMI: " << weight / ((height / 100) * (height / 100)) << endl;
}

void yeonghee::info(){
    cout << "영희의 정보" << endl;
    cout << "나이: " << age << endl;
    cout << "키: " << height << endl;
    cout << "몸무게: " << weight << endl;
    cout << "BMI: " << weight / ((height / 100) * (height / 100)) << endl;
}*/