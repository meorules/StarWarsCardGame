#include "CardDeckWindow.h"

CardDeckWindow::CardDeckWindow(HINSTANCE hInsantce, int width, int height, User* currentUser) : Window(hInsantce, width, height), currentMenuUser(currentUser)
{
  createWindow(hInsantce, width, height);

}

CardDeckWindow::~CardDeckWindow()
{
}

void CardDeckWindow::onDraw()
{
  drawBitmap(backgroundFile, 0, 0, width, height);
  setTextColour(CYAN);
  //Title
  setFont(28, L"Ebrima Bold");
  drawText(L"Current User Deck", 300, 35);

  //Drawing Card Collection
  drawText(L"Card Collection", 30, 85);
  const int xSpace = 925;
  const int ySpace = 380;


  CardLibrary* instance = CardLibrary::returnInstance();

  vector<Card*>* listOfCards = instance->returnList();
//  vector<Card*>* listOfCards = currentMenuUser->returnCardCollection();

  const int cardWidth = 100;
  const int cardHeight = 130;
  int row = 0;
  for (int counter = 1; counter < listOfCards->size()+1; counter++) {
    if (currentMenuUser->checkCardInCollection(listOfCards->at(counter-1))>-1) {
      if (currentMenuUser->checkCardInDeck(listOfCards->at(counter - 1))>-1) {
        setFont( 10, L"Times New Roman Bold");
        setPenColour(BLACK, 1);
        setBackColour(MAGENTA);
        setTextColour(BLACK);
        drawRectangle(25 + (counter % 8) * (cardWidth + 15), 100 + (row) * (cardHeight)+30, cardWidth, cardHeight - 5, true);
        drawText(L"Card ", 10 + (counter % 8) * (cardWidth + 15)+cardWidth/2, 90 + (row) * (cardHeight)+30 + cardWidth/3);
        drawText(L"in ", 20 + (counter % 8) * (cardWidth + 15) + cardWidth / 2, 90 + (row) * (cardHeight)+30 + (cardWidth / 3)*2);
        drawText(L"Deck ", 10 + (counter % 8) * (cardWidth + 15) + cardWidth / 2, 90 + (row) * (cardHeight)+30 + (cardWidth));
      }
      else {
        listOfCards->at(counter - 1)->draw(this, 25 + (counter % 8) * (cardWidth + 15), 100 + (row) * (cardHeight)+30, cardWidth, cardHeight);
        if (selectedCollectionCard!= nullptr && listOfCards->at(counter - 1) == selectedCollectionCard) {
          setBackColour(65535);
          drawCircle(25 + (counter % 8) * (cardWidth + 15) + cardWidth / 2, 100 + (row) * (cardHeight)+30, 2, true);
          setPenColour(65535, 4);
          drawRectangle(25 + (counter%8) * (cardWidth + 15),100 + (row) * (cardHeight)+30, cardWidth, cardHeight - 5, false);
        }
      }
      }
    else {
      setPenColour(BLACK,1);
      setBackColour(WHITE);
      drawRectangle(25 + (counter % 8) * (cardWidth + 15), 100 + (row) * (cardHeight)+30, cardWidth, cardHeight-5, true);
      drawBitmap(L".\\imageAssets\\questionMark.bmp", 25 + (counter % 8) * (cardWidth + 15) + 13, 100 + (row) * (cardHeight)+30 + 16, int(0.75 * cardWidth), int(0.5 * cardHeight), 0x00FFFFFF);
    }
    if (counter % 8 == 0) {
      row++;
    }
  }

  //drawing Card Deck
  setTextColour(CYAN);
  setFont(28, L"Ebrima Bold");
  drawText(L"Card Deck", 30, 530);
  for (int i = 0; i < 5; i++) {
    currentMenuUser->returnCardDeck(i)->draw(this, 25 + (i) * (cardWidth + 15), 600, cardWidth, cardHeight);
    if (selectedDeckCard != nullptr && currentMenuUser->returnCardDeck(i) == selectedDeckCard) {
      setPenColour(65535, 4);
      drawRectangle(25 + (i) * (cardWidth + 15), 600, cardWidth, cardHeight - 5, false);
    }
  }

  //Swap from Collection to Deck Menu Button 
  setPenColour(16777215, 3);
  setFont(12, L"News Gothic Bold");
  setBackColour(DARK_BLUE);
  setTextColour(WHITE);
  drawRectangle(650, 620, 120, 30, true);
  drawText(L"Swap Selected", 655, 625);
  setTextColour(CYAN);
  drawText(outputText.c_str(), 655, 660);

  //Back to User Menu Button 
  setPenColour(16777215, 3);
  setFont(12, L"News Gothic Bold");
  setBackColour(DARK_BLUE);
  setTextColour(WHITE);
  drawRectangle(880, 700, 85, 30, true);
  drawText(L"User Menu", 885, 705);

  Window::onDraw();

}

void CardDeckWindow::onCreate()
{
  Window::onCreate();
  SetWindowText(getHWND(), L"Current User Deck");
  outputText = "Select two cards to swap";
}

void CardDeckWindow::onLButtonDown(UINT nFlags, int x, int y)
{
  //back to user menu button   drawRectangle(880, 700, 85, 30, true);
  if (x > 880 && x < 965 && y >700 && y < 730) {
    UserMenuWindow* main = new UserMenuWindow(hInstance, 600, 400, currentMenuUser);
    DestroyWindow(getHWND());
    main->waitForClose();
    delete main;
  }
  //Swap from Collection to Deck Menu Button   drawRectangle(650, 620, 120, 30, true);
  else if(x > 650 && x<770 && y>620 && y<650){
    if (selectedDeckCard != nullptr && selectedCollectionCard != nullptr){
      int toReplace = currentMenuUser->checkCardInDeck(selectedDeckCard);
        currentMenuUser->replaceCardinDeck(toReplace, selectedCollectionCard);
        outputText = selectedCollectionCard->getCardName() + " was added to the deck." ;
        selectedCollectionCard = nullptr;
        selectedDeckCard = nullptr;
    }
    else {
      outputText = "Deck or Collection card not selected";
    }
  }
  else {
    for (int j = 0; j < CardLibrary::returnInstance()->returnList()->size(); j++)
    {
      if (CardLibrary::returnInstance()->returnList()->at(j)->hitTest(x, y)) {
        if (y > 590) {
          selectedDeckCard = CardLibrary::returnInstance()->returnList()->at(j);
        }
        else {
          selectedCollectionCard = CardLibrary::returnInstance()->returnList()->at(j);
        }
      }
    }
  }
  onDraw();
}
