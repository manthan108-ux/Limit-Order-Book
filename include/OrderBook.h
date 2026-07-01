#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#include <map>
#include <unordered_map>
#include <list>
#include <functional>
#include <iterator>

#include "PriceLevel.h"

class OrderBook {
public:
    // Bids sorted descending, asks sorted ascending
    std::map<double, PriceLevel, std::greater<double>> bids;
    std::map<double, PriceLevel> asks;

    // Order ID -> price level pointer + iterator to order
    std::unordered_map<int, std::pair<PriceLevel*, std::list<Order>::iterator>> orderMap;

    void addOrder(const Order &order) {
        if (order.side == 'B') {
            auto it = bids.find(order.price);

            if (it == bids.end()) {
                auto result = bids.emplace(order.price, PriceLevel(order.price));
                it = result.first;
            }

            PriceLevel &level = it->second;
            level.addOrder(order);

            auto orderIt = std::prev(level.orders.end());
            orderMap[order.id] = { &level, orderIt };
        } else {
            auto it = asks.find(order.price);

            if (it == asks.end()) {
                auto result = asks.emplace(order.price, PriceLevel(order.price));
                it = result.first;
            }

            PriceLevel &level = it->second;
            level.addOrder(order);

            auto orderIt = std::prev(level.orders.end());
            orderMap[order.id] = { &level, orderIt };
        }
    }

    bool cancelOrder(int orderId) {
        auto it = orderMap.find(orderId);

        if (it == orderMap.end()) {
            return false;
        }

        PriceLevel *level = it->second.first;
        auto orderIt = it->second.second;

        char side = orderIt->side;
        double price = level->price;

        level->removeOrder(orderIt);
        orderMap.erase(it);

        if (level->empty()) {
            if (side == 'B') {
                bids.erase(price);
            } else {
                asks.erase(price);
            }
        }

        return true;
    }

    double bestBid() const {
        return bids.empty() ? 0.0 : bids.begin()->first;
    }

    double bestAsk() const {
        return asks.empty() ? 0.0 : asks.begin()->first;
    }
};

#endif // ORDER_BOOK_H