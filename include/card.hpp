#ifndef POKER_CARDS_
#define POKER_CARDS_
#include <string>
#include <optional>
namespace poker {

   enum class Suite {
      INVALID, DIAMOND=1, CLUB=2<<0, HEART=2<<1, SPADE=2<<2
   };

   enum class Rank {
      INVALID,
      TWO,
      THREE=2<<0, 
      FOUR=2<<1, 
      FIVE=2<2, 
      SIX=2<<3, 
      SEVEN=2<<4, 
      EIGHT=2<<5, 
      NINE=2<<6, 
      TEN=2<<7, 
      JACK=2<<8, 
      QUEEN=2<<9, 
      KING=2<<10, 
      ACE=2<<11
   };

   /*
   * Cards are represented as a 32 bit unsigned integer
   * 0001 -> diamonds 
   * 0000000000001 -> 3
   * 
   * 00000000000000000000000000010001
   * 
   */
   struct Card{
      Rank rank;
      Suite suite;
      u_int32_t val;
      Card(Suite, Rank);
      Card(std::string);
      bool operator<(const Card&) const;
      bool operator>(const Card&) const;
      static std::optional<Card> newCard(std::string);
      Suite stringToSuite(std::string);
      Rank stringToRank(std::string);
      Suite uintToSuite(u_int32_t);
      Rank uintToRank(u_int32_t);
   };
   typedef Card Card;
}
#endif