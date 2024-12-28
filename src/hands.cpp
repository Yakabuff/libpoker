
#include <hands.hpp>

namespace poker {

   // OR all cards
   // bit shift 4 right
   // Returns highest poker hand
   // 
   PokerHands PokerHand::getPokerHand() {
      switch (this->cards.size()) {
         case 5:
            break;
         case 4:
            break;
         case 3:
            break;
         case 2:
            break;
         case 1:
            return PokerHands::HIGH_CARD;
      }
   }
}