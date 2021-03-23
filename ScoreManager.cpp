#include "ScoreManager.h"
#include "Color.h"
#include "MenuManager.h"

extern MenuManager menu;
ScoreManager::ScoreManager()
{
	currentScore = 0;
	selectedR = 0;
	totalR = 0;
}
void ScoreManager::increase()
{
	currentScore += 10;
}
void ScoreManager::draw()
{
	iG::iSetColor(YELLOW);
	iG::iRectangle(iG::iGetWindowWidth() - 250.0f, iG::iGetWindowHeight() - 180.0f, 250.0f, 180.0f);
	char temp[40];
	snprintf(temp, 40, "SCORE :  %d", currentScore);
	iG::iSetColor(RED);
	iG::iText(iG::iGetWindowWidth() - 200.0f, iG::iGetWindowHeight() - 50.0f, temp);
	
}
void ScoreManager::drawGameOver()
{
	char temp[40];
	snprintf(temp, 40, "SCORE : %d", currentScore);
	iG::iSetColor(BLACK);
	iG::iBigText(iG::iGetWindowWidth()/2.0f - 530, iG::iGetWindowHeight() - 300.0f, temp);

	glPushMatrix();
	glTranslatef(iG::iGetWindowWidth() / 2.0f -630, iG::iGetWindowHeight() / 2.0f-30 , 0.0f);
	glScalef(0.5f, 0.5f, 1.0f);
	iG::iSetColor(BLACK);
	iG::iBigText(0, 0,name);
	glPopMatrix();
}

void ScoreManager::drawBoard()
{
	int i;
	glPushMatrix();
	glTranslatef(iG::iGetWindowWidth() / 2.0f, iG::iGetWindowHeight(), 0.0f);
	glScalef(0.6f, 0.6f, 1.0f);
	iG::iSetColor(RED);
	iG::iBigText(-600, -200, "NAME");
	iG::iBigText(400, -200, "SCORE");
	glPopMatrix();
	ifstream in;
	cout << "DRAW" << endl;
	in.open("Data\\HIGHSCORE.txt", ios::in);
	for (i = 0;!in.eof();i++)
	{
		string str, s;
		in >> str >> s;
		cout << str << endl;
		{
			cout << str << endl;

			if (selectedR == i)
			{
				iG::iSetColor(YELLOW);
				iG::iRectangle(iG::iGetWindowWidth() / 2.0f - 800, iG::iGetWindowHeight() - 225.0f - i * 83, 1600.0f,70.0f);
			}
			
			glPushMatrix();
			glTranslatef(iG::iGetWindowWidth() / 2.0f, iG::iGetWindowHeight(), 0.0f);
			glScalef(0.45f, 0.45f, 1.0f);
			iG::iSetColor(BLACK);
			iG::iBigText(-550.0f- str.length()*35.0, - 470.0f - i * 185, str);
			iG::iBigText(550.0f ,- 470.0f - i * 185, s);
			glPopMatrix();
		}
	}
	in.close();
	iG::iSetColor(RED);
	iG::iText(iG::iGetWindowWidth() / 2.0f - 150,20.0f, "Press e to edit and d to delete");
	totalR = i;
}

struct ScoreType
{
	string name;
	int score;
};
void ScoreManager::save()
{
	vector<ScoreType> ScoreSheet;
	int i, j, k;
	ifstream in;
	in.open("Data\\HIGHSCORE.txt", ios::in);
	while (!in.eof())
	{
		string str;
		int s;
		in >> str >> s;
		if (str != "")
		{
			ScoreSheet.push_back({ str, s });
		}
	}
	in.close();

	ScoreType temp = { name, currentScore };
	for (j = 0; j < ScoreSheet.size(); j++)
	{
		if (currentScore > ScoreSheet[j].score)
		{
			
			ScoreSheet.insert(ScoreSheet.begin() + j,temp);
			break;
		}
	}
	if (j == ScoreSheet.size() && j < 10)
	{
		ScoreSheet.push_back(temp);
	}
	ofstream out;
	out.open("Data\\HIGHSCORE.txt", ios::out);
	for (i = 0; i < ScoreSheet.size() - 1 && i < 9; i++)
	{
		out << ScoreSheet[i].name << " " << ScoreSheet[i].score << endl;
	}
	out << ScoreSheet[i].name << " " << ScoreSheet[i].score;
	out.close();
	totalR = ScoreSheet.size();

}
void ScoreManager::reset()
{
	currentScore = 0;
}
void ScoreManager::nameEntry(unsigned char key)
{
	switch (key)
	{
	case '\r':
		if (!name.empty())
		{
			save();
			name.clear();
			menu.set(MenuManager::MAIN);
		}
		break;
	case '\b':
		if (!name.empty())
		{
			name.pop_back();
		}
	case ' ':
		break;
	default:
		if (name.length() < 25)
		{
			name += key;
		}
		break;
	}
}

void ScoreManager::keyUp()
{
	if (selectedR > 0)
	{
		selectedR--;
	}
	else
	{
		selectedR = totalR-1;
	}
}
void ScoreManager::keyDown()
{
	if (selectedR < totalR-1)
	{
		selectedR++;
	}
	else
	{
		selectedR = 0;
	}
}


void ScoreManager::erase()
{
	vector<ScoreType> ScoreSheet;
	int i, j, k;
	ifstream in;
	in.open("Data\\HIGHSCORE.txt", ios::in);
	while (!in.eof())
	{
		string str;
		int s;
		in >> str >> s;
		if (str != "")
		{
			ScoreSheet.push_back({ str, s });
		}
	}
	in.close();

	ScoreSheet.erase(ScoreSheet.begin() + selectedR);

	ofstream out;
	out.open("Data\\HIGHSCORE.txt", ios::out);
	for (i = 0; i < ScoreSheet.size() - 1 && i < 9; i++)
	{
		out << ScoreSheet[i].name << " " << ScoreSheet[i].score << endl;
	}
	out << ScoreSheet[i].name << " " << ScoreSheet[i].score;
	out.close();
	totalR = ScoreSheet.size();
}

void ScoreManager::edit()
{
	vector<ScoreType> ScoreSheet;
	int i, j, k;
	ifstream in;
	in.open("Data\\HIGHSCORE.txt", ios::in);
	while (!in.eof())
	{
		string str;
		int s;
		in >> str >> s;
		if (str != "")
		{
			ScoreSheet.push_back({ str, s });
		}
	}
	in.close();

	currentScore = ScoreSheet[selectedR].score;
	ScoreSheet.erase(ScoreSheet.begin() + selectedR);

	ofstream out;
	out.open("Data\\HIGHSCORE.txt", ios::out);
	for (i = 0; i < ScoreSheet.size() - 1 && i < 9; i++)
	{
		out << ScoreSheet[i].name << " " << ScoreSheet[i].score << endl;
	}
	out << ScoreSheet[i].name << " " << ScoreSheet[i].score;
	out.close();
	totalR = ScoreSheet.size();

	menu.set(MenuManager::GAMEOVER);
}