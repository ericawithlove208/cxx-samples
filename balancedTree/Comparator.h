#pragma once

namespace ericawithlove208 { namespace cxxSamples { namespace balancedTree {

template<typename T> class Comparator {
  public:
    const int compare(const T& val1, const T& val2) {
      if (val1 == val2) {
        return 0;
      }

      if (val1 < val2) {
        return -1;
      }

      return 1;
    }
};

} } }
