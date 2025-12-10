from abc import ABC, abstractmethod

class Strategy(ABC):
    def __init__(self):
        pass

    @abstractmethod
    def on_start(self):
        """Called when the backtest starts."""
        pass

    @abstractmethod
    def on_tick(self, tick):
        """Called for every market data tick."""
        pass

    @abstractmethod
    def on_end(self):
        """Called when the backtest ends."""
        pass
