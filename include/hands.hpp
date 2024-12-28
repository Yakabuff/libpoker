#ifndef POKER_HANDS_
#define POKER_HANDS_

#include <vector>
#include <card.hpp>
namespace poker{

   enum class PokerHands {
      HIGH_CARD,
      PAIR,
      TWO_PAIR,
      THREE_OF_A_KIND,
      STRAIGHT,
      FLUSH,
      FULL_HOUSE,
      FOUR_OF_A_KIND,
      STRAIGHT_FLUSH,
      FIVE_OF_A_KIND
   };

   struct PokerHand {
      std::vector<Card> cards;
      PokerHands getPokerHand();
   };

   typedef PokerHand PokerHand;
}
#endif