#pragma once

#include <boost/property_tree/ptree.hpp>

namespace bittrex::model {

struct Trade {
    explicit Trade(boost::property_tree::ptree &j) {
        id = j.get<std::string>("Id");
        time_stamp = j.get<std::string>("TimeStamp");
        quantity = j.get<std::string>("Quantity");
        price = j.get<std::string>("Price");
        total = j.get<std::string>("Total");
        fill_type = j.get<std::string>("FillType");
        order_type = j.get<std::string>("OrderType");
    };

    std::string id;
    std::string time_stamp;
    std::string quantity;
    std::string price;
    std::string total;
    std::string fill_type;
    std::string order_type;
};
} //Namespace bittrex
