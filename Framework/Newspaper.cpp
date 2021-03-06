#include "stdafx.h"
#include "Newspaper.h"
#include "Scene.h"
#include "GameManager.h"

Newspaper::Newspaper()
{
	dayChangeCheck = 1;
	mainCheck = 1;
	SetNews();

}


Newspaper::~Newspaper()
{

}

void Newspaper::NewsChange(int day) // 매일매일 신문 바뀔때 쓰는 코드 
{

	//메인기사 바꾸는 코드 
	/*if (day == 2)
	{
		ChangeSprite(mainPage, mainPageList[mainCheck]);
		mainCheck++;
	}
	else if (day == 4)
	{
		ChangeSprite(mainPage, mainPageList[mainCheck]);
		mainCheck++;
	}
	else if (day == 6)
	{
		ChangeSprite(mainPage, mainPageList[mainCheck]);
		mainCheck++;
	}*/

	//서브기사 바꾸는 코드 
	if (day < 4 && day == dayChangeCheck)
	{
		RandomPick();
		ChangeSprite(sub1, subDay1[sub1Cnt]);
		ChangeSprite(sub2, subDay1[sub2Cnt]);
		ChangeSprite(sub3, subDay1[sub3Cnt]);
		++dayChangeCheck;
		GameManager::GetInstance()->objectManager->GenerateObjects(1, sub1Cnt, sub2Cnt, sub3Cnt);
	}
	else if (day < 7 && day == dayChangeCheck)
	{
		RandomPick();
		ChangeSprite(sub1, subDay2[sub1Cnt]);
		ChangeSprite(sub2, subDay2[sub2Cnt]);
		ChangeSprite(sub3, subDay2[sub3Cnt]);
		++dayChangeCheck;
		GameManager::GetInstance()->objectManager->GenerateObjects(2, sub1Cnt, sub2Cnt, sub3Cnt);
	}
	else if (day < 10 && day == dayChangeCheck)
	{
		RandomPick();
		ChangeSprite(sub1, subDay3[sub1Cnt]);
		ChangeSprite(sub2, subDay3[sub2Cnt]);
		ChangeSprite(sub3, subDay3[sub3Cnt]);
		++dayChangeCheck;
		GameManager::GetInstance()->objectManager->GenerateObjects(3, sub1Cnt, sub2Cnt, sub3Cnt);
	}
	else if (day == dayChangeCheck)
	{
		RandomPick();
		ChangeSprite(sub1, subDay4[sub1Cnt]);
		ChangeSprite(sub2, subDay4[sub2Cnt]);
		ChangeSprite(sub3, subDay4[sub3Cnt]);
		++dayChangeCheck;
		GameManager::GetInstance()->objectManager->GenerateObjects(4, sub1Cnt, sub2Cnt, sub3Cnt);
	}
}

void Newspaper::RandomPick()//서브 기사 랜덤생성용
{
	int newsCount;
	if (dayChangeCheck < 4)
		newsCount = 11;
	else if (dayChangeCheck < 7)
		newsCount = 13;
	else if (dayChangeCheck < 10)
		newsCount = 12;
	else
		newsCount = 8;

	sub1Cnt = rand() % newsCount;
	sub2Cnt = rand() % newsCount;
	sub3Cnt = rand() % newsCount;

	while (sub1Cnt == sub2Cnt || sub2Cnt == sub3Cnt || sub1Cnt == sub3Cnt)
	{
		sub1Cnt = rand() % newsCount;
		sub2Cnt = rand() % newsCount;
		sub3Cnt = rand() % newsCount;
	}

}

void Newspaper::SetNews()//처음에 뉴스 세팅 
{

	//이거 나중에 코드 보면 이미지 위치 수정해주라  mainPage sub1 2 3 이미지 위치 
	newsOutline = Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources/sprites/newspaper/main.png", Vector2(1712, HEIGHT / 2)));
	newsOutline->renderer->SetLayer(3);

	mainPage = Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources/sprites/newspaper/b1.png", Vector2(1714.5f, HEIGHT / 2 - 53.5f)));
	mainPage->renderer->SetLayer(3);

	sub1 = Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources/sprites/newspaper/1.png", Vector2(1714.5f, HEIGHT / 2 + 193)));
	sub1->renderer->SetLayer(3);

	sub2 = Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources/sprites/newspaper/2.png", Vector2(1714.5f, HEIGHT / 2 + 297)));
	sub2->renderer->SetLayer(3);

	sub3 = Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources/sprites/newspaper/3.png", Vector2(1714.5f, HEIGHT / 2 + 400)));
	sub3->renderer->SetLayer(3);
}


void Newspaper::ChangeSprite(GameObject* g, const wchar_t* path)
{
	SAFE_DELETE(g->renderer);
	g->renderer = new Renderer(Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(path, 0, 0));
	g->renderer->SetLayer(3);
}
