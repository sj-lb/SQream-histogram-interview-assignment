/* ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~
 ~                       Dictionary Histogram Test File                        *
 * Code By:     Johnny Lichtblau                                               ~
 ~ Date:        19.09.2023                                                     *
 * Description: Sqream interview assignment: test file                         ~
 ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ */

#include <iostream>
using std::cout;
using std::cerr;
#include <chrono>
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::time_point;
#include <utility>
using std::pair;

#include <dict_hist.hpp>

#define ERROR_STYLE "\033[1;31m" // bold and red
#define LB_STYLE "\033[36m"      // light blue
#define NSTYLE "\033[0m"

int main(int argc, char **argv)
{
    if (2 != argc)
    {
        cerr << ERROR_STYLE << "Error: wrong number of arguments\n";
        cerr << "usage: " << argv[0] << " <path/to/dictionary>\n" << NSTYLE;

        return 0;
    }

    time_point<high_resolution_clock> t_start = high_resolution_clock::now();

    DictHist hist(argv[1]);

    duration<double, std::milli> runtime = high_resolution_clock::now() - t_start;

    cout << LB_STYLE << "the function finished successfully in "
         << NSTYLE << runtime.count() << LB_STYLE
         << "ms and produced the following histogram:\n\n"
         << NSTYLE << hist.ToString();
}