#include "ScoreManager.h"
#include "Color.h"
#include "MenuManager.h"

extern MenuManager menu;
extern GameManager game;
ScoreManager::ScoreManager()
{
	currentScore = 0;
	selectedR = 0;
	totalR = 0;
}
void ScoreManager::reset()
{
	currentScore = 0;
}
void ScoreManager::increase()
{
	currentScore += 10;
}
void ScoreManager::draw()
{
	iG::iSetColor(100,100,100,.5);
	iG::iRectangle(iG::iGetWindowWidth() - 260.0f, iG::iGetWindowHeight() - 210.0f, 260.0f, 210.0f);

	char temp[40];
	snprintf(temp, 40, "SCORE :  %d", currentScore);
	iG::iSetColor(RED);
	Text::render(iG::iGetWindowWidth() - 250.0f, iG::iGetWindowHeight() - 50.0f, temp);

	

	
}
void ScoreManager::drawGameOver()
{
	char temp[40];

	// Draw Score
	snprintf(temp, 40, "SCORE : %d", currentScore);
	iG::iSetColor(BLACK);
	Text::render(iG::iGetWindowWidth() / 2.0f - 530, iG::iGetWindowHeight() - 300.0f, temp);

	// Draw name entry
	glPushMatrix();
	glTranslatef(iG::iGetWindowWidth() / 2.0f - 630, iG::iGetWindowHeight() / 2.0f - 30, 0.0f);
	glScalef(0.5f, 0.5f, 1.0f);
	iG::iSetColor(BLACK);
	Text::render(0, 0, name);
	glPopMatrix();
}

void ScoreManager::drawBoard()
{
	GLint i;
	// Draw Header
	iG::iSetColor(RED);
	Text::render(200, iG::iGetWindowHeight() - 100 , "NAME");
	Text::render(600, iG::iGetWindowHeight() - 100 , "TIME");
	Text::render(1200, iG::iGetWindowHeight() - 100 , "SCORE");

	// Draw scores
	ifstream in;
	in.open("Data\\HIGHSCORE.txt", ios::in);
	for (i = 0;!in.eof();i++)
	{
		string str, s,t;
		in >> str >> t >> s;

		if (selectedR == i)
		{
			iG::iSetColor(100, 100, 100, 0.5);
			iG::iRectangle(iG::iGetWindowWidth() / 2.0f - 800, iG::iGetWindowHeight() - 225.0f - i * 83, 1600.0f, 70.0f);
		}

		iG::iSetColor(BLACK);
		Text::render(300.0f - str.length() * 35.0, iG::iGetWindowHeight()-200 - i * 85, str);
		Text::render(650.0f, iG::iGetWindowHeight() - 200 - i * 85, t);
		Text::render(1200.0f, iG::iGetWindowHeight() - 200 - i * 85, s);
	}
	in.close();

	// Draw instructions
	iG::iSetColor(RED);
	Text::render(iG::iGetWindowWidth() / 2.0f - 150, 20.0f, "Press e to edit and d to delete");
	totalR = i;
}

struct ScoreType
{
	string name;
	GLint time;
	GLint score;
};
void read(vector<ScoreType>& scoreSheet)
{
	ifstream in;
	in.open("Data\\Highscore.txt", ios::in);
	while (!in.eof())
	{
		string str;
		GLint s;
		GLint t;
		in >> str >> t >> s;
		if (str != "")
		{
			scoreSheet.push_back({ str, t , s });
		}
	}
	in.close();
}
void write(vector<ScoreType>& scoreSheet)
{
	GLint i;
	ofstream out;
	out.open("Data\\Highscore.txt", ios::out);
	for (i = 0; i < scoreSheet.size() - 1 && i < 9; i++)
	{
		out << scoreSheet[i].name << " " << scoreSheet[i].time<<" "<<scoreSheet[i].score << endl;
	}
	out << scoreSheet[i].name << " " << scoreSheet[i].time << " " << scoreSheet[i].score;
	out.close();
}
void ScoreManager::save()
{
	vector<ScoreType> scoreSheet;
	read(scoreSheet);
	ScoreType temp = { name, game.getTime() , currentScore };
	GLint i;
	for (i = 0; i < scoreSheet.size(); i++)
	{
		if (currentScore > scoreSheet[i].score)
		{
			scoreSheet.insert(scoreSheet.begin() + i, temp);
			break;
		}
		else if (currentScore == scoreSheet[i].score && game.getTime() < scoreSheet[i].time)
		{
			scoreSheet.insert(scoreSheet.begin() + i, temp);
			break;
		}
	}
	if (i == scoreSheet.size() && i < 10)
	{
		scoreSheet.push_back(temp);
	}
	write(scoreSheet);
	totalR = scoreSheet.size();
}


void ScoreManager::erase()
{
	vector<ScoreType> scoreSheet;
	read(scoreSheet);
	scoreSheet.erase(scoreSheet.begin() + selectedR);
	write(scoreSheet);
	totalR = scoreSheet.size();
}

void ScoreManager::edit()
{
	vector<ScoreType> scoreSheet;
	read(scoreSheet);
	currentScore = scoreSheet[selectedR].score;
	scoreSheet.erase(scoreSheet.begin() + selectedR);
	write(scoreSheet);
	totalR = scoreSheet.size();
	menu.set(MenuManager::GAMEOVER);
}

void ScoreManager::nameEntry(int key)
{
	switch (key)
	{
	case GLFW_KEY_ENTER:
		if (!name.empty())
		{
			save();
			name.clear();
			menu.set(MenuManager::MAIN);
		}
		break;
	case GLFW_KEY_BACKSPACE:
		if (!name.empty())
		{
			name.pop_back();
		}
	case ' ':
		break;
	default:
		if (name.length() < 25)
		{
			name += (char)key;
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
		selectedR = totalR - 1;
	}
}
void ScoreManager::keyDown()
{
	if (selectedR < totalR - 1)
	{
		selectedR++;
	}
	else
	{
		selectedR = 0;
	}
}