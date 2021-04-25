#include "CardBattleWindow.h"

CardBattleWindow::CardBattleWindow(HINSTANCE hInsantce, int width, int height, User* currentUser) : Window(hInsantce, width, height), currentMenuUser(currentUser)
{
  createWindow(hInsantce, width, height);
  battle = GameBattle(currentMenuUser);
  userSelectedStat = cardStat::none;
  selectedUserCardType = cardType::none;
}

CardBattleWindow::~CardBattleWindow()
{
  
}

void CardBattleWindow::onDraw()
{
  drawBitmap(backgroundFile, 0, 0, width, height);
  setTextColour(CYAN);
  //Title
  setFont(28, L"Ebrima Bold");
  drawText(L"User vs AI Battle", 300, 35);
  setFont(12, L"Georgia");
  drawText("Select a Card and stat or ability then click attack to apply the buffs to your cards", 600, 20);
  drawText("or the debuff to the opponent cards. If you attack with a stat,the opponent will", 600, 40);
  drawText("automatically select a card themselves to defend with.",600, 60);
  
  //Game End Screen
  gameEndState = battle.gameEnd();
  if (gameEndState != -1) {
    setBackColour(BLACK);
    setTextColour(WHITE);
    outputText = "";
    if (gameEndState == 1) {
      setPenColour(GREEN, 4);
      drawRectangle(300, 200, 600, 300, true);
      setFont(36, L"Ebrima Bold ");
      drawText(L"The game is over", 350, 250);
      setTextColour(GREEN);
      drawText(L"You won this battle :) ", 350, 350);
    }
    else if (gameEndState == 0) {
      setPenColour(YELLOW, 4);
      drawRectangle(300, 200, 600, 300, true);
      setFont(36, L"Ebrima Bold ");
      drawText(L"The game is over", 350, 250);
      setTextColour(YELLOW);
      drawText(L"A draw it is", 350, 350);
    }
    else if (gameEndState == 2) {
      setPenColour(RED, 4);
      drawRectangle(300, 200, 600, 300, true);
      setFont(36, L"Ebrima Bold ");
      drawText(L"The game is over", 350, 250);
      setTextColour(RED);
      drawText(L"You lost this battle ;( ", 350, 350);
    }
  }


  //drawing AI Card Deck
  setTextColour(CYAN);
  setFont(28, L"Ebrima Bold");
  drawText(L"AI Card Deck", 30, 100);
  string opponentScoreBoard = "AI Score: " + to_string(battle.opponentScore);
  drawText(opponentScoreBoard.c_str(), 500, 100);

  for (int i = 0; i < 5; i++) {
    if (battle.getOpponentDeck(i)!= nullptr) {
      battle.getOpponentDeck(i)->draw(this, 25 + (i) * (cardWidth + 15), 150, cardWidth, cardHeight);
    }
    }

  //Reactive Output Text discussing opponent moves
  setFont(12, L"Ebrima Bold");
  drawText(outputText.c_str(), 30, 400);
  

  if (battle.userTurn) {
    drawText(L"Its your turn", 30, 460);
  }
  else {
    drawText(L"Its the opponent's turn", 30, 460);
  }

  //drawing User Card Deck
  setTextColour(CYAN);
  setFont(28, L"Ebrima Bold");
  drawText(L"User Card Deck:", 30, 530);
  string userScoreBoard = "User Score: " + to_string(battle.userScore);
  drawText(userScoreBoard.c_str(), 500, 530);


  for (int i = 0; i < 5; i++) {
    if (battle.getUserDeck(i) != nullptr) {
      battle.getUserDeck(i)->draw(this, 25 + (i) * (cardWidth + 15), 600, cardWidth, cardHeight);
      //Drawing the Card on the side
      if (selectedUserCard != nullptr && battle.getUserDeck(i) == selectedUserCard) {
        setPenColour(65535, 4);
        drawRectangle(25 + (i) * (cardWidth + 15), 600, cardWidth, cardHeight - 5, false);
        battle.getUserDeck(i)->draw(this, 900, 100, cardWidth + 50, cardHeight + 70);
        //Checking using Runtime Type Information the type of card, to set the card type
        fC = dynamic_cast<FightingCard*>(battle.getUserDeck(i));
        sFC = dynamic_cast<SpecialFightingCard*>(battle.getUserDeck(i));
        aC = dynamic_cast<AbilityCard*>(battle.getUserDeck(i));
        if (fC != nullptr) {
          if (sFC != nullptr) {
            selectedUserCardType = cardType::special;
          }
          else {
            selectedUserCardType = cardType::fighting;
          }
        }
        else if (aC != nullptr) {
          selectedUserCardType = cardType::ability;
        }
      }
    }
  }

  //Drawing the selected ability
  if (selectedUserCard != nullptr) {
    setFont(12, L"News Gothic Bold");
    if (selectedUserCardType == cardType::ability) {
      setPenColour(16777215, 3);
      setBackColour(MAGENTA);
      drawRectangle(945, 345, 85, 50, true);
      drawText(L"Use Ability", 950, 350);
      drawText(aC->getAbilityName().c_str(), 950, 370);
      if (userSelectedStat == cardStat::ability) {
        setPenColour(65535, 3);
        drawRectangle(945, 345, 85, 50, false);
      }
    }
    else if (selectedUserCardType == cardType::fighting) {
      setPenColour(16777215, 3);
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

      setPenColour(65535, 3);
      switch (userSelectedStat) {
      case cardStat::force:
        drawRectangle(900, 345, 85, 30, false);
        break;
      case cardStat::block:
        drawRectangle(900, 380, 85, 30, false);
        break;
      case cardStat::gunnin:
        drawRectangle(990, 345, 85, 30, false);
        break;
      case cardStat::melee:
        drawRectangle(990, 380, 85, 30, false);
        break;
      }
    }
    else if (selectedUserCardType == cardType::special) {
      setPenColour(16777215, 3);
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

      setPenColour(65535, 3);
      switch (userSelectedStat) {
      case cardStat::ability:
        drawRectangle(945, 345, 85, 50, false);
        break;
      case cardStat::force:
        drawRectangle(900, 410, 85, 30, false);
        break;
      case cardStat::block:
        drawRectangle(900, 445, 85, 30, false);
        break;
      case cardStat::gunnin:
        drawRectangle(990, 410, 85, 30, false);
        break;
      case cardStat::melee:
        drawRectangle(990, 445, 85, 30, false);
        break;
      }
    }
    setPenColour(16777215, 3);
    setBackColour(DARK_BLUE);
    setTextColour(WHITE);
    drawRectangle(915, 500, 155, 50, true);
    drawText(L"Attack with Selected", 920, 505);
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
      if (gameEndState == 1) {
        currentMenuUser->addWin();
        currentMenuUser->addRandomCard();
      }
      else if (gameEndState == 0) {
        currentMenuUser->addDraw();
      }
      else if (gameEndState == 2 || gameEndState==-1) {
        currentMenuUser->addLoss();
      }
    UserMenuWindow* main = new UserMenuWindow(hInstance, 600, 400, currentMenuUser);
    // CardLibrary::loadCards();
    DestroyWindow(getHWND());
    main->waitForClose();
    delete main;
  }
  //Attack Button     drawRectangle(915, 500, 155, 50, true);
  else if (x > 915 && x < 1070 && y>500 && y < 550 && selectedUserCard!=nullptr && userSelectedStat != cardStat::none) {
    if (battle.userTurn) {
      //attacking with ability
      if (userSelectedStat == cardStat::ability) {
        if (sFC != nullptr) {
          SpecialAbility* abilityToUse = sFC->getAbility();
          int statAffected = sFC->getStatAffected();
          string effect = abilityToUse->returnEffect();
          if (effect.at(0) == '-') {
            battle.applyStatChange(statAffected, stoi(effect), false);
          }
          else if (effect.at(0) == '+') {
            battle.applyStatChange(statAffected, stoi(effect), true);
          }
          battle.removeCard(selectedUserCard, true);
          selectedUserCard = nullptr;
          selectedUserCardType = cardType::none;
          userSelectedStat = cardStat::none;
        }
        else if (aC != nullptr) {
          SpecialAbility* abilityToUse = aC->getAbility();
          string effect = abilityToUse->returnEffect();
          for (int statAffected = 0; statAffected < 4; statAffected++) {
            if (aC->getStatAffected(statAffected)) {
              if (effect.at(0) == '-') {
                battle.applyStatChange(statAffected, stoi(effect), false);
              }
              else if (effect.at(0) == '+') {
                battle.applyStatChange(statAffected, stoi(effect), true);
              }
            }
          }
          battle.removeCard(selectedUserCard, true);
          resetSelected();
          battle.userScore++;
        }
        battle.userTurn = false;
      }
      else {
        battle.cardBattle(selectedUserCard, userSelectedStat);
        resetSelected();
      }
      battle.userTurn = false;
    }
    else {
      if (attack.attackType == cardType::fighting) {
        if (selectedUserCardType != cardType::ability) {
          outputText = battle.cardBattle(selectedUserCard, attack.attackStat);
          resetSelected();
        }
        else {
          battle.removeCard(attack.attackingCard, false);
          battle.removeCard(selectedUserCard , true);
          outputText = " The opponent attacked and you used an ability card and lost :(";
          battle.opponentScore += 3;
          battle.userScore++;
        }
      }
      battle.userTurn = true;
    }
    if (battle.userTurn == false) {
      opponentAttackChoices();
    }
  }
  else {
    if (selectedUserCardType == cardType::ability) {
      //      drawRectangle(945, 345, 85, 50, true);
      if (x > 945 && x < 1030 && y>345 && y < 395) {
        userSelectedStat = cardStat::ability;
      }
    }
    else if (selectedUserCardType == cardType::fighting) {
      /*drawRectangle(900, 345, 85, 30, true); Force
      drawRectangle(900, 380, 85, 30, true); Block
      drawRectangle(990, 345, 85, 30, true); Gunnin
      drawRectangle(990, 380, 85, 30, true); Melee*/

      if (x > 900 && x < 985 && y>345 && y < 375) {
        userSelectedStat = cardStat::force;
      }
      else if (x > 900 && x < 985 && y>380 && y < 410) {
        userSelectedStat = cardStat::block;
      }
      else if (x > 990 && x < 1075 && y>345 && y < 375) {
        userSelectedStat = cardStat::gunnin;
      }
      else if (x > 990 && x < 1075 && y>380 && y < 410) {
        userSelectedStat = cardStat::melee;
      }

    }
    else if (selectedUserCardType == cardType::special) {
      if (x > 945 && x < 1030 && y>345 && y < 395) {
        userSelectedStat = cardStat::ability;
      }
      //drawRectangle(900, 410, 85, 30, true); Force
      //drawRectangle(900, 445, 85, 30, true); Block 
      //drawRectangle(990, 410, 85, 30, true); Gunnin
      //drawRectangle(990, 445, 85, 30, true); Melee
      else if (x > 900 && x < 985 && y>410 && y < 440) {
        userSelectedStat = cardStat::force;
      }
      else if (x > 900 && x < 985 && y>445 && y < 475) {
        userSelectedStat = cardStat::block;
      }
      else if (x > 990 && x < 1075 && y>410 && y < 440) {
        userSelectedStat = cardStat::gunnin;
      }
      else if (x > 990 && x < 1075 && y>445 && y < 475) {
        userSelectedStat = cardStat::melee;
      }
    }
    if (y > 580) {
      for (int j = 0; j < battle.getUserDeckSize(); j++)
      {
        if (battle.getUserDeck(j)->hitTest(x, y)) {
          selectedUserCard = battle.getUserDeck(j);
        }
      }
    }
  }


  onDraw();
}

