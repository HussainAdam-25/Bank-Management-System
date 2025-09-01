#include<iomanip>
#include<fstream>
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"clsShowLoginScreen.h"


using namespace std;




int main()
{

	while (true)
	{
		if (!clsShowLoginScreen::ShowLoginScreen())
		{
			break;

		}


	}



	system("pause>0");
}





