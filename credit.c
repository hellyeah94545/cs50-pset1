#include <stdio.h>
#include <cs50.h>
#include <math.h>

// helper funtion prototypes follow...
int get_checksum(long number);
int get_number_length(long number);
int get_first_two_digits(long number, int length);
int get_double_sum(long number, int sum);
bool is_visa(int digits);
bool is_mastercard(int digits);
bool is_amex(int digits);
string get_card_type(long number);


int main(void)
{
    // get card number
    long card_number = get_long("Number: ");
    // Verify if it's valid
    if (get_checksum(card_number) != 0)
    {
        printf("INVALID\n");        
    }
    else                           // proceed to get card type and return
    {
        string card_type = get_card_type(card_number);
        printf("%s\n", card_type);
    }
}


// Returns Luhn's sum of a number
int get_checksum(long number)
{
    int last_number = 1;
    int number_length = get_number_length(number);
    int single_sum = 0;
    int double_sum = 0;
    for (int i = 0; i < number_length; i++)
    {
        if (i % 2 == 0)         // Regular sum for first and odd numbers
        {
            single_sum += (number % 10);
        }
        else                   // double and sum for even numbers
        {
            double_sum = get_double_sum(number, double_sum);
        }
        number = number / 10;
    }
    last_number = (single_sum + double_sum) % 10;
    return last_number;
}


// Returns some of doubled numbers from odd positions
int get_double_sum(long number, int sum)
{
    if ((number % 10) > 4)    // Special handling for numbers above 4
    {
        int two_digits = (number % 10) * 2;
        sum += ((two_digits % 10) + (two_digits / 10));
    }
    else
    {
        sum += (number % 10) * 2;
    }
    return sum;
}


// Returns count of all the digits in number
int get_number_length(long number)
{
    int length = floor(log10(number)) + 1;
    return length;
}


// Returns card_type: AMEX, VISA, MASTERCARD, INVALID; main sub function
string get_card_type(long number)
{
    string card_type = "INVALID";
    int card_length = get_number_length(number);
    int first_two_digits = get_first_two_digits(number, card_length);
    if (card_length == 15 && is_amex(first_two_digits))
    {
        card_type = "AMEX";
    }
    else if ((card_length == 13) && is_visa(first_two_digits))
    {
        card_type = "VISA";
    }
    else if (card_length == 16)
    {
        
        if (is_visa(first_two_digits))
        {
            card_type = "VISA";
        }
        else if (is_mastercard(first_two_digits))
        {
            card_type = "MASTERCARD";
        }
    }
    return card_type;
}


// Returns only first two digits of number
int get_first_two_digits(long number, int length)
{
    while (length > 2)
    {
        number = number / 10;
        length = get_number_length(number);
    }
    return number;
}


// Retruns true if first digit matches Visa id
bool is_visa(int digits)
{
    int first_digit = digits / 10;
    if (first_digit == 4)
    {
        return true;
    }
    return false;
}


// Retruns true if first two digits match Mastercard id
bool is_mastercard(int digits)
{
    if (digits == 51 || digits == 52 || digits == 53 || digits == 54 || digits == 55)
    {
        return true;
    }
    return false;
}


// Retruns true if first two digits match Amex id
bool is_amex(int digits)
{
    if ((digits == 34) || (digits == 37))
    {
        return true;
    }
    return false;
}