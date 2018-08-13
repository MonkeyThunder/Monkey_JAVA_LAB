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
    void Center_Location(int Center_INDEX, int *INT_X, int *INT_Y);
    int DistanceToCenter(int Center_INDEX, int INT_X, int INT_Y);

    void LinkToCenter(int INT_Input);

    int Checking_Data(int INT_X, int INT_Y);
};

void Root_Type_xy(int ForE, int Type, int *INT_X, int *INT_Y);

int main() {


    int Test_Num_01=10199;
    int Test_Num_02=140143;
    int Test_Num_03=120199;

    Root_Map_14 FirstSession;

    FirstSession.LinkToCenter(Test_Num_01);
    std::cout<<std::endl;
    FirstSession.LinkToCenter(Test_Num_02);

    std::cout<< FirstSession.Checking_Data(0,0) <<std::endl;
    std::cout<< FirstSession.Checking_Data(13,0) <<std::endl;


    return 0;
}

void Root_Map_12::NumberToArray_12(int INT_Input)
{
    int Buff_Num_X, Buff_Num_Y, Buff_Num_Type;

    Buff_Num_Type=INT_Input%100;

    Buff_Num_Y=(INT_Input%10000-Buff_Num_Type)/100;

    Buff_Num_X=INT_Input/10000;

    Map_Array_12[Buff_Num_X-1][Buff_Num_Y-1]=Buff_Num_Type;

    //std::cout<< Buff_Num_X << ", " << Buff_Num_Y << " = " << Buff_Num_Type <<std::endl;
}

void Root_Map_14::NumberToArray_14(int INT_Input)
{
    int Buff_Num_X, Buff_Num_Y, Buff_Num_Type;

    Buff_Num_Type=INT_Input%100;

    Buff_Num_Y=(INT_Input%10000-Buff_Num_Type)/100;

    Buff_Num_X=INT_Input/10000;

    Map_Array_14[Buff_Num_X-1][Buff_Num_Y-1]=Buff_Num_Type;

    //std::cout<< Buff_Num_X << ", " << Buff_Num_Y << " = " << Buff_Num_Type <<std::endl;
}
void Root_Map_14::Center_Location(int Center_INDEX, int *INT_X, int *INT_Y)
{
    switch (Center_INDEX)
    {
        case 1:
            *INT_X=5;
            *INT_Y=3;
            break;
        case 2:
            *INT_X=6;
            *INT_Y=3;
            break;
        case 3:
            *INT_X=7;
            *INT_Y=3;
            break;
        case 4:
            *INT_X=8;
            *INT_Y=3;
            break;
        case 5:
            *INT_X=10;
            *INT_Y=5;
            break;
        case 6:
            *INT_X=10;
            *INT_Y=6;
            break;
        case 7:
            *INT_X=10;
            *INT_Y=7;
            break;
        case 8:
            *INT_X=10;
            *INT_Y=8;
            break;
        case 9:
            *INT_X=8;
            *INT_Y=10;
            break;
        case 10:
            *INT_X=7;
            *INT_Y=10;
            break;
        case 11:
            *INT_X=6;
            *INT_Y=10;
            break;
        case 12:
            *INT_X=5;
            *INT_Y=10;
            break;
        case 13:
            *INT_X=3;
            *INT_Y=8;
            break;
        case 14:
            *INT_X=3;
            *INT_Y=7;
            break;
        case 15:
            *INT_X=3;
            *INT_Y=6;
            break;
        case 16:
            *INT_X=3;
            *INT_Y=5;
            break;
        default:
            break;
    }
}
int Root_Map_14::DistanceToCenter(int Center_INDEX, int INT_X, int INT_Y)
{
    if(INT_X<9&&INT_Y<9)
    {

    }
    else if(INT_X>4&&INT_Y<9)
    {

    }
    else if(INT_X>4&&INT_Y>4)
    {

    }
    else if(INT_X<9&&INT_Y>4)
    {

    }
    else
    {
        return 0;
    }
}

void Root_Map_14::LinkToCenter(int INT_Input)
{
    int Buff_Num_X, Buff_Num_Y, Buff_Num_Type;

    Buff_Num_Type=INT_Input%100;

    Buff_Num_Y=(INT_Input%10000-Buff_Num_Type)/100;

    Buff_Num_X=INT_Input/10000;

    Map_Array_14[Buff_Num_X-1][Buff_Num_Y-1]=Buff_Num_Type;

    //std::cout<<Buff_Num_X<<", "<<Buff_Num_Y<<std::endl;

    Root_Type_xy(0,Buff_Num_Type,&Buff_Num_X,&Buff_Num_Y);

    //std::cout<<Buff_Num_X<<", "<<Buff_Num_Y<<std::endl;



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
