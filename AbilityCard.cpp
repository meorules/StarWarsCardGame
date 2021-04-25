#include "AbilityCard.h"

AbilityCard::AbilityCard(string cardId, string cardImage,bool good, string specialAbilityName, bool stats[4]) : Card(cardId,cardImage,good),noOfStatsAffected(0)
{

  ability = &SpecialAbilities::returnInstance()->returnList()->at(SpecialAbilities::returnInstance()->findAbility(SpecialAbility(specialAbilityName)));
  copy(stats, stats+4, begin(statsAffected));
  for (auto stat : statsAffected) {
    if (stat) {
      noOfStatsAffected++;
    }
  }
}

AbilityCard::~AbilityCard()
{
}

void AbilityCard::draw(EasyGraphics* canvas, int x, int y, int width, int height)
{
  Card::draw(canvas, x, y, width, height);

  canvas->setFont(width / 10 - 1, L"Times New Roman Bold");
  canvas->drawText((ability->getName()).c_str(), x + 8, y + 0.5 * height + 15);

  if (noOfStatsAffected == 2) {
    if (statsAffected[0] == 1) 
      canvas->drawText(("F" + ability->returnEffect()).c_str(), x + 5, y + 0.5 * height + 30);
    if (statsAffected[1] == 1)
      canvas->drawText(("G" + ability->returnEffect()).c_str(), x + width / 2 + 10, y + 0.5 * height + 30);
    if (statsAffected[2] == 1) 
      canvas->drawText(("B" + ability->returnEffect()).c_str(), x + 5, y + 0.5 * height + 45);
    if(statsAffected[3]==1)
      canvas->drawText(("M" + ability->returnEffect()).c_str(), x + width / 2 + 10, y + 0.5 * height + 45);
  }
  else {
    string allEffect = "All Stats " + ability->returnEffect();
    canvas->drawText(allEffect.c_str(), x +5 , y + height -23);
  }
}

string AbilityCard::getAbilityName()
{
  return ability->getName();
}

SpecialAbility* AbilityCard::getAbility()
{
  return ability;
}

bool AbilityCard::getStatAffected(int cardStat)
{
  return statsAffected[cardStat];
}

Card* AbilityCard::copyCard()
{
  return new AbilityCard(*this);
}
