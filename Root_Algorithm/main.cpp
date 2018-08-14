#include <iostream>

class Root_Map_14{

private:
    int Map_Array_14[27][27];//14+13(Wall)
    int Root_Map[16][20][13][2];

public:
    void Root_Map_Initialize();
    void Set_Flower();

    void NumberToArray_14(int INT_Input);
    void NumberToArray_14(int INT_Input, int *Type, int *INT_X, int *INT_Y);

    void Center_Location(int Center_INDEX, int *INT_X, int *INT_Y);
    int DistanceToCenter(int Center_INDEX, int INT_X, int INT_Y);
    int MaxDistanceByType(int Root_Type);
    void RootTypeToSetWall(int Type, int INT_X, int INT_Y);

    int Checking_Data(int INT_X, int INT_Y);
    void Print_Data();
    void Print_Root_Map();
};

void RootTypexy(int ForE, int Type, int *INT_X, int *INT_Y);

int main() {


    int Test_Num_01=40345;
    int Test_Num_02=130233;

    Root_Map_14 FirstSession;

    FirstSession.Root_Map_Initialize();

    FirstSession.Set_Flower();

    FirstSession.NumberToArray_14(Test_Num_01);
    FirstSession.NumberToArray_14(Test_Num_02);

    FirstSession.Print_Data();

    int Test_Type, Test_X, Test_Y;

    //FirstSession.NumberToArray_14(Test_Num_02,&Test_Type,&Test_X,&Test_Y);

    //std::cout<< Test_Type << " " << Test_X << " " << Test_Y;

    return 0;
}

void Root_Map_14::Root_Map_Initialize() {
    memset(Map_Array_14,0,sizeof(Map_Array_14));
    memset(Root_Map,-1,sizeof(Root_Map));
}
void Root_Map_14::Set_Flower() {
    for(int i0=10;i0<17;i0++){
        for(int i1=10;i1<17;i1++){
            Map_Array_14[i0][i1]=97;
        }
    }
}
void Root_Map_14::NumberToArray_14(int INT_Input) {
    int Buff_Num_X, Buff_Num_Y, Buff_Num_Type;

    Buff_Num_Type=(INT_Input%100);

    Buff_Num_Y=2*((INT_Input%10000-Buff_Num_Type)/100)-2;

    Buff_Num_X=2*(INT_Input/10000)-2;

    Map_Array_14[Buff_Num_X][Buff_Num_Y]=Buff_Num_Type;

    RootTypeToSetWall(Buff_Num_Type,Buff_Num_X,Buff_Num_Y);

    //std::cout<< Buff_Num_X << ", " << Buff_Num_Y << " = " << Buff_Num_Type <<std::endl;
}
void Root_Map_14::NumberToArray_14(int INT_Input, int *Type, int *INT_X, int *INT_Y) {

    *Type=(INT_Input%100);

    *INT_Y=2*((INT_Input%10000-*Type)/100)-2;

    *INT_X=2*(INT_Input/10000)-2;
}

void Root_Map_14::Center_Location(int Center_INDEX, int *INT_X, int *INT_Y) {
    switch (Center_INDEX)
    {
        case 0:
            *INT_X=10;
            *INT_Y=6;
            break;
        case 1:
            *INT_X=12;
            *INT_Y=6;
            break;
        case 2:
            *INT_X=14;
            *INT_Y=6;
            break;
        case 3:
            *INT_X=16;
            *INT_Y=6;
            break;
        case 4:
            *INT_X=20;
            *INT_Y=10;
            break;
        case 5:
            *INT_X=20;
            *INT_Y=12;
            break;
        case 6:
            *INT_X=20;
            *INT_Y=14;
            break;
        case 7:
            *INT_X=20;
            *INT_Y=16;
            break;
        case 8:
            *INT_X=16;
            *INT_Y=20;
            break;
        case 9:
            *INT_X=14;
            *INT_Y=20;
            break;
        case 10:
            *INT_X=12;
            *INT_Y=20;
            break;
        case 11:
            *INT_X=10;
            *INT_Y=20;
            break;
        case 12:
            *INT_X=6;
            *INT_Y=16;
            break;
        case 13:
            *INT_X=6;
            *INT_Y=14;
            break;
        case 14:
            *INT_X=6;
            *INT_Y=12;
            break;
        case 15:
            *INT_X=6;
            *INT_Y=10;
            break;
        default:
            break;
    }
}
int Root_Map_14::DistanceToCenter(int Center_INDEX, int INT_X, int INT_Y) {
    int Buff_Num_X, Buff_Num_Y;

    Buff_Num_X=0; Buff_Num_Y=0;

    Center_Location(Center_INDEX, &Buff_Num_X, &Buff_Num_Y);

    return abs(INT_X+INT_Y-Buff_Num_X-Buff_Num_Y)/2;
}
int Root_Map_14::MaxDistanceByType(int Root_Type){
    int Buff_Num;

    Buff_Num=Root_Type/10;

    switch(Buff_Num){
        case 4:
            Buff_Num=6;
            break;
        case 5:
            Buff_Num=7;
            break;
        case 6:
            Buff_Num=12;
            break;
        case 7:
            Buff_Num=13;
            break;
        default:
            break;
    }
    return Buff_Num;
}
void Root_Map_14::RootTypeToSetWall(int Type, int INT_X, int INT_Y){
    int Buff_Num;

    Buff_Num=Type%10;

    if(Type<70){
        switch (Buff_Num){
            case 1:
                if(INT_X<26){
                    Map_Array_14[INT_X+1][INT_Y]=99;
                }
                if(INT_X>0){
                    Map_Array_14[INT_X-1][INT_Y]=99;
                }
                break;
            case 2:
                if(INT_Y<26){
                    Map_Array_14[INT_X][INT_Y+1]=99;
                }
                if(INT_Y>0){
                    Map_Array_14[INT_X][INT_Y-1]=99;
                }
                break;
            case 3:
                if(INT_X>0){
                    Map_Array_14[INT_X-1][INT_Y]=99;
                }
                if(INT_Y<26){
                    Map_Array_14[INT_X][INT_Y+1]=99;
                }
                break;
            case 4:
                if(INT_X>0){
                    Map_Array_14[INT_X-1][INT_Y]=99;
                }
                if(INT_Y>0){
                    Map_Array_14[INT_X][INT_Y-1]=99;
                }
                break;
            case 5:
                if(INT_X<26){
                    Map_Array_14[INT_X+1][INT_Y]=99;
                }
                if(INT_Y>0){
                    Map_Array_14[INT_X][INT_Y-1]=99;
                }
                break;
            case 6:
                if(INT_X<26){
                    Map_Array_14[INT_X+1][INT_Y]=99;
                }
                if(INT_Y<26){
                    Map_Array_14[INT_X][INT_Y+1]=99;
                }
                break;
            default:
                break;
        }
    }
}



