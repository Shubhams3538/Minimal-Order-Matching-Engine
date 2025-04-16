#include "../include/order_book.hpp"
#include <chrono>
#include <thread>

int main() {
    OrderBook engine;

    // Sample orders to simulate order flow
    std::vector<Order> orders = {
        {1, Side::BUY, 101.5, 100, 10000001},
        {2, Side::SELL, 102.0, 50, 10000002},
        {3, Side::BUY, 102.5, 70, 10000003},
        {4, Side::SELL, 101.0, 100, 10000004},
        {5, Side::BUY, 103.0, 30, 10000005},
        {6, Side::SELL, 102.5, 90, 10000006}
    };

    for (const auto& order : orders) {
        engine.addOrder(order);
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate delay
    }

    std::cout << "\n📦 Final Order Book:\n";
    engine.printOrderBook();

    return 0;
}
