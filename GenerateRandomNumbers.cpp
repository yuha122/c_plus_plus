/*
   HW NUMBER: 1
   FILE NAME : GenerateRandomNumbers.cpp
   AUTHOR : 캠퍼스자율전공(서울) 2학년 C035328 이유하 
   YYYYMMDD : 2023.09.21
   PURPOSE : 수업시간에 언급한 것과 같이, 
               1. 3장의 정답이 공개된 실습문제들 3-1, 3-5, 3-9, 3-11를 스스로 학습하시오. (제출하지 않음)
               2. 3장의 실습문제 3-5,3-6은 서로 연관이 되어있는 문제들이니, 이들을 다음과 같이 하나의 소스파일로, 작성하여 아래와 같은 출력 결과가 나오도록, 작성하시오. 
               (C++에서 ‘랜덤함수를 사용하여 난수 생성하기’에 대해서는, 필요하면 구글링하거나 ChatGPT를 사용하여, 필요한 지식을 찾아 학습하시오.)
*/


#include <iostream> //c++ 프로그램에서 입력과 출력을 수행하는 데에 필요한 헤더 파일 추가하기
#include <cstdlib>  //랜덤 숫자를 뽑을 때 사용하는 rand()함수가 선언되어 있는 헤더 파일 추가하기
#include <ctime>    //매번 다른 난수를 뽑기 위해 srand()함수의 인자로 time()함수를 제공해야 하는데 이 time()함수를 사용하기 위한 헤더 파일 추가하기

using namespace std; //std이름공간에 선언된 이름(cin, cout, endl 등)을 사용할 때 접두어 std::를 생략하기 위한 코드

//5.5
// 임의의 정수를 랜덤하게 제공하는 클래스
class Random {    //클래스 선언부
public:
   Random(); //생성자로서 렌덤 seed를 설정함
   int next(); //랜덤 정수를 리턴함
   int nextInRange(int low, int high); //low와 high 사이의 랜덤 정수를 리턴함
};

//클래스 구현부
Random::Random() {                        //Random클래스의 객체가 생성될 때
   srand((unsigned)time(0));       //임의의 seed를 설정하여 rand()함수가 호출될 때마다 다른 랜덤 수가 나오게 함
}

int Random::next(){ //범위가 주어지지 않았을 때
   return rand();   //0에서 RAND_MAX 사이의 랜덤한 정수 리턴
}

int Random::nextInRange(int low, int high) { //범위가 주어졌을 때
   int range = (high - low) + 1;
    return low + (rand() % range);  //low부터 high까지의 랜덤한 정수 리턴


}

//5.6
//임의의 짝수 정수를 랜덤하게 제공하는 클래스
class EvenRandom {  //클래스 선언부
public:
   EvenRandom();  //생성자로서 랜덤 seed를 설정
   int next();    //랜덤 짝수 정수를 리턴함
   int nextInRange(int low, int high);  //low와 high 사이의 랜덤 짝수 정수를 리턴함
};

//클래스 구현부
EvenRandom::EvenRandom() {                //EvenRandom클래스의 객체가 생성될 때
   srand((unsigned)time(0));       //임의의 seed를 설정하여 rand()함수가 호출될 때마다 다른 랜덤 수가 나오게 함
}

int EvenRandom::next() { //범위가 주어지지 않았을 때
   int ran = rand();     //0에서 RAND_MAX 사이의 랜덤한 정수 생성
   if (ran % 2 == 0){    //그 랜덤한 정수가 짝수이면 그대로 리턴하고
      return ran;
   }
   else{               //홀수라면 -1을 해서 리턴한다. (+1대신 -1을 하는 이유는 0도 짝수로 간주하기 때문)
      return --ran;
   }
}

int EvenRandom::nextInRange(int low, int high) { //범위가 주어졌을 때 
   int range = (high - low) + 1;
   int ran = low + (rand() % range);    //low부터 high까지의 랜덤한 정수 생성
   if (ran % 2 == 0){    //위에 뽑은 랜덤한 정수가 짝수라면
      return ran;        //그대로 리턴하고 
   }
   else{                 //홀수라면 -1을 해서 리턴한다.(+1대신 -1을 하는 이유는 0도 짝수로 간주하기 때문)
      return --ran;
   }
}

int main() {
   
   cout << "0에서부터" << RAND_MAX << "까지의 랜덤 정수 10개--\n"; //RAND_MAX는 rand()함수의 범위 중 최댓값인 32767
   Random r;                         //Random클래스 객체 r을 생성
   for (int i = 0; i < 10; i++){     //총 10개의 랜덤 정수 뽑아야 하기 떄문에 for문 총 10번 돌린다.
      cout << r.next();              //뽑은 랜덤한 정수를 출력하고 
      if (i == 9){                   //맨 마지막에 출력된 수는 개행을 해준다
         cout << endl;
         break;
      }           
      cout << " ";                   //그 앞의 수들은 모두 띄어쓰기를 해준다.
   }
   cout << endl;                    //가시성을 위해 개행을 진행한다.
   cout << "--2에서 4까지의 랜덤 정수 10개--\n";                         
   for (int i = 0; i < 10; i++){     //총 10개의 랜덤 정수 뽑아야 하기 때문에 for문 총 10번 돌린다.
      cout << r.nextInRange(2, 4);   //뽑은 랜덤한 정수를 출력하고
      if (i == 9){                   //맨 마지막에 출력된 수는 개행을 해준다
         cout << endl;
         break;
      } 
      cout << " ";                   //그 앞의 수들은 모두 띄어쓰기를 해준다.
   }
   cout << endl;

   cout << "-------------------------------------------------------" << endl << endl;   //임의의 정수와 임의의 짝수 정수 출력 구분하기 위한 라인
   cout << "--0에서" << RAND_MAX << "까지의 짝수 랜덤 정수 10개--\n";
	EvenRandom er;                      //EvenRandom클래스 객체 er 생성
    for (int i = 0; i < 10; i++){      //총 10개의 짝수 랜덤 정수 뽑아야 하기 때문에 for문 총 10번 돌린다.
      cout << er.next();            //뽑은 랜덤한 짝수 정수를 출력하고
      if (i == 9){                  //맨 마지막에 출력된 수는 개행을 해준다
         cout << endl;
         break;
      }             
      cout << " ";                     //그 앞의 모든 수는 띄어쓰기를 해준다.
   }
   cout << endl;
   cout << "--2에서 10까지의 짝수 랜덤 정수 10개--\n";
   for (int i = 0; i < 10; i++){             //총 10개의 짝수 랜덤 정수 뽑아야 하기 때문에 for문 총 10번 돌린다.
      cout << er.nextInRange(2, 10);   //뽑은 랜덤한 짝수 정수를 출력하고
      if (i == 9){                     //맨 마지막에 출력된 수는 개행을 해준다
         cout << endl;
         break;
      }        
      cout << " ";                           //그 앞의 모든 수는 띄어쓰기를 해준다.
   }
   cout << endl;
}
