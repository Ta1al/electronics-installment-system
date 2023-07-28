#include <iostream>
#include <functional>
#include <cstring>
#include <conio.h>
#include <ctime>

using namespace std;

const char title[] = R"(
                  ___   __          _   _____ _           _                   _                   
                 / _ \ / _|        | | |  ___| |         | |                 (_)                  
                / /_\ \ |_ ______ _| | | |__ | | ___  ___| |_ _ __ ___  _ __  _  ___ ___          
                |  _  |  _|_  / _` | | |  __|| |/ _ \/ __| __| '__/ _ \| '_ \| |/ __/ __|         
                | | | | |  / / (_| | | | |___| |  __/ (__| |_| | | (_) | | | | | (__\__ \         
                \_| |_/_| /___\__,_|_| \____/|_|\___|\___|\__|_|  \___/|_| |_|_|\___|___/         
                                                                                                  
                                                                                                  
         _____          _        _ _                      _     _____           _                 
        |_   _|        | |      | | |                    | |   /  ___|         | |                
          | | _ __  ___| |_ __ _| | |_ __ ___   ___ _ __ | |_  \ `--. _   _ ___| |_ ___ _ __ ___  
          | || '_ \/ __| __/ _` | | | '_ ` _ \ / _ \ '_ \| __|  `--. \ | | / __| __/ _ \ '_ ` _ \ 
         _| || | | \__ \ || (_| | | | | | | | |  __/ | | | |_  /\__/ / |_| \__ \ ||  __/ | | | | |
         \___/_| |_|___/\__\__,_|_|_|_| |_| |_|\___|_| |_|\__| \____/ \__, |___/\__\___|_| |_| |_|
                                                                       __/ |                      
                                                                       |___/                       
  )";
void ptitle()
{
  cout << title << endl;
}
// =========================== Classes ============================
// ===================== Input Helper Classes =====================
class Option
{
private:
  string name;
  function<void()> func;

public:
  friend class Menu;
  Option()
  {
    name = "";
    func = []()
    { cout << "No function assigned to this option" << endl; };
  }
  Option(string name, function<void()> func)
  {
    this->name = name;
    this->func = func;
  }
};

class Menu
{
private:
  string menu_name;
  Option menu_options[10];
  int menu_items_count;

public:
  Menu()
  {
    menu_name = "";
    menu_items_count = 0;
  }
  Menu(string name, Option options[], int items_count)
  {
    menu_name = name;
    menu_items_count = items_count;
    for (int i = 0; i < items_count; i++)
    {
      menu_options[i] = options[i];
    }
  }

  void display()
  {
    cout << "\t\t\t\t*****************************" << endl;
    int menu_name_length = menu_name.length();
    float half = menu_name_length / 2;
    bool is_even = menu_name_length % 2 == 0;
    cout << "\t\t\t\t*";
    for (int i = 0; i < 15 - (half + 2); i++)
    {
      cout << " ";
    }
    cout << menu_name;
    for (int i = 0; i < 15 - (is_even ? half + 1 : half + 2); i++)
    {
      cout << " ";
    }
    cout << "*" << endl;
    cout << "\t\t\t\t*****************************" << endl;

    for (int i = 0; i < menu_items_count - 1; i++)
    {
      cout << "\t\t\t\t\t";
      cout << i + 1 << ") " << menu_options[i].name << endl;
    }

    cout << "\n\t\t\t\t\t0) " << menu_options[menu_items_count - 1].name << endl;
  }

