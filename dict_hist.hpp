/* ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~
 ~                      Dictionary Histogram Header File                       *
 * Code By:     Johnny Lichtblau                                               ~
 ~ Date:        19.09.2023                                                     *
 * Description: Sqream interview assignment                                    ~
 ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ */

#ifndef __SJ_DICT_HIST__
#define __SJ_DICT_HIST__

#include <map>
using std::map;
#include <string>
using std::string;

class DictHist
{
public:
    DictHist(const string& dict_path);
    string ToString();
private:
    map<char, size_t> m_hist;
};


#endif // __SJ_DICT_HIST__