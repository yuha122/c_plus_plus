//c++에서는 구조체안에 함수도 정의가 가능
//구조체를 잘 사용할 수 있으면 클래스도 어렵지 않음

//------접근 제어 지시자------
//멤버에 접근할 수 있는 사용자를 지정해주는 개념
//public: 공개 멤버로 외부에서도 접근 가능  ... 구조체에서는 public이 기본 속성
//private: 비공개 멤버로 외부에서는 접근 불가능 ... 클래스는 private이 기본 속성
//접근 제어 지시자를 개발가 원하는 대로 바꿀 수 있음

//------클래스(설계도)------
//특정한 용도를 수행하기 위해 변수와 함수를 모아둔 틀
//객채(제품): 클래스를 이용해 선언된 변수
//클래스: attribute(속성-멤버변수) + method(동작-멤버함수)
//구조체는 각 멤버가 public의 속성을, 클래스는 각 멤버가 private의 속성을 가짐
//자료은닉을 이유로 클래스의 멤버들은 기본적으로 private
//하지만 멤버함수는 외부에서 멤버변수에 접근할 수 있도록 하기 위해 public으로 바꿈


//------setter------
//private 속성의 멤버변수에 값을 설정해주는 역할의 메소드
//setter의 반환형은 기본적으로 void
//setter의 이름은 Set뒤에 설정할 멤버변수의 이름이나 직관적인 단어
//setter의 매개변수는 설정할 멤버변수와 같은 자료형
//ex) void SetColor(string _color){
//       color = _color;
//    }
//setter는 멤버변수의 값을 설정해주는 역할을 하기 때문에 적절한 예외처리를 함께 진행해줄 수 있음


//------getter------
//private 속성의 멤버변수의 값을 가져오는 역할의 메소드
//getter의 반환형은 반환해줄 멤버변수의 자료형과 일치
//getter의 이름은 Get뒤에 반환할 멤버변수의 이름이나 직관적인 단어
//ex) string GetColor(){
//      return color;
//    }

//------const method------
//메소드를 상수화해서 내부에서 의도치 않은 값 변경으로 인해 발생할 수 있는 문제를 방지하는 개념
//메소드를 상수화 시켜주기 위해서는 매개변수 뒤에 const 작성
//ex) int GetMaxspeed() const{
//
//    }
//멤버변수의 값을 변경하지 않는 함수라면 모두 const 붙일 수 있음
//setter는 const X, getter는 const O

#include <iostream>
#include <stdlib.h>

using namespace std;

/*클래스 기본, 접근제어지시자 사용
class Car{

    string color;
    int maxspeed;
    int gear;

public:
    //setter
    void SetColor(string _color){
        if(_color == "Red" || _color == "Black" || _color == "White" || _color == "Silver"){
            color = _color;
        }
        else{
            cout << "Red, Black, White, Silver 중 한 가지 색상을 고르세요!" << endl;
            color = "Red";
        }
    }

    void SetMaxspeed(int _maxspeed){
        if(_maxspeed > 190){
            cout << "최대 속력이 190km/h을 초과할 수 없습니다." << endl;
            maxspeed = 140;
        }
        else if(_maxspeed < 100){
            cout << "최대 속력이 100km/h 미만일 수 없습니다." << endl;
            maxspeed = 140;
        }
        else{
            maxspeed = _maxspeed;
        }
        
    }

    void SetGear(int _gear){
        gear = _gear;
    }


    //getter
    string GetColor(){
        return color;
    }

    int GetMaxspeed() const{
        return maxspeed;
    }

    int GetGear(){
        return gear;
    }

    void ShowInfo() const{
        cout << "색상: " << color << endl;
        cout << "최대 속력: " << maxspeed << endl;
        cout << "기어: " << gear << endl;
    }
};*/

class TV{
    int channel, volume;
public:
    void Default(){
        channel = 1;
        volume = 30;
    }

    void SetChannel(int _channel){
        if (_channel > 999){
            cout << "채널은 999번까지만 존재합니다." << endl;
        }
        else{
            channel = _channel;
        }
        
    }

    void SetChannelPlus(){
        if (channel >= 999){
            cout << "채널을 더 올릴 수 없습니다." << endl;
        }
        else{
            channel++;
        }
        
    }

    void SetChannelMinus(){
        if (channel <= 1){
            cout << "체널을 더 내릴 수 없습니다." << endl;
        }
        else{
            channel--;
        }
        
    }

    void SetVolumePlus(){
        if (volume >= 100){
            cout << "볼륨을 더 키울 수 없습니다." << endl;
        }
        else{
            volume++;
        }
    }

    void SetVolumeMinus(){
        if (volume <= 0){
            cout << "볼륨을 더 줄일 수 없습니다." << endl;
        }
        else{
            volume--;
        }
        
    }

    int GetChannel(){
        return channel;
    }
    void ShowInfo(){
        cout << "현재 채널은 " << channel << "이며 현재 볼륨은 " << volume << "입니다." << endl;
    }
};

int main(){

    /*클래스 기본 사용
    Car Avante{"Red", 140, 3}; //유니폼 초기화
    Avante.ShowInfo();*/

    /*클래스 setter
    //Avante.color = "Red"; color는 private속성이기 때문에 이렇게 접근하는 것이 불가능
    Car Avante;
    Avante.SetColor("Blue");
    Avante.SetMaxspeed(200);
    Avante.SetGear(3);*/
    
    /*클래스 getter
    //Avante.color; color는 private속성이기 때문에 이렇게 하나만 접근하는 것은 불가능
    //그래서 쓰는 것이 getter
    cout << "색상: " << Avante.GetColor() << endl;
    cout << "최대 속력: " << Avante.GetMaxspeed() << endl;
    cout << "기어: " << Avante.GetGear() << endl;*/

   

    /*문제1*/
    int choice, _channel;
    TV myTV;
    myTV.Default();
    while (1){
    system("clear");
    cout << "----------TV 설정 프로그램----------" << endl;
    cout << "1. 채널 입력" << endl;
    cout << "2. 채널 올림" << endl;
    cout << "3. 채널 내림" << endl;
    cout << "4. 볼륨 증가" << endl;
    cout << "5. 볼륨 감소" << endl;
    cout << "6. 현재 정보" << endl;
    cout << "입력: ";
    cin >> choice;
    cout << endl;

    switch(choice){
        case 1:
            system("clear");
            cout << "현재 채널: " << myTV.GetChannel() << endl;
            cout << "채널 입력: ";
            cin >> _channel;
            myTV.SetChannel(_channel);
            break;
        case 2:
            myTV.SetChannelPlus();
            break;
        case 3:
            myTV.SetChannelMinus();
            break;
        case 4:
            myTV.SetVolumePlus();
            break;
        case 5:
            myTV.SetVolumeMinus();
            break;
        case 6:
            myTV.ShowInfo();
            break;
    }
    system( "read -n 1 -s -p \"Press any key to continue...\"" ); 
    }
    return 0;
}

