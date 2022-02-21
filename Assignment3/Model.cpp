/*
Encodes the rules of the Tutnese language.
Implements methods to handle translation of English characters.
*/
#include "Model.h"

using namespace std;

/**
 * Model
 * @brief Construct a new Model:: Model object
 * 
 */
Model::Model()
{
}

/**
 * ~Model
 * @brief Destroy the Model:: Model object
 * 
 */
Model::~Model()
{
}

/**
 * translateSingleCharacter
 * @brief Takes a single char c and returns a string representing 
 * its coding in Tutnese. Preserve capitalization.
 * 
 * @param c 
 * @return string singleCharEncoding
 */
string Model::translateSingleCharacter(char c)
{
    string singleCharEncoding;

    if (isupper(c))
    {
        switch (c)
        {
            case 'B':
                singleCharEncoding = "Bub";
                break;
            case 'C':
                singleCharEncoding = "Cash";
                break;
            case 'D':
                singleCharEncoding = "Dud";
                break;
            case 'F':
                singleCharEncoding = "Fuf";
                break;
            case 'G':
                singleCharEncoding = "Gug";
                break;
            case 'H':
                singleCharEncoding = "Hash";
                break;
            case 'J':
                singleCharEncoding = "Jay";
                break;
            case 'K':
                singleCharEncoding = "Kuck";
                break;
            case 'L':
                singleCharEncoding = "Lul";
                break;
            case 'M':
                singleCharEncoding = "Mum";
                break;
            case 'N':
                singleCharEncoding = "Nun";
                break;
            case 'P':
                singleCharEncoding = "Pub";
                break;
            case 'Q':
                singleCharEncoding = "Quack";
                break;
            case 'R':
                singleCharEncoding = "Rug";
                break;
            case 'S':
                singleCharEncoding = "Sus";
                break;
            case 'T':
                singleCharEncoding = "Tut";
                break;
            case 'V':
                singleCharEncoding = "Vuv";
                break;
            case 'W':
                singleCharEncoding = "Wack";
                break;
            case 'X':
                singleCharEncoding = "Ex";
                break;
            case 'Z':
                singleCharEncoding = "Zub";
                break;
            default:
                singleCharEncoding = c;
                break;
        }
    }
    else
    {
        switch (c)
        {
            case 'b':
                singleCharEncoding = "bub";
                break;
            case 'c':
                singleCharEncoding = "cash";
                break;
            case 'd':
                singleCharEncoding = "dud";
                break;
            case 'f':
                singleCharEncoding = "fuf";
                break;
            case 'g':
                singleCharEncoding = "gug";
                break;
            case 'h':
                singleCharEncoding = "hash";
                break;
            case 'j':
                singleCharEncoding = "jay";
                break;
            case 'k':
                singleCharEncoding = "kuck";
                break;
            case 'l':
                singleCharEncoding = "lul";
                break;
            case 'm':
                singleCharEncoding = "mum";
                break;
            case 'n':
                singleCharEncoding = "nun";
                break;
            case 'p':
                singleCharEncoding = "pub";
                break;
            case 'q':
                singleCharEncoding = "quack";
                break;
            case 'r':
                singleCharEncoding = "rug";
                break;
            case 's':
                singleCharEncoding = "sus";
                break;
            case 't':
                singleCharEncoding = "tut";
                break;
            case 'v':
                singleCharEncoding = "vuv";
                break;
            case 'w':
                singleCharEncoding = "wack";
                break;
            case 'x':
                singleCharEncoding = "ex";
                break;
            case 'y':
                singleCharEncoding = "yub";
                break;
            case 'z':
                singleCharEncoding = "zub";
                break;
            default:
                singleCharEncoding = c;
                break;
        }
    }

    return singleCharEncoding;
}

/**
 * translateDoubleCharacter
 * @brief Takes a single char cc that appears twice in a row and 
 * returns a string representing its coding in Tutnese.
 * Preserve capitalization.
 * 
 * @param cc 
 * @return string doubleCharEncoding
 */
string Model::translateDoubleCharacter(char cc)
{
    // add code to describe scenario for letter pairs
    // if vowel -> add prefix "squat" then repeat vowel "oo" becomes "squato"
    // if consonant -> add prefix "squa" then converted consonant "ll" becomes "squatlul"
    string doubleCharEncoding;

    if (isVowel(cc))
    {
        doubleCharEncoding = "squat";
    }
    else
    {
        doubleCharEncoding = "squa";
    }

    return doubleCharEncoding;
}

/**
 * isVowel
 * @brief Takes a character c as input and test to see whether that character is a vowel (a,e,i,o,u)
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool Model::isVowel(char c)
{
    switch (c)
    {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            return true;
            break;
        default:
            return false;
            break;
    }

}