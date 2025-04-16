# Minimal Order Matching Engine (HFT Simulation)

This project is a lightweight, high-level simulation of an **Order Matching Engine** written in modern C++. It mimics the core logic used in real-world High-Frequency Trading (HFT) systems to match buy and sell orders 
based on price and time priority.

## Key Concepts

- **Order Matching**: Matches buy and sell orders using price-time priority.
- **Multimap for Order Book**: Buy and Sell orders are stored using `std::multimap` for efficient lookup and ordering.
- **Real-time Matching Logic**: As soon as an order is added, the engine checks for possible matches.
- **Simple CLI Output**: Trade executions are printed directly to the console.

---

## 🚀 How to Build

```bash
# Clone the repo
git clone https://github.com/your-username/order-engine.git
cd order-engine

# Create a build directory and compile
mkdir build
cd build
cmake ..
make

# Run the executable
./order_engine
