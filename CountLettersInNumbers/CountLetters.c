#include <stdio.h>

int getLettersInDigit(int digit);
int getNumLettersInNumber(int number);
int countLettersInNumbers(int upTo);

int main()
{
	int num = 0;
	printf("Enter number no greater than 9999: ");
	scanf("%d", &num);
	printf("There are %d letters in all of the numbers up to %d\n", countLettersInNumbers(num), num);
	return 0;
}

int getLettersInDigit(int digit)
{
	switch(digit)
	{
		//case 0: //ZERO
		//	return 4;
		case 1: //ONE
			return 3;
		case 2: //TWO
			return 3;
		case 3: //THREE
			return 5;
		case 4: //FOUR
			return 4;
		case 5: //FIVE
			return 4;
		case 6: //SIX
			return 3;
		case 7: //SEVEN
			return 5;
		case 8: //EIGHT
			return 5;
		case 9: //NINE
			return 4;
		case 10: //TEN
			return 3;
		case 11: //ELEVEN
			return 6;
		case 12: //TWELVE
			return 6;
		case 13: //THIRTEEN
			return 8;
		case 14: //FOURTEEN
			return 8;
		case 15: //FIFTEEN
			return 7;
		case 16: //SIXTEEN
			return 7;
		case 17: //SEVENTEEN
			return 9;
		case 18: //EIGHTEEN
			return 8;
		case 19: //NINETEEN
			return 8;
		case 20: //TWENTY
			return 6;
		case 30: //THIRTY
			return 6;
		case 40: //FORTY
			return 5;
		case 50: //FIFTY
			return 5;
		case 60: //SIXTY
			return 5;
		case 70: //SEVENTY
			return 7;
		case 80: //EIGHTY
			return 6;
		case 90: //NINETY
			return 6;
	}
}

int getNumLettersInNumber(int number)
{
	int count = 0;
	const int THOUSAND = 8;
	const int HUNDRED = 7;
	
	while(number)
	{
		if(number > 999)
		{
			count += getLettersInDigit(number / 1000);
			count += THOUSAND;
			number = number % 1000;
		}
		else if(number > 99)
		{
			count += getLettersInDigit(number / 100);
			count += HUNDRED;
			if (number % 100)
				count += 3; //AND
			number = number % 100;
		}
		else if (number > 20)
		{
			count += getLettersInDigit((number / 10) * 10);
			number = number % 10;
			if(number)
				count += getLettersInDigit(number);
			return count;
		}
		else 
		{
			count += getLettersInDigit(number);
			return count;
		}
	}
	return count;
}

int countLettersInNumbers(int upTo)
{
	int count = 0;	
	int i;
	
	for(i = 1; i <= upTo; ++i)
	{
		printf("%d : %d letters\n", i, getNumLettersInNumber(i));
		count += getNumLettersInNumber(i);
	}
	
	return count;
}
