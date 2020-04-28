#include<bits/stdc++.h>

using namespace std;

//#define LOCAL_TESTING

#define QUERY_LIMIT 250000

#ifdef LOCAL_TESTING
FILE *spoj_p_in, *spoj_p_out, *spoj_t_out, *spoj_p_info, *spoj_for_tested;

#define SPOJ_RV_TLE			5
#define SPOJ_RV_WA			1
#define SPOJ_RV_AC			0

void spoj_init() {
    spoj_p_in = fopen("input/input_subtask_0.txt", "r");
    spoj_p_out = fopen("output/output_subtask_0.txt", "r");
    spoj_t_out = fopen("user_output.txt", "r");
    spoj_p_info = fopen("debug.txt", "w");
    spoj_for_tested = fopen("judge_output.txt", "w");
}

void spoj_assert(bool t) {
    assert(t);
}

#else

#include "spoj_interactive.h"

#endif

typedef long long int ll;


void wrong_answer() {
    fprintf(spoj_p_info, "------------------------\nWRONG ANS\n------------------------");
    // Provide negative input to signal their program to stop execution
    fprintf(spoj_for_tested, "%d\n", -1);
    exit(SPOJ_RV_WA);
}

void correct_answer() {
    exit(SPOJ_RV_AC);
}

void time_limit_exceeded() {
    exit(SPOJ_RV_TLE);
}

//void finalizeIT(int score) {
//    fprintf(spoj_score, "%d\n", score);
//}

char get_char_from_input(FILE *input) {
    char ch;
    do {
        fscanf(input, "%c", &ch);
    } while (isspace(ch));
    return ch;
}

string get_string_from_input(FILE *input, int max_length) {
    char str[max_length + 1];
    char ch;
    // omit all white spaces before the string
    do {
        fscanf(input, "%c", &ch);
    } while (isspace(ch));

    int i = 0;
    do {
        str[i++] = ch;
    } while (fscanf(input, "%c", &ch) == 1 && !isspace(ch));
    str[i] = '\0';

    return string(str);
}


int main() {

    spoj_init();

    int t, temp;
    temp = fscanf(spoj_p_in, "%d", &t);

    // Output test cases to user program
    fprintf(spoj_for_tested, "%d\n", t);

    fprintf(spoj_p_info, "Test cases = %d\n", t);

    while (t--) {

        ll n, m, x, y;
        temp = fscanf(spoj_p_in, "%lld", &n);
        temp = fscanf(spoj_p_in, "%lld", &m);
        temp = fscanf(spoj_p_in, "%lld", &x);
        temp = fscanf(spoj_p_in, "%lld", &y);

        // Output variables for user program to read
        fprintf(spoj_for_tested, "%lld %lld\n", n, m);
        fprintf(spoj_for_tested, "%lld %lld\n", x, y);


        fprintf(spoj_p_info, "NxM: %lld %lld\nCenter: %lld %lld\n", n, m, x, y);

        ll my_ans_top_left_x, my_ans_top_left_y, my_ans_bottom_right_x, my_ans_bottom_right_y;

        temp = fscanf(spoj_p_out, "%lld", &my_ans_top_left_x);
        temp = fscanf(spoj_p_out, "%lld", &my_ans_top_left_y);
        temp = fscanf(spoj_p_out, "%lld", &my_ans_bottom_right_x);
        temp = fscanf(spoj_p_out, "%lld", &my_ans_bottom_right_y);

        string my_shape = get_string_from_input(spoj_p_out, 15);
//        temp = fscanf(spoj_p_out, "%[^\n]", my_shape);


        fprintf(spoj_p_info, "Judge Ans: %lld %lld %lld %lld %s\n", my_ans_top_left_x, my_ans_top_left_y,
                my_ans_bottom_right_x,
                my_ans_bottom_right_y, my_shape.c_str());

        ll asked_queries = 0;
        bool ac = false;
        char choice;
        while (true) {

            asked_queries++;

            choice = get_char_from_input(spoj_t_out);
//            fscanf(spoj_t_out, "%c", &choice);

//            fprintf(spoj_p_info, "Choice: %c\n", choice);


            if (choice != 'Q') {
                break;
            }

            if (asked_queries <= QUERY_LIMIT) {
                string rgb = "255 255 255";
                ll xt, yt;
                temp = fscanf(spoj_t_out, "%lld", &xt);
                temp = fscanf(spoj_t_out, "%lld", &yt);

//                fprintf(spoj_p_info, "Query: %lld %lld\n", xt, yt);


                //if coordinates are out of bounds
                if (xt < 0 || xt > m || yt < 0 || yt > n) {
                    fprintf(spoj_p_info, "Invalid Input\n");
                    wrong_answer();
                } else {
                    // check if the coordinates fall under the region of rectangle
                    // if yes return 255, 255, 255
                    // else return 123,123,123 (non-black rgb code)
                    if (xt < my_ans_top_left_x || xt > my_ans_bottom_right_x || yt < my_ans_bottom_right_y ||
                        yt > my_ans_top_left_y) {
                        rgb = "123 123 123";
                    }
                }


                // RGB output for user to read
                fprintf(spoj_for_tested, "%s\n", rgb.c_str());

//                fprintf(spoj_p_info, "RGB: %s\n", rgb.c_str());

            } else {
                break;
            }
        }


        if (choice == 'A') {

            ll user_top_left_x, user_top_left_y, user_bottom_right_x, user_bottom_right_y;
            temp = fscanf(spoj_t_out, "%lld", &user_top_left_x);
            temp = fscanf(spoj_t_out, "%lld", &user_top_left_y);
            temp = fscanf(spoj_t_out, "%lld", &user_bottom_right_x);
            temp = fscanf(spoj_t_out, "%lld", &user_bottom_right_y);
//            temp = fscanf(spoj_t_out, "%s", &user_shape[0]);
            string user_shape = get_string_from_input(spoj_t_out, 15);

            fprintf(spoj_p_info, "ANS: %lld %lld %lld %lld %s\n", user_top_left_x, user_top_left_y, user_bottom_right_x,
                    user_bottom_right_y, user_shape.c_str());

            if (my_ans_top_left_x == user_top_left_x && my_ans_top_left_y == user_top_left_y &&
                my_ans_bottom_right_x == user_bottom_right_x && my_ans_bottom_right_y == user_bottom_right_y &&
                my_shape == user_shape) {
                ac = true;
            }
        }


        if (!ac) {
            wrong_answer();
        }
    }
//    finalizeIT(1);
    return SPOJ_RV_AC;
}