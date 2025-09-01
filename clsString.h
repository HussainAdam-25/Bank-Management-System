#pragma once

#include<iostream>
#include<string>
using namespace std;


class clsString
{
private: 
	string  _Value;

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{

		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;


	///////////////////////////  Function to CountWords
	static int CountWords(string Text)
	{
		string Delim = " ";
		string Sword = "";
		short Counter = 0;
		short Pos = 0;

		while ((Pos = Text.find(Delim)) != std::string::npos)
		{
			Sword = Text.substr(0, Pos);
			if (Sword != "")
			{
				Counter++;

			}

			Text.erase(0, Pos + Delim.length());
		}

		if (Text != "")
		{
			Counter++;

		}

		return Counter;
	}

	 short CountWords()
	{

		return CountWords(_Value);
	}



	 ///////////////////////////////////////////////////////////////

	static string ReadString(string Msg)
	 {
		 string Text;
		 cout << Msg << endl;
		 getline(cin >> ws, Text);
		 return Text;
	 }

	string ReadString()
	{
		return ReadString(_Value);
	}

	 ///
	 char ReadChar()
	 {
		 char X;
		 cout << "\nPlease enter char :\n";
		 cin >> X;
		 return X;
	 }


	 ///  
	static char InvertingCharacter(char MyChar)
	 {
		 return (isupper(MyChar)) ? tolower(MyChar) : toupper(MyChar);
	 }

	static short Length(string Text)
	{

		return Text.length();

	}

	short Length()
	{

		return _Value.length();

	}
	 ///******************************
	 void PrintFirstLettersOfString(string Text)
	 {
		 bool IsSpace = true;
		 for (int i = 0; i < Text.length(); i++)
		 {
			 if (Text[i] != ' ' && IsSpace)
				 cout << Text[i] << endl;
			 IsSpace = (Text[i] == ' ') ? true : false;
		 }
	 }


	 ///
	static string UpperFirstLetterOfEachWord(string Text)
	 {
		 bool IsSpace = true;
		 for (int i = 0; i < Text.length(); i++)
		 {
			 if (Text[i] != ' ' && IsSpace)
				 Text[i] = toupper(Text[i]);
			 IsSpace = (Text[i] == ' ') ? true : false;
		 }
		 return Text;
	 }

	 void  UpperFirstLetterOfEachWord()
	 {
		 _Value = UpperFirstLetterOfEachWord(_Value);
	 }

	 ///
	 static	 string LowerFirstLetterOfEachWord(string Text)
	 {
		 bool IsSpace = true;
		 for (int i = 0; i < Text.length(); i++)
		 {
			 if (Text[i] != ' ' && IsSpace)
				 Text[i] = tolower(Text[i]);
			 IsSpace = (Text[i] == ' ') ? true : false;
		 }
		 return Text;
	 }

	 void  LowerFirstLetterOfEachWord()
	 {
		 _Value = LowerFirstLetterOfEachWord(_Value);
	 }

	 ///
	 static string UpperAllLetterOfString(string Text)
	 {
		 for (int i = 0; i < Text.length(); i++)
		 {
			 Text[i] = toupper(Text[i]);
		 }
		 return Text;
	 }


	  void  UpperAllLetterOfString()
	 {
		 _Value = UpperAllLetterOfString(_Value);
	 }

	 ///
	 static string LowerAllLetterOfString(string Text)
	 {
		 for (int i = 0; i < Text.length(); i++)
		 {
			 Text[i] = tolower(Text[i]);
		 }
		 return Text;
	 }

	 void  LowerAllLetterOfString()
	 {
		 _Value = LowerAllLetterOfString(_Value);
	 }


	 ///
	static string InvertAllLettersOfStringCase(string Text)
	 {
		 for (int i = 0; i < Text.length(); i++)
		 {
			 Text[i] = InvertingCharacter(Text[i]);
		 }
		 return Text;
	 }


	void InvertAllLettersOfStringCase()
	{
		_Value = InvertAllLettersOfStringCase(_Value);
	
	}


	/*******          ********
   *******             *****/
	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };


	 ///
	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{


		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
				Counter++;


			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
				Counter++;


		}

