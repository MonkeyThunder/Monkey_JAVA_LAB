#include <iostream>

class Root_Map_14{

private:
    int Map_Array_14[29][29];//14+15(Wall)
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

    void AStarAlgorithm(int Start_X, int Start_Y, int Dest_X, int Dest_Y);

    void FindRoute(int INT_Input);

    int Checking_Data(int INT_X, int INT_Y);
    void Print_Data();
    void Print_Root_Map();
};

void RootTypexy(int ForE, int Type, int *INT_X, int *INT_Y);

int main() {


    int Test_Num_01=40374;
    int Test_Num_02=10499;

    Root_Map_14 FirstSession;

    FirstSession.Root_Map_Initialize();

    FirstSession.Set_Flower();

    FirstSession.NumberToArray_14(Test_Num_01);
    FirstSession.NumberToArray_14(Test_Num_02);

    FirstSession.Print_Data();

    int Test_Type, Test_X01, Test_X02, Test_Y01, Test_Y02;
    FirstSession.NumberToArray_14(Test_Num_01,&Test_Type,&Test_X01,&Test_Y01);
    FirstSession.Center_Location(3,&Test_X02,&Test_Y02);

    FirstSession.AStarAlgorithm(Test_X01,Test_Y01,Test_X02,Test_Y02);

    //FirstSession.NumberToArray_14(Test_Num_02,&Test_Type,&Test_X,&Test_Y);

    //std::cout<< Test_Type << " " << Test_X << " " << Test_Y;

    return 0;
}

void Root_Map_14::Root_Map_Initialize() {
    memset(Map_Array_14,0,sizeof(Map_Array_14));
    memset(Root_Map,0,sizeof(Root_Map));
    for(int i0=0;i0<29;i0++){
        Map_Array_14[i0][0]=99;
        Map_Array_14[i0][28]=99;
        Map_Array_14[0][i0]=99;
        Map_Array_14[28][i0]=99;
    }
}
void Root_Map_14::Set_Flower() {
    for(int i0=11;i0<18;i0++){
        for(int i1=11;i1<18;i1++){
            Map_Array_14[i0][i1]=97;
        }
    }
}
void Root_Map_14::NumberToArray_14(int INT_Input) {
    int Buff_Num_X, Buff_Num_Y, Buff_Num_Type;

    Buff_Num_Type=(INT_Input%100);

    Buff_Num_Y=2*((INT_Input%10000-Buff_Num_Type)/100)-1;

    Buff_Num_X=2*(INT_Input/10000)-1;

    Map_Array_14[Buff_Num_X][Buff_Num_Y]=Buff_Num_Type;

    RootTypeToSetWall(Buff_Num_Type,Buff_Num_X,Buff_Num_Y);

    //std::cout<< Buff_Num_X << ", " << Buff_Num_Y << " = " << Buff_Num_Type <<std::endl;
}
void Root_Map_14::NumberToArray_14(int INT_Input, int *Type, int *INT_X, int *INT_Y) {

    *Type=(INT_Input%100);

    *INT_Y=2*((INT_Input%10000-*Type)/100)-1;

    *INT_X=2*(INT_Input/10000)-1;
}

