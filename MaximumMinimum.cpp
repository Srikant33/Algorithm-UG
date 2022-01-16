// main.cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <array>
using namespace std;
int main(int ac, char* av[]) {

 // variables
 string message_min("Minimum is ");
 string message_max("Maximum is ");
 string const hello = "hello";
 string const bye0 = "bye0";
 string const bye1 = "bye1";
 string const bye2 = "bye2";
 char letter1 = 'a';
 char letter2 = 'm';

 double number1 = 1.2213;
 double number2 = 1.2212;
 int number3 = -232;
 int number4 = 0;
 int number5 = 999;
 int number6 = 562;
 array <int, 10> elements {8, 3, 1, 9, 0, 2, 7, 4, 6, 5};
 auto elements_2 = { number3, number4, number5, number6 };
 // get min
 int result_min_1 = min(letter1, letter2);
 char result_min_2 = min(letter1, letter2);
 string result_min_3 = min(hello, bye1);
 string result_min_4 = min(bye1, bye2);
 string result_min_5 = min(bye1, bye0);
 double result_min_6 = min(number1, number2);
 int result_min_7 = min(number3, number4);
int result_min_8 = min(number4, number4);
 // get max
 int result_max_1 = max(letter1, letter2);
 char result_max_2 = max(letter1, letter2);
 string result_max_3 = max(hello, bye1);
 string result_max_4 = max(bye1, bye2);
 string result_max_5 = max(bye1, bye0);
 double result_max_6 = max(number1, number2);
 int result_max_7 = max(number3, number4);
 int result_max_8 = max(number4, number4);
 // get min and max
 auto result_minmax = minmax(elements_2);

 // get min and max elements in an array
 auto result_min_element = min_element(elements.begin(), elements.end());
 auto result_max_element = max_element(elements.begin(), elements.end());

 // get minmax elements in an array
 auto result_minmax_element = minmax_element(elements.begin(), elements.end());
 //
 // display
 //
 // min()
 cout << message_min << result_min_1 << endl;
 cout << message_min << result_min_2 << endl;
 cout << message_min << result_min_3 << endl;
 cout << message_min << result_min_4 << endl;
 cout << message_min << result_min_5 << endl;
 cout << message_min << result_min_6 << endl;
 cout << message_min << result_min_7 << endl;
cout << message_min << result_min_8 << endl << endl;
 // max()
 cout << message_max << result_max_1 << endl;
 cout << message_max << result_max_2 << endl;
 cout << message_max << result_max_3 << endl;
 cout << message_max << result_max_4 << endl;
 cout << message_max << result_max_5 << endl;
 cout << message_max << result_max_6 << endl;
 cout << message_max << result_max_7 << endl;
 cout << message_max << result_max_8 << endl << endl;
 // minmax()
 cout << message_min << result_minmax.first << endl;
 cout << message_max << result_minmax.second << endl << endl;
 // min_element() and max_element()
 cout << message_min << *result_min_element << endl;
cout << message_max << *result_max_element << endl << endl;
 // minmax_element()
 cout << message_min << *result_minmax_element.first << endl;
 cout << message_max << *result_minmax_element.second << endl << endl;
 while (1337);
 return 0;
}
