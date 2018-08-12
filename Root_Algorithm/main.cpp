#include <iostream>

class Root_Map_12{

private:
    int Map_Array_12[12][12];

public:
    void NumberToArray_12(int INT_Input,int INT_Output[12][12]);


};

class Root_Map_14{

private:
    int Map_Array_14[14][14];

public:
    void NumberToArray_14(int INT_Input,int INT_Output[14][14]);


};



int main() {


    int Test_Num_01=10199;
    int Test_Num_02=140143;
    int Test_Num_03=120199;



    return 0;
}

void Root_Map_12::NumberToArray_12(int INT_Input,int INT_Output[12][12])
{
    int Buff_Num_X, Buff_Num_Y, Buff_Num_Type;

    Buff_Num_Type=INT_Input%100;

    Buff_Num_Y=(INT_Input%10000-Buff_Num_Type)/100;

    Buff_Num_X=INT_Input/10000;

    INT_Output[Buff_Num_X][Buff_Num_Y]=Buff_Num_Type;

    //std::cout<< Buff_Num_X << ", " << Buff_Num_Y << " = " << Buff_Num_Type <<std::endl;
}
void Root_Map_14::NumberToArray_14(int INT_Input,int INT_Output[14][14])
{
    int Buff_Num_X, Buff_Num_Y, Buff_Num_Type;

    Buff_Num_Type=INT_Input%100;

    Buff_Num_Y=(INT_Input%10000-Buff_Num_Type)/100;

    Buff_Num_X=INT_Input/10000;

    INT_Output[Buff_Num_X][Buff_Num_Y]=Buff_Num_Type;

    //std::cout<< Buff_Num_X << ", " << Buff_Num_Y << " = " << Buff_Num_Type <<std::endl;
}