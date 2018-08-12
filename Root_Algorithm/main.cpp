#include <iostream>

class Root_Map_12{

private:
    int Map_Array_12[12][12];
    int Root_Map[16][9][2];

public:
    void NumberToArray_12(int INT_Input);


    int Checking_Data(int INT_X, int INT_Y);
};

class Root_Map_14{

private:
    int Map_Array_14[14][14];
    int Root_Map[16][13][2];

public:
    void NumberToArray_14(int INT_Input);
    void LinkToCenter(int INT_Input);


    int Checking_Data(int INT_X, int INT_Y);
};

void Root_Type_xy(int ForE, int Type, int *INT_X, int *INT_Y);

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
void Root_Map_14::LinkToCenter(int INT_Input)
{
    int Buff_Num_X, Buff_Num_Y, Buff_Num_Type;

    Buff_Num_Type=INT_Input%100;

    Buff_Num_Y=(INT_Input%10000-Buff_Num_Type)/100;

    Buff_Num_X=INT_Input/10000;

    Map_Array_14[Buff_Num_X][Buff_Num_Y]=Buff_Num_Type;



}

void Root_Type_xy(int ForE, int Type,int *INT_X, int *INT_Y)
{
    int Buff_Num01;

    Buff_Num01=Type%10;

    if(Type>70)
    {
        switch(Buff_Num01)
        {
            case 3:
                   *INT_Y=*INT_Y-1;
                break;
            case 4:
                   *INT_X=*INT_X+1;
                break;
            case 5:
                   *INT_Y=*INT_Y+1;
                break;
            case 6:
                   *INT_X=*INT_X-1;
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
                    *INT_Y=*INT_Y-1;
                }
                else
                {
                    *INT_Y=*INT_Y+1;
                }
                break;
            case 4:
                if(ForE==0)
                {
                    *INT_X=*INT_X-1;
                }
                else
                {
                    *INT_X=*INT_X+1;
                }
                break;
            case 5:
                if(ForE==0)
                {
                    *INT_Y=*INT_Y-1;
                }
                else
                {
                    *INT_X=*INT_X+1;
                }
                break;
            case 6:
                if(ForE==0)
                {
                    *INT_X=*INT_X+1;
                }
                else
                {
                    *INT_Y=*INT_Y+1;
                }
                break;
            case 7:
                if(ForE==0)
                {
                    *INT_X=*INT_X-1;
                }
                else
                {
                    *INT_Y=*INT_Y+1;
                }
                break;
            case 8:
                if(ForE==0)
                {
                    *INT_Y=*INT_Y-1;
                }
                else
                {
                    *INT_X=*INT_X-1;
                }
                break;
            default:
                break;
        }
    }


}

int Root_Map_12::Checking_Data(int INT_X, int INT_Y)
{
    return Map_Array_12[INT_X][INT_Y];
}
int Root_Map_14::Checking_Data(int INT_X, int INT_Y)
{
    return Map_Array_14[INT_X][INT_Y];
}
