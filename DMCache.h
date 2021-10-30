#ifndef DMCACHE_H
#define DMCACHE_H

#include <stdio.h>
#include <string>

using namespace std;

struct DMCacheEntry{
    bool invalid;
    unsigned short upper_tag; 
    char bytes[4];
};

class DMCache
{
    public:
        // contructor and destructor
        DMCache();
        ~DMCache();
        // member functions
        void invalidateCache(); // function to invalidate all entries within cache 
        char getByte(int x, char input_bytes[4]); // function to query cache for a specific address value
                                                  // if cache miss occurs, load bytes from input array
    private:
        struct DMCacheEntry cache_entries[16384]; // Array representing a cache block
                                                  // Each entry represents a cache line
        int hit_counter; // counter to track number of cache hits 
        int miss_counter; // counter to track number of cache misses
};

#endif
