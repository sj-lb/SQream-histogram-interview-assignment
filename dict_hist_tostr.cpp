/* ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~
 ~                   Dictionary Histogram Implementation File                  *
 * Code By:     Johnny Lichtblau                                               ~
 ~ Date:        19.09.2023                                                     *
 * Description: SQream interview assignment: utility function                  ~
 ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ */

#include <utility>
using std::pair;

#include "dict_hist.hpp"

string DictHist::ToString()
{
    string hist_str;

    for (const pair<char, size_t>& hist_entry : m_hist)
    {
        hist_str += hist_entry.first;
        hist_str += ": ";
        hist_str += std::to_string(hist_entry.second);
        hist_str += "\n";
    }

    return hist_str;
}
