
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    
    //1. Read all words from STDIN to a vector<string> (called words below).
    vector<string> words{ istream_iterator<string>{cin}, istream_iterator<string>{} };
    
    //2. Create a frequency table of the words. Might require new data structures, Don't copy more  data than necessary
    map<string, int> frequencies;
    for_each ( begin(words), end(words), [&frequencies](string s) { frequencies[s]++; } );
    
    //3. Sort the frequency table in descending order of frequency. Might requires new data structures. Don't copy more data than necessary
    vector< pair<string, int> > v1{ make_move_iterator( begin(frequencies) ), make_move_iterator(end(frequencies) )};
    
    sort( begin(v1), end(v1), [](auto p1, auto p2) { return p1.second > p2.second; });
    
    
    //4. Copy the ten most common words to a new vector<string>, replace.
    vector<string> replace(10);
    transform( begin(v1), next( begin(v1), 10 ), begin(replace), [](auto p) { return p.first; });
    
    //5. Replace the words in words that also exist in replace. A word that exists in replace is replaced by the symbol $N, given that N is the index of the word in replace. The 10 words will then be replaced with the symbols $0 to $9.
    
    transform( begin(words), end(words), begin(words), [&replace](string s)
    {
        auto it = find( begin(replace), end(replace), s);
        if ( it != end(replace) )
            return "$" + to_string(distance(begin(replace), it));
        
        return s;
    });
    
    //6. Print a translation table with the format $0=word1;$1=word2;...;$9=word10; on one line on cout.
    transform( begin(replace), end(replace), ostream_iterator<string>{cout, ";"}, [index=0](string s) mutable
    {
        ostringstream oss;
        oss << '$' << index++ << '=' << s;
        return oss.str();
    });
    cout << "\n";
    
    //7. Print all words in words to cout separated with one space. This will remove all other kind of whitespace that happened to exist in the given output (expected behavior).
    copy(begin(words), end(words), ostream_iterator<string>{cout, " "});
    
    
    //The command:
    //cat textfile.txt | a.out | given_files/uncompress
    //should give the contents of the file textfile.txt as output (if you disregard difference in whitespace) if everything works.
    
    return 0;
}

