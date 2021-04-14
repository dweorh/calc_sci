#include "common.h"

using namespace std;

const char standardTokensList[] = { '+', '-', '*', /*'%',*/ '^', '/','(',')', '^', '!', '|'};
const int standardTokensListSize = 10;
const string divMultiplySingsList[] = {"*","/","|","^"};
const string supportedFunctionsList[] = {
	"abs", "asin", "acos", "atan", "actg",
	"cos", "cosd", "cosh", "ctg", "ctgh",
	"log10", "log2", "log", "ln",
	"sin", "sind", "sinh", "sqrt", 
	"tg", "tan", "tgh", "tanh",
	"arcsin", "arccos", "arcctg", "arctan"};
int supportedFunctionsListSize = 26;

int in_array_str( const string a[], int size, string lookfor ){
	int i;
	for( i = 0; i < size; i++){
		if( a[i].compare( lookfor ) == 0 )
			return 1;
	}
	return 0;
}

int in_array_chr( const char a[], int size, char c){
	int i;
	for( i=0; i<size; i++){
		if( a[i] == c )
			return 1;
	}
	return 0;
}

bool is_number(const string& s)
{
	bool already_has_dot = false;

	for (int i = 0; i < (int)s.length(); i++) {
		if (!std::isdigit(s[i]) && ( s[i]!='.' || (s[i] == '.' && already_has_dot) ) )
			return false;
		if( s[i] == '.' ){
			if(already_has_dot)
				return false;
			else
				already_has_dot = true;
		}
	}

   return true;
}

symbol* getSymbol( string &c ){
	if( c == "(" )
		return new symbolOB();
	else if( c == ")" )
		return new symbolCB();
	else if( c == "!" )
		return new symbolFactorial(c);
	else if( is_number(c) )
		return new symbolNumber( c );
	else if( c == "+" )
		return new symbolPlus( c );
	else if( c == "-" )
		return new symbolMinus( c );
	else if( in_array_str( divMultiplySingsList, 4, c ) == 1 )
		return new symbolDivMultiply( c );
	else if( in_array_str( supportedFunctionsList, supportedFunctionsListSize, c ) == 1 )
		return new symbolFunction( c );
	//throw(calculatorException("unknown symbol: " + c));
	return new symbol();
}


void removeLastTokenFromEquation(string &s){
	string _tmp = "";
	char c;
	int end_eq = -1;
	int i = (int)s.length()-1;
	
	if( i < 0 )
		return;

	c = s.at(i);
	if( isdigit(c) || c == '.' 
		|| ( c != '(' && in_array_chr( standardTokensList, standardTokensListSize, c ) == 1 )
		|| (i == 0 && c == '(')
	){ // removing single char tokens
		end_eq = i;
	//	break;
	} else if( c == '(' ){ // removing functions
		for( int j = i-1; j >= 0; j--){
			c = s.at(j);
			_tmp = c + _tmp;
			if( in_array_str( supportedFunctionsList, supportedFunctionsListSize, _tmp ) == 1 ){
				end_eq = j;
				break;
			}
		}
		if( end_eq == -1 ){
			end_eq = i; // simply remove open bracket
		}
	}


	if( end_eq != -1 ){
		s = s.substr(0,end_eq);
	}
}

vector<string> string2Tokens(string &s){
	vector<string> tokens_stack;
	string token = "", last_token = "", token_tmp = "";
	const char *chars;
	int chars_qty = s.size();
	bool stop_search = true;
	int j = 0, last_index = 0;
	
	chars = s.c_str();
	
	for( int i = 0; i < chars_qty; i++ ){
		token.clear();
		if( chars[i] == 0 )
			continue;

		if( isdigit( chars[i] ) ){
			token = chars[i];
			for( j = i+1; j < chars_qty; j++ ){
				if( isdigit( chars[ j ] ) || chars[ j ] == '.' ){
					token+=chars[j];
				} else {
					break;
				}
			}
			tokens_stack.push_back( token );
			
			if( token.length() > 1 ){ // means that at least one additional character was added to base token
				i = j - 1;
				continue;
			}
		} else if( in_array_chr( standardTokensList, standardTokensListSize, chars[i] ) == 1 ) {
			tokens_stack.push_back( std::string(1, chars[i] ) );
		} else { // find in advanced
			token = chars[i];
			last_index = i;
			last_token.clear();
			token_tmp = token;
			for( j = i+1; j < chars_qty; j++ ){
				stop_search = true;
				token_tmp+=chars[j];
				for(int z = 0; z < supportedFunctionsListSize; z++){
					if( strpos( supportedFunctionsList[z], token_tmp ) == 0){ // in function lists exists function starts with `token`
						token = token_tmp;
						stop_search = false;
						break;
					}
				}
				if( stop_search ){ // no more functions matching our token
					last_index = j-1;
					last_token = token;
					break;
				}
			}
			if( ! last_token.empty() /*! empty( $sLastFoundToken)*/ ){
				tokens_stack.push_back( last_token );
				i = last_index;
			}
			continue;
		}
	}
	return tokens_stack;
}

size_t strpos(const string &haystack, const string &needle)
{
    int sleng = haystack.length();
    int nleng = needle.length();

    if (sleng==0 || nleng==0)
        return string::npos;

    for(int i=0, j=0; i<sleng; j=0, i++ )
    {
        while (i+j<sleng && j<nleng && haystack[i+j]==needle[j])
            j++;
        if (j==nleng)
            return i;
    }
    return string::npos;
}

void rtrim(string *s, char trim ){
	int end_at = -1;
	char c;
	if((*s).length() > 0 && (*s).at((*s).length()-1) == trim){
		for(int i = (*s).length()-1; i >= 0; i--){
			c = (*s).at(i);
			if( (*s).at(i) != trim ){
				end_at = i;
				break;
			}
		}
	}
	if( end_at != -1 ){
		(*s) = (*s).substr(0,end_at+1);
	}
}


string implode( const string &glue, const vector<string> &pieces )
{
    string a;
    int leng=pieces.size();
    for(int i=0; i<leng; i++)
    {
        a+= pieces[i];
        if (  i < (leng-1) )
            a+= glue;
    }
    return a;
}