#include <iostream>
#include <conio.h>
#include <functional>
#include <stdlib.h>
using namespace std;

struct product
{
    int id;
    string name;
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

product product_storage[100] = {
    {0, "Laptop", 100000},
    {1, "Mobile", 50000},
    {2, "TV", 70000},
    {3, "Refrigerator", 50000},
    {4, "Washing Machine", 50000}
};
purchase purchase_storage[100];
int product_id = 5;
int purchase_id = 0;
int total_products = 5;
int total_purchases = 0;

// Display Functions
void display_product(int i)
{
    cout << "\tProduct ID: "    << product_storage[i].id    << endl;
    cout << "\tProduct Name: "  << product_storage[i].name  << endl;
    cout << "\tProduct Price: " << product_storage[i].price << endl;
}
void list_all_products()
{
    cout << "==============================" << endl;
    cout << "*        Products List       *" << endl;
    cout << "==============================" << endl;
    for (int i = 0; i < total_products; i++)
    {
        cout << i << ") " << product_storage[i].name
             << " | Price: " << product_storage[i].price
             << endl;
    }
}
void display_purchase(int i)
{
    cout << "\tPurchase ID: "   << purchase_storage[i].id                           << endl;
    cout << "\tProduct ID: "    << purchase_storage[i].product_id                   << endl;
    cout << "\tCustomer Name: " << purchase_storage[i].customer_name                << endl;
    cout << "\tInitial Price: " << purchase_storage[i].initial_price                << endl;
    cout << "\tFinal Price: "   << purchase_storage[i].final_price                  << endl;
    cout << "\tIntallment per month: " << purchase_storage[i].installment_per_month << endl;
    cout << "\tMonths: "        << purchase_storage[i].months                       << endl;
}
void list_all_purchases()
{
    cout << "==============================" << endl;
    cout << "*        Purchases List      *" << endl;
    cout << "==============================" << endl;
    for (int i = 0; i < total_purchases; i++)
    {
        cout << i << ") " << purchase_storage[i].customer_name
             << " | Product ID: " << purchase_storage[i].product_id
             << " | Final Price: " << purchase_storage[i].final_price
             << endl;
    }
}

// Get Choice Functions
int get_choice(int min, int max, function<void()> func)
{
    int a;
    while (true)
    {
        a = getch();
        if(isdigit(a)) a = a - '0';
        if (a > max || a < min)
        {
            system("cls");
            cout << "Invalid Choice!\nTry again\n";
            func();
        }
        else
        {
            system("cls");
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
        a = getch();
        if (a > max || a < min)
        {
            system("cls");
            cout << "Invalid Choice!\nTry again\n";
            func();
        }
        else
        {
            system("cls");
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
    cout << "\t3) Report"                    << endl;
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
    cout << "\tc) Search by Purchase ID"     << endl;
    cout << "\td) Search by Customer Name"   << endl;
    cout << "\te) Go Back"                   << endl;
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

void add_product(int i)
{
    cout << "Product ID: " << i << endl;
    product_storage[i].id = i;
    cout << "Enter Product Name: ";
    cin >> product_storage[i].name;
    cout << "Enter Product Price: ";
    cin >> product_storage[i].price;
    system("cls");
}
void add_purchase(int i)
{
    cout << "Purchase ID: " << i << endl;
    purchase_storage[i].id = i;
    cout << "Enter Customer Name: ";
    cin >> purchase_storage[i].customer_name;

    if (total_products == 0)
    {
        cout << "No Products Available!" << endl;
        return;
    }
    else
        for (int i = 0; i < total_products; i++)
        {
            cout << i << ") " << product_storage[i].name
                << " | Price: " << product_storage[i].price
                << endl;
        }
    cout << "Enter Product ID: ";
    cin >> purchase_storage[i].product_id;
    product prod = product_storage[purchase_storage[i].product_id];
    cout << "You are purchasing " << prod.name << endl;
    cout << "Initial Price: " << prod.price << endl;
    cout << "Enter installment months: ";
    cin >> purchase_storage[i].months;
    purchase purch = purchase_storage[i];
    cout << purch.months << endl;
    float initial_pm = prod.price / purch.months;
    float markup = initial_pm * 0.2;
    float final_pm = initial_pm + markup;
    purchase_storage[i].installment_per_month = final_pm;
    purchase_storage[i].final_price = final_pm * purch.months;
    purchase_storage[i].initial_price = prod.price;

    system("cls");
}

void delete_product()
{
    if (total_products == 0)
    {
        cout << "No Products Available!" << endl;
        return;
    }
    else
    {
        while (true)
        {
            list_all_products();
            cout << "Enter Product ID: ";
            int id;
            cin >> id;
            if (id >= total_products || id < 0)
            {
                system("cls");
                cout << "Invalid ID!" << endl;
                cout << "Try Again!" << endl;
            }
            else
            {
                string temp = product_storage[id].name;
                for (int i = id; i < total_products; i++)
                {
                    product_storage[i].id = product_storage[i + 1].id;
                    product_storage[i].name = product_storage[i + 1].name;
                    product_storage[i].price = product_storage[i + 1].price;
                }
                total_products--;
                system("cls");
                cout << temp << " Deleted!" << endl;
                break;
            }
        }
    }
}
void delete_purchase()
{
    if (total_purchases == 0)
    {
        cout << "No Purchases Available!" << endl;
        return;
    }
    else
    {
        while (true)
        {
            list_all_purchases();
            cout << "Enter Purchase ID: ";
            int id;
            cin >> id;
            if (id >= total_purchases || id < 0)
            {
                system("cls");
                cout << "Invalid ID!" << endl;
                cout << "Try Again!" << endl;
            }
            else
            {
                string temp = purchase_storage[id].customer_name;
                for (int i = id; i < total_purchases; i++)
                {
                    purchase_storage[i].id = purchase_storage[i + 1].id;
                    purchase_storage[i].customer_name = purchase_storage[i + 1].customer_name;
                    purchase_storage[i].product_id = purchase_storage[i + 1].product_id;
                    purchase_storage[i].months = purchase_storage[i + 1].months;
                    purchase_storage[i].initial_price = purchase_storage[i + 1].initial_price;
                    purchase_storage[i].final_price = purchase_storage[i + 1].final_price;
                    purchase_storage[i].installment_per_month = purchase_storage[i + 1].installment_per_month;
                }
                total_purchases--;
                system("cls");
                cout << temp << " Deleted!" << endl;
                break;
            }
        }
    }
}

void update_product()
{
    if (total_products == 0)
    {
        cout << "No Products Available!" << endl;
        return;
    }
    else
    {
        while (true)
        {
            list_all_products();
            cout << "Enter Product ID: ";
            int id;
            cin >> id;
            if (id >= total_products || id < 0)
            {
                system("cls");
                cout << "Invalid ID!" << endl;
                cout << "Try Again!" << endl;
            }
            else
            {
                cout << "You are updating " << product_storage[id].name << endl;
                add_product(id);
                cout << "Product Updated!" << endl;
                cout << "====================================" << endl;
                display_product(id);
                cout << "====================================" << endl;
                break;
            }
        }
    }
}
void update_purchase()
{
    if (total_purchases == 0)
    {
        cout << "No Purchases Available!" << endl;
        return;
    }
    else
    {
        while (true)
        {
            for (int i = 0; i < total_purchases; i++)
            {
                cout << i << ") " << purchase_storage[i].customer_name
                     << " | Product: " << product_storage[purchase_storage[i].product_id].name
                     << endl;
            }
            cout << "Enter Purchase ID: ";
            int id;
            cin >> id;
            if (id >= total_purchases || id < 0)
            {
                system("cls");
                cout << "Invalid ID!" << endl;
                cout << "Try Again!" << endl;
            }
            else
            {
                cout << "You are updating " << purchase_storage[id].customer_name << endl;
                add_purchase(id);
                system("cls");
                cout << "Purchase Updated!" << endl;
                cout << "====================================" << endl;
                display_purchase(id);
                cout << "====================================" << endl;
                break;
            }
        }
    }
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
            add_product(total_products);
            cout << "Product Added!" << endl;
            cout << "====================================" << endl;
            display_product(total_products);
            cout << "====================================" << endl;
            total_products++;
            product_id++;
        }
        else if (ch == 'b')
        {
            add_purchase(total_purchases);
            cout << "Purchase Added!" << endl;
            cout << "====================================" << endl;
            display_purchase(total_purchases);
            cout << "====================================" << endl;
            total_purchases++;
            purchase_id++;
        }
        else if (ch == 'c')
        {
            system("cls");
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
            update_product();
        else if (ch == 'b')
        {
            update_purchase();
        }
        else if (ch == 'c')
        {
            system("cls");
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
            delete_product();
        }
        else if (ch == 'b')
        {
            delete_purchase();
        }
        else if (ch == 'c')
        {
            system("cls");
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
            if (total_products == 0)
            {
                cout << "No Products Available!" << endl;
                return;
            }
            else
            {
                cout << "====================================" << endl;
                for (int i = 0; i < total_products; i++)
                {
                    display_product(i);
                    cout << "====================================" << endl;
                }
            }
        }
        else if (ch == 'b')
        {
            if (total_purchases == 0)
            {
                cout << "No Purchases Available!" << endl;
                return;
            }
            else
            {
                cout << "====================================" << endl;
                for (int i = 0; i < total_purchases; i++)
                {
                    display_purchase(i);
                    cout << "====================================" << endl;
                }
            }
        }
        else if (ch == 'c')
        {
            system("cls");
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
            cout << "====================================" << endl;
            display_product(mid);
            cout << "====================================" << endl;
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
            cout << "====================================" << endl;
            display_product(i);
            cout << "====================================" << endl;
        }
    }
}
void purchase_id_search()
{
    cout << "Enter Purchase ID: ";
    int id;
    cin >> id;
    int low = 0;
    int high = total_purchases - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (id == purchase_storage[mid].id)
        {
            cout << "====================================" << endl;
            display_purchase(mid);
            cout << "====================================" << endl;
            break;
        }
        else if (id < purchase_storage[mid].id)
            high = mid - 1;
        else
            low = mid + 1;
    }
}
void purchase_customer_search()
{
    cout << "Enter Customer Name: ";
    string name;
    cin >> name;
    for (int i = 0; i < total_purchases; i++)
    {
        if (name == purchase_storage[i].customer_name)
        {
            cout << "====================================" << endl;
            display_purchase(i);
            cout << "====================================" << endl;
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
            update_data();
        else if (ch == 'c')
            delete_data();
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
        char ch = get_choice_char('a', 'e', search_data_options);
        if (ch == 'a')
            product_id_search();
        else if (ch == 'b')
            product_name_search();
        else if (ch == 'c')
            purchase_id_search();
        else if (ch == 'd')
            purchase_customer_search();
        else if (ch == 'e')
            break;
    }
}
void report()
{
    cout << "Total Products: " << total_products << endl;
    cout << "Total Purchases: " << total_purchases << endl;
}

int main()
{
    system("cls");
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
            report();
        else if (ch == 4)
        {
            goodbye();
            break;
        }
    }
    return 0;
}
