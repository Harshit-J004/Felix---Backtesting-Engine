import sys
import os

# Ensure we can import the local module
root_dir = os.path.join(os.path.dirname(__file__), "..")
sys.path.append(root_dir) # For felix_engine (if in root)
sys.path.append(os.path.join(root_dir, "python")) # For felix package

try:
    import felix_engine
except ImportError as e:
    print(f"Error importing felix_engine: {e}")
    sys.exit(1)

from felix.strategy.base import Strategy

class MyStrategy(Strategy):
    def on_start(self):
        print("Strategy started")

    def on_tick(self, tick):
        print(f"Tick: TS={tick.timestamp} Price={tick.price} Flags={tick.flags}")

    def on_end(self):
        print("Strategy ended")

def create_test_data(filename):
    import struct
    with open(filename, "wb") as f:
        # 3 ticks
        # timestamp(Q), symbol_id(Q), price(d), volume(d), flags(B), pad(7x)
        data = [
            (100, 1, 10.5, 100.0, 1),
            (200, 1, 10.6, 50.0, 0),
            (300, 1, 10.7, 75.0, 1)
        ]
        for ts, sym, px, vol, flags in data:
            # pack: QQddB7x
            packed = struct.pack("<QQddB7x", ts, sym, px, vol, flags)
            f.write(packed)

def main():
    data_file = "integration_test.bin"
    create_test_data(data_file)

    stream = felix_engine.DataStream()
    stream.load(data_file)

    strategy = MyStrategy()
    
    loop = felix_engine.EventLoop()
    loop.run(stream, strategy)

    if os.path.exists(data_file):
        os.remove(data_file)

if __name__ == "__main__":
    main()
