#include <iostream>
#include "Order.h"
#include "PriceLevel.h"

int main()
{
    PriceLevel level(100.5);

    Order o1(1, 'B', 100.5, 10);
    Order o2(2, 'B', 100.5, 20);
    Order o3(3, 'B', 100.5, 30);

    level.addOrder(o1);
    level.addOrder(o2);
    level.addOrder(o3);

    std::cout << "Price: " << level.price << '\n';
    std::cout << "Orders: " << level.orders.size() << '\n';
    std::cout << "Total Quantity: " << level.totalQuantity << '\n';

    std::cout << "\nFIFO Order:\n";

    for (const auto &order : level.orders)
    {
        std::cout << order.id << " "
                  << order.quantity << '\n';
    }

    return 0;
}