void CardBattleWindow::resetSelected()
{
  selectedUserCard = nullptr;
  selectedUserCardType = cardType::none;
  userSelectedStat = cardStat::none;
}

void CardBattleWindow::opponentAttackChoices()
{
  //Opponent Attack and user can defend unless ability card
  attack = battle.opponentAttack();
  SpecialFightingCard* oSFC = dynamic_cast<SpecialFightingCard*>(attack.attackingCard);
  AbilityCard* oAC = dynamic_cast<AbilityCard*>(attack.attackingCard);
  string effect;
  gameEndState = battle.gameEnd();
  if (!battle.userTurn) {
    if (gameEndState == -1) {
      if (attack.attackType == cardType::ability) {
        outputText = "The opponent used " + attack.attackingCard->getCardName(); +" with ability ";
        if (oSFC != nullptr) {
          SpecialAbility* abilityToUse = oSFC->getAbility();
          int statAffected = oSFC->getStatAffected();
          effect = abilityToUse->returnEffect();
          outputText += abilityToUse->getName() + " which ";
          if (effect.at(0) == '-') {
            battle.applyStatChange(statAffected, stoi(effect), true);
            outputText += "decreased the user's stats as follows " + effect;
          }
          else if (effect.at(0) == '+') {
            battle.applyStatChange(statAffected, stoi(effect), false);
            outputText += "increased the opponent's stats as follows " + effect;
          }
          battle.removeCard(attack.attackingCard, false);
        }
        else if (oAC != nullptr) {
          SpecialAbility* abilityToUse = oAC->getAbility();
          effect = abilityToUse->returnEffect();
          outputText += abilityToUse->getName() + " which ";
          bool added = false;
          for (int statAffected = 0; statAffected < 4; statAffected++) {
            if (oAC->getStatAffected(statAffected)) {
              if (effect.at(0) == '-') {
                battle.applyStatChange(statAffected, stoi(effect), true);
                if (!added) {
                  outputText += "decreased the user's stats as follows " + effect;
                  added = true;
                }
              }
              else if (effect.at(0) == '+') {
                battle.applyStatChange(statAffected, stoi(effect), false);
                if (!added) {
                  outputText += "increased the opponent's stats as follows " + effect;
                  added = true;
                }
              }
            }
          }
        }
        battle.removeCard(attack.attackingCard, false);
        battle.opponentScore++;
      }
      else if (attack.attackType == cardType::fighting) {
        FightingCard* oFC = dynamic_cast<FightingCard*>(attack.attackingCard);
        outputText = "The opponent used card " + attack.attackingCard->getCardName() + " to attack you using the stat ";
        switch (attack.attackStat) {
        case cardStat::block:
          outputText += "Block with a value of " + to_string(oFC->checkStat(static_cast<int>(cardStat::block)));
          break;
        case cardStat::force:
          outputText += "Force with a value of " + to_string(oFC->checkStat(static_cast<int>(cardStat::force)));
          break;
        case cardStat::gunnin:
          outputText += "Gunning with a value of " + to_string(oFC->checkStat(static_cast<int>(cardStat::gunnin)));
          break;
        case cardStat::melee:
          outputText += "Melee with a value of " + to_string(oFC->checkStat(static_cast<int>(cardStat::melee)));
          break;
        }
      }
    }
  }
}
