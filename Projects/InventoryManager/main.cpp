#include "inventoryManager.hpp"
#include <iostream>

void program_run()
{
    InventoryManager manager;
    int choice = 0;
    std::cout << "===== Welcome to Inventory Manager =====\n\n";
    while (choice != 10)
    {
        std::cout << "=== CHOICES ===\n";
        std::cout << "1. ADD Products to Inventory.\n";
        std::cout << "2. Remove Products from Inventory.\n";
        std::cout << "3. Total Products in Inventory.\n";
        std::cout << "4. Total value of Inventory.\n";
        std::cout << "5. Search a product in Inventory.\n";
        std::cout << "6. Information of all Products.\n ";
        std::cout << "ENTER 10 TO EXIT\n\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            manager.add_products_in_inventory();
            break;

        case 2:
            manager.remove_products_from_inventory();
            break;

        case 3:
            manager.total_products_in_inventory();
            break;

        case 4:
            manager.total_value_of_inventory();
            break;

        case 5:
            manager.search_a_product();
            break;

        case 6:
            manager.ProductsInfo();
            break;

        case 10:
            std::cout << "Exiting...";
            break;
        }
    }
}

int main()
{
    program_run();
}