// LANGEVIN: 
// Copyright@2018 Yao, Li CCNU

#ifndef UTIL_H
#define UTIL_H

#include <memory>
#include <boost/multi_array.hpp>

namespace langevin {

// Alias for a three-dimensional grid.
using Grid = boost::multi_array<double, 3>;

// Alias for a two-dimensional table.
using Table = boost::multi_array<double, 2>;

}

#endif