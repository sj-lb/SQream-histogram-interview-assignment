/* ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~
 ~                   Dictionary Histogram Implementation File                  *
 * Code By:     Johnny Lichtblau                                               ~
 ~ Date:        19.09.2023                                                     *
 * Description: SQream interview assignment: multithreaded implementation      ~
 ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ */

#include <fstream>
using std::ifstream;
#include <utility>
using std::pair;
#include <cctype>
using std::isalpha;
#include <thread>
using std::thread;
#include <mutex>
using std::mutex;
using std::unique_lock;
// using std::defer_lock;
#include <vector>
using std::vector;
#include <array>
using std::array;

using std::tolower;

#include "dict_hist.hpp"

#ifndef NUM_THREADS
#define NUM_THREADS 10
#endif // NUM_THREADS


typedef pair<map<char, size_t>::iterator, bool> entry_t;

DictHist::DictHist(const string& dict_path)
{
    ifstream dict(dict_path, std::ios::in);
    vector<thread> threads;
    array<string, NUM_THREADS> buffer;
    mutex m;
    int i = 0;

    while (!dict.eof() && !dict.fail())
    {
        string word;
        dict >> word;
        buffer[i++ % NUM_THREADS] += word;
    }

    for (i = 0; i < NUM_THREADS; ++i)
    {
        threads.emplace_back([this, &m](string buffer)
        {
            map<char, size_t> hist;
            unique_lock<mutex> lk(m, std::defer_lock);

            for (char c : buffer)
            {
                if (!isalpha(c)) continue;

                entry_t entry = hist.insert(pair<char, size_t>(tolower(c), 1));
                if (!entry.second)
                {
                    ++(entry.first->second);
                }
            }

            lk.lock();
            for (const pair<char, size_t>& l_entry : hist)
            {
                entry_t m_entry = this->m_hist.insert(
                            pair<char, size_t>(l_entry.first, l_entry.second));
                if (!m_entry.second)
                {
                    m_entry.first->second += l_entry.second;
                }
            }
            lk.unlock();
        }, buffer[i]);
    }

    for (thread& t : threads)
    {
        t.join();
    }
}