/*
Translates English sentences to Tutnese using the Model class
*/
#include "Model.h"
#include "Translator.h"

using namespace std;

/**
 * Translator
 * @brief Construct a new Translator:: Translator object
 * 
 */
Translator::Translator()
{
}

/**
 * ~Translator
 * @brief Destroy the Translator:: Translator object
 * 
 */
Translator::~Translator()
{
}

/**
 * translateEnglishWord
 * @brief Takes a single string singleEngWord and returns that string
 * translated into Tutnese as translatedWord
 * 
 * @param singleEngWord 
 * @return string translatedWord
 */
string Translator::translateEnglishWord(string singleEngWord)
{
    string translatedWord = "";
    Model model;

    for (int i = 0; i < singleEngWord.length(); ++i)
    {
        if (singleEngWord[i] == singleEngWord[i+1])
        {
            translatedWord += model.translateDoubleCharacter(singleEngWord[i]);
        }
        else
        {
            translatedWord += model.translateSingleCharacter(singleEngWord[i]);
        }
    }

    return translatedWord;
}

/**
 * translateEnglishSentence
 * @brief Takes a single string singleEngSentence and returns that string
 * translated into Tutnese as translatedSentence. Extracts each word from the
 * sentence and passes them through translateEnglishWord().
 * 
 * @param singleEngSentence 
 * @return string translatedSentence
 */
string Translator::translateEnglishSentence(string singleEngSentence)
{
    string translatedSentence = "";
    string tempWord;

    for (char c : singleEngSentence)
    {
        if (c == ' ')
        {
            translatedSentence += translateEnglishWord(tempWord) + " ";
            tempWord = "";
        }
        else
        {
            tempWord += c;
        }
    }
    translatedSentence += translateEnglishWord(tempWord);
    
    return translatedSentence;
}