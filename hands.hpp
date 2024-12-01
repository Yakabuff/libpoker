#ifndef POKER_HANDS_
#define POKER_HANDS_

#include <vector>
#include <card.hpp>
namespace poker{

   struct PokerHand {
      std::vector<Card> cards;
      PokerHands getPokerHand();
   };

   typedef PokerHand PokerHand;

   enum PokerHands {
      HIGH_CARD
   };
}
#endif