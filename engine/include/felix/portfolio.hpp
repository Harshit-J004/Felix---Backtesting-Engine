#pragma once

#include <string>
#include <unordered_map>

namespace felix {

    class Portfolio {
    public:
        Portfolio();
        
        void deposit(double amount);
        double get_cash() const;
        double get_position(const std::string& symbol) const;
        
        void update_position(const std::string& symbol, double quantity, double price);

    private:
        double cash_ = 0.0;
        std::unordered_map<std::string, double> positions_;
    };

}
