#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename K>
class HashFunction 
{
public:
    virtual unsigned int operator()(const K& key) const = 0;
};

class SimpleStringHash : public HashFunction<string> 
{
public:
    unsigned int operator()(const string& s) const
    {
        unsigned hashBrowns = 0; 
        
        for(unsigned i = 0; i < s.size(); i++)
        {
            hashBrowns = hashBrowns + s.at(i);
        }
        
        /*
        
        ****NOT CURRENTLY BEING USED.. THIS IS THE BETTER FUNCTION FROM INTERNET****
        
        int chiaSeed = 100; 
        
        unsigned long hashBrowns = 0;
        
        for(int i = 0; i < s.length(); i++)
          hashBrowns = (hashBrowns * chiaSeed) + s.at(i);
          
         */
         
        return hashBrowns;
    }
};

class ResolutionFunction
{
public:
    virtual unsigned int operator()(int i) const = 0;
};

/// The instructor did the simplest part for you.  You're welcome.  Enjoy Thanksgiving turkey
// with a side of C++ code!

class LinearProbing : public ResolutionFunction
{
public:
    unsigned int operator()(int i) const 
    {
        return i;
    }
};

class QuadraticProbing : public ResolutionFunction
{
public:
    unsigned int operator()(int i) const
    {
        return i * i;
    }
};

/// Returns the bit index of the most significant bit.
/// If the input is zero, it returns zero
/// This function will help you locate the crrect good prime in the array below
/// It will also help you compute the next power of two
int mostSignificantBit(int x)
{
    if (x == 0)
        return 0;
    int mostSignificantBit = 31;
    while ((x & (1 << mostSignificantBit)) == 0)
        mostSignificantBit--;
    return mostSignificantBit;
}

/// Good prime numbers to use as Hashtable sizes
/// Copied from https://web.archive.org/web/20120705020114/http://planetmath.org/encyclopedia/GoodHashTablePrimes.html
int GoodPrimeNumbers[] = {53, 97, 193, 389, 769, 1543, 3079, 6151, 12289,
    24593, 49157, 98317, 196613, 393241, 786433, 1572869, 3145739, 6291469,
    12582917, 25165843, 50331653, 100663319, 201326611, 402653189,
    805306457, 1610612741
};


template <typename K>
class Hashtable
{
    enum BucketStatus {EMPTY, OCCUPIED, DELETED};
    
    int numCollisions;
    
    vector<K>buckets; //ALL HAIL PLANKTON
    
    vector<BucketStatus>status;
    
    HashFunction<K>* hash;
    
    ResolutionFunction* f;
    
public:

    Hashtable(int n, HashFunction<K>* _h, ResolutionFunction* _f) : numCollisions(0), hash(_h), f(_f)
    {
        int temp = 0;
        
        int position = 0;
        
        /*
        ======================================
        POWER OF TWO INITIALIZATION BELOW
        ======================================
        */
        
        int temp2Dude = 0;
        
        temp2Dude = mostSignificantBit(n) + 1;
        
        temp = pow(2,temp2Dude);
        
        /*
        ======================================
        GOOD PRIME NUMBER INITIALIZATION BELOW
        ****CURRENTLY NOT BEING USED****
        ======================================
        */
        
        
        // while(n > GoodPrimeNumbers[position])
        // {
        //     position++;
        // }
        //
        // temp = GoodPrimeNumbers[position];
        
        status.assign(temp,EMPTY);
        
        buckets.assign(temp," ");
    }
    
   void insert(const K& key)
   {
        int position = ((*hash)(key) % buckets.size());
        
        int tempPos = position;
        
        while(status.at(position) == OCCUPIED)
        {
            
        /*
        ======================================
        QUADRATIC PROBING BELOW
        ****CURRENTLY NOT BEING USED****
        ======================================
        */
            
            
            // ResolutionFunction *f = new QuadraticProbing;
            
            
        /*
        ======================================
        LINEAR PROBING BELOW
        ======================================
        */
            ResolutionFunction *f = new LinearProbing;
            
        /*
        =============================================
        NOW BACK TO OUR REGULARLY SCHEDULED PROGRAMS
        =============================================
        */
            numCollisions++;
            
            position = (position+(*f)(tempPos)) % buckets.size();
            
            tempPos++;
        }
        
        buckets.at(position) = key;
        
        status.at(position) = OCCUPIED;
       
    }
    