void Root_Map_14::Center_Location(int Center_INDEX, int *INT_X, int *INT_Y) {
    switch (Center_INDEX)
    {
        case 0:
            *INT_X=11;
            *INT_Y=9;
            break;
        case 1:
            *INT_X=13;
            *INT_Y=9;
            break;
        case 2:
            *INT_X=15;
            *INT_Y=9;
            break;
        case 3:
            *INT_X=17;
            *INT_Y=9;
            break;
        case 4:
            *INT_X=19;
            *INT_Y=11;
            break;
        case 5:
            *INT_X=19;
            *INT_Y=13;
            break;
        case 6:
            *INT_X=19;
            *INT_Y=15;
            break;
        case 7:
            *INT_X=19;
            *INT_Y=17;
            break;
        case 8:
            *INT_X=17;
            *INT_Y=19;
            break;
        case 9:
            *INT_X=15;
            *INT_Y=19;
            break;
        case 10:
            *INT_X=13;
            *INT_Y=19;
            break;
        case 11:
            *INT_X=11;
            *INT_Y=19;
            break;
        case 12:
            *INT_X=9;
            *INT_Y=17;
            break;
        case 13:
            *INT_X=9;
            *INT_Y=15;
            break;
        case 14:
            *INT_X=9;
            *INT_Y=13;
            break;
        case 15:
            *INT_X=9;
            *INT_Y=11;
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
                if(INT_X<27){
                    Map_Array_14[INT_X+1][INT_Y]=99;
                }
                if(INT_X>0){
                    Map_Array_14[INT_X-1][INT_Y]=99;
                }
                break;
            case 2:
                if(INT_Y<27){
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
                if(INT_Y<27){
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
                if(INT_X<27){
                    Map_Array_14[INT_X+1][INT_Y]=99;
                }
                if(INT_Y>0){
                    Map_Array_14[INT_X][INT_Y-1]=99;
                }
                break;
            case 6:
                if(INT_X<27){
                    Map_Array_14[INT_X+1][INT_Y]=99;
                }
                if(INT_Y<27){
                    Map_Array_14[INT_X][INT_Y+1]=99;
                }
                break;
            default:
                break;
        }
    }
    else if(Type>70){
        switch (Buff_Num){
            case 1:
                    Map_Array_14[INT_X+1][INT_Y]=99;
                    Map_Array_14[INT_X-1][INT_Y]=99;
                    Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            case 2:
                    Map_Array_14[INT_X-1][INT_Y]=99;
                    Map_Array_14[INT_X][INT_Y-1]=99;
                    Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            case 3:
                    Map_Array_14[INT_X+1][INT_Y]=99;
                    Map_Array_14[INT_X-1][INT_Y]=99;
                    Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            case 4:
                    Map_Array_14[INT_X+1][INT_Y]=99;
                    Map_Array_14[INT_X][INT_Y-1]=99;
                    Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            case 8:
                    Map_Array_14[INT_X-1][INT_Y]=99;
                    Map_Array_14[INT_X+1][INT_Y]=99;
                    Map_Array_14[INT_X][INT_Y-1]=99;
                    Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            case 9:
                    Map_Array_14[INT_X-1][INT_Y]=99;
                    Map_Array_14[INT_X+1][INT_Y]=99;
                    Map_Array_14[INT_X][INT_Y-1]=99;
                    Map_Array_14[INT_X][INT_Y+1]=99;
                break;
            default:
                break;
        }
    }
}

void Root_Map_14::AStarAlgorithm(int Start_X, int Start_Y, int Dest_X, int Dest_Y){
    int CurrentDistance, Current_X, Current_Y, Buff_INT01, Buff_INT02;
    int Weight[36];
    int OpenNode[12][2], CloseNode[12][2];

    memset(OpenNode,0,sizeof(OpenNode)); memset(CloseNode,0, sizeof(CloseNode));
    Current_X=Start_X; Current_Y=Start_Y;
    Buff_INT01=0;
    for(int i0=0;i0<12;i0++){
        if(Current_X!=Dest_X||Current_Y!=Dest_Y){
            Buff_INT02=Buff_INT01;
            CloseNode[Buff_INT01][0]=Current_X; CloseNode[Buff_INT01][1]=Current_Y;
            if(Current_X<Dest_X&&Map_Array_14[Current_X+1][Current_Y]==0){
                Current_X=Current_X+2;
                Buff_INT01++;
            }
            else if(Current_X>Dest_X&&Map_Array_14[Current_X-1][Current_Y]==0){
                Current_X=Current_X-2;
                Buff_INT01++;
            }
            CloseNode[Buff_INT01][0]=Current_X; CloseNode[Buff_INT01][1]=Current_Y;
            if(Current_Y<Dest_Y&&Map_Array_14[Current_X][Current_Y+1]==0){
                Current_Y=Current_Y+2;
                Buff_INT01++;
            }
            else if(Current_Y>Dest_Y&&Map_Array_14[Current_X][Current_Y-1]==0){
                Current_Y=Current_Y-2;
                Buff_INT01++;
            }
            CloseNode[Buff_INT01][0]=Current_X; CloseNode[Buff_INT01][1]=Current_Y;
            if(Buff_INT01==Buff_INT02){
                if(Map_Array_14[Current_X+1][Current_Y]==0){
                    Current_X=Current_X+2;
                    Buff_INT01++;
                }
                else if(Map_Array_14[Current_X-1][Current_Y]==0){
                    Current_X=Current_X-2;
                    Buff_INT01++;
                }
                CloseNode[Buff_INT01][0]=Current_X; CloseNode[Buff_INT01][1]=Current_Y;
                if(Map_Array_14[Current_X][Current_Y+1]==0){
                    Current_Y=Current_Y+2;
                    Buff_INT01++;
                }
                else if(Map_Array_14[Current_X][Current_Y-1]==0){
                    Current_Y=Current_Y-2;
                    Buff_INT01++;
                }
                CloseNode[Buff_INT01][0]=Current_X; CloseNode[Buff_INT01][1]=Current_Y;
            }
        }
    }

    std::cout<<"Start = (" <<Start_X/2<<","<<Start_Y/2<<"), Desti = ("<<Dest_X/2<<", "<<Dest_Y/2<<")"<<std::endl;
    for(int i0=0;i0<12;i0++)
    {
        std::cout<<"("<<CloseNode[i0][0]/2<<","<<CloseNode[i0][1]/2<<") ";
    }
}

void Root_Map_14::FindRoute(int INT_Input){
    int Buff_Num_Type, Buff_Num_X, Buff_Num_X01, Buff_Num_X02, Buff_Num_Y, Buff_Num_Y01, Buff_Num_Y02;


    NumberToArray_14(INT_Input,&Buff_Num_Type,&Buff_Num_X,&Buff_Num_Y);

    Buff_Num_X01=Buff_Num_X; Buff_Num_X02=Buff_Num_X;
    Buff_Num_Y01=Buff_Num_Y; Buff_Num_Y02=Buff_Num_Y;

    if(Buff_Num_Type/10<7){
        RootTypexy(0,Buff_Num_Type,&Buff_Num_X01,&Buff_Num_Y01);

        RootTypexy(1,Buff_Num_Type,&Buff_Num_X02,&Buff_Num_Y02);
    }
    else if(Buff_Num_Type/10<8){

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
    for(int i0=0;i0<15;i0++){
        for(int i1=0;i1<14;i1++){
            if(Map_Array_14[2*i1+1][2*i0]==0){
                std::cout << "   ||";
            }
            else{
                std::cout << "   --";
            }
        }
        std::cout<<std::endl;
        if(i0==14){
            break;
        }
        for(int i1=0;i1<15;i1++){
            if(Map_Array_14[2*i1][2*i0+1]==0){
                std::cout << " = ";
            }
            else{
                std::cout << " | ";
            }
            if(i1==14){
                break;
            }
            std::cout.width(2);
            std::cout<<Map_Array_14[2*i1+1][2*i0+1];
        }
        std::cout<<std::endl;
        if(i0==13){
            //break;
        }

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
