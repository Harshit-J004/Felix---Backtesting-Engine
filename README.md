# Felix Backtester

High-performance HFT backtesting engine written in C++20 with Python bindings.

## Structure
- `engine/`: C++ core logic (matching, risk, event loop)
- `python/`: Strategy API and analytics
- `data/`: Market data storage

## Build
```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```
