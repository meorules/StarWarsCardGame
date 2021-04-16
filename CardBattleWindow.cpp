#include "CardBattleWindow.h"

CardBattleWindow::CardBattleWindow(HINSTANCE hInsantce, int width, int height, User* currentUser) : Window(hInsantce, width, height), currentMenuUser(currentUser),userScore(0),opponentScore(0)
{
  createWindow(hInsantce, width, height);

  for (int i = 0; i < 5; i++) {
    userDeck[i] = *currentMenuUser->returnCardDeck(i);
  }
  opponent = new User("Opponent", "", currentMenuUser->getLosses(), currentMenuUser->getWins());
  userSelectedStat = nothing;
  selectedUserCardType = none;

}

CardBattleWindow::~CardBattleWindow()
{
  delete opponent;
}

void CardBattleWindow::onDraw()
{
  drawBitmap(backgroundFile, 0, 0, width, height);
  setTextColour(CYAN);
  //Title
  setFont(28, L"Univers Bold");
  drawText(L"User vs AI Battle", 300, 35);
  setFont(12, L"Univers");
  drawText("Select a Card and stat or ability then click attack to apply the buffs to your cards", 600, 20);
  drawText("or the debuff to the opponent cards. If you attack with a stat,the opponent will", 600, 40);
  drawText("automatically select a card themselves to defend with.",600, 60);
  

  //drawing AI Card Deck
  setTextColour(CYAN);
  setFont(28, L"Univers Bold");
  drawText(L"User Card Deck", 30, 530);
  for (int i = 0; i < 5; i++) {
    opponent->returnCardDeck(i)->draw(this, 25 + (i) * (cardWidth + 15), 100, cardWidth, cardHeight);
    if (selectedAICard != nullptr && currentMenuUser->returnCardDeck(i) == selectedAICard) {
      setPenColour(65535, 4);
      drawRectangle(25 + (i) * (cardWidth + 15), 100, cardWidth, cardHeight - 5, false);
    }
  }


  //Making Pointers to the various types of cards to be used later
  FightingCard* fC=nullptr;
  SpecialFightingCard* sFC=nullptr;
  AbilityCard* aC=nullptr;

  //drawing User Card Deck
  setTextColour(CYAN);
  setFont(28, L"Univers Bold");
  drawText(L"User Card Deck", 30, 530);

  for (int i = 0; i < 5; i++) {
    currentMenuUser->returnCardDeck(i)->draw(this, 25 + (i) * (cardWidth + 15), 600, cardWidth, cardHeight);
    if (selectedUserCard != nullptr && currentMenuUser->returnCardDeck(i) == selectedUserCard) {
      setPenColour(65535, 4);
      drawRectangle(25 + (i) * (cardWidth + 15), 600, cardWidth, cardHeight - 5, false);
      currentMenuUser->returnCardDeck(i)->draw(this, 900, 100, cardWidth+50, cardHeight+70);

      fC = dynamic_cast<FightingCard*>(currentMenuUser->returnCardDeck(i));
      sFC = dynamic_cast<SpecialFightingCard*>(currentMenuUser->returnCardDeck(i));
      aC = dynamic_cast<AbilityCard*>(currentMenuUser->returnCardDeck(i));
      if (fC != nullptr) {
        if ( sFC!= nullptr) {
          selectedUserCardType = special;
        }
        else {
          selectedUserCardType = fighting;
        }
      }
      else if( aC != nullptr){
        selectedUserCardType = ability;
      }
    }
  }

  if (selectedUserCard != nullptr) {
    setFont(12, L"News Gothic Bold");
    if (selectedUserCardType == ability) {
      setBackColour(MAGENTA);
      drawRectangle(945, 345, 85, 50, true);
      drawText(L"Use Ability", 950, 350);
      drawText(aC->getAbilityName().c_str(), 950, 370);
      if (userSelectedStat == specialability) {
        setPenColour(65535, 4);
        drawRectangle(945, 345, 85, 50, false);
      }
    }
    else if (selectedUserCardType == fighting) {
      setBackColour(DARK_BLUE);
      setTextColour(WHITE);
      drawRectangle(900, 345, 85, 30, true);
      drawText(L"Force", 905, 350);
      drawRectangle(900, 380, 85, 30, true);
      drawText(L"Block", 905, 385);
      drawRectangle(990, 345, 85, 30, true);
      drawText(L"Gunnin", 995, 350);
      drawRectangle(990, 380, 85, 30, true);
      drawText(L"Melee", 995, 385);

      switch (userSelectedStat) {
        setPenColour(65535, 4);
      case force:
        drawRectangle(900, 345, 85, 30, false);
        break;
      case block:
        drawRectangle(900, 380, 85, 30, false);
        break;
      case gunnin:
        drawRectangle(990, 345, 85, 30, false);
        break;
      case melee:
        drawRectangle(990, 380, 85, 30, false);
        break;
      }
    }
    else if (selectedUserCardType == special) {
      setBackColour(MAGENTA);
      drawRectangle(945, 345, 85, 50, true);
      drawText(L"Use Ability", 950, 350);
      drawText(sFC->getAbilityName().c_str(), 950, 370);
      setFont(12, L"News Gothic Bold");
      setBackColour(DARK_BLUE);
      setTextColour(WHITE);
      drawRectangle(900, 410, 85, 30, true);
      drawText(L"Force", 905, 415);
      drawRectangle(900, 445, 85, 30, true);
      drawText(L"Block", 905, 450);
      drawRectangle(990, 410, 85, 30, true);
      drawText(L"Gunnin", 995, 415);
      drawRectangle(990, 445, 85, 30, true);
      drawText(L"Melee", 995, 450);

      switch (userSelectedStat) {
        setPenColour(65535, 4);
      case specialability:
        drawRectangle(945, 345, 85, 50, false);
        break;
      case force:
        drawRectangle(900, 410, 85, 30, false);
        break;
      case block:
        drawRectangle(900, 445, 85, 30, false);
        break;
      case gunnin:
        drawRectangle(990, 410, 85, 30, false);
        break;
      case melee:
        drawRectangle(990, 445, 85, 30, false);
        break;
      }
    }
  }
  //Back to User Menu Button 
  setPenColour(16777215, 3);
  setFont(12, L"News Gothic Bold");
  setBackColour(DARK_BLUE);
  setTextColour(WHITE);
  drawRectangle(1000, 700, 85, 30, true);
  drawText(L"User Menu", 1005, 705);

  Window::onDraw();
}

