#ifndef _function4
#define _function4

#include <string>
using namespace std;

/*
CountConsonants functions
@param string text      The text to count the consonants of
@param int pos          (For the recursive version) current position being investigated

Iterate through each char in the string [text] and count up 1 if that letter is a consonant.
*/

bool IsConsonant( char letter )
{
    if (    tolower( letter ) == 'a' ||
            tolower( letter ) == 'e' ||
            tolower( letter ) == 'i' ||
            tolower( letter ) == 'o' ||
            tolower( letter ) == 'u'
        )
    {
        return false;
    }

    return true;
}

int CountConsonants_Iter( string text )
{
    int sum = 0;
    for (unsigned int i = 0 ; i < text.size(); i++)
        if (IsConsonant(text[i]))
            sum += 1;
   
	return sum;
}

int CountConsonants_Rec( string text, int pos )
{
	int consonant = 0;
	if (text[pos] == '\0')
		return 0;

	if (IsConsonant(text[pos]))
		consonant = 1;


	return consonant + CountConsonants_Rec(text, (pos + 1));

}

#endif
