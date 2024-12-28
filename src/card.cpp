#include <card.hpp>
#include <set>
#include <iostream>
namespace poker{
   bool Card::operator <(const Card &card) const{
      return this->rank < card.rank && this->suite < card.suite;
   }

   bool Card::operator >(const Card &card) const{
      return card < *this;
   }

   Card::Card(Suite s, Rank r) {
      Card::rank = r;
      Card::suite = s;
   }

   // String representation to `Card`
   // JS -> Jack of spades, 2D -> 2 of diamonds
   // 2,3,4,5,6,7,8,9,10,J,Q,K,A
   // D,C,H,S
   // Assert not 1 and is digit or JQKA
   // Assert DCHS for suite
   Card::Card(std::string s) {
      if (s.length() == 2) {
         this->rank = stringToRank(s.substr(0,1));
         this->suite = stringToSuite(s.substr(1));
      } else {
         this->rank = Rank::TEN;
         this->suite = stringToSuite(s.substr(2));
      }
      this->val = static_cast<u_int32_t>(this->rank) << 4 | static_cast<u_int32_t>(this->suite);
   }

   // LE systems: mask all but first 4 bits
   Rank Card::uintToRank(u_int32_t card) {
      return static_cast<Rank>(card & 15);
   }

   // bitshift 4 right
   Suite Card::uintToSuite(u_int32_t card) {
      return static_cast<Suite>(card >> 4);
   }

   // If num, convert to enum directly: 2^(stoi(s)-2)
   // If not, convert to face card
   Rank Card::stringToRank(std::string s) {
      return static_cast<Rank>(std::stoi(s)-1);
   }

   Suite Card::stringToSuite(std::string s) {
      if (s == "D") {
         return Suite::DIAMOND;
      } else if (s == "C") {
         return Suite::CLUB;
      } else if (s == "H") {
         return Suite::HEART;
      } else {
         return Suite::SPADE;
      }
   }

   std::optional<Card> Card::newCard(std::string s) {
      std::set<char> validRank = {'2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K', 'A'};
      std::set<char> validSuite = {'D', 'C', 'H', 'S'};
      if (s.length() > 3 || s.length() < 2) {
         return {};
      } 
      if (s.length() == 2) {
         return validRank.count(s[0]) == 1 && validSuite.count(s[1]) == 1 ? std::optional<Card>{Card(s)} : std::nullopt;
      } else if (s.length() == 3) {
         return s[0] == '1' && s[1] == '0' && validSuite.count(s[2]) == 1 ? std::optional<Card>{Card(s)} : std::nullopt;
      } else {
         return std::nullopt;
      }
   }

}