void RootTypexy(int ForE, int Type,int *INT_X, int *INT_Y) {
    int Buff_Num01;

    Buff_Num01=Type%10;

    if(Type>70)
    {
        switch(Buff_Num01)
        {
            case 3:
                   *INT_Y=*INT_Y-2;
                break;
            case 4:
                   *INT_X=*INT_X+2;
                break;
            case 5:
                   *INT_Y=*INT_Y+2;
                break;
            case 6:
                   *INT_X=*INT_X-2;
                break;
            default:
                break;
        }
    }
    else
    {
        switch(Buff_Num01)
        {
            case 3:
                if(ForE==0)
                {
                    *INT_Y=*INT_Y-2;
                }
                else
                {
                    *INT_Y=*INT_Y+2;
                }
                break;
            case 4:
                if(ForE==0)
                {
                    *INT_X=*INT_X-2;
                }
                else
                {
                    *INT_X=*INT_X+2;
                }
                break;
            case 5:
                if(ForE==0)
                {
                    *INT_Y=*INT_Y-2;
                }
                else
                {
                    *INT_X=*INT_X+2;
                }
                break;
            case 6:
                if(ForE==0)
                {
                    *INT_X=*INT_X+2;
                }
                else
                {
                    *INT_Y=*INT_Y+2;
                }
                break;
            case 7:
                if(ForE==0)
                {
                    *INT_X=*INT_X-2;
                }
                else
                {
                    *INT_Y=*INT_Y+2;
                }
                break;
            case 8:
                if(ForE==0)
                {
                    *INT_Y=*INT_Y-2;
                }
                else
                {
                    *INT_X=*INT_X-2;
                }
                break;
            default:
                break;
        }
    }


}

int Root_Map_14::Checking_Data(int INT_X, int INT_Y) {
    return Map_Array_14[INT_X][INT_Y];
}
void Root_Map_14::Print_Data() {
    std::cout.fill('0');
    for(int i0=0;i0<14;i0++){
        for(int i1=0;i1<14;i1++){
            std::cout.width(2);
            std::cout<<Map_Array_14[2*i1][2*i0];
            if(i1==13){
                break;
            }
            if(Map_Array_14[2*i1+1][2*i0]==0&&i1!=13){
                std::cout << " = ";
            }
            else{
                std::cout << " | ";
            }
        }
        std::cout<<std::endl;
        if(i0==13){
            break;
        }
        for(int i1=0;i1<14;i1++){
            if(Map_Array_14[2*i1][2*i0+1]==0){
                std::cout << "||   ";
            }
            else{
                std::cout << " -   ";
            }
        }
        std::cout<<std::endl;
    }
}
void Root_Map_14::Print_Root_Map() {
    for(int i0=0;i0<16;i0++){
        std::cout<<i0<<" "<<std::endl;
        for(int i1=0;i1<20;i1++) {
            std::cout<<" "<<std::endl;
            for (int i2 = 0; i2 < 13; i2++) {
                std::cout << "(" << Root_Map[i0][i1][i2][0] << "," << Root_Map[i0][i1][i2][1] << ")";
            }
            std::cout << std::endl;
        }
    }
}
