#ifndef _function5
#define _function5

#include <string>
using namespace std;

/*
CountConsonants functions
@param string text      The text to look for capital letters in
@param int pos          (For the recursive version) current position being investigated

Iterate through each char in the string [text] and return the char if it is an upper-case letter.
If no upper-case letters are found, return a space character: ' '
*/

bool IsUppercase( char letter )
{
    return ( letter != ' ' && toupper( letter ) == letter );
}

char GetFirstUppercase_Iter(string text)
{
	bool found = false;

	for (int i = 0; i < text.size(); i++) {
		if (IsUppercase(text[i]))
		{
			found = true;
			return text[i];
		}	
	}
	 
	if (!found) return ' ';

}

char GetFirstUppercase_Rec( string text, int pos )
{
	
	if (text[pos] == '\0')
		return ' ';

	if ( IsUppercase( text[pos] ) )
		return text[pos];
	
	return GetFirstUppercase_Rec(text, (pos + 1) );

}

#endif
