#include <iostream>

class Root_Map_12{

private:
    int Map_Array_12[12][12];

public:
    void NumberToArray_12(int INT_Input);


    int Checking_Data(int INT_X, int INT_Y);
};

class Root_Map_14{

private:
    int Map_Array_14[14][14];

public:
    void NumberToArray_14(int INT_Input);


    int Checking_Data(int INT_X, int INT_Y);
};



int main() {


    int Test_Num_01=10199;
    int Test_Num_02=140143;
    int Test_Num_03=120199;

    Root_Map_14 FirstSession;

    FirstSession.NumberToArray_14(Test_Num_01);
    std::cout<< FirstSession.Checking_Data(1,1);



    return 0;
}

void Root_Map_12::NumberToArray_12(int INT_Input)
{
    int Buff_Num_X, Buff_Num_Y, Buff_Num_Type;

    Buff_Num_Type=INT_Input%100;

    Buff_Num_Y=(INT_Input%10000-Buff_Num_Type)/100;

    Buff_Num_X=INT_Input/10000;

    Map_Array_12[Buff_Num_X][Buff_Num_Y]=Buff_Num_Type;

    //std::cout<< Buff_Num_X << ", " << Buff_Num_Y << " = " << Buff_Num_Type <<std::endl;
}
void Root_Map_14::NumberToArray_14(int INT_Input)
{
    int Buff_Num_X, Buff_Num_Y, Buff_Num_Type;

    Buff_Num_Type=INT_Input%100;

    Buff_Num_Y=(INT_Input%10000-Buff_Num_Type)/100;

    Buff_Num_X=INT_Input/10000;

    Map_Array_14[Buff_Num_X][Buff_Num_Y]=Buff_Num_Type;

    //std::cout<< Buff_Num_X << ", " << Buff_Num_Y << " = " << Buff_Num_Type <<std::endl;
}
int Root_Map_12::Checking_Data(int INT_X, int INT_Y)
{
    return Map_Array_12[INT_X][INT_Y];
}
int Root_Map_14::Checking_Data(int INT_X, int INT_Y)
{
    return Map_Array_14[INT_X][INT_Y];
}
