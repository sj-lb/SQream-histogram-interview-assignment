/* ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~
 ~                   Dictionary Histogram Implementation File                  *
 * Code By:     Johnny Lichtblau                                               ~
 ~ Date:        19.09.2023                                                     *
 * Description: SQream interview assignment: single-threaded implementation    ~
 ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ */

#include <fstream>
using std::ifstream;
#include <utility>
using std::pair;
#include <cctype>
using std::isalpha;

using std::tolower;

#include "dict_hist.hpp"

typedef pair<map<char, size_t>::iterator, bool> entry_t;

DictHist::DictHist(const string& dict_path)
{
    ifstream dict(dict_path, std::ios::in);

    string buffer;
    
    while (!dict.eof())
    {
        string word;
        dict >> word;
        buffer += word;
    }

    for (char c : buffer)
    {
        if (!isalpha(c)) continue;

        entry_t entry = m_hist.insert(pair<char, size_t>(tolower(c), 1));
        if (!entry.second)
        {
            ++(entry.first->second);
        }
    }
}
