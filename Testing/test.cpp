#include <bits/stdc++.h>
using namespace std;

bool leapYearCheck(int year)
{
    bool check = false;
    if (year % 400 == 0)
    {
        check = true;
    }
    else if (year % 100 == 0)
    {
        check = false;
    }
    else if (year % 4 == 0)
    {
        check = true;
    }
    else
    {
        check = false;
    }

    return check;
}

void month_select(int MM,int &till,int &YYYY,string &monthName){
    switch (MM)
    {
    case 1:
        till = 31;
        monthName = "January";
        break;
    case 2:
    monthName = "February";
        if (leapYearCheck(YYYY))
        {
            till = 29;
        }
        else
        {
            till = 28;
        }
        break;
    case 3:
    monthName = "March";
        till = 31;
        break;
    case 4:
    monthName = "April";
        till = 30;
        break;
    case 5:
    monthName = "May";
        till = 31;
        break;
    case 6:
    monthName = "June";
        till = 30;
        break;
    case 7:
    monthName = "July";
        till = 31;
        break;
    case 8:
    monthName = "August";
        till = 30;
        break;
    case 9:
    monthName = "Septemper";
        till = 31;
        break;
    case 10:
    monthName = "October";
        till = 30;
        break;
    case 11:
    monthName = "November";
        till = 31;
        break;
    case 12:
    monthName = "December";
        till = 30;
        break;
    default:
    cout<<"Invalid Month!"<<endl;
    }
}

void month(int till, string month)
{

    cout << "--------------" << month << "----------------" << endl;
    cout << "  Mon   Tue   Wed   Thr   Fri   Sat   Sun" << endl;

    for (int i = 1; i <= till; i++)
    {
        string number;
        if (i < 10)
        {
            number = "0" + to_string(i);
            cout << "  " << number << "  ";
        }
        else
        {
            cout << "  " << i << "  ";
        }
        if (i % 7 == 0)
        {
            cout << endl;
        }
    }
}

int main()
{
    int till;
    string monthName;
    int DD,MM,YYYY;
    cin>>DD>>MM>>YYYY;
    month_select(MM,till,YYYY,monthName);
    month(till,monthName);


}