    bool search(const K& key) 
    {
        int position = ((*hash)(key) % buckets.size());
        
        while(status.at(position) != EMPTY)
        {
            if(status.at(position) == OCCUPIED && buckets.at(position) == key)
                return true;
                
            else
            {
                
                /*
                ======================================
                QUADRATIC PROBING BELOW
                ****CURRENTLY NOT BEING USED****
                ======================================
                */
                
                // ResolutionFunction *f = new QuadraticProbing;
                
                /*
                ======================================
                LINEAR PROBING BELOW
                ======================================
                */
                
                ResolutionFunction *f = new LinearProbing;
                
                
                /*
                =============================================
                NOW BACK TO OUR REGULARLY SCHEDULED PROGRAMS
                =============================================
                */
                
                int tempPos = position;
                
                position = (position + (*f)(tempPos)) % buckets.size();
                
                ++tempPos;
                
                return false;
            }
        }
        
        return false;
    }
   bool erase(const K& key) 
   {
       int position = (*hash)(key) % buckets.size();
       
       while(status.at(position) == OCCUPIED)
       {
           if(buckets.at(position) == key)
           {
               status.at(position) = DELETED;
               
               return true;
           }
           
           else
           {
               /*
                ======================================
                QUADRATIC PROBING BELOW
                ****CURRENTLY NOT BEING USED****
                ======================================
                */
                
                // ResolutionFunction *f = new QuadraticProbing;
                
                /*
                ======================================
                LINEAR PROBING BELOW
                ======================================
                */
                
                ResolutionFunction *f = new LinearProbing;
              
            /*
            =============================================
            NOW BACK TO OUR REGULARLY SCHEDULED PROGRAMS
            =============================================
            */
              int tempPos = position;
              
              position = ((position+(*f)(tempPos)) % buckets.size());
              
              tempPos++;
              
              return false;
           }
       }
       
       return false;
    }
    
    int getNumCollisions() const 
    {
        return numCollisions;
    }
};

/// The following code is only for testing. Any changes you make
/// beyond this point will be ignored in the final deliverable

vector<string> loadWords(string filename)
{
    ifstream file(filename);
    vector<string> lines;
    string line;
    if (file.is_open())
    {
        while (getline(file, line)) 
        {
            while (line[line.size() - 1] == '\r' || line[line.size() - 1] == '\n')
                line = line.substr(0, line.size() - 1);
            lines.push_back(line);
        }
    }
    
    return lines;
}

void generateRandomPhrases(const vector<string>& words, int numPhrases, vector<string>& phrases)
{
    srand(0);
    for (int i = 0; i < numPhrases; i++)
    {
        string line;
        int length = rand() % 4 + 2; // Generate a random number in [2, 5]
        for (int iWord = 0; iWord < length; iWord++)
        {
            if (iWord != 0)
                line += " ";
            string word = words[rand() % words.size()];
            line = line + word;
        }
        
        phrases.push_back(line);
    }
    
    sort(phrases.begin(), phrases.end());
    int newSize = unique(phrases.begin(), phrases.end()) - phrases.begin();
    phrases.resize(newSize);
    shuffle (phrases.begin(), phrases.end(), std::default_random_engine(0));
}

void testHashtableSimple()
{
    HashFunction<string>* hash = new SimpleStringHash();
    ResolutionFunction* f = new LinearProbing();
    Hashtable<string> hashtable = Hashtable<string>(10, hash, f);
    hashtable.insert("first word");
    hashtable.insert("second word");
    hashtable.insert("third word");
    EXPECT_TRUE(hashtable.search("first word"));
    EXPECT_TRUE(hashtable.search("second word"));
    EXPECT_TRUE(hashtable.search("third word"));
    EXPECT_FALSE(hashtable.search("fourth word"));
    EXPECT_TRUE(hashtable.erase("first word"));
    EXPECT_FALSE(hashtable.search("first word"));
    EXPECT_TRUE(hashtable.search("second word"));
    EXPECT_TRUE(hashtable.search("third word"));
    
    delete hash;
    delete f;
}

int stressTest(int hashtableSize)
{
    // Load words from file
    vector<string> words = loadWords("1kwords.txt");
    // Generate random phrases
    vector<string> phrases;
    generateRandomPhrases(words, hashtableSize, phrases);

    // Create the hashtable
    HashFunction<string>* hash = new SimpleStringHash();
    ResolutionFunction* f = new LinearProbing();
    //ResolutionFunction* f = new QuadraticProbing();
    Hashtable<string> hashtable = Hashtable<string>(hashtableSize, hash, f);

    
    // Insert all phrases into the hashtable
    for (string phrase : phrases)
        hashtable.insert(phrase);
    // Search for all phrases
    for (string phrase : phrases)
        hashtable.search(phrase);
        
    delete hash;
    delete f;
    // return number of collisions
    return hashtable.getNumCollisions();
}

int main()
{
    testHashtableSimple();
    int sizes[] = {100, 1000, 10000, 100000};
    for (int hashtableSize : sizes) 
    {
        int numCollisions = stressTest(hashtableSize);
        cout << "Number of collisions with " << hashtableSize << " phrases is " << numCollisions << endl;
    }
	return 0;
}
