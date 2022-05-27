class ValidatePlayerInPutLocation
{
	string _playerInPutString = "";
	string _validateThatString = "";
	
	bool _stringTooLong = true;
	bool _stringWithNoLetter = true;
	bool _stringWithNoNumbers = true;
	string InPutStringTooLong(string stringTooLong)
	{
		cout << "Somethings wrong with this position(too long i guess) try again\n";
		cin >> stringTooLong;
		return stringTooLong;
	}
	string MissingLetterInInPutString(string stringWithMissingLetter)
	{
		cout << "Wrong input, try again (format: A4||4A)\n ";
		cin >> stringWithMissingLetter;
		return stringWithMissingLetter;
	}
	void Validate()
	{
		while ((_stringTooLong || _stringWithNoLetter))
		{
			_stringTooLong = false;
			_stringWithNoLetter = false;
			if (_validateThatString.length() > 2)
			{
				_validateThatString = InPutStringTooLong(_validateThatString);
				_stringTooLong = true;
			}
			if (!(((_validateThatString[0] <= 74 && _validateThatString[0] >= 65) || (_validateThatString[0] <= 106 && _validateThatString[0] >= 97)) || ((_validateThatString[1] <= 74 && _validateThatString[1] >= 65) || (_validateThatString[1] <= 106 && _validateThatString[1] >= 97))))
			{
				_validateThatString = MissingLetterInInPutString(_validateThatString);
				_stringWithNoLetter = true;
			}
		}
	}

	void SortLetterAndNumberOrder()
	{

	}


public:
	ValidatePlayerInPutLocation(string playerInPutString)
	{
		_validateThatString = playerInPutString;
		Validate();
		SortLetterAndNumberOrder();
		_playerInPutString = _validateThatString;
	}
	string GetPropperPlayerString()
	{
		return _playerInPutString;
	}
	
};


/*
* 
A - 65 J-74
a - 97 j-106
0 - 48 9-57

*/