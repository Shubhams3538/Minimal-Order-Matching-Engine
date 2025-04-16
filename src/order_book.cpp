#include "../include/order_book.hpp"
#include <iostream>

// Adds an order to the book and tries to match orders
void OrderBook::addOrder(const Order& order) {
    if (order.side == Side::BUY) {
        buyOrders.insert({order.price, order});
    } else {
        sellOrders.insert({order.price, order});
    }

    matchOrders();  // Match top-of-book after each insertion
}

// Core matching logic for best buy and sell orders
void OrderBook::matchOrders() {
    while (!buyOrders.empty() && !sellOrders.empty()) {
        auto buyIt = buyOrders.begin();   // Highest price first (due to std::greater)
        auto sellIt = sellOrders.begin(); // Lowest price first

        if (buyIt->first >= sellIt->first) {
            Order buyOrder = buyIt->second;
            Order sellOrder = sellIt->second;

            int tradeQuantity = std::min(buyOrder.quantity, sellOrder.quantity);

            std::cout << "💥 Trade executed: " << tradeQuantity
                      << " units at price " << sellOrder.price
                      << " (Buy ID: " << buyOrder.id
                      << " ↔ Sell ID: " << sellOrder.id << ")\n";

            // Update or remove buy order
            buyOrders.erase(buyIt);
            if (buyOrder.quantity > tradeQuantity) {
                buyOrder.quantity -= tradeQuantity;
                buyOrders.insert({buyOrder.price, buyOrder});
            }

            // Update or remove sell order
            sellOrders.erase(sellIt);
            if (sellOrder.quantity > tradeQuantity) {
                sellOrder.quantity -= tradeQuantity;
                sellOrders.insert({sellOrder.price, sellOrder});
            }
        } else {
            break; // No more matchable orders
        }
    }
}

// Cancels an order by ID (not fully functional yet)
void OrderBook::cancelOrder(int id) {
    // Placeholder for future logic
    std::cout << "🚫 Cancel not implemented yet for ID: " << id << "\n";
}

// Prints the current state of the order book
void OrderBook::printOrderBook() const {
    std::cout << "\n📘 Order Book State:\n";

    std::cout << "SELL ORDERS:\n";
    for (const auto& [price, order] : sellOrders) {
        std::cout << "  Price: " << price
                  << " | Qty: " << order.quantity
                  << " | ID: " << order.id << "\n";
    }

    std::cout << "BUY ORDERS:\n";
    for (const auto& [price, order] : buyOrders) {
        std::cout << "  Price: " << price
                  << " | Qty: " << order.quantity
                  << " | ID: " << order.id << "\n";
    }
    std::cout << std::endl;
}
