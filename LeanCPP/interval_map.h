#ifndef INTERVAL_MAP_H
#define INTERVAL_MAP_H

#include <iostream>
#include <assert.h>
#include <map>
#include <limits>
#include <vector>

using namespace std;


template<class K, class V>
class interval_map
{
    friend void IntervalMapTest();

private:
    std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map(V const& val)
    {
        m_map.insert(m_map.begin(), std::make_pair(std::numeric_limits<K>::lowest(), val));
    };

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Do not change values outside this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, const V& val )
    {
        if (keyBegin < keyEnd)
        {
            int count = keyBegin;
            while (count < keyEnd)
            {
                m_map.insert(pair<K,V>(count, val));
                count++;
            }
        }
    }

    void printData()
    {
        for(auto imap: m_map)
        {
            cout << imap.first << "=" << imap.second << endl;
        }
    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const
    {
        return ( --m_map.upper_bound(key) )->second;
    }

};

#endif // INTERVAL_MAP_H