  void select(int c)
  {
    if (c == 0)
    {
      system("cls");
      ptitle();
      menu_options[menu_items_count - 1].func();
      return;
    }
    if (c > menu_items_count - 1)
    {
      system("cls");
      ptitle();
      cout << "Invalid option" << endl;
      return;
    }
    system("cls");
    ptitle();
    menu_options[c - 1].func();
  }
};
// ----------------------------------------------------------------
void run(Menu m)
{
  while (true)
  {
    m.display();
    int c;
    c = getch();
    if (isdigit(c))
      c = c - '0';
    m.select(c);
    if (c == 0)
      break;
  }
}
// ================== Product and Purchase Classes ================
class Product
{
private:
  int id;
  char name[20];
  float price;
  int quantity;

public:
  static int id_tracker;
  static int total;
  Product()
  {
    strcpy(name, "");
    id = -1;
    price = 0;
    quantity = 0;
  }
  Product(char name[], float price, int quantity)
  {
    strcpy(this->name, name);
    id = id_tracker++;
    total++;
    this->price = price;
    this->quantity = quantity;
  }
  void display()
  {
    cout << "\t\t\t\t============================" << endl;
    cout << "\t\t\t\t\tName: " << name << endl;
    cout << "\t\t\t\t\tID: " << id << endl;
    cout << "\t\t\t\t\tPrice: " << price << endl;
    cout << "\t\t\t\t\tQuantity: " << quantity << endl;
    cout << "\t\t\t\t============================" << endl;
  }
  void update(int id)
  {
    if (this->id == -1)
      total++;
    cout << "Updating product with ID " << id << endl;
    this->id = id;
    cout << "Enter new name: ";
    
    cin.getline(name, 20);
    cout << "Enter new price: ";
    cin >> price;
    cout << "Enter new quantity: ";
    cin >> quantity;
    system("cls");
    ptitle();
    cout << "Product updated successfully!" << endl;
    this->display();
  }
  void input()
  {
    cout << "Enter name: ";
    // cin.ignore();
    cin.getline(name, 20);
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter quantity: ";
    cin >> quantity;
    id = id_tracker++;
    total++;
    system("cls");
    ptitle();
    cout << "Product added successfully!" << endl;
    this->display();
  }
  int get_id()
  {
    return id;
  }
  char *get_name()
  {
    return name;
  }
  int get_price()
  {
    return price;
  }
  int get_quantity()
  {
    return quantity;
  }
  void set_quantity(int quantity)
  {
    this->quantity = quantity;
  }
};
// ----------------------------------------------------------------
Product products[100] = {
    Product("Air Conditioner", 50000, 45),
    Product("Refrigerator", 40000, 50),
    Product("Washing Machine", 30000, 55),
    Product("Television", 20000, 40),
    Product("Microwave", 10000, 65),
    Product("Juicer", 5000, 70),
    Product("Blender", 4000, 55),
    Product("Toaster", 3000, 70),
    Product("Kettle", 2000, 55),
    Product("Iron", 1000, 80),
    Product("Vacuum Cleaner", 10000, 75),
    Product("Fan", 5000, 60),
};
int Product::id_tracker = 0;
int Product::total = 0;
// ----------------------------------------------------------------
class Purchase
{
private:
  int id;
  int product_id;
  int quantity;
  int months;
  float initial_price;
  float final_price;
  float monthly_payment;
  char customer_name[20];
  char seller_name[20];
  string timestamp;

public:
  static int id_tracker;
  static int total;
  Purchase()
  {
    id = -1;
    product_id = -1;
    quantity = 0;
    months = 0;
    initial_price = 0;
    final_price = 0;
    monthly_payment = 0;
    strcpy(customer_name, "");
    strcpy(seller_name, "");
    time_t now = time(0);
    timestamp = ctime(&now);
  }
  Purchase(int product_id, int quantity, int months, char customer_name[], char seller_name[])
  {
    if (quantity > products[product_id].get_quantity())
    {
      cout << "Not enough quantity" << endl;
      Purchase();
      return;
    }
    id = id_tracker++;
    total++;
    this->product_id = product_id;
    this->quantity = quantity;
    products[product_id].set_quantity(products[product_id].get_quantity() - quantity);
    this->months = months;
    this->initial_price = products[product_id].get_price() * quantity;
    this->final_price = initial_price * (1 + 0.1 * months);
    this->monthly_payment = final_price / months;
    strcpy(this->customer_name, customer_name);
    strcpy(this->seller_name, seller_name);

    time_t now = time(0);
    timestamp = ctime(&now);
  }
  void display()
  {
    cout << "\t\t\t\t============================" << endl;
    cout << "\t\t\t\t   ID: " << id << endl;
    cout << "\t\t\t\t   Product ID: " << product_id << endl;
    cout << "\t\t\t\t   Quantity: " << quantity << endl;
    cout << "\t\t\t\t   Months: " << months << endl;
    cout << "\t\t\t\t   Initial price: " << initial_price << endl;
    cout << "\t\t\t\t   Final price: " << final_price << endl;
    cout << "\t\t\t\t   Monthly payment: " << monthly_payment << endl;
    cout << "\t\t\t\t   Customer name: " << customer_name << endl;
    cout << "\t\t\t\t   Seller name: " << seller_name << endl;
    cout << "\t\t\t\t   Timestamp: " << timestamp;
    cout << "\t\t\t\t============================" << endl;
  }
  void input()
  {
    while (true)
    {
      cout << "Enter product ID: ";
      cin >> product_id;
      if (product_id >= Product::id_tracker)
      {
        cout << "Invalid ID" << endl;
        continue;
      }
      if (products[product_id].get_id() == -1)
      {
        cout << "Product with ID " << product_id << " has been deleted" << endl;
        continue;
      }
      break;
    }
    while (true)
    {
      cout << "Enter quantity: ";
      cin >> quantity;
      if (quantity > products[product_id].get_quantity())
      {
        cout << "Not enough quantity" << endl;
        cout << "Available quantity: " << products[product_id].get_quantity() << endl;
        continue;
      }
      break;
    }
    cout << "Enter months: ";
    cin >> months;
    cout << "Enter customer name: ";
    cin.ignore();
    cin.getline(customer_name, 20);
    cout << "Enter seller name: ";
    cin.getline(seller_name, 20);
    id = id_tracker++;
    total++;
    products[product_id].set_quantity(products[product_id].get_quantity() - quantity);
    initial_price = products[product_id].get_price() * quantity;
    final_price = initial_price * (1 + 0.1 * months);
    monthly_payment = final_price / months;
    time_t now = time(0);
    timestamp = ctime(&now);
    system("cls");
    ptitle();
    cout << "Purchase added successfully!" << endl;
    this->display();
  }
  void update(int id)
  {
    if (this->id == -1)
      total++;
    cout << "Updating purchase with ID " << id << endl;
    this->id = id;

    while (true)
    {
      cout << "Enter product ID: ";
      cin >> product_id;
      if (product_id >= Product::id_tracker)
      {
        cout << "Invalid ID" << endl;
        continue;
      }
      if (products[product_id].get_id() == -1)
      {
        cout << "Product with ID " << product_id << " has been deleted" << endl;
        continue;
      }
      break;
    }
    products[product_id].set_quantity(products[product_id].get_quantity() + quantity);
    while (true)
    {
      cout << "Enter quantity: ";
      cin >> quantity;
      if (quantity > products[product_id].get_quantity())
      {
        cout << "Not enough quantity" << endl;
        cout << "Available quantity: " << products[product_id].get_quantity() << endl;
        continue;
      }
      break;
    }
    cout << "Enter months: ";
    cin >> months;
    cout << "Enter customer name: ";
    cin.ignore();
    cin.getline(customer_name, 20);
    products[product_id].set_quantity(products[product_id].get_quantity() - quantity);
    initial_price = products[product_id].get_price() * quantity;
    final_price = initial_price * (1 + 0.1 * months);
    monthly_payment = final_price / months;
    system("cls");
    ptitle();
    cout << "Purchase updated successfully!" << endl;
    this->display();
  }
  int get_id()
  {
    return id;
  }
  int get_product_id()
  {
    return product_id;
  }
  int get_quantity()
  {
    return quantity;
  }
  char *get_customer_name()
  {
    return customer_name;
  }
  char *get_seller_name()
  {
    return seller_name;
  }
  int get_months()
  {
    return months;
  }
  string get_timestamp()
    {
      return timestamp;
    }
  float get_monthly_payment()
  {
    return monthly_payment;
  }
};
// ----------------------------------------------------------------
Purchase purchases[100] = {
    Purchase(0, 4, 2, "Ali", "Usman"),
    Purchase(1, 19, 3, "Sajid", "Danish"),
    Purchase(2, 15, 4, "Amir", "Usman"),
    Purchase(3, 4, 5, "Qasim", "Haroon"),
    Purchase(4, 12, 6, "Asif", "Usman"),
    Purchase(5, 4, 7, "Munir", "Akbar"),
    Purchase(6, 2, 8, "Kabeer", "Anas"),
    Purchase(3, 7, 9, "Mubashir", "Karim"),
    Purchase(5, 3, 10, "Abid", "Usman"),
    Purchase(9, 11, 2, "Javed", "Asim"),
};
int Purchase::id_tracker = 0;
int Purchase::total = 0;

