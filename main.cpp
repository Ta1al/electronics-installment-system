#include <iostream>
#include <functional>
#include <stdlib.h>
using namespace std;

struct product
{
    int id;
    char name[20];
    int price;
};
struct purchase
{
    int id;
    int product_id;
    string customer_name;
    int initial_price;
    int final_price;
    int installment_per_month;
    int months;
};

product product_storage[100];
purchase purchase_storage[100];
int total_products = 0;
int total_purchases = 0;

int get_choice(int min, int max, function<void()> func)
{
    int a;
    while (true)
    {
        cin >> a;
        if (a > max || a < min)
        {
            system("clear");
            cout << "Invalid Choice!\nTry again\n";
            func();
        }
        else
        {
            system("clear");
            break;
        }
    }
    return a;
}
char get_choice_char(char min, char max, function<void()> func)
{
    char a;
    while (true)
    {
        cin >> a;
        if (a > max || a < min)
        {
            system("clear");
            cout << "Invalid Choice!\nTry again\n";
            func();
        }
        else
        {
            system("clear");
            break;
        };
    }
    return a;
}

void welcome()
{
    cout << "********************************************" << endl;
    cout << "*              Welcome to the              *" << endl;
    cout << "*   Afzal Electronics Installment System   *" << endl;
    cout << "********************************************" << endl;
}
void goodbye()
{
    cout << "********************************************" << endl;
    cout << "*            Thank you for using           *" << endl;
    cout << "*   Afzal Electronics Installment System   *" << endl;
    cout << "*                 Goodbye!                 *" << endl;
    cout << "********************************************" << endl;
}

void menu()
{
    cout << "==============================" << endl;
    cout << "*         Main Menu          *" << endl;
    cout << "==============================" << endl;
    cout << "\t1) Manage Data"               << endl;
    cout << "\t2) Search"                    << endl;
    cout << "\t3) Reports"                   << endl;
    cout << "\t4) Exit"                      << endl;
}

// Main Menu Sub Options
void manage_data_options()
{
    cout << "==============================" << endl;
    cout << "*        Manage Menu         *" << endl;
    cout << "==============================" << endl;
    cout << "\ta) Add data"                  << endl;
    cout << "\tb) Update data"               << endl;
    cout << "\tc) Delete data"               << endl;
    cout << "\td) Display"                   << endl;
    cout << "\te) Go back"                   << endl;
}
void search_data_options()
{
    cout << "==============================" << endl;
    cout << "*        Search Menu         *" << endl;
    cout << "==============================" << endl;
    cout << "\ta) Search by Product ID"      << endl;
    cout << "\tb) Search by Product Name"    << endl;
    cout << "\tc) Search by Customer Name"   << endl;
    cout << "\td) Go Back"                   << endl;
}

// Manage Menu Options
void add_data_options()
{
    cout << "==============================" << endl;
    cout << "*        Add Menu            *" << endl;
    cout << "==============================" << endl;
    cout << "\ta) Add Product"               << endl;
    cout << "\tb) Add Purchase"              << endl;
    cout << "\tc) Go back"                   << endl;
}
void update_data_options()
{
    cout << "==============================" << endl;
    cout << "*        Update Menu         *" << endl;
    cout << "==============================" << endl;
    cout << "\ta) Update Product"            << endl;
    cout << "\tb) Update Purchase"           << endl;
    cout << "\tc) Go back"                   << endl;
}
void delete_data_options()
{
    cout << "==============================" << endl;
    cout << "*        Delete Menu         *" << endl;
    cout << "==============================" << endl;
    cout << "\ta) Delete Product"            << endl;
    cout << "\tb) Delete Purchase"           << endl;
    cout << "\tc) Go back"                   << endl;
}
void display_data_options()
{
    cout << "==============================" << endl;
    cout << "*        Display Menu        *" << endl;
    cout << "==============================" << endl;
    cout << "\ta) Display Products"          << endl;
    cout << "\tb) Display Purchases"         << endl;
    cout << "\tc) Go back"                   << endl;
}
void display_product(int i)
{
    cout << "\tProduct ID: "    << product_storage[i].id    << endl;
    cout << "\tProduct Name: "  << product_storage[i].name  << endl;
    cout << "\tProduct Price: " << product_storage[i].price << endl;
}
void display_purchase(int i)
{
    cout << "\tPurchase ID: "   << purchase_storage[i].id              << endl;
    cout << "\tProduct ID: "    << purchase_storage[i].product_id      << endl;
    cout << "\tCustomer Name: " << purchase_storage[i].customer_name   << endl;
    cout << "\tInitial Price: " << purchase_storage[i].initial_price   << endl;
    cout << "\tFinal Price: "   << purchase_storage[i].final_price     << endl;
    cout << "\tFinal Price: "   << purchase_storage[i].final_price     << endl;
}