		return Counter;

	}

	 ///
	static short  CountLettersByMatchCase(string Text, char CharToCount, bool MatchCase = true)
	 {
		 short Counter = 0;
		 for (int i = 0; i < Text.length(); i++)
		 {
			 if (MatchCase == false)
			 {
				 if (toupper(Text[i]) == toupper(CharToCount))
					 Counter++;
			 }
			 else
				 if (Text[i] == CharToCount)
					 Counter++;
		 }
		 return Counter;
	 }


	short CountLettersByMatchCase(char CharToCount, bool MatchCase = true)
	{

		return  CountLettersByMatchCase(_Value, CharToCount, MatchCase);
	}


	 ///
	static bool isvowel(char i)
	 {
		 i = tolower(i);
		 return (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') ? true : false;
	 }



	 ///
	static short CountVowelLetters(string Text)
	 {
		 short Counter = 0;
		 for (int i = 0; i < Text.length(); i++)
		 {
			 if (isvowel(Text[i]))
				 Counter++;
		 }
		 return Counter;
	 }

	///////////CountVowelLetters
	short CountVowelLetters()
	{

		return CountVowelLetters(_Value);
	}


	 ///
	static string PrintAllVowelsInString(string Text, string Space = "  ")
	 {
		 string Vowels;
		 for (int i = 0; i < Text.length(); i++)
		 {
			 if (isvowel(Text[i]))
				 Vowels += Text[i] + Space;
		 }
		 return Vowels;
	 }


	 ///
	static void  PrintEachWordInString(string Text)
	 {
		 string Space = " ";
		 string NewText;
		 int Pos;
		 while ((Pos = Text.find(Space)) != string::npos)
		 {
			 NewText = Text.substr(0, Pos);
			 if (NewText != "")
				 cout << NewText << "\t";
			 Text.erase(0, Pos + Space.length());
		 }
		 if (Text != "")
			 cout << Text << endl;
	 }


	 ///
	static short CountEachWordInString(string Text)
	 {
		 short Counter = 0;
		 string Space = " ";
		 string NewText;
		 int Pos;
		 while ((Pos = Text.find(Space)) != string::npos)
		 {
			 NewText = Text.substr(0, Pos);
			 if (NewText != "")
				 Counter++;
			 Text.erase(0, Pos + Space.length());
		 }
		 if (Text != "")
			 return ++Counter;
	 }


	short CountEachWordInString()
	{

		return CountEachWordInString(_Value);
	}

	 ///
	static vector <string> SplitString(string Text, string Space)
	 {
		 vector <string> vSplit;
		 string NewText;
		 int Pos;
		 while ((Pos = Text.find(Space)) != string::npos)
		 {
			 NewText = Text.substr(0, Pos);
			 if (NewText != "")
			 {
				 vSplit.push_back(NewText);
			 }
			 Text.erase(0, Pos + Space.length());
		 }
		 if (Text != "")
			 vSplit.push_back(Text);
           return vSplit;
	 }

	 vector <string> SplitString(string Space)
	 {

		 return SplitString(_Value, Space);
	 }
	 ///


	 static string TrimLeft(string Text)
	 {
		 for (int i = 0; i < Text.length(); i++)
		 {
			 if (Text[i] != ' ')
				 return Text = Text.substr(i, Text.length());
		 }
	 }


	 void TrimLeft()
	 {

		 _Value = TrimLeft(_Value);
	 }
	 ///


	 static string TrimRight(string Text )
	 {
		 for (int i = 0; i < Text.length(); i++)
		 {
			 if (Text[Text.length() - i - 1] != ' ')
				 return Text = Text.substr(0, Text.length() - i);
		 }
	 }



	 void TrimRight( )
	 {

		 _Value = TrimRight(_Value);
	 }

	 ///

	 static string Trim(string Text)
	 {
		 return TrimLeft(TrimRight(Text));
	 }

	 void Trim()
	 {
		 _Value = Trim(_Value);

	 }
	 /*************************** * here * ******************************/


	 static  string JoinString(vector <string> vSplit, string Delim="**")
	 {
		 string Line;
		 for (string& temp : vSplit)
			 Line += temp + Delim;
		 return Trim(Line);
	 }



	 ///
	 static	 string JoinString(string ArrString[], short length, string Delim)
	 {
		 string Line;
		 for (int i = 0; i < length; i++)
		 {
			 Line += ArrString[i] + Delim;
		 }
		 return Trim(Line);
	 }


	 ///
	 static string ReverseWords(string Text)
	 {
		 string Line;
		 vector <string> vSplit = SplitString(Text, " ");
		 vector <string>::iterator iter = vSplit.end();
		 while (iter != vSplit.begin())
		 {
			 --iter;
			 Line += *iter + " ";
		 }
		 Line = Line.substr(0, Line.length() - 1);
		 return Line;
	 }


	 string ReverseWords()
	{

		 return ReverseWords(_Value);
    }

	 ///
	static string ReplaceWords(string Text, string Word, string Replace)
	 {
		 int Pos;
		 while ((Pos = Text.find(Word)) != string::npos)
			 Text = Text.replace(Pos, Word.length(), Replace);
		 return Text;
	 }


	 ///
	 static string ReplaceWordsCustom(string Text, string Word, string Replace, bool MatchCase = true)
	 {
		 int Pos;
		 vector <string> vText = SplitString(Text, " ");
		 if (MatchCase)
		 {
			 while ((Pos = Text.find(Word)) != string::npos)
			 {
				 Text = Text.replace(Pos, Word.length(), Replace);
				 vText = SplitString(Text, " ");
			 }
		 }
		 else
			 for (string& temp : vText)
				 if (LowerAllLetterOfString(Word) == LowerAllLetterOfString(temp))
					 temp = Replace;
		 return JoinString(vText, " ");
	 }


	 string ReplaceWordsCustom(string Word, string Replace)
	 {

		 return ReplaceWordsCustom(_Value, Word, Replace);

	 }

	 ///

	static string RemovePuncuations(string Text)
	 {
		 for (int i = 0; i < Text.length(); i++)
		 {
			 if (ispunct(Text[i]))
				 Text[i] = ' ';
		 }
		 return Text;
	 }

	void RemovePuncuations()
	{
		_Value = RemovePuncuations(_Value);

	}
	 ///
	static string PrintStringWithoutPunct(string Text, string Space)
	 {
		 string Word;
		 vector <string> vText = SplitString(Text, " ");
		 for (string& temp : vText)
			 Word += temp + Space;
		 return Word.substr(0, Word.length() - 1);
	 }

	 ////////////////////////////////////////////////////////////
};



