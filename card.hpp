#ifndef POKER_CARDS_
#define POKER_CARDS_
namespace poker {
   struct Card{
      Rank rank;
      Suite suite;

      bool operator<(const Card &card) const;

      bool operator>(const Card &card) const;

   };

   typedef Card Card;

   enum class Suite {
      DIAMOND=1, CLUB, HEART, SPADE
   };

   enum class Rank {
      ONE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
   };

}
#endif