// ======================= Options and Menus ======================
Option back(
    "Back",
    []()
    { system("cls"); ptitle(); });
// =================== 1.1.1 | Add Data ========================
Option add_product(
    "Add Product",
    []()
    {
      products[Product::id_tracker] = Product();
      products[Product::id_tracker].input();
    });
Option add_purchase(
    "Add Purchase",
    []()
    {
      purchases[Purchase::id_tracker] = Purchase();
      purchases[Purchase::id_tracker].input();
    });
// ---------------------------------------------------------
Option add_data_options[] = {add_product, add_purchase, back};
Menu add_data_submenu("Add Data", add_data_options, 3);
// =================== 1.1.2 | Update Data =====================
Option update_product(
    "Update Product",
    []()
    {
      while (true)
      {
        cout << "Enter product ID: ";
        int id;
        cin >> id;
        if (id >= Product::id_tracker)
        {
          cout << "Invalid ID" << endl;
          continue;
        }
        products[id].update(id);
        break;
      }
    });
Option update_purchase(
    "Update Purchase",
    []()
    {
      while (true)
      {
        cout << "Enter purchase ID: ";
        int id;
        cin >> id;
        if (id >= Purchase::id_tracker)
        {
          cout << "Invalid ID" << endl;
          continue;
        }
        purchases[id].update(id);
        break;
      }
    });
