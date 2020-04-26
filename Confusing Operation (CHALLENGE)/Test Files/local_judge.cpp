#include <iostream>
#include <string>
#include<cassert>
#define LOCAL_TESTING

#ifdef LOCAL_TESTING
FILE *spoj_p_in, *spoj_p_out, *spoj_t_out;
#define PIN "input_N_2.txt"
#define TOUT "user_output.txt"

#define SPOJ_RV_POSITIVE 0
#define SPOJ_RV_NEGATIVE -1


#else
#include "spoj_interactive.h"
#endif


int c = 0;

char get_char_from_input(FILE* input){
        char ch;
        do{
            fscanf(input, "%c", &ch);
         }while(isspace(ch));
        return ch;
}

std::string get_string_from_input(FILE *input, int max_length){
    char str[max_length + 1];
    char ch;
    // omit all white spaces before the string
    do{
        fscanf(input, "%c", &ch);
    } while (isspace(ch));
    int i = 0;
    do{
        str[i++] = ch;
    }while (fscanf(input, "%c", &ch) == 1 && !isspace(ch));
    str[i] = '\0';
    return std::string(str);
}

void spoj_init() {
    spoj_p_in = fopen(PIN, "r");
//    spoj_p_out = fopen(POUT, "r");
    spoj_t_out = fopen(TOUT, "r");
}

void spoj_assert(bool t) {
    assert(t);
}

using namespace std;
typedef int ll;

int main(){
    spoj_init();
    ll n;
	fscanf(spoj_p_in, "%d", &n);
	cout<<n<<endl;
    ll k;
	fscanf(spoj_t_out,"%d",&k);
	for(ll i=0;i<k;i++){
        string ch = get_string_from_input(spoj_t_out,3);
        ll index;
        fscanf(spoj_t_out,"%d",&index);
        cout<<ch<<" "<<index<<endl;
	}

}
