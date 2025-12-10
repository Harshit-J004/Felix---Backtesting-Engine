#include "felix/portfolio.hpp"

namespace felix {

    Portfolio::Portfolio() {
    }

    void Portfolio::deposit(double amount) {
        cash_ += amount;
    }

    double Portfolio::get_cash() const {
        return cash_;
    }

    double Portfolio::get_position(const std::string& symbol) const {
        auto it = positions_.find(symbol);
        if (it != positions_.end()) {
            return it->second;
        }
        return 0.0;
    }

    void Portfolio::update_position(const std::string& symbol, double quantity, double price) {
        positions_[symbol] += quantity;
    }

}