// ---------------------------------------------------------
Option update_data_options[] = {update_product, update_purchase, back};
Menu update_data_submenu("Update Data", update_data_options, 3);
// =================== 1.1.3 | Delete Data =====================
Option delete_product(
    "Delete Product",
    []()
    {
      while (true)
      {
        cout << "Enter product ID: ";
        int id;
        cin >> id;
        system("cls");
        ptitle();
        if (id >= Product::id_tracker)
        {
          cout << "Invalid ID" << endl;
          continue;
        }
        products[id] = Product();
        Product::total--;
        cout << "Product deleted successfully!" << endl;
        break;
      }
    });
Option delete_purchase(
    "Delete Purchase",
    []()
    {
      while (true)
      {
        cout << "Enter purchase ID: ";
        int id;
        cin >> id;
        system("cls");
        ptitle();
        if (id >= Purchase::id_tracker)
        {
          cout << "Invalid ID" << endl;
          continue;
        }
        if (purchases[id].get_id() == -1)
        {
          cout << "Purchase with ID " << id << " has been deleted" << endl;
          continue;
        }
        if (products[purchases[id].get_product_id()].get_id() != -1)
        {
          products[purchases[id].get_product_id()].set_quantity(products[purchases[id].get_product_id()].get_quantity() + purchases[id].get_quantity());
        }
        purchases[id] = Purchase();
        Purchase::total--;
        cout << "Purchase deleted successfully!" << endl;
        break;
      }
    });
