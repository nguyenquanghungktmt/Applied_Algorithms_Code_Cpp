#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    char key_press;
    int ascii_value;
    cout<<"\n\t\tNhap phim bat ky de kiem tra ma ASCII\n\t\t\An ESC de thoat\n\n\n";
    while(1)
    {
        key_press=getch();
        ascii_value=key_press;
        if(ascii_value==3) // For ESC
            break;
        cout<<"Ban nhap phim-> \" "<<key_press<<" \" Gia tri ASCII =  "<<ascii_value<<"\n";
    }
    return 0;
}
