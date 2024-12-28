#include <vector>
#include <card.hpp>
namespace poker {
   struct Deck{
      Deck();
      std::vector<Card> cards;
      std::vector<Card> dealCards(int numCards);
   };
   typedef struct Deck Deck;
}