// ---------------------------------------------------------
Option delete_data_options[] = {delete_product, delete_purchase, back};
Menu delete_data_submenu("Delete Data", delete_data_options, 3);
// =================== 1.1.4 | Display Data ====================
Option display_product(
    "Display Product",
    []()
    {
      system("cls");
      ptitle();
      for (int i = 0; i < Product::id_tracker; i++)
      {
        if (products[i].get_id() == -1)
          continue;
        cout << "\t\t\t\t" << products[i].get_id() << ") ";
        cout << products[i].get_name() << " | " << products[i].get_quantity() << " available | RS/= " << products[i].get_price() << endl;
      }
    });
Option display_purchase(
    "Display Purchase",
    []()
    {
      system("cls");
      ptitle();
      for (int i = 0; i < Purchase::id_tracker; i++)
      {
        if (purchases[i].get_id() == -1)
          continue;
        cout << "\t" << purchases[i].get_id() << ") ";
        cout << purchases[i].get_customer_name() << " bought " << purchases[i].get_quantity() << " " << products[purchases[i].get_product_id()].get_name() << " from " << purchases[i].get_seller_name() << " at RS/= " << purchases[i].get_monthly_payment() << " per month for " << purchases[i].get_months() << " months on " << purchases[i].get_timestamp();  
      }
    });
// ---------------------------------------------------------
Option display_data_options[] = {display_product, display_purchase, back};
Menu display_data_submenu("Display Data", display_data_options, 3);
// =================== 1.1.0 | Manage Menu =====================
Option add_data(
    "Add Data",
    []()
    { run(add_data_submenu); });
Option update_data(
    "Update Data",
    []()
    { run(update_data_submenu); });
Option delete_data(
    "Delete Data",
    []()
    { run(delete_data_submenu); });
Option display_data(
    "Display Data",
    []()
    { run(display_data_submenu); });
// ---------------------------------------------------------
Option manage_menu_options[] = {add_data, update_data, delete_data, display_data, back};
Menu manage_submenu("Manage Data", manage_menu_options, 5);
// =================== 1.2.1 | Search Product ==================
Option search_by_id(
    "Search by ID",
    []()
    {
      while (true)
      {
        cout << "Enter product ID: ";
        int id;
        cin >> id;
        system("cls");
        ptitle();
        if (id >= Product::id_tracker)
        {
          cout << "Invalid ID" << endl;
          continue;
        }
        if (products[id].get_id() == -1)
          cout << "Product with ID " << id << " has been deleted" << endl;
        else
          products[id].display();
        break;
      }
    });
Option search_by_name(
    "Search by Name",
    []()
    {
      cout << "Enter product name: ";
      char name[20];
      
      cin.getline(name, 20);
      bool found = false;
      system("cls");
      ptitle();
      for (int i = 0; i < Product::id_tracker; i++)
      {
        if (strcmp(products[i].get_name(), name) == 0)
        {
          products[i].display();
          found = true;
          break;
        }
      }
      if (!found)
      {
        system("cls");
        ptitle();
        cout << "No product found with name " << name << endl;
      }
    });
Option search_by_price(
    "Search by Price",
    []()
    {
      cout << "Enter product price: ";
      float price;
      cin >> price;
      bool found = false;
      system("cls");
      ptitle();
      for (int i = 0; i < Product::id_tracker; i++)
      {
        if (products[i].get_price() == price)
        {
          found = true;
          products[i].display();
        }
      }
      if (!found)
      {
        system("cls");
        ptitle();
        cout << "No product found with price " << price << endl;
      }
    });
// ---------------------------------------------------------
Option search_product_options[] = {search_by_id, search_by_name, search_by_price, back};
Menu search_product_submenu("Search Product", search_product_options, 4);
// =================== 1.2.2 | Search Purchase =================
Option search_purchase_by_id(
    "Search by ID",
    []()
    {
      while (true)
      {
        cout << "Enter purchase ID: ";
        int id;
        cin >> id;
        system("cls");
        ptitle();
        if (id >= Purchase::id_tracker)
        {
          cout << "Invalid ID" << endl;
          continue;
        }
        if (purchases[id].get_id() == -1)
          cout << "Purchase with ID " << id << " has been deleted" << endl;
        else
          purchases[id].display();
        break;
      }
    });
