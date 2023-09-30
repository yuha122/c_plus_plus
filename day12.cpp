#include <iostream>

//------디폴트 매개변수------
//기본값이 제공되는 함수의 매개 변수
//함수를 호출할 때 이 매개 변수의 값을 넘겨주지 않으면 기본값이 사용되고
//매개 변수의 값을 넘겨주면 넘겨준 값이 사용됨
//디폴트 매개 변수는 오직 한 번만 선언될 수 있음
//즉 printfValue(int x, int y = 10){}; 함수를 선언해 놓고 다시 printValues(int x, int y = 20){}; 할 수 없음

void printValues(int x, int y = 10){
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
}

void Sum(int n1, int n2 = 0, int n3 = 0, int n4 = 0, int n5 = 0){
    std::cout << "정수의 총합: " << n1 + n2 + n3 + n4 + n5 << std::endl;

}

int main(){
    
    /*디폴트 매개 변수 기본 사용*/
    //y값을 넘겨주지 않았을 때
    printValues(5);
    //y값을 넘겨줬을 때
    printValues(10, 20);


    /*문제1
    int cnt, arr[5];
    std::cout << "정수의 개수: ";
    std::cin >> cnt;
    std::cout << "정수 입력: ";
    for (int i = 0; i < cnt; i++){
        std::cin >> arr[i];
    }
    switch(cnt){
        case 1:
            Sum(arr[0]);
            break;
        case 2:
            Sum(arr[0], arr[1]);
            break;
        case 3:
            Sum(arr[0], arr[1], arr[2]);
            break;
        case 4:
            Sum(arr[0], arr[1], arr[2], arr[3]);
            break;
        case 5:
            Sum(arr[0], arr[1], arr[2], arr[3], arr[4]);
            break;

    }*/
    
    return 0;
}
    