// Manage Menu
void add_data()
{
    while (true)
    {
        add_data_options();
        char ch = get_choice_char('a', 'c', add_data_options);
        if (ch == 'a')
        {
            cout << "Product ID: " << total_products << endl;
            product_storage[total_products].id = total_products;
            cout << "Enter Product Name: ";
            cin >> product_storage[total_products].name;
            cout << "Enter Product Price: ";
            cin >> product_storage[total_products].price;
            system("clear");
            cout << "Product Added!"                                             << endl;
            cout << "===================================="                       << endl;
            cout << "\tProduct ID: "    << product_storage[total_products].id    << endl;
            cout << "\tProduct Name: "  << product_storage[total_products].name  << endl;
            cout << "\tProduct Price: " << product_storage[total_products].price << endl;
            cout << "===================================="                       << endl;
            total_products++;
        }
        else if (ch == 'b')
        {
            cout << "User Added" << endl;
        }
        else if (ch == 'c')
        {
            system("clear");
            break;
        }
    }
}
void update_data()
{
    while (true)
    {
        update_data_options();
        char ch = get_choice_char('a', 'c', update_data_options);
        if (ch == 'a')
        {
            cout << "Product Updated" << endl;
        }
        else if (ch == 'b')
        {
            cout << "User Updated" << endl;
        }
        else if (ch == 'c')
        {
            system("clear");
            break;
        }
    }
}
void delete_data()
{
    while (true)
    {
        delete_data_options();
        char ch = get_choice_char('a', 'c', delete_data_options);
        if (ch == 'a')
        {
            cout << "Product Deleted" << endl;
        }
        else if (ch == 'b')
        {
            cout << "User Deleted" << endl;
        }
        else if (ch == 'c')
        {
            system("clear");
            break;
        }
    }
}
void display_data()
{
    while (true)
    {
        display_data_options();
        char ch = get_choice_char('a', 'c', display_data_options);
        if (ch == 'a')
        {
            cout << "====================================" << endl;
            for (int i = 0; i < total_products; i++)
            {
                display_product(i);
                cout << "====================================" << endl;
            }
        }
        else if (ch == 'b')
        {
            cout << "====================================" << endl;
            for (int i = 0; i < total_purchases; i++)
            {
                display_purchase(i);
                cout << "====================================" << endl;
            }
        }
        else if (ch == 'c')
        {
            system("clear");
            break;
        }
    }
}

// Search Menu
void product_id_search()
{
    cout << "Enter Product ID: ";
    int id;
    cin >> id;
    int low = 0;
    int high = total_products - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (id == product_storage[mid].id)
        {
            cout << "===================================="              << endl;
            cout << "\tProduct ID: " << product_storage[mid].id         << endl;
            cout << "\tProduct Name: " << product_storage[mid].name     << endl;
            cout << "\tProduct Price: " << product_storage[mid].price   << endl;
            cout << "===================================="              << endl;
            break;
        }
        else if (id < product_storage[mid].id)
            high = mid - 1;
        else
            low = mid + 1;
    }
}
void product_name_search()
{
    cout << "Enter Product Name: ";
    string name;
    cin >> name;
    for (int i = 0; i < total_products; i++)
    {
        if (name == product_storage[i].name)
        {
            cout << "===================================="              << endl;
            cout << "\tProduct ID: " << product_storage[i].id           << endl;
            cout << "\tProduct Name: " << product_storage[i].name       << endl;
            cout << "\tProduct Price: " << product_storage[i].price     << endl;
            cout << "===================================="              << endl;
        }
    }
}

// Main Menu
void manage_data()
{
    while (true)
    {
        manage_data_options();
        char ch = get_choice_char('a', 'e', manage_data_options);
        if (ch == 'a')
            add_data();
        else if (ch == 'b')
            cout << "TBD" << endl;
        else if (ch == 'c')
            cout << "TBD" << endl;
        else if (ch == 'd')
            display_data();
        else if (ch == 'e')
            break;
    }
}
void search_data()
{
    while (true)
    {
        search_data_options();
        char ch = get_choice_char('a', 'd', search_data_options);
        if (ch == 'a')
            product_id_search();
        else if (ch == 'b')
            product_name_search();
        else if (ch == 'c')
            cout << "TBD" << endl;
        else if (ch == 'd')
            break;
    }
}
void reports()
{
    cout << "No data yet!" << endl;
}

int main()
{
    welcome();
    while (true)
    {
        menu();
        int ch = get_choice(1, 4, menu);
        if (ch == 1)
            manage_data();
        else if (ch == 2)
            search_data();
        else if (ch == 3)
            reports();
        else if (ch == 4)
        {
            goodbye();
            break;
        }
    }
    return 0;
}
