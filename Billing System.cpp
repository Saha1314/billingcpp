#include <iostream>
#include <fstream>

using namespace std;

class shopping
{

private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void customer();
    void add();
    void edit();
    void rem();
    void tlist();
    void receipt();
};

void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t-----------------------------\n";
    cout << "\t\t\t\t                             \n";
    cout << "\t\t\t\t    Supermarket Main Menu    \n";
    cout << "\t\t\t\t                             \n";
    cout << "\t\t\t\t-----------------------------\n";
    cout << "\t\t\t\t                             \n";
    cout << "\t\t\t\t|   1)Administrator   |\n";
    cout << "\t\t\t\t                             \n";
    cout << "\t\t\t\t|   2)Customer        |\n";
    cout << "\t\t\t\t                             \n";
    cout << "\t\t\t\t|   3))Exit           |\n";
    cout << "\t\t\t\t                             \n";
    cout << "\n\t\t\t\t Please Select !";
    cin >> choice;

    switch (choice)
    {

    case 1:
    {
        cout << "\t\t\t\nLogin As Administrator  \n";
        cout << "\t\t\t\nEnter Email: ";
        cin >> email;
        cout << "\t\t\t Enter Password: ";
        cin >> password;
        if (email == "akmtme1234@gmail.com" && password == "akmtme1234")
        {
            administrator();
        }
        else
        {
            cout << "Invalid Email/Password";
        }
        break;
    }
    case 2:
    {
        customer();
    }
    case 3:
    {
        exit(0);
    }
    default:
        cout << "Invalid Choice !";
    }
    goto m;
}

void shopping::administrator()
{

m:
    int choice;
    cout << "\n\t\t\t Administrator Menu";
    cout << "\n\t\t\t|-----1)Add the Product-----|";
    cout << "\n\t\t\t|                           |";
    cout << "\n\t\t\t|-----2)Modify the Product--|";
    cout << "\n\t\t\t|                           |";
    cout << "\n\t\t\t|-----3)Delete the Product--|";
    cout << "\n\t\t\t|                           |";
    cout << "\n\t\t\t|-----4)Back to Main Menu---|";

    cout << "\n\n\t\t\t Please enter your choice ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "Invalid Choice !";
    }
    goto m;
}
void shopping::customer()
{

m:
    int choice;
    cout << "\t\t\t      Customer      \n";
    cout << "\t\t\t--------------------\n";
    cout << "                            ";
    cout << "\t\t\t1) Purchase Product \n";
    cout << "                            ";
    cout << "\t\t\t2) Go Back          \n";
    cout << "\t\t\t Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
    default:
        cout << "Invalid Choice !";
    }
    goto m;
}

void shopping::add()
{

m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Add New Product";
    cout << "\n\t\t\t Product code of the Product:";
    cin >> pcode;
    cout << "\n\t\t\t Name of the Product:";
    cin >> pname;
    cout << "\n\t\t\t Price of the Product:";
    cin >> price;
    cout << "\n\t\t\t Discount on the Product:";
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;

        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
            goto m;
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
    }
    cout << "Record Inserted...\n";
}

void shopping::edit()
{

    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t    Modify the Record";
    cout << "\n\t\t\t    Product Code:";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\nFile doesn't Exist1 ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t New code of Product:";
                cin >> c;
                cout << "\n\t\t Name of the Product:";
                cin >> n;
                cout << "\n\t\tPrice of the Product:";
                cin >> p;
                cout << "\n\t\t Discount:";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\nRecord Edited !";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\nRecord Not Found !";
        }
    }
}

void shopping ::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\t\t\t    Delete the Product record";
    cout << "\n\t\t\t    Product Code:";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\nFile doesn't Exist1 ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\nRecord Deleted !";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\nRecord Not Found !";
        }
    }
}

void shopping::tlist()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|---------------------------------------\n";
    cout << "ProNo\t\tName\t\tPrice\n";
    cout << "\n\n|---------------------------------------\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt()
{

    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int i;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File doesn't Exist !";
    }
    else
    {
        data.close();

        tlist();
        cout << "\n-----------------------------\n";
        cout << "\n                             \n";
        cout << "\n------Place the Order..------\n";
        cout << "\n                             \n";
        cout << "\n-----------------------------\n";
        do
        {
        m:
            cout << "\n\nEnter Product Code: ";
            cin >> arrc[c];
            cout << "\n\nEnter Product Quantity: ";
            cin >> arrq[c];
            for (i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate Product Code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout << "\n\nWilling to buy another product? If Yes then Press y else N";
            cin >> choice;
        } while (choice);

        cout << "\n\n\t\t\t-------------RECEIPT-----------\n";
        cout << "\nProduct No\t Product Quantity\t Price\t Amount\t Amount With Discount\n";

        for (i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total += dis;
                    cout << "\n"
                         << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t";
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n-----------------------------\n";
    cout << "\n Total Amount: " << total;
}

int main()
{
    shopping s;
    s.menu();
}