Option search_purchase_by_product_id(
    "Search by Product ID",
    []()
    {
      cout << "Enter product ID: ";
      int product_id;
      cin >> product_id;
      bool found = false;
      system("cls");
      ptitle();
      for (int i = 0; i < Purchase::id_tracker; i++)
      {
        if (purchases[i].get_product_id() == product_id)
        {
          found = true;
          purchases[i].display();
        }
      }
      if (!found)
      {
        system("cls");
        ptitle();
        cout << "No purchase found with product ID " << product_id << endl;
      }
    });
Option search_purchase_by_customer_name(
    "Search by Customer Name",
    []()
    {
      cout << "Enter customer name: ";
      char name[20];
      
      cin.getline(name, 20);
      bool found = false;
      system("cls");
      ptitle();
      for (int i = 0; i < Purchase::id_tracker; i++)
      {
        if (strcmp(purchases[i].get_customer_name(), name) == 0)
        {
          purchases[i].display();
          found = true;
        }
      }
      if (!found)
      {
        system("cls");
        ptitle();
        cout << "No purchase found with customer name " << name << endl;
      }
    });
Option search_purchase_by_seller_name(
    "Search by Seller Name",
    []()
    {
      cout << "Enter seller name: ";
      char name[20];
      
      cin.getline(name, 20);
      bool found = false;
      system("cls");
      ptitle();
      for (int i = 0; i < Purchase::id_tracker; i++)
      {
        if (strcmp(purchases[i].get_seller_name(), name) == 0)
        {
          purchases[i].display();
          found = true;
        }
      }
      if (!found)
      {
        system("cls");
        ptitle();
        cout << "No purchase found with seller name " << name << endl;
      }
    });
// ---------------------------------------------------------
Option search_purchase_options[] = {search_purchase_by_id, search_purchase_by_product_id, search_purchase_by_customer_name,search_purchase_by_seller_name, back};
Menu search_purchase_submenu("Search Purchase", search_purchase_options, 5);
// =================== 1.2.0 | Search Menu =====================
Option search_product(
    "Search Product",
    []()
    { run(search_product_submenu); });
Option search_purchase(
    "Search Purchase",
    []()
    { run(search_purchase_submenu); });
// ---------------------------------------------------------
Option search_menu_options[] = {search_product, search_purchase, back};
Menu search_submenu("Search Data", search_menu_options, 3);
// =================== 1.0.0 | Main Menu =======================
Option manage_menu(
    "Manage Data",
    []()
    { run(manage_submenu); });
Option search_menu(
    "Search Data",
    []()
    { run(search_submenu); });
Option reports(
    "Reports",
    []()
    {
      int total_quantity = 0;
      for (int i = 0; i < Product::id_tracker; i++)
      {
        if (products[i].get_id() == -1)
          continue;
        total_quantity += products[i].get_quantity();
      }
      system("cls");
      ptitle();
      cout << "\t\t\t\t============================" << endl;
      cout << "\t\t\t\t    Total products: " << Product::total << endl;
      cout << "\t\t\t\t    Total quantity: " << total_quantity << endl;
      cout << "\t\t\t\t    Total purchases: " << Purchase::total << endl;
      cout << "\t\t\t\t============================" << endl;
    });

Option exitprogram(
    "Exit",
    []()
    { cout << "Exiting..." << endl; exit(0); });
// ---------------------------------------------------------
Option main_menu_options[] = {manage_menu, search_menu, reports, exitprogram};
Menu main_menu("Main Menu", main_menu_options, 4);
// =============================================================

// ============================ Main ==============================
int main()
{
  system("cls");
  ptitle();
  run(main_menu);
  return 0;
}