void CardBattleWindow::onCreate()
{
  Window::onCreate();
  SetWindowText(getHWND(), L"User Battle vs AI");
}

void CardBattleWindow::onLButtonDown(UINT nFlags, int x, int y)
{
  if (x > 1000 && x < 1085 && y>700 && y < 730) {
    UserMenuWindow* main = new UserMenuWindow(hInstance, 600, 400, currentMenuUser);
   // CardLibrary::loadCards();
    DestroyWindow(getHWND());
    main->waitForClose();
    delete this;
  }
  else {
    for (int j = 0; j < CardLibrary::returnInstance()->returnList()->size(); j++)
    {
      if (CardLibrary::returnInstance()->returnList()->at(j)->hitTest(x, y)) {
          selectedUserCard = CardLibrary::returnInstance()->returnList()->at(j);
        
      }
    }
    if (selectedUserCardType == ability) {
      //      drawRectangle(945, 345, 85, 50, true);
      if (x > 945 && x < 1030 && y>345 && y < 395) {
        userSelectedStat = specialability;
      }
    }
    else if (selectedUserCardType == fighting) {
      /*drawRectangle(900, 345, 85, 30, true); Force
      drawRectangle(900, 380, 85, 30, true); Block
      drawRectangle(990, 345, 85, 30, true); Gunnin
      drawRectangle(990, 380, 85, 30, true); Melee*/

      if (x > 900 && x < 985 && y>345 && y < 375) {
        userSelectedStat = force;
      }
      else if (x > 900 && x < 985 && y>380 && y < 410) {
        userSelectedStat = block;
      }
      else if (x > 990 && x < 1075 && y>345 && y < 375) {
        userSelectedStat = gunnin;
      }
      else if (x > 990 && x < 1075 && y>380 && y < 410) {
        userSelectedStat = melee;
      }

    }
    else if (selectedUserCardType == special) {
     if (x > 945 && x < 1030 && y>345 && y < 395) {
      userSelectedStat = specialability;
    }
     //drawRectangle(900, 410, 85, 30, true); Force
     //drawRectangle(900, 445, 85, 30, true); Block 
     //drawRectangle(990, 410, 85, 30, true); Gunnin
     //drawRectangle(990, 445, 85, 30, true); Melee
     else if (x > 900 && x < 985 && y>410 && y < 440) {
       userSelectedStat = force;
     }
     else if (x > 900 && x < 985 && y>445 && y < 475) {
       userSelectedStat = block;
     }
     else if (x > 990 && x < 1075 && y>410 && y < 440) {
       userSelectedStat = gunnin;
     }
     else if (x > 990 && x < 1075 && y>445 && y < 475) {
       userSelectedStat = melee;
     }
    }
  }
  onDraw();
}

void CardBattleWindow::applyStatChange(bool isUser, cardStat, int change)
{
  if (isUser) {
    //Apply buff or debuff on user cards
  }
  else {
    //Apply buff or debuff on opponent cards
  }
}
