# Felix Backtester

Production-grade HFT backtesting engine with C++20 core and Python strategy interface.

## Features

- **C++ Event Loop** - Deterministic, microsecond-level tick processing
- **Python Strategy API** - `on_start`, `on_tick`, `on_bar`, `on_fill`, `on_end`
- **Slippage & Latency Models** - Realistic execution simulation
- **Portfolio & Risk Engine** - Position tracking, P&L, max drawdown limits
- **Analytics** - Sharpe, Sortino, Max Drawdown, CAGR, Win Rate
- **Export** - JSON/CSV trade logs and equity curves

## Quick Start

```powershell
# 1. Install dependencies
pip install -r requirements.txt

# 2. Build C++ engine
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
cd ..
copy build\Release\*.pyd .

# 3. Download market data
python scripts/preprocess_data.py --symbol AAPL --start 2025-01-01 --end 2025-06-01

# 4. Run backtest
python scripts/run_backtest.py
```

## Output

```
==================================================
BACKTEST RESULTS
==================================================
Initial Capital:    $100,000.00
Final Equity:       $120,042.80
Total P&L:          $+20,042.80 (+20.04%)
--------------------------------------------------
Sharpe Ratio:       0.98
Max Drawdown:       19.76%
CAGR:               56.35%
==================================================
```

Results exported to:
- `results/backtest_results.json`
- `results/trades.csv`

## Project Structure

```
felix-backtester/
├── engine/           # C++ core (event loop, matching, portfolio)
├── python/felix/     # Python strategy API and analytics
├── scripts/          # Data preprocessing and backtest runner
├── data/             # Binary market data
├── results/          # Output JSON/CSV
└── tests/            # C++ and Python tests
```

## Writing Strategies

```python
from felix.strategy.base import Strategy

class MyStrategy(Strategy):
    def on_start(self):
        print("Backtest started")
    
    def on_tick(self, tick):
        # Your trading logic here
        pass
    
    def on_bar(self, bar):
        pass
    
    def on_fill(self, fill):
        print(f"Filled: {fill.price}")
    
    def on_end(self):
        print("Backtest complete")
```

## License

MIT
