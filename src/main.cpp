#include <iostream>
#include "OrderBook.h"

int main() {
    OrderBook book;

    book.addOrder(Order(1, 'B', 100.50, 10));
    book.addOrder(Order(2, 'B', 101.00, 5));
    book.addOrder(Order(3, 'S', 102.25, 7));

    std::cout << "Best bid: " << book.bestBid() << std::endl;
    std::cout << "Best ask: " << book.bestAsk() << std::endl;

    book.cancelOrder(2);

    std::cout << "Best bid after cancel: " << book.bestBid() << std::endl;

    return 0;
}